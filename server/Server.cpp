#define _WINSOCKAPI_

#include "Common.hpp"
#include <ace/Time_Value.h>
#include <ace/OS_main.h>
#include <ace/Reactor.h>
#include "KatSecurity.hpp"
#include "GatewayServer.hpp"
#include "GameServer.hpp"
#include <nsrpc/ProactorFactory.h>
#include <nsrpc/ReactorTask.h>

//=========================================================================================================================================

int ACE_TMAIN(int argc, ACE_TCHAR* argv[])
{
	LogLine(Logf_Normal, "[Main] SmashServer %s %s\n", __DATE__, __TIME__);

	SetConsoleTitle("SmashServer");

	ACE_Proactor* proactor = nsrpc::ProactorFactory::create(nsrpc::ptWin32);

	nsrpc::ReactorTask reactor_task;
	ACE_Reactor* reactor = reactor_task.getReactor();

	kat::KatPacketCoderFactory packet_coder_factory("tea", 0);

	reactor_task.start(1);
	LogLine(Logf_Normal, "[Main] Started reactor\n");

	GameServerInstance game_server(proactor, reactor, &packet_coder_factory);
	ACE_INET_Addr game_server_address(11120, "127.0.0.1");
	game_server.open(game_server_address, proactor);
	game_server.start();
	LogLine(Logf_Normal, "[Main] Started game-server\n");

	GatewayServerInstance* gateway_server = new GatewayServerInstance(proactor, &packet_coder_factory);
	ACE_INET_Addr gateway_server_address(11111, "127.0.0.1");
	gateway_server->open(gateway_server_address, proactor);
	gateway_server->start();
	LogLine(Logf_Normal, "[Main] Started gateway-server\n");

	LogLine(Logf_Normal, "[Main] Started proactor\n");
	int success = 1;
	while (success > 0)
		success = proactor->handle_events();

	LogLine(Logf_Normal, "[Main] Finished\n");
	_getch();

	return 0;
}

//=========================================================================================================================================