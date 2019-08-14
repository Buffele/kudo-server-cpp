#pragma once

#include "GatewayServer.hpp"
#include "Common.hpp"

//=========================================================================================================================================

GatewayServerSession::GatewayServerSession(nsrpc::RpcSessionConfig& config) :
	KatServerSession(config)
{
}

GatewayServerSession::~GatewayServerSession()
{
}

void GatewayServerSession::open(ACE_HANDLE new_handle, ACE_Message_Block& message_block)
{
	KatServerSession::open(new_handle, message_block);
	if (isConnected())
	{
		char str_remote_addr[64];
		ACE_INET_Addr remote_addr = getRemoteAddress();
		remote_addr.addr_to_string(str_remote_addr, sizeof(str_remote_addr));

		char str_private_addr[64];
		ACE_INET_Addr private_addr = getPrivateAddress();
		private_addr.addr_to_string(str_private_addr, sizeof(str_remote_addr));

		LogLine(Logf_Normal, "[Gateway] Connected %s (%s)\n", str_remote_addr, str_private_addr);

		// TODO: true balancer

		kat::RAddressPair gs_address;
		gs_address.ip = "127.0.0.1";
		gs_address.port = 11120;
		onConnectionInfo(gs_address);

		LogLine(Logf_Normal, "[Gateway] Routed %s to %s:%u\n", str_remote_addr, gs_address.ip.c_str(), gs_address.port.get());
	}
}

void GatewayServerSession::onDisconnected()
{
	char str_remote_addr[64];
	ACE_INET_Addr remote_addr = getRemoteAddress();
	remote_addr.addr_to_string(str_remote_addr, sizeof(str_remote_addr));

	char str_private_addr[64];
	ACE_INET_Addr private_addr = getPrivateAddress();
	private_addr.addr_to_string(str_private_addr, sizeof(str_remote_addr));

	LogLine(Logf_Normal, "[Gateway] Disconnected %s (%s)\n", str_remote_addr, str_private_addr);

	KatServerSession::onDisconnected();
}

IMPLEMENT_SRPC_EVENT_DISPATCHER(GatewayServerSession);

DEFINE_SRPC_METHOD_1(GatewayServerSession, onConnectionInfo, kat::RAddressPair, address);

//=========================================================================================================================================

GatewayServerInstance::GatewayServerInstance(ACE_Proactor* proactor, kat::KatPacketCoderFactory* packet_coder_factory) :
	nsrpc::SessionAcceptor((nsrpc::SessionCreator&)*this)
{
	m_proactor = proactor;
	m_packet_coder_factory = packet_coder_factory;
}

GatewayServerInstance::~GatewayServerInstance()
{
}

nsrpc::Session* GatewayServerInstance::acquire()
{
	nsrpc::SessionRpcNetwork* session_network = new nsrpc::SessionRpcNetwork(true);
	if (!session_network)
		return nullptr;
	nsrpc::PacketCoder* packet_coder = m_packet_coder_factory->create();
	if (!packet_coder)
		return nullptr;
	nsrpc::PacketSeedExchangerForServer* seed_exchanger = new nsrpc::PacketSeedExchangerForServer();
	if (!seed_exchanger)
		return nullptr;
	seed_exchanger->initialize(packet_coder, session_network);
	nsrpc::SynchMessageBlockManager* message_block_mgr = new nsrpc::SynchMessageBlockManager(packet_coder->getDefaultPacketPoolSize(), packet_coder->getDefaultPacketSize());
	if (!message_block_mgr)
		return nullptr;
	nsrpc::RpcSessionConfig session_config(this, message_block_mgr, packet_coder, m_proactor, session_network, seed_exchanger);
	GatewayServerSession* session = new GatewayServerSession(session_config);
	if (!session)
		return nullptr;
	printf("[Gateway] Session created %p\n", session);
	return session;
}

void GatewayServerInstance::release(nsrpc::Session* session)
{
	if (!session)
		return;
	GatewayServerSession* gateway_session = (GatewayServerSession*)session;
	printf("[Gateway] Session destroyed %p\n", gateway_session);
	delete gateway_session;
}

//=========================================================================================================================================