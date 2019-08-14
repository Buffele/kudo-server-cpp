#include "GameServer.hpp"
#include "Common.hpp"

//=========================================================================================================================================

MessengerServerSession::MessengerServerSession(class GameServerSession* parent, srpc::RpcNetwork* network) :
	m_parent(parent)
{
	srpc::RpcReceiver::setRpcNetwork(network);
	srpc::RpcForwarder::setRpcNetwork(network);
}

MessengerServerSession::~MessengerServerSession()
{
}

DEFINE_GET_SRPC_EVENT_MAP(MessengerServerSession);

void MessengerServerSession::dispatch(srpc::RpcEvent& event, srpc::IStream& istream, const void* rpcHint)
{
	//LogLine(Logf_Normal, "[Messenger] Dispatch event %p\n", &event);
	event.dispatch(this, istream, rpcHint);
}

IMPLEMENT_SRPC_METHOD_1(MessengerServerSession, subscribeBuddy, kudo::RNickname, nickname)
{
}
IMPLEMENT_SRPC_METHOD_1(MessengerServerSession, unsubscribeBuddy, srpc::RUInt32, uint1)
{
}
IMPLEMENT_SRPC_METHOD_1(MessengerServerSession, blockBuddy, srpc::RUInt32, uint1)
{
}
IMPLEMENT_SRPC_METHOD_1(MessengerServerSession, unblockBuddy, srpc::RUInt32, uint1)
{
}
IMPLEMENT_SRPC_METHOD_1(MessengerServerSession, addBuddyGroup, kudo::RNickname, nickname)
{
}
IMPLEMENT_SRPC_METHOD_1(MessengerServerSession, removeBuddyGroup, srpc::RUInt32, uint1)
{
}
IMPLEMENT_SRPC_METHOD_2(MessengerServerSession, changeBuddyGroupName, srpc::RUInt32, uint1, kudo::RNickname, name)
{
}
IMPLEMENT_SRPC_METHOD_2(MessengerServerSession, classifyBuddy, srpc::RUInt32, uint1, srpc::RUInt32, uint2)
{
}
IMPLEMENT_SRPC_METHOD_1(MessengerServerSession, getBuddyInfo, srpc::RUInt32, uint1)
{
}
IMPLEMENT_SRPC_METHOD_1(MessengerServerSession, inviteBuddy, srpc::RUInt32, uint1)
{
}
DEFINE_SRPC_METHOD_2(MessengerServerSession, onSubscribeBuddy, kudo::RErrorCode, error_code, kudo::RBuddy, buddy);
DEFINE_SRPC_METHOD_2(MessengerServerSession, onUnsubscribeBuddy, kudo::RErrorCode, error_code, srpc::RUInt32, uint2);
DEFINE_SRPC_METHOD_2(MessengerServerSession, onBlockBuddy, kudo::RErrorCode, error_code, srpc::RUInt32, uint2);
DEFINE_SRPC_METHOD_2(MessengerServerSession, onUnblockBuddy, kudo::RErrorCode, error_code, srpc::RUInt32, uint2);
DEFINE_SRPC_METHOD_2(MessengerServerSession, onAddBuddyGroup, kudo::RErrorCode, error_code, kudo::RBuddyGroup, group);
DEFINE_SRPC_METHOD_2(MessengerServerSession, onRemoveBuddyGroup, kudo::RErrorCode, error_code, srpc::RUInt32, uint2);
DEFINE_SRPC_METHOD_2(MessengerServerSession, onChangeBuddyGroupName, kudo::RErrorCode, error_code, kudo::RBuddyGroup, group);
DEFINE_SRPC_METHOD_3(MessengerServerSession, onClassifyBuddy, kudo::RErrorCode, error_code, srpc::RUInt32, uint2, srpc::RUInt32, uint3);
DEFINE_SRPC_METHOD_3(MessengerServerSession, onGetBuddyInfo, kudo::RErrorCode, error_code, srpc::RUInt32, uint2, kudo::RFullCharacter, info);

DEFINE_SRPC_METHOD_2(MessengerServerSession, onBuddyRoster, kudo::RBuddyGroups, groups, kudo::RBuddies, buddies);
DEFINE_SRPC_METHOD_2(MessengerServerSession, onBuddySubscribed, kudo::RNickname, nickname, kudo::RPlace, place);
DEFINE_SRPC_METHOD_2(MessengerServerSession, onBuddyCurrentPlaceChanged, srpc::RUInt32, uint1, kudo::RPlace, place);
DEFINE_SRPC_METHOD_3(MessengerServerSession, onBuddyInvited, srpc::RUInt32, uint1, kudo::RPlace, place, kudo::RRoomPass, string3);

IMPLEMENT_SRPC_METHOD_2(MessengerServerSession, call, kudo::RChatVec1, vec1, srpc::RUInt16, uint2)
{
}
IMPLEMENT_SRPC_METHOD_2(MessengerServerSession, say, srpc::RUInt16, uint1, kudo::RChatMessage, message)
{
}
IMPLEMENT_SRPC_METHOD_1(MessengerServerSession, bye, srpc::RUInt16, uint1)
{
}
DEFINE_SRPC_METHOD_3(MessengerServerSession, onCall, kudo::RErrorCode, error_code, kudo::RChatVec1, vec1, srpc::RUInt16, uint2);

DEFINE_SRPC_METHOD_2(MessengerServerSession, onCalled, srpc::RUInt16, uint1, kudo::RBaseUserInfos, users);
DEFINE_SRPC_METHOD_2(MessengerServerSession, onJoined, srpc::RUInt16, uint1, kudo::RBaseUserInfos, users);
DEFINE_SRPC_METHOD_3(MessengerServerSession, onSaid, srpc::RUInt16, uint1, srpc::RUInt32, uint2, kudo::RChatMessage, message);
DEFINE_SRPC_METHOD_2(MessengerServerSession, onBye, srpc::RUInt16, uint1, srpc::RUInt32, uint2);

IMPLEMENT_SRPC_METHOD_3(MessengerServerSession, openChannelRoomDoor, kudo::RRoomTitle, str1, kudo::RRoomPass, str2, kudo::RChatUint1, uint3)
{
}
IMPLEMENT_SRPC_METHOD_2(MessengerServerSession, enterChannelRoom, srpc::RUInt16, uint1, kudo::RRoomPass, str2)
{
}
IMPLEMENT_SRPC_METHOD_1(MessengerServerSession, leaveChannelRoom, srpc::RUInt16, uint1)
{
}
IMPLEMENT_SRPC_METHOD_3(MessengerServerSession, channelChat, srpc::RUInt16, uint1, srpc::RUInt32, uint2, kudo::RChatMessage, message)
{
}
IMPLEMENT_SRPC_METHOD_2(MessengerServerSession, requestChannelRoomList, srpc::RUInt16, uint1, srpc::RUInt8, uint2)
{
	//LogLine(Logf_Normal, "[Messenger] requestChannelRoomList\n");
	kudo::RChannelRoomInfos room_list;
	onRequestChannelRoomList(room_list, 0);
}
IMPLEMENT_SRPC_METHOD_3(MessengerServerSession, searchChannelRoomList, kudo::RRoomTitle, str1, srpc::RUInt16, uint2, srpc::RUInt8, uint3)
{
}
IMPLEMENT_SRPC_METHOD_2(MessengerServerSession, kickChannelUser, srpc::RUInt16, uint1, srpc::RUInt32, uint2)
{
}
IMPLEMENT_SRPC_METHOD_2(MessengerServerSession, inviteBuddyToChannel, srpc::RUInt16, uint1, srpc::RUInt32, uint2)
{
}
IMPLEMENT_SRPC_METHOD_4(MessengerServerSession, modifyChannelRoom, srpc::RUInt16, uint1, kudo::RRoomTitle, str2, kudo::RRoomPass, str3, kudo::RChatUint1, uint4)
{
}
DEFINE_SRPC_METHOD_2(MessengerServerSession, onOpenChannelRoomDoor, kudo::RErrorCode, error_code, kudo::RFullChannelRoomInfo, room_info);
DEFINE_SRPC_METHOD_2(MessengerServerSession, onEnterChannelRoom, kudo::RErrorCode, error_code, kudo::RFullChannelRoomInfo, room_info);
DEFINE_SRPC_METHOD_2(MessengerServerSession, onLeaveChannelRoom, kudo::RErrorCode, error_code, srpc::RUInt16, uint2);
DEFINE_SRPC_METHOD_2(MessengerServerSession, onRequestChannelRoomList, kudo::RChannelRoomInfos, rooms_list, srpc::RUInt16, uint2);
DEFINE_SRPC_METHOD_1(MessengerServerSession, onSearchChannelRoomList, kudo::RChannelRoomInfo, room_info);
DEFINE_SRPC_METHOD_3(MessengerServerSession, onKickChannelUser, kudo::RErrorCode, error_code, srpc::RUInt16, uint2, srpc::RUInt32, uint3);
DEFINE_SRPC_METHOD_1(MessengerServerSession, onInviteBuddyToChannel, kudo::RErrorCode, error_code);
DEFINE_SRPC_METHOD_6(MessengerServerSession, onModifyChannelRoom, kudo::RErrorCode, error_code, srpc::RUInt16, uint2, kudo::RRoomTitle, str3, kudo::RRoomPass, str4, kudo::RChatUint1, uint5, srpc::RBool, bool5);

DEFINE_SRPC_METHOD_2(MessengerServerSession, onChannelUserEntered, srpc::RUInt16, uint1, kudo::RChannelUserInfo, user_info);
DEFINE_SRPC_METHOD_2(MessengerServerSession, onChannelRoomLeft, srpc::RUInt16, uint1, srpc::RUInt32, uint2);
DEFINE_SRPC_METHOD_2(MessengerServerSession, onChannelRoomMasterChanged, srpc::RUInt16, uint1, srpc::RUInt32, uint2);
DEFINE_SRPC_METHOD_3(MessengerServerSession, onChannelChat, srpc::RUInt16, uint1, srpc::RUInt32, uint2, kudo::RChatMessage, message);
DEFINE_SRPC_METHOD_2(MessengerServerSession, onChannelUserKicked, srpc::RUInt16, uint1, srpc::RUInt32, uint2);
DEFINE_SRPC_METHOD_3(MessengerServerSession, onChannelUserStateChanged, srpc::RUInt16, uint1, srpc::RUInt32, uint2, srpc::RBool, bool3);
DEFINE_SRPC_METHOD_3(MessengerServerSession, onChannelInvited, srpc::RUInt16, uint1, srpc::RUInt32, uint2, kudo::RRoomPass, str3);
DEFINE_SRPC_METHOD_4(MessengerServerSession, onChannelRoomModified, srpc::RUInt16, uint1, kudo::RRoomTitle, str2, kudo::RChatUint1, uint3, srpc::RBool, bool4);

IMPLEMENT_SRPC_METHOD_0(MessengerServerSession, requestMails)
{
}
IMPLEMENT_SRPC_METHOD_2(MessengerServerSession, sendMail, kudo::RNickname, nickname, kudo::RMailText, text)
{
}
IMPLEMENT_SRPC_METHOD_4(MessengerServerSession, sendPresentMail, kudo::RNickname, nickname, srpc::RUInt32, uint2, kudo::RPayWay, pay_way, kudo::RBuyMethod, buy_method)
{
}
IMPLEMENT_SRPC_METHOD_2(MessengerServerSession, receivePresentItem, srpc::RUInt32, uint1, kudo::RMailType, mail_type)
{
}
IMPLEMENT_SRPC_METHOD_2(MessengerServerSession, readMail, srpc::RUInt32, uint1, kudo::RMailType, mail_type)
{
}
IMPLEMENT_SRPC_METHOD_2(MessengerServerSession, deleteMail, srpc::RUInt32, uint1, kudo::RMailType, mail_type)
{
}
IMPLEMENT_SRPC_METHOD_1(MessengerServerSession, sendBackMail, srpc::RUInt32, uint1)
{
}
DEFINE_SRPC_METHOD_2(MessengerServerSession, onMailList, kudo::RMailInfos, mails1, kudo::RMailInfos, mails2);
DEFINE_SRPC_METHOD_3(MessengerServerSession, onSendMail, kudo::RErrorCode, error_code, kudo::RPrice, price, kudo::RMailInfo, info);
DEFINE_SRPC_METHOD_7(MessengerServerSession, onReceivePresentItem, kudo::RErrorCode, error_code, srpc::RUInt32, uint2, kudo::RMailType, mail_type, srpc::RUInt32, uint4, srpc::RUInt32, uint5, srpc::RUInt16, uint6, srpc::RInt32, sint7);
DEFINE_SRPC_METHOD_5(MessengerServerSession, onReadMail, kudo::RErrorCode, error_code, srpc::RUInt32, uint2, kudo::RMailType, type, kudo::RMailText, text, srpc::RUInt32, uint5);
DEFINE_SRPC_METHOD_3(MessengerServerSession, onDeleteMail, kudo::RErrorCode, error_code, srpc::RUInt32, uint2, kudo::RMailType, type);
DEFINE_SRPC_METHOD_2(MessengerServerSession, onSendBackMail, kudo::RErrorCode, error_code, srpc::RUInt32, uint2);

DEFINE_SRPC_METHOD_2(MessengerServerSession, onMailReceived, kudo::RMailType, type, kudo::RMailInfo, info);
DEFINE_SRPC_METHOD_2(MessengerServerSession, onSentMailStateChanged, srpc::RUInt32, uint1, kudo::RMailState, state);
DEFINE_SRPC_METHOD_1(MessengerServerSession, onPresentItemReceived, srpc::RUInt32, uint1);

//=========================================================================================================================================

bool validateRoomTitle(const srpc::WString& room_title)
{
	for (auto ch : room_title)
	{
		if (ch < ' ' || ch > '~')
			return false;
	}
	return true;
}

bool validateRoomPassword(const srpc::String& room_pass)
{
	for (auto ch : room_pass)
	{
		if (ch < ' ' || ch > '~')
			return false;
	}
	return true;
}

bool validateChatMessage(const srpc::WString& chat_msg)
{
	// TODO: check for injections, ac signatures, etc.
	return !chat_msg.empty() && chat_msg.length() < 192;
}

//=========================================================================================================================================

GameServerRoomRelay::GameServerRoomRelay(GameServerRoom* owner, ACE_Reactor* reactor, nsrpc::PacketCoder* packet_coder, bool use_bit_packing) :
	m_owner(owner),
	m_reactor(reactor),
	m_packet_coder(packet_coder),
	m_recv_block(new ACE_Message_Block(m_packet_coder->getDefaultPacketSize())),
	m_send_block(new ACE_Message_Block(m_packet_coder->getDefaultPacketSize())),
	m_rpc_network(*this, *m_recv_block, *m_send_block, use_bit_packing),
	m_endpoint(*this, *m_recv_block, m_reactor),
	m_outgoing_unreliable_sequence_number(nsrpc::invalidSequenceNumber),
	m_peer_cipher_keys(*m_packet_coder),
	m_port(0),
	m_key(0)
{
	srpc::RpcReceiver::setRpcNetwork(&m_rpc_network);
	srpc::RpcForwarder::setRpcNetwork(&m_rpc_network);
}

GameServerRoomRelay::~GameServerRoomRelay()
{
	stop();
	m_recv_block->release();
	m_send_block->release();
	if (m_packet_coder)
		delete m_packet_coder;
}

bool GameServerRoomRelay::start(uint16_t port, uint32_t key)
{
	if (!m_endpoint.open(port))
		return false;

	if (key != 0)
	{
		srpc::String cipher_key = Format("%u", key);
		m_peer_cipher_keys.set(nsrpc::relayServerPeerId, cipher_key);
	}

	m_packet_coder->setDecryptSeed(m_peer_cipher_keys.get(nsrpc::relayServerPeerId));

	m_port = port;
	m_key = key;

	LogLine(Logf_Normal, "[Relay] <Room%u> Started %u (%u)\n", m_owner->m_number, port, key);

	return true;
}

void GameServerRoomRelay::stop()
{
	if (m_port)
	{
		LogLine(Logf_Normal, "[Relay] <Room%u> Stopped %u (%u)\n", m_owner->m_number, m_port, m_key);
		m_port = 0;
	}
	m_endpoint.close();
}

void GameServerRoomRelay::onMessageArrived(const ACE_INET_Addr& peerAddress)
{
	/*if (LogBegin(Logf_Normal))
	{
		srpc::String str_bytes;
		for (char* i = m_recv_block->base(); i != m_recv_block->wr_ptr(); i++)
			str_bytes.append(Format(" %02x", (uint8_t)*i));
		LogLine(Logf_Normal | Logf_Nolock, "[Relay] <Room%u> onMessageArrived: %s:%u [%s ]\n", m_owner->m_number,
			peerAddress.get_host_addr(), peerAddress.get_port_number(), str_bytes.c_str());
		LogEnd(Logf_Normal);
	}*/

	nsrpc::P2pPacketHeader header;
	if (!m_packet_coder->readHeader(header, *m_recv_block))
	{
		LogLine(Logf_Normal, "[Relay] <Room%u> onMessageArrived: %s:%u - invalid header\n", m_owner->m_number,
			peerAddress.get_host_addr(), peerAddress.get_port_number());
		return;
	}

	if (!m_packet_coder->isValidHeader(header, *m_recv_block))
	{
		LogLine(Logf_Normal, "[Relay] <Room%u> onMessageArrived: %s:%u - body too short\n", m_owner->m_number,
			peerAddress.get_host_addr(), peerAddress.get_port_number());
		return;
	}

	if (isReliable(header.packetType_))
	{
		LogLine(Logf_Normal, "[Relay] <Room%u> onMessageArrived: %s:%u - is reliable\n", m_owner->m_number,
			peerAddress.get_host_addr(), peerAddress.get_port_number());
		return;
	}

	if (!m_packet_coder->decode(*m_recv_block))
		return;

	m_packet_coder->advanceToBody(*m_recv_block);

	if (!m_rpc_network.handleMessage(header.peerId_, peerAddress))
	{
		LogLine(Logf_Normal, "[Relay] <Room%u> onMessageArrived: %s:%u - handle error\n", m_owner->m_number,
			peerAddress.get_host_addr(), peerAddress.get_port_number());
		return;
	}
}

bool GameServerRoomRelay::sendNow(const nsrpc::PeerIdPair& peerIdPair, const nsrpc::detail::AddressPair& addressPair,
	const ACE_Message_Block& mblock, srpc::RpcPacketType packetType, nsrpc::SequenceNumber sequenceNumber, srpc::UInt32 sentTime)
{
	return true;
}

void GameServerRoomRelay::marshalingErrorOccurred()
{
	LogLine(Logf_Normal, "[Relay] <Room%u> Marshalling error\n", m_owner->m_number);
	m_endpoint.close();
}

void GameServerRoomRelay::sendOutgoingMessage(srpc::RpcPacketType packetType, ACE_Message_Block* mblock, const nsrpc::detail::P2pPeerHint* peerHint)
{
	if (!peerHint)
		return;

	nsrpc::P2pPacketHeader header(packetType, nsrpc::relayServerPeerId, ++m_outgoing_unreliable_sequence_number, 0);
	m_packet_coder->setEncryptSeed(m_peer_cipher_keys.get(peerHint->peerId_));
	if (m_packet_coder->encode(*mblock, header))
		m_endpoint.send(peerHint->getAddress(), *mblock);
	else
		LogLine(Logf_Normal, "[Relay] <Room%u> Encoding fail\n", m_owner->m_number);
}

size_t GameServerRoomRelay::getHeaderSize() const
{
	return m_packet_coder->getHeaderSize();
}

IMPLEMENT_SRPC_EVENT_DISPATCHER(GameServerRoomRelay);

IMPLEMENT_SRPC_P2P_METHOD_0(GameServerRoomRelay, rpcResolve, srpc::ptUnreliable)
{
	if (!rpcHint)
	{
		LogLine(Logf_Normal, "[Relay] <Room%u> rpcResolve: no hint\n", m_owner->m_number);
		return;
	}
	const nsrpc::detail::P2pPeerHint& hint = *static_cast<const nsrpc::detail::P2pPeerHint*>(rpcHint);
	if (!hint.isValid())
	{
		LogLine(Logf_Normal, "[Relay] <Room%u> rpcResolve: invalid hint\n", m_owner->m_number);
		return;
	}

	ACE_INET_Addr peer_addr(hint.getAddress());

	LogLine(Logf_Normal, "[Relay] <Room%u> rpcResolve: Peer%u:%s:%u\n", m_owner->m_number,
		hint.peerId_, peer_addr.get_host_addr(), peer_addr.get_port_number());

	rpcResolved(peer_addr.get_host_addr(), peer_addr.get_port_number(), &hint);
}

DEFINE_SRPC_P2P_METHOD_2(GameServerRoomRelay, rpcResolved, srpc::RShortString, ipAddress, srpc::RUInt16, port, srpc::ptUnreliable);

IMPLEMENT_SRPC_P2P_METHOD_6(GameServerRoomRelay, rpcRelay, nsrpc::RPeerIdPair, peerIdPair, nsrpc::detail::RAddress, peerAddress,
	nsrpc::detail::RMessageBuffer, messageBlock, srpc::RRpcPacketType, packetType, nsrpc::RSequenceNumber, sequenceNumber,
	nsrpc::RRelativeTime, sentTime, srpc::ptUnreliable)
{
	if (!rpcHint)
	{
		LogLine(Logf_Normal, "[Relay] <Room%u> rpcRelay: no hint\n", m_owner->m_number);
		return;
	}
	const nsrpc::detail::P2pPeerHint& hint = *static_cast<const nsrpc::detail::P2pPeerHint*>(rpcHint);
	if (!hint.isValid())
	{
		LogLine(Logf_Normal, "[Relay] <Room%u> rpcRelay: invalid hint\n", m_owner->m_number);
		return;
	}

	if (LogBegin(Logf_Normal))
	{
		const ACE_INET_Addr from_addr(hint.getAddress());
		char from_ip[INET_ADDRSTRLEN];
		from_addr.get_host_addr(from_ip, INET_ADDRSTRLEN);
		char to_ip[INET_ADDRSTRLEN];
		peerAddress.get_host_addr(to_ip, INET_ADDRSTRLEN);
		LogLine(Logf_Normal | Logf_Nolock, "[Relay] <Room%u> rpcRelay: Peer%u:%s:%u -> Peer%u:%s:%u:%u\n", m_owner->m_number,
			peerIdPair.from_, from_ip, from_addr.get_port_number(),
			peerIdPair.to_, to_ip, peerAddress.get_port_number(),
			messageBlock.getBufferLength());
		LogEnd(Logf_Normal);
	}

	const nsrpc::detail::P2pPeerHint to_hint(peerIdPair.to_, &peerAddress);
	rpcRelayed(peerIdPair.from_, messageBlock, packetType, sequenceNumber, sentTime, &to_hint);
}

DEFINE_SRPC_P2P_METHOD_5(GameServerRoomRelay, rpcRelayed, nsrpc::RPeerId, peerId, nsrpc::detail::RMessageBuffer, messageBlock,
	srpc::RRpcPacketType, packetType, nsrpc::RSequenceNumber, sequenceNumber, nsrpc::RRelativeTime, sentTime, srpc::ptUnreliable);

//=========================================================================================================================================

GameServerRoom::GameServerRoom(class GameServerInstance* owner) :
	m_owner(owner)
{
	//m_title = L"";
	//m_password = "";
	m_number = 0;
	m_state = State_Unknown;
	m_relay = nullptr;
}

GameServerRoom::~GameServerRoom()
{
	if (m_relay)
		delete m_relay;
}

void GameServerRoom::buildRpcGameRules(kudo::RGameRules& game_rules)
{
	game_rules.match_mode = (m_game_type == kudo::GT_Singles) ? 0 : 1;
	game_rules.set_count = m_set_count;
	game_rules.game_count = m_game_count;
	game_rules.bool4 = false;
	game_rules.bool5 = false;
	game_rules.bool6 = false;
	game_rules.map_id = kudo::buildItemCode(0, kudo::IT_Map, 0, m_map_id);
	game_rules.sint8 = 0;
	game_rules.sint9 = 0;
}

void GameServerRoom::buildSimpleRpcInfo(kudo::RSimpleGameRoomInfo& info)
{
	info.title = m_title;
	info.grade_mode = m_grade_mode;
	info.locked = m_locked;
	info.bool5 = false;
	info.room_number = m_number;
	buildRpcGameRules(info.game_rules);

	for (size_t i = 0; i < _countof(GameServerRoom::m_players); i++)
	{
		GameServerSession* player = m_players[i];
		if (player)
		{
			kudo::RSimplePlayerInfo player_info;
			player_info.slot = player->m_room_slot;
			player_info.nickname = player->m_user_nickname;
			player_info.uint3 = 1; // unknown
			//player_info.vect4.push_back(1); // unknown
			//player_info.vect5.push_back(1); // unknown
			info.players.push_back(player_info);
		}
	}
}

void GameServerRoom::buildFullRpcInfo(kudo::RFullGameRoomInfo& info, bool show_password)
{
	info.title = m_title;
	info.grade_mode = m_grade_mode;
	info.locked = m_locked;
	info.bool5 = false;
	info.master_uid = m_players[m_master_slot] ? m_players[m_master_slot]->m_user_uid : 0;
	if (m_relay)
	{
		info.relay_addr = "127.0.0.1";
		info.relay_port = m_relay->m_port;
		info.relay_key = m_relay->m_key;
	}
	else
	{
		info.relay_addr = "";
		info.relay_port = 0;
		info.relay_key = 0;
	}
	info.pass = show_password ? m_password : "";
	buildRpcGameRules(info.game_rules);

	for (size_t i = 0; i < _countof(GameServerRoom::m_players); i++)
	{
		GameServerSession* player = m_players[i];
		if (player)
		{
			kudo::RPlayerInfo player_info;
			player->buildPlayerRpcInfo(player_info);
			info.players.push_back(player_info);
		}
	}
}

int8_t GameServerRoom::findFreeSlot()
{
	if (m_game_type == kudo::GT_Singles)
	{
		if (!m_players[0])
			return 0;
		if (!m_players[2])
			return 2;
	}
	else if (m_game_type == kudo::GT_Doubles)
	{
		for (int8_t i = 0; i < 4; i++)
			if (!m_players[i])
				return i;
	}
	return -1;
}

size_t GameServerRoom::calcPlayers()
{
	size_t player_count = 0;
	for (size_t i = 0; i < _countof(GameServerRoom::m_players); i++)
	{
		if (m_players[i])
			player_count++;
	}
	return player_count;
}

void GameServerRoom::delegateMaster(int8_t new_master_slot, size_t new_master_index, class GameServerSession* elimiated_user)
{
	if (new_master_slot == -1) // by index
	{
		for (size_t i = 0, j = 0; i < _countof(GameServerRoom::m_players); i++)
		{
			GameServerSession* player = m_players[i];
			if (player && player != elimiated_user)
			{
				if (new_master_index == j)
				{
					new_master_slot = (int8_t)i;
					break;
				}
				j++;
			}
		}
	}
	if (new_master_slot != -1)
	{
		GameServerSession* new_master = m_players[new_master_slot];
		LogLine(Logf_Normal, "[Game] <Room%u> User%u became master\n", m_number, new_master->m_user_uid);
		new_master->m_state_lock.lock();
		m_master_slot = new_master_slot;
		new_master->m_ready_flag = true;
		new_master->m_state_lock.unlock();
		for (size_t i = 0; i < _countof(GameServerRoom::m_players); i++)
		{
			GameServerSession* player = m_players[i];
			if (player && player != elimiated_user)
				player->onMasterChanged(m_number, new_master->m_user_uid, false);
		}
	}
}

size_t GameServerRoom::playerLeft(class GameServerSession* user)
{
	size_t player_count = calcPlayers();

	if (m_master_slot == user->m_room_slot && player_count > 1)
		delegateMaster(-1, (size_t)rand() % (player_count - 1), user);

	m_players[user->m_room_slot] = nullptr;
	user->m_room = nullptr;
	user->m_room_slot = 0;
	LogLine(Logf_Normal, "[Game] <Room%u> User%u left\n", m_number, user->m_user_uid);

	if (player_count > 1)
	{
		kudo::RFullGameRoomInfo room_info;
		buildFullRpcInfo(room_info, true);

		kudo::RDetailedGameResult game_result;
		if (m_state != GameServerRoom::State_Waiting)
		{
			game_result.winner = 0;
			game_result.uint4 = 0;
		}

		for (size_t i = 0; i < _countof(GameServerRoom::m_players); i++)
		{
			GameServerSession* player = m_players[i];
			if (player && player != user)
			{
				player->onGameRoomUserLeft(m_number, user->m_user_uid);
				if (m_state != GameServerRoom::State_Waiting)
				{
					player->onGameCanceled(m_number, (kudo::GameCancelReason)0);
					player->onGameStopped(m_number, game_result);
				}
			}
		}

		if (m_state != GameServerRoom::State_Waiting)
		{
			m_state = GameServerRoom::State_Waiting;
			LogLine(Logf_Normal, "[Game] <Room%u> Match stopped as incomplete\n", m_number);
		}
	}

	return player_count - 1;
}

//=========================================================================================================================================

GameServerSession::GameServerSession(class GameServerInstance* owner, nsrpc::RpcSessionConfig& config) :
	KatServerSession(config),
	m_messenger(this, config.rpcNetwork_),
	m_owner(owner)
{
	m_user_uid = 0;
	//m_user_nickname = L"";
	m_room = nullptr;
	m_game_mode = kudo::GM_Unknown;
}

GameServerSession::~GameServerSession()
{
}

void GameServerSession::buildFullUserRpcInfo(kudo::RFullUserInfo& info)
{
	info.uid = this->m_user_uid;
	info.nickname = this->m_user_nickname;
	info.str3 = L"";
	for (auto& cur_char : this->m_characters)
	{
		kudo::RFullCharacter char_info;
		char_info.person = cur_char.second.person;
		for (size_t k = 0; k < _countof(kudo::RFullCharacter::status); k++)
			char_info.status[k] = cur_char.second.status[k];
		char_info.bool3 = false;
		char_info.visible = cur_char.second.visible;
		char_info.id = cur_char.second.id;
		char_info.type = cur_char.second.type;
		char_info.exp = cur_char.second.exp;
		char_info.minor_grade = cur_char.second.minor_grade;
		// RCharacter::RItems items9
		// RUnkVect1 vect10
		// srpc::RMap<srpc::RpcIntType<srpc::Int32, 4>, RSubInfo2> map11
		char_info.uint12 = 0;
		char_info.uint13 = 0;
		info.characters.push_back(char_info);
	}
	info.sint5 = 0;
	info.sint6 = 0;
	// RWearItems wear_items
	// srpc::RVector<RUnk1Item> items8
	info.data9.uint1 = 0;
	info.data9.uint2 = 0;
	info.data9.uint3 = 0;
	info.data9.uint4 = 0;
	info.data9.uint5 = 0;
	info.data9.uint6 = 0;
	info.data9.uint7 = 0;
	info.data9.uint8 = 0;
	info.data9.uint9 = 0;
	info.data9.uint10 = 0;
	info.data9.uint11 = 0;
	info.data9.uint12 = 0;
	info.data9.uint13 = 0;
	info.data9.uint14 = 0;
}

void GameServerSession::buildPlayerRpcInfo(kudo::RPlayerInfo& info)
{
	info.uid = this->m_user_uid;
	info.nickname = this->m_user_nickname;
	for (auto& cur_char : this->m_characters)
	{
		kudo::RFullCharacter char_info;
		char_info.person = cur_char.second.person;
		for (size_t k = 0; k < _countof(kudo::RFullCharacter::status); k++)
			char_info.status[k] = cur_char.second.status[k];
		char_info.bool3 = false;
		char_info.visible = cur_char.second.visible;
		char_info.id = cur_char.second.id;
		char_info.type = cur_char.second.type;
		char_info.exp = cur_char.second.exp;
		char_info.minor_grade = cur_char.second.minor_grade;
		// RCharacter::RItems items9
		// RUnkVect1 vect10
		// srpc::RMap<srpc::RpcIntType<srpc::Int32, 4>, RSubInfo2> map11
		char_info.uint12 = 0;
		char_info.uint13 = 0;
		info.characters.push_back(char_info);
	}
	info.slot = this->m_room_slot;
	info.ready = this->m_ready_flag;
	info.sint6 = 0;
}

kudo::ErrorCode GameServerSession::getCurrentRoom(class GameServerRoom*& game_room)
{
	if (this->m_user_uid == 0)
		return kudo::EC_NotAuthenticated;
	if (this->m_game_mode == kudo::GM_Unknown)
		return kudo::EC_NotEnteredPlayableGameMode;
	if (!this->m_room)
		return kudo::EC_NotEntered;
	game_room = this->m_room;
	return kudo::EC_None;
}

void GameServerSession::open(ACE_HANDLE new_handle, ACE_Message_Block& message_block)
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

		LogLine(Logf_Normal, "[Game] Connected %s (%s)\n", str_remote_addr, str_private_addr);
	}
}

void GameServerSession::onDisconnected()
{
	char str_remote_addr[64];
	ACE_INET_Addr remote_addr = getRemoteAddress();
	remote_addr.addr_to_string(str_remote_addr, sizeof(str_remote_addr));

	char str_private_addr[64];
	ACE_INET_Addr private_addr = getPrivateAddress();
	private_addr.addr_to_string(str_private_addr, sizeof(str_remote_addr));

	LogLine(Logf_Normal, "[Game] Disconnected %s (%s)\n", str_remote_addr, str_private_addr);

	KatServerSession::onDisconnected();
}

DEFINE_GET_SRPC_EVENT_MAP(GameServerSession);

void GameServerSession::dispatch(srpc::RpcEvent& event, srpc::IStream& istream, const void* rpcHint)
{
	//LogLine(Logf_Normal,"[Game] <User%u> Dispatch %p\n", this->m_user_uid, &event);
	event.dispatch(this, istream, rpcHint);
}

IMPLEMENT_SRPC_METHOD_0(GameServerSession, heartbeat)
{
	//LogLine(Logf_Normal,"[Game] <User%u> heartbeat\n", this->m_user_uid);
}

IMPLEMENT_SRPC_METHOD_2(GameServerSession, login, kudo::RAccountLogin, login, kudo::RAccountPassword, password)
{
	LogLine(Logf_Normal, "[Game] <User%u> login: \"%S\" \"%S\"\n", this->m_user_uid, login.c_str(), password.c_str());

	this->m_info_lock.lock();
	this->m_state_lock.lock();

	kudo::RFullUserInfo user_info;

	if (!this->m_user_uid)
	{
		this->m_room = nullptr;
		this->m_game_mode = kudo::GM_Unknown;

		this->m_owner->m_sessions_lock.lock();
		this->m_user_uid = this->m_owner->findFreeUserId(this);
		this->m_owner->m_sessions_lock.unlock();
		this->m_user_nickname = Format(L"%s_%u", login.c_str(), m_user_uid);

		Character char_info;
		char_info.person = 2;
		char_info.visible = true;
		char_info.status[0] = 8000;
		char_info.status[1] = 8000;
		char_info.status[2] = 8000;
		char_info.status[3] = 8000;
		char_info.status[4] = 8000;
		char_info.status[5] = 2000;
		char_info.id = 1;
		char_info.type = 1;
		char_info.exp = 0;
		char_info.minor_grade = 5;
		this->m_characters[char_info.id] = char_info;

		this->buildFullUserRpcInfo(user_info);

		this->onLoginResult(kudo::EC_None, user_info);

		LogLine(Logf_Normal, "[Game] <User%u> Logged in\n", this->m_user_uid);
	}
	else
	{
		this->onLoginResult(kudo::EC_AlreadyLoggedIn, user_info);
	}

	this->m_info_lock.unlock();
	this->m_state_lock.unlock();
	
}
DEFINE_SRPC_METHOD_2(GameServerSession, onLoginResult, kudo::RErrorCode, error_code, kudo::RFullUserInfo, user_info);

IMPLEMENT_SRPC_METHOD_0(GameServerSession, requestCharacterTemplates)
{
	LogLine(Logf_Normal, "[Game] <User%u> requestCharacterTemplates\n", m_user_uid);

	kudo::RCharacterTemplates templates;
	kudo::RCharacterTemplate template1;
	template1.person = 2;
	template1.bool3 = true;
	template1.visible = true;
	template1.status[0] = 8000;
	template1.status[1] = 1000;
	template1.status[2] = 2000;
	template1.status[3] = 3000;
	template1.status[4] = 4000;
	template1.status[5] = 400;
	templates.push_back(template1);

	kudo::RCharacterStyles styles;
	kudo::RCharacterStyle style1;
	styles.push_back(style1);

	kudo::RRawWearItems items;
	kudo::RRawWearItem item1;
	items.push_back(item1);

	onCharacterTemplates(templates, styles, items);
}
IMPLEMENT_SRPC_METHOD_4(GameServerSession, activateAccount, kudo::RNickname, nickname, srpc::RUInt16, player_type, kudo::RCharStyleId, play_style, kudo::RUnkVect1, unk_vect_u32)
{
	LogLine(Logf_Normal, "[Game] <User%u> activateAccount: \"%S\" %u %u\n", m_user_uid, nickname.c_str(), player_type.get(), play_style.get());

	this->m_info_lock.lock();

	kudo::RFullUserInfo user_info;
	this->buildFullUserRpcInfo(user_info);

	if (m_user_uid != 0)
	{
		this->onActivateAccount(kudo::EC_None, user_info);
	}
	else
	{
		this->onActivateAccount(kudo::EC_NotAuthenticated, user_info);
	}

	this->m_info_lock.unlock();
}
DEFINE_SRPC_METHOD_3(GameServerSession, onCharacterTemplates, kudo::RCharacterTemplates, templates, kudo::RCharacterStyles, styles, kudo::RRawWearItems, items);
DEFINE_SRPC_METHOD_2(GameServerSession, onActivateAccount, kudo::RErrorCode, error_code, kudo::RFullUserInfo, user_info);

IMPLEMENT_SRPC_METHOD_0(GameServerSession, requestFullUserInfo)
{
	LogLine(Logf_Normal, "[Game] <User%u> requestFullUserInfo\n", this->m_user_uid);

	this->m_info_lock.lock();

	kudo::RFullUserInfo user_info;
	this->buildFullUserRpcInfo(user_info);
	this->onFullUserInfo(user_info);

	this->m_info_lock.unlock();
}
DEFINE_SRPC_METHOD_1(GameServerSession, onFullUserInfo, kudo::RFullUserInfo, user_info);

IMPLEMENT_SRPC_METHOD_1(GameServerSession, enterGameMode, kudo::RGameMode, game_mode)
{
	LogLine(Logf_Normal, "[Game] <User%u> enterGameMode: %u\n", this->m_user_uid, game_mode.get());

	this->m_state_lock.lock();

	if (this->m_game_mode == kudo::GM_Unknown)
	{
		if (game_mode == kudo::GM_FreeMatch)
		{
			this->m_game_mode = game_mode;
			this->onEnterGameMode(kudo::EC_None, game_mode);
		}
		else if (game_mode == kudo::GM_Starwars)
		{
			this->m_game_mode = game_mode;
			this->onEnterGameMode(kudo::EC_None, game_mode);
		}
		else
		{
			this->onEnterGameMode(kudo::EC_InvalidGameMode, game_mode);
		}
	}
	else
	{
		this->onEnterGameMode(kudo::EC_AlreadyEnteredGameMode, m_game_mode);
	}

	this->m_state_lock.unlock();
}
IMPLEMENT_SRPC_METHOD_0(GameServerSession, leaveGameMode)
{
	LogLine(Logf_Normal, "[Game] <User%u> leaveGameMode\n", this->m_user_uid);

	this->m_state_lock.lock();

	if (this->m_game_mode != kudo::GM_Unknown)
	{
		if (!this->m_room)
		{
			this->m_game_mode = kudo::GM_Unknown;
			this->onLeaveGameMode(kudo::EC_None);
		}
		else
		{
			this->onLeaveGameMode(kudo::EC_CannotLeaveGameModeInGameRoom);
		}
	}
	else
	{
		this->onLeaveGameMode(kudo::EC_NotEnteredGameMode);
	}

	this->m_state_lock.unlock();
}
DEFINE_SRPC_METHOD_2(GameServerSession, onEnterGameMode, kudo::RErrorCode, error_code, kudo::RGameMode, game_mode);
DEFINE_SRPC_METHOD_1(GameServerSession, onLeaveGameMode, kudo::RErrorCode, error_code);

IMPLEMENT_SRPC_METHOD_3(GameServerSession, openGameRoomDoor, kudo::RRoomTitle, title, kudo::RGameType, game_type, kudo::RRoomPass, pass)
{
	LogLine(Logf_Normal, "[Game] <User%u> openGameRoomDoor: \"%S\" %u \"%s\"\n", this->m_user_uid, title.c_str(), game_type.get(), pass.c_str());

	this->m_info_lock.lock();
	this->m_state_lock.lock();

	if (this->m_user_uid != 0)
	{
		if (this->m_game_mode != kudo::GM_Unknown)
		{
			if ((game_type == kudo::GT_Singles || game_type == kudo::GT_Doubles) &&
				validateRoomTitle(title) && validateRoomPassword(pass))
			{
				if (!this->m_room)
				{
					this->m_owner->m_rooms_lock.lock();

					uint32_t room_number = this->m_owner->findFreeRoomNumber();
					GameServerRoom* room = new GameServerRoom(m_owner);
					if (room)
					{
						GameServerRoomRelay* room_relay = new GameServerRoomRelay(room, room->m_owner->m_reactor,
							room->m_owner->m_packet_coder_factory->createForP2p(), true);
						if (room_relay)
						{
							uint32_t relay_port = 11130 + room_number;
							uint32_t relay_key = (uint32_t)rand() ^ (uint32_t)rand();
							if (room_relay->start(relay_port, relay_key))
							{
								room->m_total_lock.lock();

								room->m_number = room_number;
								room->m_title = title;
								room->m_password = pass;
								room->m_relay = room_relay;
								room->m_grade_mode = 1;
								room->m_locked = false;
								for (size_t i = 0; i < 4; i++)
									room->m_players[i] = nullptr;
								room->m_game_type = game_type;
								room->m_set_count = 1;
								room->m_game_count = 3;
								room->m_map_id = 1;
								room->m_state = GameServerRoom::State_Waiting;
								this->m_owner->m_rooms[room->m_number] = room;

								this->m_room_slot = 0;
								this->m_ready_flag = true;
								room->m_players[this->m_room_slot] = this;
								room->m_master_slot = this->m_room_slot;
								this->m_room = room;

								this->onOpenGameRoomDoor(kudo::EC_None, room->m_number);

								kudo::RFullGameRoomInfo room_info;
								room->buildFullRpcInfo(room_info, true);
								this->onGameRoomInfo(room->m_number, room_info);

								LogLine(Logf_Normal, "[Game] <Room%u> created\n", room->m_number);

								room->m_total_lock.unlock();
							}
							else
							{
								delete room_relay;
								delete room;
								this->onOpenGameRoomDoor(kudo::EC_RelayServiceFailed, 0);
							}
						}
						else
						{
							delete room;
							this->onOpenGameRoomDoor(kudo::EC_RelayServiceFailed, 0);
						}
					}
					else
					{
						this->onOpenGameRoomDoor(kudo::EC_OpenGameRoomDoorFailed, 0);
					}

					this->m_owner->m_rooms_lock.unlock();
				}
				else
				{
					this->onOpenGameRoomDoor(kudo::EC_AlreadyEntered, 0);
				}
			}
			else
			{
				this->onOpenGameRoomDoor(kudo::EC_Disconnected, 0);
			}
		}
		else
		{
			this->onOpenGameRoomDoor(kudo::EC_NotEnteredPlayableGameMode, 0);
		}
	}
	else
	{
		this->onOpenGameRoomDoor(kudo::EC_NotAuthenticated, 0);
	}

	this->m_info_lock.unlock();
	this->m_state_lock.unlock();
}
IMPLEMENT_SRPC_METHOD_3(GameServerSession, requestGameRoomList, kudo::RGameRoomType, game_room_type, srpc::RUInt16, uint2, srpc::RUInt8, limit)
{
	LogLine(Logf_Normal, "[Game] <User%u> requestGameRoomList: %u %u %u\n", this->m_user_uid, game_room_type.get(), uint2.get(), limit.get());

	this->m_owner->m_rooms_lock.lock();

	kudo::RSimpleGameRoomInfos room_list;

	size_t room_count = 0;
	for (auto& cur_room : this->m_owner->m_rooms)
	{
		if (room_count >= 256 && room_count >= limit)
			break;

		GameServerRoom* room = cur_room.second;

		room->m_total_lock.lock();

		kudo::RSimpleGameRoomInfo room_info;
		room->buildSimpleRpcInfo(room_info);

		room_list.push_back(room_info);

		room->m_total_lock.unlock();

		room_count++;
	}

	this->m_owner->m_rooms_lock.unlock();

	this->onGameRoomList(room_list, (srpc::UInt16)room_list.size());
}
IMPLEMENT_SRPC_METHOD_2(GameServerSession, enterGameRoom, srpc::RUInt16, room_number, kudo::RRoomPass, room_pass)
{
	LogLine(Logf_Normal, "[Game] <User%u> enterGameRoom: %u %s\n", this->m_user_uid, room_number.get(), room_pass.c_str());

	this->m_state_lock.lock();
	this->m_info_lock.lock();

	if (this->m_user_uid != 0)
	{
		if (this->m_game_mode != kudo::GM_Unknown)
		{
			if (!this->m_room)
			{
				this->m_owner->m_rooms_lock.lock();

				auto room_iter = this->m_owner->m_rooms.find(room_number);
				if (room_iter != this->m_owner->m_rooms.end())
				{
					GameServerRoom* room = room_iter->second;

					room->m_total_lock.lock();

					if (room->m_password.empty() || room->m_password.compare(room_pass) != 0)
					{
						if (room->m_state == GameServerRoom::State_Waiting)
						{
							int8_t room_slot = room->findFreeSlot();
							if (room_slot != -1)
							{
								this->m_room = room;
								this->m_room_slot = room_slot;
								this->m_ready_flag = false;
								room->m_players[room_slot] = this;

								kudo::RPlayerInfo player_info;
								this->buildPlayerRpcInfo(player_info);

								kudo::RFullGameRoomInfo room_info;
								room->buildFullRpcInfo(room_info, true);

								this->onEnterGameRoom(kudo::EC_None, room_number, room_slot);
								this->onGameRoomInfo(room_number, room_info);

								for (size_t i = 0; i < _countof(GameServerRoom::m_players); i++)
								{
									GameServerSession* player = room->m_players[i];
									if (player && player != this)
									{
										player->onGameRoomUserEntered(room_number, player_info);
										//player->onGameRoomSlotSelected(room_number, this->m_user_uid, room_slot); // need?
									}
								}

								//this->onMasterChanged(room_number, room->m_players[room->m_master_slot]->m_user_uid, false); // need?

								LogLine(Logf_Normal, "[Game] <Room%u> User%u entered\n", room->m_number, this->m_user_uid);
							}
							else
							{
								this->onEnterGameRoom(kudo::EC_TooManyPlayers, 0, 0);
							}
						}
					}
					else
					{
						this->onEnterGameRoom(kudo::EC_NoPermission, 0, 0);
					}

					room->m_total_lock.unlock();
				}
				else
				{
					this->onEnterGameRoom(kudo::EC_GameRoomNotExist, 0, 0);
				}

				this->m_owner->m_rooms_lock.unlock();
			}
			else
			{
				this->onEnterGameRoom(kudo::EC_CanEnterOnlyOneGameRoom, 0, 0);
			}
		}
		else
		{
			this->onEnterGameRoom(kudo::EC_NotEnteredPlayableGameMode, 0, 0);
		}
	}
	else
	{
		this->onEnterGameRoom(kudo::EC_NotAuthenticated, 0, 0);
	}

	this->m_state_lock.unlock();
	this->m_info_lock.unlock();
}
IMPLEMENT_SRPC_METHOD_0(GameServerSession, leaveGameRoom)
{
	LogLine(Logf_Normal, "[Game] <User%u> leaveGameRoom\n", this->m_user_uid);

	this->m_state_lock.lock();
	this->m_info_lock.lock();

	GameServerRoom* room = nullptr;
	kudo::ErrorCode error_code = getCurrentRoom(room);
	if (error_code == kudo::EC_None)
	{
		if ((this->m_room_slot == room->m_master_slot) || !this->m_ready_flag)
		{
			room->m_total_lock.lock();

			if (room->playerLeft(this) == 0)
			{
				this->m_owner->m_rooms_lock.lock();
				LogLine(Logf_Normal, "[Game] <Room%u> Destroyed as empty\n", room->m_number);
				room->m_total_lock.unlock();
				delete room;
				this->m_owner->m_rooms.erase(room->m_number);
				this->m_owner->m_rooms_lock.unlock();
			}
			else
			{
				room->m_total_lock.unlock();
			}

			this->onLeaveGameRoom(kudo::EC_None, room->m_number);
		}
		else
		{
			this->onLeaveGameRoom(kudo::EC_CannotLeaveGameRoomOnReady, 0);
		}
	}
	else
	{
		this->onLeaveGameRoom(error_code, 0);
	}

	this->m_state_lock.unlock();
	this->m_info_lock.unlock();
}
IMPLEMENT_SRPC_METHOD_1(GameServerSession, requestQuickJoinableRoomId, kudo::RGameType, game_type)
{
	LogLine(Logf_Normal, "[Game] <User%u> requestQuickJoinableRoomId: %u\n", this->m_user_uid, game_type.get());
}
IMPLEMENT_SRPC_METHOD_0(GameServerSession, requestGameRoomPlayerList)
{
	LogLine(Logf_Normal, "[Game] <User%u> requestGameRoomPlayerList\n", this->m_user_uid);

	kudo::RPlayersInfo players_info;

	GameServerRoom* room = nullptr;
	kudo::ErrorCode error_code = getCurrentRoom(room);
	if (error_code == kudo::EC_None)
	{
		room->m_total_lock.lock();

		uint32_t master_uid = 0;
		for (size_t i = 0; i < _countof(GameServerRoom::m_players); i++)
		{
			GameServerSession* player = room->m_players[i];
			if (player)
			{
				kudo::RPlayerInfo player_info;
				player->m_state_lock.lock();
				player->m_info_lock.lock();
				player->buildPlayerRpcInfo(player_info);
				if (room->m_master_slot == i)
					master_uid = player->m_user_uid;
				player->m_info_lock.unlock();
				player->m_state_lock.unlock();
				players_info.push_back(player_info);
			}
		}

		this->onGameRoomPlayerList(room->m_number, master_uid, players_info);

		room->m_total_lock.unlock();
	}
	else
	{
		this->onGameRoomPlayerList(0, 0, players_info);
	}
}
IMPLEMENT_SRPC_METHOD_1(GameServerSession, chat, kudo::RChatMessage, message)
{
	LogLine(Logf_Normal, "[Game] <User%u> chat: \"%S\"\n", this->m_user_uid, message.c_str());

	this->m_state_lock.lock();
	this->m_info_lock.lock();

	GameServerRoom* room = nullptr;
	kudo::ErrorCode error_code = getCurrentRoom(room);
	if (error_code == kudo::EC_None)
	{
		if (validateChatMessage(message))
		{
			room->m_total_lock.lock();

			for (size_t i = 0; i < _countof(GameServerRoom::m_players); i++)
			{
				GameServerSession* player = room->m_players[i];
				if (player)
					player->onChat(this->m_user_uid, message);
			}

			room->m_total_lock.unlock();
		}
	}

	this->m_state_lock.unlock();
	this->m_info_lock.unlock();
}
IMPLEMENT_SRPC_METHOD_1(GameServerSession, selectGameRoomSlot, kudo::RGameRoomSlot, game_room_slot)
{
	LogLine(Logf_Normal, "[Game] <User%u> selectGameRoomSlot: %u\n", this->m_user_uid, game_room_slot.get());

	this->m_state_lock.lock();
	this->m_info_lock.lock();

	GameServerRoom* room = nullptr;
	kudo::ErrorCode error_code = getCurrentRoom(room);
	if (error_code == kudo::EC_None)
	{
		room->m_total_lock.lock();

		if ((this->m_room_slot == room->m_master_slot) || !this->m_ready_flag)
		{
			if ((room->m_game_type == kudo::GT_Singles && (game_room_slot == 0 || game_room_slot == 2)) ||
				(room->m_game_type == kudo::GT_Doubles && (game_room_slot >= 0 && game_room_slot <= 3)))
			{
				if (room->m_state == GameServerRoom::State_Waiting)
				{
					if (!room->m_players[game_room_slot])
					{
						room->m_players[this->m_room_slot] = nullptr;
						room->m_players[game_room_slot] = this;
						if (this->m_room_slot == room->m_master_slot)
							room->m_master_slot = game_room_slot;
						this->m_room_slot = game_room_slot;
						this->onSelectGameRoomSlot(kudo::EC_None, room->m_number, game_room_slot);
						for (size_t i = 0; i < _countof(GameServerRoom::m_players); i++)
						{
							GameServerSession* player = room->m_players[i];
							if (player && player != this)
								player->onGameRoomSlotSelected(room->m_number, this->m_user_uid, game_room_slot);
						}
						LogLine(Logf_Normal, "[Game] <Room%u> User%u selected slot %u\n", room->m_number, this->m_user_uid, this->m_room_slot);
					}
					else
					{
						this->onSelectGameRoomSlot(kudo::EC_InvalidSlot, room->m_number, game_room_slot);
					}
				}
				else
				{
					this->onSelectGameRoomSlot(kudo::EC_GameStarted, room->m_number, game_room_slot);
				}
			}
			else
			{
				this->onSelectGameRoomSlot(kudo::EC_InvalidSlot, room->m_number, 0);
			}
		}
		else
		{
			this->onSelectGameRoomSlot(kudo::EC_CannotSelectGameRoomSlotOnReady, room->m_number, 0);
		}

		room->m_total_lock.unlock();
	}
	else
	{
		this->onSelectGameRoomSlot(error_code, 0, 0);
	}

	this->m_state_lock.unlock();
	this->m_info_lock.unlock();
}
IMPLEMENT_SRPC_METHOD_0(GameServerSession, toggleReadyFlag)
{
	LogLine(Logf_Normal, "[Game] <User%u> toggleReadyFlag\n", this->m_user_uid);

	this->m_state_lock.lock();
	this->m_info_lock.lock();

	GameServerRoom* room = nullptr;
	kudo::ErrorCode error_code = getCurrentRoom(room);
	if (error_code == kudo::EC_None)
	{
		room->m_total_lock.lock();

		if (room->m_state == GameServerRoom::State_Waiting)
		{
			if (this->m_room_slot != room->m_master_slot)
			{
				this->m_ready_flag = !this->m_ready_flag;
				this->onToggleReadyFlag(kudo::EC_None, this->m_ready_flag);
				for (size_t i = 0; i < _countof(GameServerRoom::m_players); i++)
				{
					GameServerSession* player = room->m_players[i];
					if (player && player != this)
						player->onGameRoomReadyFlagToggled(room->m_number, this->m_user_uid, this->m_ready_flag);
				}
				LogLine(Logf_Normal, "[Game] <Room%u> User%u set ready to %s\n", room->m_number, this->m_user_uid, this->m_ready_flag ? "true" : "false");
			}
			else
			{
				this->onToggleReadyFlag(kudo::EC_NoPermission, false);
			}
		}
		else
		{
			this->onToggleReadyFlag(kudo::EC_GameStarted, false);
		}

		room->m_total_lock.unlock();
	}
	else
	{
		this->onToggleReadyFlag(error_code, false);
	}

	this->m_state_lock.unlock();
	this->m_info_lock.unlock();
}
IMPLEMENT_SRPC_METHOD_1(GameServerSession, setGameRules, kudo::RGameRules, game_rules)
{
	LogLine(Logf_Normal, "[Game] <User%u> setGameRules: %d %u %u %s %s %s %u %d %d\n", this->m_user_uid, game_rules.match_mode.get(),
		game_rules.set_count.get(), game_rules.game_count.get(), game_rules.bool4 ? "true" : "false",
		game_rules.bool5 ? "true" : "false", game_rules.bool6 ? "true" : "false", game_rules.map_id.get(),
		game_rules.sint8.get(), game_rules.sint9.get());

	this->m_state_lock.lock();
	this->m_info_lock.lock();

	GameServerRoom* room = nullptr;
	kudo::ErrorCode error_code = getCurrentRoom(room);
	if (error_code == kudo::EC_None)
	{
		room->m_total_lock.lock();

		if (room->m_master_slot == this->m_room_slot)
		{
			if (room->m_state == GameServerRoom::State_Waiting)
			{
				kudo::ErrorCode error_code = kudo::EC_None;
				size_t player_count = room->calcPlayers();

				if (game_rules.match_mode == 0 || game_rules.match_mode == 1)
				{
					kudo::GameType new_game_type = (game_rules.match_mode == 0) ? kudo::GT_Singles : kudo::GT_Doubles;
					if ((new_game_type == kudo::GT_Singles && player_count <= 2) ||
						(new_game_type == kudo::GT_Doubles && player_count <= 4))
					{
						room->m_game_type = new_game_type;
						// TODO: reassign slots
					}
					else
					{
						error_code = kudo::EC_TooManyPlayers;
					}
				}

				if (error_code == kudo::EC_None)
				{
					uint16_t map_char_index;
					kudo::ItemType map_item_type;
					uint8_t map_item_sub_type;
					uint16_t map_item_number;
					kudo::parseItemCode(game_rules.map_id.get(), map_char_index, map_item_type, map_item_sub_type, map_item_number);
					if (map_item_type == kudo::IT_Map && map_item_number >= 1 && map_item_number <= 4)
						room->m_map_id = map_item_number;
				}

				if (game_rules.set_count >= 1 && game_rules.set_count <= 1)
					room->m_set_count = game_rules.set_count;

				if (game_rules.game_count >= 3 && game_rules.game_count <= 3)
					room->m_game_count = game_rules.game_count;

				if (error_code == kudo::EC_None)
				{
					kudo::RGameRules new_game_rules;
					room->buildRpcGameRules(new_game_rules);

					for (size_t i = 0; i < _countof(GameServerRoom::m_players); i++)
					{
						GameServerSession* player = room->m_players[i];
						if (player/* && player != this*/)
							player->onGameRulesChanged(room->m_number, new_game_rules);
					}

					LogLine(Logf_Normal, "[Game] <Room%u> Game rules changed\n", room->m_number);
				}

				this->onSetGameRules(room->m_number, error_code);
			}
			else
			{
				this->onSetGameRules(room->m_number, kudo::EC_GamePlaying);
			}
		}
		else
		{
			this->onSetGameRules(room->m_number, kudo::EC_NoPermission);
		}

		room->m_total_lock.unlock();
	}
	else
	{
		this->onSetGameRules(0, error_code);
	}

	this->m_state_lock.unlock();
	this->m_info_lock.unlock();
}
IMPLEMENT_SRPC_METHOD_1(GameServerSession, kick, srpc::RUInt32, player_id)
{
	LogLine(Logf_Normal, "[Game] <User%u> kick: %u\n", this->m_user_uid, player_id.get());
}
IMPLEMENT_SRPC_METHOD_1(GameServerSession, startGame, kudo::RAddressPairs, addresses)
{
	if (LogBegin(Logf_Normal))
	{
		srpc::String str_addresses;
		for (size_t i = 0; i < addresses.size(); i++)
			str_addresses.append(Format("%s%s:%u", (i != 0) ? ", " : "", addresses[i].ip.c_str(), addresses[i].port.get()));
		LogLine(Logf_Normal | Logf_Nolock, "[Game] <User%u> startGame: [ %s ]\n", this->m_user_uid, str_addresses.c_str());
		LogEnd(Logf_Normal);
	}

	this->m_state_lock.lock();
	this->m_info_lock.lock();

	GameServerRoom* room = nullptr;
	kudo::ErrorCode error_code = getCurrentRoom(room);
	if (error_code == kudo::EC_None)
	{
		room->m_total_lock.lock();

		if (room->m_master_slot == this->m_room_slot)
		{
			if (room->m_state == GameServerRoom::State_Waiting)
			{
				// TODO: check addresses

				int8_t player_map[4] = { 0, 0, 0, 0 };
				player_map[this->m_room_slot] = 2;
				for (size_t i = 0; i < _countof(GameServerRoom::m_players); i++)
				{
					GameServerSession* player = room->m_players[i];
					if (player && player != this)
					{
						player->m_state_lock.lock();
						player_map[i] = player->m_ready_flag ? 2 : 1;
						player->m_state_lock.unlock();
					}
				}

				kudo::ErrorCode error_code = kudo::EC_None;

				if (room->m_game_type == kudo::GT_Singles)
				{
					if (!player_map[0] || !player_map[2])
						error_code = kudo::EC_NotEnoughPlayers;
					else if (player_map[0] != 2 || player_map[2] != 2)
						error_code = kudo::EC_NoReady;
				}
				else if (room->m_game_type == kudo::GT_Doubles)
				{
					if (!player_map[0] || !player_map[1] || !player_map[2] || !player_map[3])
						error_code = kudo::EC_NotEnoughPlayers;
					else if (player_map[0] != 2 || player_map[1] != 2 || player_map[2] != 2 || player_map[3] != 2)
						error_code = kudo::EC_NoReady;
				}
				else
				{
					error_code = kudo::EC_InvalidGameType;
				}

				if (error_code == kudo::EC_None)
				{
					room->m_state = GameServerRoom::State_Starting;

					this->onStartGame(room->m_number, kudo::EC_None);

					for (size_t i = 0; i < _countof(GameServerRoom::m_players); i++)
					{
						GameServerSession* player = room->m_players[i];
						if (player)
						{
							if (player != this)
							{
								player->m_state_lock.lock();
								player->m_info_lock.lock();
							}
							kudo::RBaseCharacters player_characters;
							for (auto& cur_char : this->m_characters)
							{
								kudo::RBaseCharacter char_info;
								char_info.person = cur_char.second.person;
								for (size_t k = 0; k < _countof(kudo::RFullCharacter::status); k++)
									char_info.status[k] = cur_char.second.status[k];
								char_info.bool3 = false;
								char_info.visible = cur_char.second.visible;
								char_info.uint5 = 0;
								char_info.sint6 = 0;
								char_info.uint7 = 0;
								char_info.sint8 = 0;
								player_characters.push_back(char_info);
							}
							player->onGameStarted(room->m_number, addresses, player_characters);
							if (player != this)
							{
								player->m_state_lock.unlock();
								player->m_info_lock.unlock();
							}
						}
					}

					LogLine(Logf_Normal, "[Game] <Room%u> Match started\n", room->m_number);
				}
				else
				{
					this->onStartGame(room->m_number, error_code);
				}
			}
			else
			{
				this->onStartGame(room->m_number, kudo::EC_GameStarted);
			}
		}
		else
		{
			this->onStartGame(room->m_number, kudo::EC_NoPermission);
		}

		room->m_total_lock.unlock();
	}
	else
	{
		this->onStartGame(0, error_code);
	}

	this->m_state_lock.unlock();
	this->m_info_lock.unlock();
}
IMPLEMENT_SRPC_METHOD_0(GameServerSession, playGame)
{
	LogLine(Logf_Normal, "[Game] <User%u> playGame\n", this->m_user_uid);

	this->m_state_lock.lock();
	this->m_info_lock.lock();

	GameServerRoom* room = nullptr;
	kudo::ErrorCode error_code = getCurrentRoom(room);
	if (error_code == kudo::EC_None)
	{
		room->m_total_lock.lock();

		if (room->m_master_slot == this->m_room_slot)
		{
			if (room->m_state == GameServerRoom::State_Starting)
			{
				room->m_state = GameServerRoom::State_Playing;

				this->onPlayGame(room->m_number, kudo::EC_None);

				for (size_t i = 0; i < _countof(GameServerRoom::m_players); i++)
				{
					GameServerSession* player = room->m_players[i];
					if (player)
					{
						if (player != this)
						{
							player->m_state_lock.lock();
							player->m_info_lock.lock();
						}
						player->onGamePlayed(room->m_number);
						if (player != this)
						{
							player->m_state_lock.unlock();
							player->m_info_lock.unlock();
						}
					}
				}

				LogLine(Logf_Normal, "[Game] <Room%u> Match playing\n", room->m_number);
			}
			else
			{
				this->onPlayGame(room->m_number, kudo::EC_GameNotStarted);
			}
		}
		else
		{
			this->onPlayGame(room->m_number, kudo::EC_NoPermission);
		}

		room->m_total_lock.unlock();
	}
	else
	{
		this->onPlayGame(0, error_code);
	}

	this->m_state_lock.unlock();
	this->m_info_lock.unlock();
}
IMPLEMENT_SRPC_METHOD_1(GameServerSession, stopGame, kudo::RGameResult, game_result)
{
	LogLine(Logf_Normal, "[Game] <User%u> stopGame\n", this->m_user_uid);

	this->m_state_lock.lock();
	this->m_info_lock.lock();

	GameServerRoom* room = nullptr;
	kudo::ErrorCode error_code = getCurrentRoom(room);
	if (error_code == kudo::EC_None)
	{
		room->m_total_lock.lock();

		if (room->m_master_slot == this->m_room_slot)
		{
			if (room->m_state == GameServerRoom::State_Playing)
			{
				// TODO: validate result

				kudo::RDetailedGameResult det_game_result;
				det_game_result.winner = game_result.winner;
				det_game_result.info2 = game_result.info2;
				det_game_result.info3 = game_result.info3;
				det_game_result.uint4 = game_result.uint4;
				
				// TODO: rewards

				this->onStopGame(room->m_number, kudo::EC_None);

				for (size_t i = 0; i < _countof(GameServerRoom::m_players); i++)
				{
					GameServerSession* player = room->m_players[i];
					if (player)
					{
						if (player != this)
						{
							player->m_state_lock.lock();
							player->m_info_lock.lock();
						}
						player->onGameStopped(room->m_number, det_game_result);
						if (player != this)
						{
							player->m_state_lock.unlock();
							player->m_info_lock.unlock();
						}
					}
				}

				room->m_state = GameServerRoom::State_Waiting;
				LogLine(Logf_Normal, "[Game] <Room%u> Match stopped by request\n", room->m_number);
			}
		}

		room->m_total_lock.unlock();
	}
	else
	{
		this->onPlayGame(0, error_code);
	}

	this->m_state_lock.unlock();
	this->m_info_lock.unlock();
}
IMPLEMENT_SRPC_METHOD_1(GameServerSession, cancelGame, kudo::RGameCancelReason, cancel_reason)
{
	LogLine(Logf_Normal, "[Game] <User%u> cancelGame: %u\n", this->m_user_uid, cancel_reason.get());

	this->m_state_lock.lock();
	this->m_info_lock.lock();

	GameServerRoom* room = nullptr;
	kudo::ErrorCode error_code = getCurrentRoom(room);
	if (error_code == kudo::EC_None)
	{
		room->m_total_lock.lock();

		if (room->m_master_slot == this->m_room_slot)
		{
			if (room->m_state == GameServerRoom::State_Starting)
			{
				// TODO: validate reason

				room->m_state = GameServerRoom::State_Waiting;

				this->onCancelGame(room->m_number, kudo::EC_None);

				for (size_t i = 0; i < _countof(GameServerRoom::m_players); i++)
				{
					GameServerSession* player = room->m_players[i];
					if (player)
					{
						if (player != this)
						{
							player->m_state_lock.lock();
							player->m_info_lock.lock();
						}
						player->onGameCanceled(room->m_number, cancel_reason);
						if (player != this)
						{
							player->m_state_lock.unlock();
							player->m_info_lock.unlock();
						}
					}
				}

				LogLine(Logf_Normal, "[Game] <Room%u> Match canceled\n", room->m_number);
			}
			else
			{
				this->onCancelGame(0, kudo::EC_GameNotStarted);
			}
		}

		room->m_total_lock.unlock();
	}
	else
	{
		this->onCancelGame(0, error_code);
	}

	this->m_state_lock.unlock();
	this->m_info_lock.unlock();
}
IMPLEMENT_SRPC_METHOD_0(GameServerSession, inviteWaiter)
{
	LogLine(Logf_Normal, "[Game] <User%u> inviteWaiter\n", this->m_user_uid);
}
DEFINE_SRPC_METHOD_2(GameServerSession, onOpenGameRoomDoor, kudo::RErrorCode, error_code, srpc::RUInt16, room_number);
DEFINE_SRPC_METHOD_2(GameServerSession, onGameRoomList, kudo::RSimpleGameRoomInfos, rooms_info, srpc::RUInt16, rooms_count);
DEFINE_SRPC_METHOD_3(GameServerSession, onEnterGameRoom, kudo::RErrorCode, error_code, srpc::RUInt16, room_number, kudo::RGameRoomSlot, room_slot);
DEFINE_SRPC_METHOD_2(GameServerSession, onLeaveGameRoom, kudo::RErrorCode, error_code, srpc::RUInt16, room_number);
DEFINE_SRPC_METHOD_1(GameServerSession, onQuickJoinableRoomId, srpc::RUInt16, room_number);
DEFINE_SRPC_METHOD_3(GameServerSession, onGameRoomPlayerList, srpc::RUInt16, room_number, srpc::RUInt32, master_uid, kudo::RPlayersInfo, players_info);
DEFINE_SRPC_METHOD_3(GameServerSession, onSelectGameRoomSlot, kudo::RErrorCode, error_code, srpc::RUInt16, room_number, kudo::RGameRoomSlot, room_slot);
DEFINE_SRPC_METHOD_2(GameServerSession, onToggleReadyFlag, srpc::RUInt16, room_number, srpc::RBool, ready_flag);
DEFINE_SRPC_METHOD_2(GameServerSession, onSetGameRules, srpc::RUInt16, room_number, kudo::RErrorCode, error_code);
DEFINE_SRPC_METHOD_2(GameServerSession, onStartGame, srpc::RUInt16, room_number, kudo::RErrorCode, error_code);
DEFINE_SRPC_METHOD_2(GameServerSession, onPlayGame, srpc::RUInt16, room_number, kudo::RErrorCode, error_code);
DEFINE_SRPC_METHOD_2(GameServerSession, onStopGame, srpc::RUInt16, room_number, kudo::RErrorCode, error_code);
DEFINE_SRPC_METHOD_2(GameServerSession, onCancelGame, srpc::RUInt16, room_number, kudo::RErrorCode, error_code);

DEFINE_SRPC_METHOD_2(GameServerSession, onGameRoomInfo, srpc::RUInt16, room_number, kudo::RFullGameRoomInfo, room_info);
DEFINE_SRPC_METHOD_2(GameServerSession, onGameRoomUserEntered, srpc::RUInt16, room_number, kudo::RPlayerInfo, player_info);
DEFINE_SRPC_METHOD_2(GameServerSession, onGameRoomUserLeft, srpc::RUInt16, room_number, srpc::RUInt32, player_uid);
DEFINE_SRPC_METHOD_2(GameServerSession, onChat, srpc::RUInt32, player_uid, kudo::RChatMessage, message);
DEFINE_SRPC_METHOD_3(GameServerSession, onMasterChanged, srpc::RUInt16, room_number, srpc::RUInt32, player_uid, srpc::RBool, unk_bool);
DEFINE_SRPC_METHOD_3(GameServerSession, onGameRoomSlotSelected, srpc::RUInt16, room_number, srpc::RUInt32, player_uid, kudo::RGameRoomSlot, room_slot);
DEFINE_SRPC_METHOD_3(GameServerSession, onGameRoomReadyFlagToggled, srpc::RUInt16, room_number, srpc::RUInt32, player_uid, srpc::RBool, ready_flag);
DEFINE_SRPC_METHOD_2(GameServerSession, onGameRulesChanged, srpc::RUInt16, room_number, kudo::RGameRules, game_rules);
DEFINE_SRPC_METHOD_2(GameServerSession, onKicked, srpc::RUInt16, room_number, srpc::RUInt32, player_uid);
DEFINE_SRPC_METHOD_2(GameServerSession, onGameSlotsArranged, srpc::RUInt16, room_number, kudo::RDetailedSlotInfos, slots_info);
DEFINE_SRPC_METHOD_3(GameServerSession, onGameStarted, srpc::RUInt16, room_number, kudo::RAddressPairs, start_addresses, kudo::RBaseCharacters, characters);
DEFINE_SRPC_METHOD_1(GameServerSession, onGamePlayed, srpc::RUInt16, room_number);
DEFINE_SRPC_METHOD_2(GameServerSession, onGameStopped, srpc::RUInt16, room_number, kudo::RDetailedGameResult, game_result);
DEFINE_SRPC_METHOD_2(GameServerSession, onGameCanceled, srpc::RUInt16, room_number, kudo::RGameCancelReason, reason);
DEFINE_SRPC_METHOD_2(GameServerSession, onInvited, srpc::RUInt16, room_number, kudo::RRoomPass, str2);
DEFINE_SRPC_METHOD_3(GameServerSession, onWargerGameRulesChanged, srpc::RUInt16, room_number, kudo::RWagerRules, game_rules, kudo::RWagerReason, reason);











IMPLEMENT_SRPC_METHOD_0(GameServerSession, requestItems)
{
	LogLine(Logf_Normal, "[Game] requestItems\n");

	kudo::RUnkVect1 vect1;
	vect1.push_back(kudo::buildItemCode(1, kudo::ItemType::IT_WearableItem, 1, 1));

	kudo::RUnkVect1 clothes;
	clothes.push_back(kudo::buildItemCode(2, kudo::ItemType::IT_WearableItem, 1, 16));
	clothes.push_back(kudo::buildItemCode(2, kudo::ItemType::IT_WearableItem, 2, 16));
	clothes.push_back(kudo::buildItemCode(2, kudo::ItemType::IT_WearableItem, 3, 16));
	clothes.push_back(kudo::buildItemCode(2, kudo::ItemType::IT_WearableItem, 4, 16));
	clothes.push_back(kudo::buildItemCode(2, kudo::ItemType::IT_WearableItem, 5, 16));
	clothes.push_back(kudo::buildItemCode(2, kudo::ItemType::IT_WearableItem, 6, 16));

	clothes.push_back(kudo::buildItemCode(2, kudo::ItemType::IT_WearableItem, 7, 2));
	clothes.push_back(kudo::buildItemCode(2, kudo::ItemType::IT_WearableItem, 7, 3));
	clothes.push_back(kudo::buildItemCode(2, kudo::ItemType::IT_WearableItem, 7, 4));
	clothes.push_back(kudo::buildItemCode(2, kudo::ItemType::IT_WearableItem, 7, 5));
	clothes.push_back(kudo::buildItemCode(2, kudo::ItemType::IT_WearableItem, 7, 6));
	clothes.push_back(kudo::buildItemCode(2, kudo::ItemType::IT_WearableItem, 7, 7));
	clothes.push_back(kudo::buildItemCode(2, kudo::ItemType::IT_WearableItem, 7, 8));
	clothes.push_back(kudo::buildItemCode(2, kudo::ItemType::IT_WearableItem, 7, 9));
	clothes.push_back(kudo::buildItemCode(2, kudo::ItemType::IT_WearableItem, 7, 10));
	clothes.push_back(kudo::buildItemCode(2, kudo::ItemType::IT_WearableItem, 7, 11));
	clothes.push_back(kudo::buildItemCode(2, kudo::ItemType::IT_WearableItem, 7, 12));
	clothes.push_back(kudo::buildItemCode(2, kudo::ItemType::IT_WearableItem, 7, 13));
	clothes.push_back(kudo::buildItemCode(2, kudo::ItemType::IT_WearableItem, 8, 1));
	clothes.push_back(kudo::buildItemCode(2, kudo::ItemType::IT_WearableItem, 8, 6));
	clothes.push_back(kudo::buildItemCode(2, kudo::ItemType::IT_WearableItem, 8, 7));

	kudo::RUnkVect1 vect3; // clothes?
	vect3.push_back(kudo::buildItemCode(1, kudo::ItemType::IT_WearableItem, 1, 1));

	kudo::RUnkVect1 vect4;
	vect4.push_back(kudo::buildItemCode(1, kudo::ItemType::IT_WearableItem, 1, 1));

	kudo::RUnkVect2 vect5;
	vect5.push_back(kudo::buildItemCode(1, kudo::ItemType::IT_WearableItem, 1, 1));

	onItems(vect1, clothes, vect3, vect4, vect5);
}
IMPLEMENT_SRPC_METHOD_3(GameServerSession, buyItem, srpc::RUInt32, uint1, kudo::RPayWay, pay_way, kudo::RBuyMethod, buy_method)
{
	LogLine(Logf_Normal, "[Game] buyItem\n");

	kudo::RPrice price;
	onBuyItem(kudo::ErrorCode::EC_HaveNoEnoughCash, 0, 0, 0, 0, price);
}
IMPLEMENT_SRPC_METHOD_4(GameServerSession, buyCharacter, srpc::RUInt16, uint1, kudo::RCharStyleId, char_style, kudo::RUnkVect1, vect3, kudo::RPayWay, pay_way)
{
	LogLine(Logf_Normal, "[Game] buyCharacter\n");

	kudo::RFullCharacter character_info;
	kudo::RPrice price;

	onBuyCharacter(kudo::ErrorCode::EC_NotBuyableCharacter, character_info, price);
}
IMPLEMENT_SRPC_METHOD_2(GameServerSession, sellItem, srpc::RUInt32, uint1, kudo::RItemType, item_type)
{
	LogLine(Logf_Normal, "[Game] sellItem\n");
}
IMPLEMENT_SRPC_METHOD_2(GameServerSession, destroyItem, srpc::RUInt32, uint1, kudo::RItemType, item_type)
{
	LogLine(Logf_Normal, "[Game] destroyItem\n");
}
IMPLEMENT_SRPC_METHOD_2(GameServerSession, restoreItem, srpc::RUInt32, uint1, kudo::RItemType, item_type)
{
	LogLine(Logf_Normal, "[Game] restoreItem\n");
}
IMPLEMENT_SRPC_METHOD_2(GameServerSession, adornCharacter, srpc::RUInt32, uint1, kudo::RUnkVect1, vect2)
{
	LogLine(Logf_Normal, "[Game] adornCharacter\n");
}

DEFINE_SRPC_METHOD_5(GameServerSession, onItems, kudo::RUnkVect1, vect1, kudo::RUnkVect1, vect2, kudo::RUnkVect1, vect3, kudo::RUnkVect1, vect4, kudo::RUnkVect2, vect5);
DEFINE_SRPC_METHOD_6(GameServerSession, onBuyItem, kudo::RErrorCode, error_code, srpc::RUInt32, uint2, srpc::RUInt32, uint3, srpc::RUInt16, uint4, srpc::RInt32, sint5, kudo::RPrice, price);
DEFINE_SRPC_METHOD_3(GameServerSession, onBuyCharacter, kudo::RErrorCode, error_code, kudo::RFullCharacter, character_info, kudo::RPrice, price);
DEFINE_SRPC_METHOD_4(GameServerSession, onSellItem, kudo::RErrorCode, error_code, srpc::RUInt32, uint2, kudo::RItemType, item_type, srpc::RInt32, sint4);
DEFINE_SRPC_METHOD_3(GameServerSession, onDestroyItem, kudo::RErrorCode, error_code, srpc::RUInt32, uint2, kudo::RItemType, item_type);
DEFINE_SRPC_METHOD_3(GameServerSession, onRestoreItem, kudo::RErrorCode, error_code, srpc::RUInt32, uint2, kudo::RItemType, item_type);
DEFINE_SRPC_METHOD_4(GameServerSession, onAdornCharacter, kudo::RErrorCode, error_code, srpc::RUInt32, uint2, kudo::RCharacter::RItems, char_items, kudo::RWearItems, wear_items);




DEFINE_SRPC_METHOD_4(GameServerSession, onCharacterAdorned, srpc::RUInt16, uint1, srpc::RUInt32, uint2, srpc::RUInt32, uint3, kudo::RUnkVect1, vect4);
DEFINE_SRPC_METHOD_4(GameServerSession, onItemVanished, srpc::RUInt16, uint1, srpc::RUInt32, uint2, srpc::RUInt32, uint3, kudo::RUnkVect1, vect4);
DEFINE_SRPC_METHOD_3(GameServerSession, onMapItemVanished, srpc::RUInt16, uint1, srpc::RUInt32, uint2, kudo::RUnkVect1, vect4);









//=========================================================================================================================================

GameServerInstance::GameServerInstance(ACE_Proactor* proactor, ACE_Reactor* reactor, kat::KatPacketCoderFactory* packet_coder_factory) :
	nsrpc::SessionAcceptor((nsrpc::SessionCreator&)*this)
{
	m_proactor = proactor;
	m_reactor = reactor;
	m_packet_coder_factory = packet_coder_factory;
}

GameServerInstance::~GameServerInstance()
{
	m_rooms_lock.lock();
	auto room_it = m_rooms.begin();
	while (room_it != m_rooms.end())
	{
		GameServerRoom* room = room_it->second;
		if (room)
		{
			room->m_total_lock.lock();
			for (size_t i = 0; i < _countof(GameServerRoom::m_players); i++)
			{
				GameServerSession* player = room->m_players[i];
				if (player)
				{
					player->m_state_lock.lock();
					player->m_room = nullptr;
					player->m_state_lock.unlock();
				}
				room->m_players[i] = nullptr;
			}
			if (room->m_relay)
				room->m_relay->stop();
			room->m_total_lock.unlock();
			delete room;
			room_it = m_rooms.erase(room_it);
			continue;
		}
		room_it++;
	}
	m_rooms_lock.unlock();

	m_sessions_lock.lock();
	auto sess_it = m_sessions.begin();
	while (sess_it != m_sessions.end())
	{
		GameServerSession* session = *sess_it;
		if (session)
		{
			session->m_state_lock.lock();
			session->m_info_lock.lock();
			session->disconnect();
			session->m_room = nullptr;
			session->m_state_lock.unlock();
			session->m_info_lock.unlock();
			delete session;
			sess_it = m_sessions.erase(sess_it);
			continue;
		}
		sess_it++;
	}
	m_sessions_lock.unlock();
}

uint32_t GameServerInstance::findFreeUserId(const GameServerSession* current)
{
	uint32_t free_id = 1;
	while (true)
	{
		bool exists = false;
		auto cur_session = m_sessions.begin();
		while (cur_session != m_sessions.end())
		{
			if (!current || (*cur_session) != current)
			{
				(*cur_session)->m_info_lock.lock();
				bool matches = (*cur_session)->m_user_uid == free_id;
				(*cur_session)->m_info_lock.unlock();
				if (matches)
				{
					exists = true;
					break;
				}
			}
			cur_session++;
		}
		if (!exists)
			break;
		free_id++;
	}
	return free_id;
}

uint16_t GameServerInstance::findFreeRoomNumber()
{
	uint16_t free_number = 1;
	while (true)
	{
		if (m_rooms.find(free_number) == m_rooms.end())
			break;
		free_number++;
	}
	return free_number;
}

nsrpc::Session* GameServerInstance::acquire()
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
	GameServerSession* session = new GameServerSession(this, session_config);
	if (!session)
		return nullptr;
	m_sessions_lock.lock();
	LogLine(Logf_Normal, "[Game] Session created %p\n", session);
	m_sessions.push_back(session);
	m_sessions_lock.unlock();
	return session;
}

void GameServerInstance::release(nsrpc::Session* session)
{
	GameServerSession* user = (GameServerSession*)session;
	if (user)
	{
		user->m_state_lock.lock();
		user->m_info_lock.lock();

		if (user->m_user_uid)
		{
			GameServerRoom* room = user->m_room;
			if (room)
			{
				room->m_total_lock.lock();

				if (room->playerLeft(user) == 0)
				{
					m_rooms_lock.lock();
					LogLine(Logf_Normal, "[Game] <Room%u> Destroyed as empty\n", room->m_number);
					room->m_total_lock.unlock();
					delete room;
					m_rooms.erase(room->m_number);
					m_rooms_lock.unlock();
				}
				else
				{
					room->m_total_lock.unlock();
				}
			}
		}

		user->m_state_lock.unlock();
		user->m_info_lock.unlock();

		m_sessions_lock.lock();
		m_sessions.remove(user);
		delete user;
		LogLine(Logf_Normal, "[Game] Session destroyed %p\n", user);
		m_sessions_lock.unlock();
	}
}

//=========================================================================================================================================