#pragma once

#include "KatCommon.hpp"
#include "KatRpc.hpp"
#include "KatServer.hpp"

//=========================================================================================================================================

// Gateway-server session (server-side)
class GatewayServerSession :
	public kat::KatServerSession,
	public kat::RpcLoadBalancingServiceEvent
{
	DECLARE_SRPC_EVENT_DISPATCHER(GatewayServerSession);

public:
	// Constructor
	GatewayServerSession(nsrpc::RpcSessionConfig& config);

	// Destructor
	virtual ~GatewayServerSession() override;

	// Opens a session
	virtual void open(ACE_HANDLE new_handle, ACE_Message_Block& message_block) override;

	// Session closed
	virtual void onDisconnected() override;

	// Load-balancing service event
	DECLARE_SRPC_METHOD_1(onConnectionInfo, kat::RAddressPair, address);
};

//=========================================================================================================================================

// Gateway-server instance (server-side)
class GatewayServerInstance :
	public nsrpc::SessionDestroyer,
	public nsrpc::SessionCreator,
	public nsrpc::SessionAcceptor
{
public:
	// Constructor
	GatewayServerInstance(ACE_Proactor* proactor, kat::KatPacketCoderFactory* packet_coder_factory);

	// Destructor
	virtual ~GatewayServerInstance() override;

	// Acquires new gateway-server session
	virtual nsrpc::Session* acquire() override;

	// Releases gateway-server session
	virtual void release(nsrpc::Session* session) override;

private:
	ACE_Proactor* m_proactor;
	kat::KatPacketCoderFactory* m_packet_coder_factory;
};

//=========================================================================================================================================