#pragma once

#include <inttypes.h>

//=========================================================================================================================================

namespace kat
{
	// Session event handler prototype
	class SessionEventHandler
	{
	public:
		virtual ~SessionEventHandler() { };
		virtual void onSendError() { };
		virtual void onReceiveError() { };
		virtual void onDisconnected() { };
		virtual void onConnected() { };
		virtual void onTimeout() { };

	};
}

//=========================================================================================================================================