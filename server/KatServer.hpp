#pragma once

#include <ace\Proactor.h>
#include <ace\Asynch_IO.h>
#include <ace\Asynch_Acceptor.h>
#include <nsrpc\ProactorFactory.h>
#include <nsrpc\RpcSession.h>
#include <nsrpc\RpcSessionConfig.h>
#include <nsrpc\SessionAcceptor.h>
#include <nsrpc\detail\SessionCreator.h>
#include <nsrpc\detail\SessionDestroyer.h>
#include <nsrpc\utility\MessageBlockManager.h>
#include "KatCommon.hpp"
#include "KatRpc.hpp"
#include "KatSecurity.hpp"

//=========================================================================================================================================

namespace kat
{
	// Session container (server-side)
	class KatServerSession :
		public nsrpc::RpcSession/*,
		public RpcHeartbeatService*/
	{
	public:
		KatServerSession(nsrpc::RpcSessionConfig& config) :
			nsrpc::RpcSession(config)
		{
		}
	};
}

//=========================================================================================================================================