#pragma once

#include <ace\Task.h>
#include <srpc\RpcTypes.h>
#include <srpc\RpcContainers.h>
#include <srpc\RpcInterface.h>
#include <srpc\RpcReceiver.h>
#include <srpc\RpcForwarder.h>
#include <srpc\RpcNetwork.h>
#include <nsrpc\PacketSeedExchanger.h>
#include <nsrpc\..\..\src\PacketSeedExchangerImpl.h>
#include <nsrpc\detail\SessionRpcNetwork.h>
#include "KatCommon.hpp"

//=========================================================================================================================================

namespace kat
{
	// RPC address pair
	struct RAddressPair
	{
		srpc::RShortString ip;
		srpc::RUInt16 port;

		void write(srpc::OStream& ostream)
		{
			ip.write(ostream);
			port.write(ostream);
		}
		void read(srpc::IStream& istream)
		{
			ip.read(istream);
			port.read(istream);
		}

	};

	// Heartbeat service (for game)
	class RpcHeartbeatService
	{
	public:
		virtual ~RpcHeartbeatService() { }
		DECLARE_SRPC_PURE_METHOD_0(RpcHeartbeatService, heartbeat);

	};

	// Rpc load-balancing service event (for gateway)
	class RpcLoadBalancingServiceEvent
	{
	public:
		virtual ~RpcLoadBalancingServiceEvent() { }
		DECLARE_SRPC_PURE_METHOD_1(RpcLoadBalancingServiceEvent, onConnectionInfo, RAddressPair, address);
	};
}

//=========================================================================================================================================