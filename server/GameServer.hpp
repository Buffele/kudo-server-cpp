#pragma once

#include "KatCommon.hpp"
#include "KatRpc.hpp"
#include "KatServer.hpp"
#include "KudoCommon.hpp"
#include "KudoRpc.hpp"
#include <mutex>
#include <ace/Reactor.h>
#include <nsrpc/p2p/rpc_interface/StunService.h>
#include <nsrpc/p2p/rpc_interface/RelayService.h>
#include <nsrpc/p2p/detail/P2pEndpoint.h>
#include <nsrpc/p2p/detail/P2pRpcNetwork.h>
#include <nsrpc/p2p/detail/P2pPeerHint.h>
#include <nsrpc/p2p/detail/PeerNetworkSender.h>
#include <nsrpc/p2p/detail/PeerNotifier.h>
#include <nsrpc/p2p/detail/PeerCipherKeyCache.h>
#include <nsrpc/p2p/P2pEventHandler.h>
#include <nsrpc/detail/PacketCoder.h>
#include <nsrpc/detail/PacketCoderFactory.h>

//=========================================================================================================================================

// Messenger-subserver session (server-side)
class MessengerServerSession :
	public kudo::RpcBuddyService,
	public kudo::RpcBuddyServiceEvent,
	public kudo::RpcInstantChatService,
	public kudo::RpcInstantChatServiceEvent,
	public kudo::RpcChannelChattingService,
	public kudo::RpcChannelChattingServiceEvent,
	public kudo::RpcMailService,
	public kudo::RpcMailServiceEvent,
	public srpc::RpcReceiver,
	public srpc::RpcForwarder
{
	DECLARE_SRPC_EVENT_DISPATCHER(MessengerServerSession);
public:
	// Constructor
	MessengerServerSession(class GameServerSession* parent, srpc::RpcNetwork* network);

	// Destructor
	virtual ~MessengerServerSession();

	// Buddy service
	DECLARE_SRPC_METHOD_1(subscribeBuddy, kudo::RNickname, nickname);
	DECLARE_SRPC_METHOD_1(unsubscribeBuddy, srpc::RUInt32, uint1);
	DECLARE_SRPC_METHOD_1(blockBuddy, srpc::RUInt32, uint1);
	DECLARE_SRPC_METHOD_1(unblockBuddy, srpc::RUInt32, uint1);
	DECLARE_SRPC_METHOD_1(addBuddyGroup, kudo::RNickname, nickname);
	DECLARE_SRPC_METHOD_1(removeBuddyGroup, srpc::RUInt32, uint1);
	DECLARE_SRPC_METHOD_2(changeBuddyGroupName, srpc::RUInt32, uint1, kudo::RNickname, name);
	DECLARE_SRPC_METHOD_2(classifyBuddy, srpc::RUInt32, uint1, srpc::RUInt32, uint2);
	DECLARE_SRPC_METHOD_1(getBuddyInfo, srpc::RUInt32, uint1);
	DECLARE_SRPC_METHOD_1(inviteBuddy, srpc::RUInt32, uint1);
	DECLARE_SRPC_METHOD_2(onSubscribeBuddy, kudo::RErrorCode, error_code, kudo::RBuddy, buddy);
	DECLARE_SRPC_METHOD_2(onUnsubscribeBuddy, kudo::RErrorCode, error_code, srpc::RUInt32, uint2);
	DECLARE_SRPC_METHOD_2(onBlockBuddy, kudo::RErrorCode, error_code, srpc::RUInt32, uint2);
	DECLARE_SRPC_METHOD_2(onUnblockBuddy, kudo::RErrorCode, error_code, srpc::RUInt32, uint2);
	DECLARE_SRPC_METHOD_2(onAddBuddyGroup, kudo::RErrorCode, error_code, kudo::RBuddyGroup, group);
	DECLARE_SRPC_METHOD_2(onRemoveBuddyGroup, kudo::RErrorCode, error_code, srpc::RUInt32, uint2);
	DECLARE_SRPC_METHOD_2(onChangeBuddyGroupName, kudo::RErrorCode, error_code, kudo::RBuddyGroup, group);
	DECLARE_SRPC_METHOD_3(onClassifyBuddy, kudo::RErrorCode, error_code, srpc::RUInt32, uint2, srpc::RUInt32, uint3);
	DECLARE_SRPC_METHOD_3(onGetBuddyInfo, kudo::RErrorCode, error_code, srpc::RUInt32, uint2, kudo::RFullCharacter, info);

	// Buddy service event
	DECLARE_SRPC_METHOD_2(onBuddyRoster, kudo::RBuddyGroups, groups, kudo::RBuddies, buddies);
	DECLARE_SRPC_METHOD_2(onBuddySubscribed, kudo::RNickname, nickname, kudo::RPlace, place);
	DECLARE_SRPC_METHOD_2(onBuddyCurrentPlaceChanged, srpc::RUInt32, uint1, kudo::RPlace, place);
	DECLARE_SRPC_METHOD_3(onBuddyInvited, srpc::RUInt32, uint1, kudo::RPlace, place, kudo::RRoomPass, string3);

	// Instant chat service
	DECLARE_SRPC_METHOD_2(call, kudo::RChatVec1, vec1, srpc::RUInt16, uint2);
	DECLARE_SRPC_METHOD_2(say, srpc::RUInt16, uint1, kudo::RChatMessage, message);
	DECLARE_SRPC_METHOD_1(bye, srpc::RUInt16, uint1);
	DECLARE_SRPC_METHOD_3(onCall, kudo::RErrorCode, error_code, kudo::RChatVec1, vec1, srpc::RUInt16, uint2);

	// Instant chat service event
	DECLARE_SRPC_METHOD_2(onCalled, srpc::RUInt16, uint1, kudo::RBaseUserInfos, users);
	DECLARE_SRPC_METHOD_2(onJoined, srpc::RUInt16, uint1, kudo::RBaseUserInfos, users);
	DECLARE_SRPC_METHOD_3(onSaid, srpc::RUInt16, uint1, srpc::RUInt32, uint2, kudo::RChatMessage, message);
	DECLARE_SRPC_METHOD_2(onBye, srpc::RUInt16, uint1, srpc::RUInt32, uint2);

	// Channel chat service
	DECLARE_SRPC_METHOD_3(openChannelRoomDoor, kudo::RRoomTitle, str1, kudo::RRoomPass, str2, kudo::RChatUint1, uint3);
	DECLARE_SRPC_METHOD_2(enterChannelRoom, srpc::RUInt16, uint1, kudo::RRoomPass, str2);
	DECLARE_SRPC_METHOD_1(leaveChannelRoom, srpc::RUInt16, uint1);
	DECLARE_SRPC_METHOD_3(channelChat, srpc::RUInt16, uint1, srpc::RUInt32, uint2, kudo::RChatMessage, message);
	DECLARE_SRPC_METHOD_2(requestChannelRoomList, srpc::RUInt16, uint1, srpc::RUInt8, uint2);
	DECLARE_SRPC_METHOD_3(searchChannelRoomList, kudo::RRoomTitle, str1, srpc::RUInt16, uint2, srpc::RUInt8, uint3);
	DECLARE_SRPC_METHOD_2(kickChannelUser, srpc::RUInt16, uint1, srpc::RUInt32, uint2);
	DECLARE_SRPC_METHOD_2(inviteBuddyToChannel, srpc::RUInt16, uint1, srpc::RUInt32, uint2);
	DECLARE_SRPC_METHOD_4(modifyChannelRoom, srpc::RUInt16, uint1, kudo::RRoomTitle, str2, kudo::RRoomPass, str3, kudo::RChatUint1, uint4);
	DECLARE_SRPC_METHOD_2(onOpenChannelRoomDoor, kudo::RErrorCode, error_code, kudo::RFullChannelRoomInfo, room_info);
	DECLARE_SRPC_METHOD_2(onEnterChannelRoom, kudo::RErrorCode, error_code, kudo::RFullChannelRoomInfo, room_info);
	DECLARE_SRPC_METHOD_2(onLeaveChannelRoom, kudo::RErrorCode, error_code, srpc::RUInt16, uint2);
	DECLARE_SRPC_METHOD_2(onRequestChannelRoomList, kudo::RChannelRoomInfos, rooms_list, srpc::RUInt16, uint2);
	DECLARE_SRPC_METHOD_1(onSearchChannelRoomList, kudo::RChannelRoomInfo, room_info);
	DECLARE_SRPC_METHOD_3(onKickChannelUser, kudo::RErrorCode, error_code, srpc::RUInt16, uint2, srpc::RUInt32, uint3);
	DECLARE_SRPC_METHOD_1(onInviteBuddyToChannel, kudo::RErrorCode, error_code);
	DECLARE_SRPC_METHOD_6(onModifyChannelRoom, kudo::RErrorCode, error_code, srpc::RUInt16, uint2, kudo::RRoomTitle, str3, kudo::RRoomPass, str4, kudo::RChatUint1, uint5, srpc::RBool, bool5);

	// Channel chat service event
	DECLARE_SRPC_METHOD_2(onChannelUserEntered, srpc::RUInt16, uint1, kudo::RChannelUserInfo, user_info);
	DECLARE_SRPC_METHOD_2(onChannelRoomLeft, srpc::RUInt16, uint1, srpc::RUInt32, uint2);
	DECLARE_SRPC_METHOD_2(onChannelRoomMasterChanged, srpc::RUInt16, uint1, srpc::RUInt32, uint2);
	DECLARE_SRPC_METHOD_3(onChannelChat, srpc::RUInt16, uint1, srpc::RUInt32, uint2, kudo::RChatMessage, message);
	DECLARE_SRPC_METHOD_2(onChannelUserKicked, srpc::RUInt16, uint1, srpc::RUInt32, uint2);
	DECLARE_SRPC_METHOD_3(onChannelUserStateChanged, srpc::RUInt16, uint1, srpc::RUInt32, uint2, srpc::RBool, bool3);
	DECLARE_SRPC_METHOD_3(onChannelInvited, srpc::RUInt16, uint1, srpc::RUInt32, uint2, kudo::RRoomPass, str3);
	DECLARE_SRPC_METHOD_4(onChannelRoomModified, srpc::RUInt16, uint1, kudo::RRoomTitle, str2, kudo::RChatUint1, uint3, srpc::RBool, bool4);

	// Mail service
	DECLARE_SRPC_METHOD_0(requestMails);
	DECLARE_SRPC_METHOD_2(sendMail, kudo::RNickname, nickname, kudo::RMailText, text);
	DECLARE_SRPC_METHOD_4(sendPresentMail, kudo::RNickname, nickname, srpc::RUInt32, uint2, kudo::RPayWay, pay_way, kudo::RBuyMethod, buy_method);
	DECLARE_SRPC_METHOD_2(receivePresentItem, srpc::RUInt32, uint1, kudo::RMailType, mail_type);
	DECLARE_SRPC_METHOD_2(readMail, srpc::RUInt32, uint1, kudo::RMailType, mail_type);
	DECLARE_SRPC_METHOD_2(deleteMail, srpc::RUInt32, uint1, kudo::RMailType, mail_type);
	DECLARE_SRPC_METHOD_1(sendBackMail, srpc::RUInt32, uint1);
	DECLARE_SRPC_METHOD_2(onMailList, kudo::RMailInfos, mails1, kudo::RMailInfos, mails2);
	DECLARE_SRPC_METHOD_3(onSendMail, kudo::RErrorCode, error_code, kudo::RPrice, price, kudo::RMailInfo, info);
	DECLARE_SRPC_METHOD_7(onReceivePresentItem, kudo::RErrorCode, error_code, srpc::RUInt32, uint2, kudo::RMailType, mail_type, srpc::RUInt32, uint4, srpc::RUInt32, uint5, srpc::RUInt16, uint6, srpc::RInt32, sint7);
	DECLARE_SRPC_METHOD_5(onReadMail, kudo::RErrorCode, error_code, srpc::RUInt32, uint2, kudo::RMailType, type, kudo::RMailText, text, srpc::RUInt32, uint5);
	DECLARE_SRPC_METHOD_3(onDeleteMail, kudo::RErrorCode, error_code, srpc::RUInt32, uint2, kudo::RMailType, type);
	DECLARE_SRPC_METHOD_2(onSendBackMail, kudo::RErrorCode, error_code, srpc::RUInt32, uint2);

	// Mail service event
	DECLARE_SRPC_METHOD_2(onMailReceived, kudo::RMailType, type, kudo::RMailInfo, info);
	DECLARE_SRPC_METHOD_2(onSentMailStateChanged, srpc::RUInt32, uint1, kudo::RMailState, state);
	DECLARE_SRPC_METHOD_1(onPresentItemReceived, srpc::RUInt32, uint1);

private:
	friend class GameServerSession;
	friend class GameServerInstance;

	// data
	GameServerSession* m_parent;
};

//=========================================================================================================================================

// Starwars-subserver session (server-side)
class StarwarsServerSession :
	public kudo::RpcStarwarsService,
	public kudo::RpcStarwarsServiceEvent,
	public srpc::RpcReceiver,
	public srpc::RpcForwarder
{
public:
	// Constructor
	StarwarsServerSession(srpc::RpcNetwork* network, ACE_Reactor* reactor)
	{
		srpc::RpcReceiver::setRpcNetwork(network);
		srpc::RpcForwarder::setRpcNetwork(network);
	}

	// Destructor
	virtual ~StarwarsServerSession()
	{
	}
};

//=========================================================================================================================================

// Relay-subserver for game room
class GameServerRoomRelay :
	public nsrpc::detail::RpcStunService,
	public nsrpc::detail::RpcRelayService,
	private srpc::RpcReceiver,
	private srpc::RpcForwarder,
	private nsrpc::detail::PeerNotifier,
	private nsrpc::detail::PeerNetworkSender
{
	DECLARE_SRPC_EVENT_DISPATCHER(GameServerRoomRelay);
public:
	// Constructor
	GameServerRoomRelay(class GameServerRoom* owner, ACE_Reactor* reactor, nsrpc::PacketCoder* packet_coder, bool use_bit_packing = true);

	// Destructor
	virtual ~GameServerRoomRelay();

	// Starts server
	bool start(uint16_t port, uint32_t key = 0);

	// Stops server
	void stop();

public:
	// RpcStunService
	DECLARE_SRPC_P2P_METHOD_0(rpcResolve);
	DECLARE_SRPC_METHOD_2(rpcResolved, srpc::RShortString, ipAddress, srpc::RUInt16, port);

	// RpcRelayService
	DECLARE_SRPC_P2P_METHOD_6(rpcRelay, nsrpc::RPeerIdPair, peerIdPair, nsrpc::detail::RAddress, peerAddress,
		nsrpc::detail::RMessageBuffer, messageBlock, srpc::RRpcPacketType, packetType,
		nsrpc::RSequenceNumber, sequenceNumber, nsrpc::RRelativeTime, sentTime);
	DECLARE_SRPC_METHOD_5(rpcRelayed, nsrpc::RPeerId, peerId, nsrpc::detail::RMessageBuffer, messageBlock,
		srpc::RRpcPacketType, packetType, nsrpc::RSequenceNumber, sequenceNumber, nsrpc::RRelativeTime, sentTime);

private:
	// PeerNotifier
	virtual void onMessageArrived(const ACE_INET_Addr& peerAddress);

	// PeerNetworkSender
	virtual bool sendNow(const nsrpc::PeerIdPair& peerIdPair, const nsrpc::detail::AddressPair& addressPair, const ACE_Message_Block& mblock,
		srpc::RpcPacketType packetType, nsrpc::SequenceNumber sequenceNumber, srpc::UInt32 sentTime);
	virtual void marshalingErrorOccurred();
	virtual void sendOutgoingMessage(srpc::RpcPacketType packetType, ACE_Message_Block* mblock, const nsrpc::detail::P2pPeerHint* peerHint);
	virtual size_t getHeaderSize() const;

private:
	friend class GameServerRoom;

	// data
	ACE_Reactor* m_reactor;
	nsrpc::PacketCoder* m_packet_coder;
	ACE_Message_Block* m_recv_block;
	ACE_Message_Block* m_send_block;
	nsrpc::detail::P2pEndpoint m_endpoint;
	nsrpc::detail::P2pRpcNetwork m_rpc_network;
	nsrpc::SequenceNumber m_outgoing_unreliable_sequence_number;
	nsrpc::detail::PeerCipherKeyCache m_peer_cipher_keys;
	class GameServerRoom* m_owner;
	uint16_t m_port;
	uint32_t m_key;
};

// Game-server room (server-side)
class GameServerRoom
{
public:
	// Constructor
	GameServerRoom(class GameServerInstance* owner);

	// Destructor
	~GameServerRoom();

	// Builds game rules for RPC
	void buildRpcGameRules(kudo::RGameRules& game_rules);

	// Builds simplified information for RPC
	void buildSimpleRpcInfo(kudo::RSimpleGameRoomInfo& info);

	// Builds full information for RPC
	void buildFullRpcInfo(kudo::RFullGameRoomInfo& info, bool show_password);

	// States
	enum
	{
		State_Unknown = 0,
		State_Waiting = 1,
		State_Starting = 2,
		State_Playing = 3,
	};

private:
	friend class GameServerSession;
	friend class GameServerInstance;
	friend class GameServerRoomRelay;

	// Searches for a free slot for a player
	int8_t findFreeSlot();

	// Calculates player count
	size_t calcPlayers();

	// Delegates master
	void delegateMaster(int8_t new_master_slot, size_t new_master_index, class GameServerSession* elimiated_user);

	// Handles player exit
	size_t playerLeft(class GameServerSession* user);

	// common
	std::mutex m_total_lock;
	GameServerRoomRelay* m_relay;
	class GameServerInstance* m_owner;

	// information
	srpc::WString m_title;
	srpc::String m_password;
	uint16_t m_number;
	int32_t m_grade_mode;
	bool m_locked;
	uint8_t m_master_slot;
	uint8_t m_state;
	GameServerSession* m_players[4]; // nullptr means unassigned

	// game rules
	kudo::GameType m_game_type; // also match_mode
	uint32_t m_map_id;
	uint8_t m_set_count;
	uint8_t m_game_count;
};

//=========================================================================================================================================

// Game-server session (server-side)
class GameServerSession :
	public kat::KatServerSession,
	public kat::RpcHeartbeatService,
	public kudo::RpcAccountService,
	public kudo::RpcLoginService,
	public kudo::RpcUserService,
	public kudo::RpcGameModeService,
	public kudo::RpcGameService,
	public kudo::RpcGameServiceEvent,
	public kudo::RpcItemService,
	public kudo::RpcItemServiceEvent
{
	DECLARE_SRPC_EVENT_DISPATCHER(GameServerSession);
public:
	// Constructor
	GameServerSession(class GameServerInstance* owner, nsrpc::RpcSessionConfig& config);

	// Destructor
	virtual ~GameServerSession() override;

	// Builds full user information for RPC
	void buildFullUserRpcInfo(kudo::RFullUserInfo& info);

	// Build player information for RPC
	void buildPlayerRpcInfo(kudo::RPlayerInfo& info);

	// Returns current entered room with error
	kudo::ErrorCode getCurrentRoom(class GameServerRoom*& game_room);

	// Opens a session
	virtual void open(ACE_HANDLE new_handle, ACE_Message_Block& message_block) override;

	// Session closed
	virtual void onDisconnected() override;

	// Heartbeat service
	DECLARE_SRPC_METHOD_0(heartbeat);

	// Account service
	DECLARE_SRPC_METHOD_2(login, kudo::RAccountLogin, login, kudo::RAccountPassword, password);
	DECLARE_SRPC_METHOD_2(onLoginResult, kudo::RErrorCode, error_code, kudo::RFullUserInfo, user_info);

	// Login service
	DECLARE_SRPC_METHOD_0(requestCharacterTemplates);
	DECLARE_SRPC_METHOD_4(activateAccount, kudo::RNickname, nickname, srpc::RUInt16, player_type, kudo::RCharStyleId, play_style, kudo::RUnkVect1, unk_vect_u32);
	DECLARE_SRPC_METHOD_3(onCharacterTemplates, kudo::RCharacterTemplates, templates, kudo::RCharacterStyles, styles, kudo::RRawWearItems, items);
	DECLARE_SRPC_METHOD_2(onActivateAccount, kudo::RErrorCode, error_code, kudo::RFullUserInfo, user_info);

	// User service
	DECLARE_SRPC_METHOD_0(requestFullUserInfo);
	DECLARE_SRPC_METHOD_1(onFullUserInfo, kudo::RFullUserInfo, user_info);

	// Game-mode service
	DECLARE_SRPC_METHOD_1(enterGameMode, kudo::RGameMode, game_mode_id);
	DECLARE_SRPC_METHOD_0(leaveGameMode);
	DECLARE_SRPC_METHOD_2(onEnterGameMode, kudo::RErrorCode, error_code, kudo::RGameMode, game_mode_id);
	DECLARE_SRPC_METHOD_1(onLeaveGameMode, kudo::RErrorCode, error_code);

	// Game service
	DECLARE_SRPC_METHOD_3(openGameRoomDoor, kudo::RRoomTitle, title, kudo::RGameType, game_type, kudo::RRoomPass, pass);
	DECLARE_SRPC_METHOD_3(requestGameRoomList, kudo::RGameRoomType, game_room_type, srpc::RUInt16, uint2, srpc::RUInt8, limit);
	DECLARE_SRPC_METHOD_2(enterGameRoom, srpc::RUInt16, uint1, kudo::RRoomPass, str2);
	DECLARE_SRPC_METHOD_0(leaveGameRoom);
	DECLARE_SRPC_METHOD_1(requestQuickJoinableRoomId, kudo::RGameType, game_type);
	DECLARE_SRPC_METHOD_0(requestGameRoomPlayerList);
	DECLARE_SRPC_METHOD_1(chat, kudo::RChatMessage, message);
	DECLARE_SRPC_METHOD_1(selectGameRoomSlot, kudo::RGameRoomSlot, game_room_slot);
	DECLARE_SRPC_METHOD_0(toggleReadyFlag);
	DECLARE_SRPC_METHOD_1(setGameRules, kudo::RGameRules, game_rules);
	DECLARE_SRPC_METHOD_1(kick, srpc::RUInt32, player_id);
	DECLARE_SRPC_METHOD_1(startGame, kudo::RAddressPairs, addresses);
	DECLARE_SRPC_METHOD_0(playGame);
	DECLARE_SRPC_METHOD_1(stopGame, kudo::RGameResult, game_result);
	DECLARE_SRPC_METHOD_1(cancelGame, kudo::RGameCancelReason, cancel_reason);
	DECLARE_SRPC_METHOD_0(inviteWaiter);
	DECLARE_SRPC_METHOD_2(onOpenGameRoomDoor, kudo::RErrorCode, error_code, srpc::RUInt16, room_number);
	DECLARE_SRPC_METHOD_2(onGameRoomList, kudo::RSimpleGameRoomInfos, rooms_info, srpc::RUInt16, rooms_count);
	DECLARE_SRPC_METHOD_3(onEnterGameRoom, kudo::RErrorCode, error_code, srpc::RUInt16, room_number, kudo::RGameRoomSlot, room_slot);
	DECLARE_SRPC_METHOD_2(onLeaveGameRoom, kudo::RErrorCode, error_code, srpc::RUInt16, room_number);
	DECLARE_SRPC_METHOD_1(onQuickJoinableRoomId, srpc::RUInt16, room_number);
	DECLARE_SRPC_METHOD_3(onGameRoomPlayerList, srpc::RUInt16, room_number, srpc::RUInt32, master_uid, kudo::RPlayersInfo, players_info);
	DECLARE_SRPC_METHOD_3(onSelectGameRoomSlot, kudo::RErrorCode, error_code, srpc::RUInt16, room_number, kudo::RGameRoomSlot, room_slot);
	DECLARE_SRPC_METHOD_2(onToggleReadyFlag, srpc::RUInt16, room_number, srpc::RBool, ready_flag);
	DECLARE_SRPC_METHOD_2(onSetGameRules, srpc::RUInt16, room_number, kudo::RErrorCode, error_code);
	DECLARE_SRPC_METHOD_2(onStartGame, srpc::RUInt16, room_number, kudo::RErrorCode, error_code);
	DECLARE_SRPC_METHOD_2(onPlayGame, srpc::RUInt16, room_number, kudo::RErrorCode, error_code);
	DECLARE_SRPC_METHOD_2(onStopGame, srpc::RUInt16, room_number, kudo::RErrorCode, error_code);
	DECLARE_SRPC_METHOD_2(onCancelGame, srpc::RUInt16, room_number, kudo::RErrorCode, error_code);

	// Game service event
	DECLARE_SRPC_METHOD_2(onGameRoomInfo, srpc::RUInt16, room_number, kudo::RFullGameRoomInfo, room_info);
	DECLARE_SRPC_METHOD_2(onGameRoomUserEntered, srpc::RUInt16, room_number, kudo::RPlayerInfo, player_info);
	DECLARE_SRPC_METHOD_2(onGameRoomUserLeft, srpc::RUInt16, room_number, srpc::RUInt32, player_uid);
	DECLARE_SRPC_METHOD_2(onChat, srpc::RUInt32, player_uid, kudo::RChatMessage, message);
	DECLARE_SRPC_METHOD_3(onMasterChanged, srpc::RUInt16, room_number, srpc::RUInt32, player_uid, srpc::RBool, unk_bool);
	DECLARE_SRPC_METHOD_3(onGameRoomSlotSelected, srpc::RUInt16, room_number, srpc::RUInt32, player_uid, kudo::RGameRoomSlot, room_slot);
	DECLARE_SRPC_METHOD_3(onGameRoomReadyFlagToggled, srpc::RUInt16, room_number, srpc::RUInt32, player_uid, srpc::RBool, ready_flag);
	DECLARE_SRPC_METHOD_2(onGameRulesChanged, srpc::RUInt16, room_number, kudo::RGameRules, game_rules);
	DECLARE_SRPC_METHOD_2(onKicked, srpc::RUInt16, room_number, srpc::RUInt32, player_uid);
	DECLARE_SRPC_METHOD_2(onGameSlotsArranged, srpc::RUInt16, room_number, kudo::RDetailedSlotInfos, slots_info);
	DECLARE_SRPC_METHOD_3(onGameStarted, srpc::RUInt16, room_number, kudo::RAddressPairs, start_addresses, kudo::RBaseCharacters, characters);
	DECLARE_SRPC_METHOD_1(onGamePlayed, srpc::RUInt16, room_number);
	DECLARE_SRPC_METHOD_2(onGameStopped, srpc::RUInt16, room_number, kudo::RDetailedGameResult, game_result);
	DECLARE_SRPC_METHOD_2(onGameCanceled, srpc::RUInt16, room_number, kudo::RGameCancelReason, reason);
	DECLARE_SRPC_METHOD_2(onInvited, srpc::RUInt16, room_number, kudo::RRoomPass, str2);
	DECLARE_SRPC_METHOD_3(onWargerGameRulesChanged, srpc::RUInt16, room_number, kudo::RWagerRules, game_rules, kudo::RWagerReason, reason);

	// Item service
	DECLARE_SRPC_METHOD_0(requestItems);
	DECLARE_SRPC_METHOD_3(buyItem, srpc::RUInt32, uint1, kudo::RPayWay, pay_way, kudo::RBuyMethod, buy_method);
	DECLARE_SRPC_METHOD_4(buyCharacter, srpc::RUInt16, uint1, kudo::RCharStyleId, char_style, kudo::RUnkVect1, vect3, kudo::RPayWay, pay_way);
	DECLARE_SRPC_METHOD_2(sellItem, srpc::RUInt32, uint1, kudo::RItemType, item_type);
	DECLARE_SRPC_METHOD_2(destroyItem, srpc::RUInt32, uint1, kudo::RItemType, item_type);
	DECLARE_SRPC_METHOD_2(restoreItem, srpc::RUInt32, uint1, kudo::RItemType, item_type);
	DECLARE_SRPC_METHOD_2(adornCharacter, srpc::RUInt32, uint1, kudo::RUnkVect1, vect2);
	DECLARE_SRPC_METHOD_5(onItems, kudo::RUnkVect1, vect1, kudo::RUnkVect1, vect2, kudo::RUnkVect1, vect3, kudo::RUnkVect1, vect4, kudo::RUnkVect2, vect5);
	DECLARE_SRPC_METHOD_6(onBuyItem, kudo::RErrorCode, error_code, srpc::RUInt32, uint2, srpc::RUInt32, uint3, srpc::RUInt16, uint4, srpc::RInt32, sint5, kudo::RPrice, price);
	DECLARE_SRPC_METHOD_3(onBuyCharacter, kudo::RErrorCode, error_code, kudo::RFullCharacter, character_info, kudo::RPrice, price);
	DECLARE_SRPC_METHOD_4(onSellItem, kudo::RErrorCode, error_code, srpc::RUInt32, uint2, kudo::RItemType, item_type, srpc::RInt32, sint4);
	DECLARE_SRPC_METHOD_3(onDestroyItem, kudo::RErrorCode, error_code, srpc::RUInt32, uint2, kudo::RItemType, item_type);
	DECLARE_SRPC_METHOD_3(onRestoreItem, kudo::RErrorCode, error_code, srpc::RUInt32, uint2, kudo::RItemType, item_type);
	DECLARE_SRPC_METHOD_4(onAdornCharacter, kudo::RErrorCode, error_code, srpc::RUInt32, uint2, kudo::RCharacter::RItems, char_items, kudo::RWearItems, wear_items);

	// Item service event
	DECLARE_SRPC_METHOD_4(onCharacterAdorned, srpc::RUInt16, uint1, srpc::RUInt32, uint2, srpc::RUInt32, uint3, kudo::RUnkVect1, vect4);
	DECLARE_SRPC_METHOD_4(onItemVanished, srpc::RUInt16, uint1, srpc::RUInt32, uint2, srpc::RUInt32, uint3, kudo::RUnkVect1, vect4);
	DECLARE_SRPC_METHOD_3(onMapItemVanished, srpc::RUInt16, uint1, srpc::RUInt32, uint2, kudo::RUnkVect1, vect4);

private:
	friend class GameServerRoom;
	friend class GameServerInstance;

	// character information
	struct Character
	{
		uint16_t person;
		uint16_t status[6];
		bool visible;
		uint32_t id;
		uint32_t type;
		uint32_t exp;
		uint32_t minor_grade;
	};

	// common
	MessengerServerSession m_messenger;
	class GameServerInstance* m_owner;

	// user
	uint32_t m_user_uid; // 0 means unauthorized
	srpc::WString m_user_nickname;
	std::map<uint32_t, Character> m_characters;
	std::mutex m_info_lock;

	// player
	kudo::GameMode m_game_mode;
	class GameServerRoom* m_room;
	uint8_t m_room_slot;
	bool m_ready_flag;
	std::mutex m_state_lock;
};

//=========================================================================================================================================

// Game server instance (server-side)
class GameServerInstance :
	public nsrpc::SessionDestroyer,
	public nsrpc::SessionCreator,
	public nsrpc::SessionAcceptor
{
public:
	// Constructor
	GameServerInstance(ACE_Proactor* proactor, ACE_Reactor* reactor, kat::KatPacketCoderFactory* packet_coder_factory);

	// Destructor
	virtual ~GameServerInstance() override;

	// Finds free user identifier
	uint32_t findFreeUserId(const GameServerSession* current = nullptr);

	// Finds free number for a new room
	uint16_t findFreeRoomNumber();

	// Acquires new game-server session
	virtual nsrpc::Session* acquire() override;

	// Releases game-server session
	virtual void release(nsrpc::Session* session) override;

private:
	friend class GameServerRoom;
	friend class GameServerSession;

	// data
	ACE_Proactor* m_proactor;
	ACE_Reactor* m_reactor;
	kat::KatPacketCoderFactory* m_packet_coder_factory;
	std::mutex m_rooms_lock;
	std::map<uint16_t, GameServerRoom*> m_rooms;
	std::mutex m_sessions_lock;
	std::list<GameServerSession*> m_sessions;
};

//=========================================================================================================================================