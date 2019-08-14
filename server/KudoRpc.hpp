#pragma once

#include "KudoCommon.hpp"
#include <srpc\RpcTypes.h>
#include <srpc\RpcContainers.h>
#include <srpc\RpcInterface.h>

//=========================================================================================================================================

namespace kudo
{
	typedef srpc::RpcUIntType<ErrorCode, 16> RErrorCode;
	typedef srpc::RpcIntType<CharStyleId, 4> RCharStyleId;
	typedef srpc::RpcIntType<GameMode, 4> RGameMode;
	typedef srpc::RpcIntType<GameType, 2> RGameType;
	typedef srpc::RpcIntType<GameRoomType, 2> RGameRoomType;
	typedef srpc::RpcIntType<uint8_t, 4> RGameRoomSlot;
	typedef srpc::RpcIntType<GameCancelReason, 4> RGameCancelReason;
	typedef srpc::RpcIntType<WagerReason, 4> RWagerReason;
	typedef srpc::RpcIntType<CharacterType, 3> RCharacterType;
	typedef srpc::RpcIntType<StrokeTrainingType, 3> RStrokeTrainingType;
	typedef srpc::RpcIntType<AbilityType, 4> RAbilityType;
	typedef srpc::RpcIntType<MailType, 3> RMailType;
	typedef srpc::RpcIntType<MailState, 4> RMailState;
	typedef srpc::RpcStringType<srpc::WString, 42> RAccountLogin;
	typedef srpc::RpcStringType<srpc::WString, 36> RAccountPassword;
	typedef srpc::RpcStringType<srpc::WString, 30> RNickname;
	typedef srpc::RpcStringType<srpc::WString, 60> RRoomTitle;
	typedef srpc::RpcStringType<srpc::String, 8> RRoomPass;
	typedef srpc::RpcStringType<srpc::WString, 192> RChatMessage;
	typedef srpc::RpcIntType<PayWay, 5> RPayWay;
	typedef srpc::RpcIntType<BuyMethod, 5> RBuyMethod;
	typedef srpc::RpcIntType<ItemType, 5> RItemType;
	typedef srpc::RVector<srpc::RUInt32, 16> RUnkVect1;
	typedef srpc::RVector<srpc::RUInt16, 8> RUnkVect2;
	typedef srpc::RpcUIntType<srpc::UInt8, 4> RPlayerSlot;

	struct RCharacter
	{
		struct RItem
		{
			srpc::RUInt32 uint1;
			srpc::RUInt32 uint2;

			void write(srpc::OStream& ostream);
			void read(srpc::IStream& istream);

		};

		typedef srpc::RVector<RItem, 4> RItems;

		srpc::RUInt16 person;
		srpc::RUInt16 status[6];
		srpc::RBool bool3;
		srpc::RBool visible;

		void write(srpc::OStream& ostream);
		void read(srpc::IStream& istream);

	};

	struct RBaseCharacter : public RCharacter
	{
		srpc::RUInt32 uint5;
		srpc::RpcIntType<srpc::Int32, 3> sint6;
		srpc::RUInt32 uint7;
		srpc::RpcIntType<srpc::Int32, 7> sint8;

		void write(srpc::OStream& ostream);
		void read(srpc::IStream& istream);

	};

	typedef srpc::RVector<RBaseCharacter, 4> RBaseCharacters;

	struct RSubInfo2
	{
		srpc::RUInt16 uint1;
		srpc::RUInt16 uint2;
		srpc::RUInt16 uint3;
		srpc::RUInt16 uint4;

		void write(srpc::OStream& ostream);
		void read(srpc::IStream& istream);

	};

	struct RFullCharacter : public RCharacter
	{
		srpc::RUInt32 id;
		srpc::RpcIntType<srpc::UInt32, 3> type;
		srpc::RUInt32 exp;
		srpc::RpcIntType<srpc::UInt32, 7> minor_grade;
		RCharacter::RItems items9;
		RUnkVect1 vect10;
		srpc::RMap<srpc::RpcIntType<srpc::Int32, 4>, RSubInfo2> map11;
		srpc::RUInt8 uint12;
		srpc::RUInt8 uint13;

		void write(srpc::OStream& ostream);
		void read(srpc::IStream& istream);

	};

	typedef srpc::RVector<RFullCharacter, 8> RFullCharacters;

	struct RSubInfo3
	{
		srpc::RUInt32 item_code;
		srpc::RpcIntType<srpc::Int32, 5> sint2;
		srpc::RBool bool3;
		srpc::RBool bool4;
		srpc::RBool bool5;
		srpc::RBool bool6;
		srpc::RBool bool7;
		srpc::RInt32 sint8;
		srpc::RInt32 sint9;
		srpc::RUInt16 uints10[6];

		void write(srpc::OStream& ostream);
		void read(srpc::IStream& istream);

	};

	struct RWearItem : public RSubInfo3
	{
		srpc::RUInt16 uint11;
		srpc::RUInt32 uint12;
		srpc::RBool bool13;
		srpc::RpcIntType<srpc::Int32, 5> sint14;
		srpc::RUInt16 uint15;
		srpc::RInt32 uint16;

		void write(srpc::OStream& ostream);
		void read(srpc::IStream& istream);

	};

	typedef srpc::RVector<RWearItem, 8> RWearItems;

	struct RUnk1Item : public RSubInfo3
	{
		srpc::RUInt32 uint11;
		srpc::RInt32 uint12;
		srpc::RUInt32 uint13;
		srpc::RBool bool14;
		srpc::RpcIntType<srpc::Int32, 5> sint15;
		srpc::RUInt16 uint16;
		srpc::RInt32 sint17;

		void write(srpc::OStream& ostream);
		void read(srpc::IStream& istream);

	};

	struct RRawWearItem : public RSubInfo3
	{
		srpc::RUInt16 uint11;

		void write(srpc::OStream& ostream);
		void read(srpc::IStream& istream);

	};

	typedef srpc::RVector<RRawWearItem, 8> RRawWearItems;

	struct RUnkInfo4
	{
		srpc::RUInt16 uint1;
		srpc::RUInt16 uint2;
		srpc::RUInt16 uint3;
		srpc::RUInt16 uint4;
		srpc::RUInt16 uint5;
		srpc::RUInt16 uint6;
		srpc::RUInt16 uint7;
		srpc::RUInt16 uint8;
		srpc::RUInt16 uint9;
		srpc::RpcUIntType<srpc::UInt16, 9> uint10;
		srpc::RpcUIntType<srpc::UInt16, 9> uint11;
		srpc::RpcUIntType<srpc::UInt16, 9> uint12;
		srpc::RpcUIntType<srpc::UInt16, 9> uint13;
		srpc::RpcUIntType<srpc::UInt16, 9> uint14;

		void write(srpc::OStream& ostream);
		void read(srpc::IStream& istream);

	};

	struct RUnkInfo5 : public RUnkInfo4
	{
		srpc::RUInt16 uint15;
		srpc::RUInt16 uint16;
		srpc::RUInt16 uint17;
		srpc::RUInt16 uint18;
		srpc::RUInt16 uint19;
		srpc::RUInt16 uint20;
		srpc::RUInt16 uint21;

		void write(srpc::OStream& ostream);
		void read(srpc::IStream& istream);

	};

	struct RFullUserInfo
	{
		srpc::RUInt32 uid;
		RNickname nickname;
		srpc::RpcStringType<srpc::WString, 42> str3;
		RFullCharacters characters;
		srpc::RInt32 sint5;
		srpc::RInt32 sint6;
		RWearItems wear_items;
		srpc::RVector<RUnk1Item> items8;
		RUnkInfo4 data9;

		void write(srpc::OStream& ostream);
		void read(srpc::IStream& istream);

	};

	struct RCharacterTemplate : public RCharacter
	{
		srpc::RpcIntType<srpc::Int32, 3> sint5;
		srpc::RInt32 sint6;
		srpc::RInt32 sint7;
		srpc::RUInt16 uint8;
		srpc::RUInt16 uint9;

		void write(srpc::OStream& ostream);
		void read(srpc::IStream& istream);

	};

	typedef srpc::RVector<RCharacterTemplate, 8> RCharacterTemplates;

	struct RCharacterStyle
	{
		srpc::RUInt16 uint1;
		srpc::RpcIntType<srpc::Int32, 4> sint2;
		srpc::RUInt16 uints3[6];

		void write(srpc::OStream& ostream);
		void read(srpc::IStream& istream);

	};

	typedef srpc::RVector<RCharacterStyle, 8> RCharacterStyles;

	struct RGameRules
	{
		srpc::RpcIntType<srpc::Int32, 2> match_mode;
		srpc::RpcUIntType<srpc::UInt8, 3> set_count;
		srpc::RpcUIntType<srpc::UInt8, 3> game_count;
		srpc::RBool bool4;
		srpc::RBool bool5;
		srpc::RBool bool6;
		srpc::RUInt32 map_id;
		srpc::RpcIntType<srpc::Int32, 2> sint8;
		srpc::RInt32 sint9;
		
		void write(srpc::OStream& ostream);
		void read(srpc::IStream& istream);

	};

	struct RWagerRules
	{
		srpc::RpcIntType<srpc::Int32, 2> sint1;
		srpc::RInt32 sint2;

		void write(srpc::OStream& ostream);
		void read(srpc::IStream& istream);

	};

	struct RPlayerReward
	{
		srpc::RUInt32 player_uid;
		srpc::RUInt32 uint2;
		srpc::RInt32 game_mode;
		srpc::RpcIntType<srpc::Int32, 2> sint4;
		srpc::RInt32 sint5;
		srpc::RUInt16 uint6;
		srpc::RUInt16 uint7;
		// only game_mode 1/2/5
		srpc::RUInt32 uint8;
		srpc::RpcIntType<srpc::Int32, 7> sint9;
		srpc::RUInt32 uint10;
		srpc::RUInt32 uint11;
		srpc::RUInt16 uints12[6];
		srpc::RUInt8 uint13;
		srpc::RUInt8 uint14;
		// only game_mode 4
		srpc::RInt32 sint15;

		void write(srpc::OStream& ostream);
		void read(srpc::IStream& istream);

	};

	struct RSubInfo5
	{
		srpc::RpcUIntType<srpc::UInt8, 3> uint1;
		srpc::RpcUIntType<srpc::UInt8, 3> uint2;

		void write(srpc::OStream& ostream);
		void read(srpc::IStream& istream);

	};

	struct RGameResult
	{
		srpc::RpcIntType<srpc::Int32, 2> winner;
		srpc::RMap<srpc::RUInt32, RUnkInfo5> info2;
		srpc::RVector<srpc::RVector<RSubInfo5, 2>, 2> info3;
		srpc::RUInt16 uint4;

		void write(srpc::OStream& ostream);
		void read(srpc::IStream& istream);

	};

	struct RDetailedGameResult : public RGameResult
	{
		srpc::RVector<RPlayerReward, 3> rewards;

		void write(srpc::OStream& ostream);
		void read(srpc::IStream& istream);

	};

	struct RPlayerInfo
	{
		srpc::RUInt32 uid;
		RNickname nickname;
		RFullCharacters characters;
		RPlayerSlot slot;
		srpc::RBool ready;
		srpc::RpcIntType<srpc::Int32, 7> sint6;

		void write(srpc::OStream& ostream);
		void read(srpc::IStream& istream);

	};

	typedef srpc::RVector<RPlayerInfo, 8> RPlayersInfo;

	struct RGameRoomInfo
	{
		RRoomTitle title;
		RGameRules game_rules;
		srpc::RpcIntType<srpc::Int32, 5> grade_mode;
		srpc::RBool locked;
		srpc::RBool bool5;

		void write(srpc::OStream& ostream);
		void read(srpc::IStream& istream);
	};

	struct RSimplePlayerInfo
	{
		RPlayerSlot slot;
		RNickname nickname;
		srpc::RUInt16 uint3;
		RUnkVect1 vect4;
		RUnkVect1 vect5;

		void write(srpc::OStream& ostream);
		void read(srpc::IStream& istream);

	};

	struct RSimpleGameRoomInfo : public RGameRoomInfo
	{
		srpc::RUInt16 room_number;
		srpc::RVector<RSimplePlayerInfo, 3> players;

		void write(srpc::OStream& ostream);
		void read(srpc::IStream& istream);

	};

	typedef srpc::RVector<RSimpleGameRoomInfo, 16> RSimpleGameRoomInfos;

	struct RFullGameRoomInfo : public RGameRoomInfo
	{
		srpc::RUInt32 master_uid;
		RPlayersInfo players;
		srpc::RShortString relay_addr;
		srpc::RUInt16 relay_port;
		srpc::RUInt32 relay_key;
		RRoomPass pass;

		void write(srpc::OStream& ostream);
		void read(srpc::IStream& istream);

	};

	struct RDetailedSlotInfo
	{
		RGameRoomSlot slot;
		srpc::RBool bool2;
		srpc::RUInt32 user_uid;

		void write(srpc::OStream& ostream);
		void read(srpc::IStream& istream);

	};

	typedef srpc::RVector<RDetailedSlotInfo, 3> RDetailedSlotInfos;

	struct RPrice
	{
		srpc::RpcIntType<srpc::Int32, 5> sint1;
		srpc::RInt32 sint2;

		void write(srpc::OStream& ostream);
		void read(srpc::IStream& istream);

	};

	struct RStrokeTrainingRanking
	{
		srpc::RpcStringType<srpc::WString, 30> str1;
		srpc::RUInt16 uint2;

		void write(srpc::OStream& ostream);
		void read(srpc::IStream& istream);

	};

	typedef srpc::RMap<RAbilityType, srpc::RVector<RStrokeTrainingRanking, 2>, 3> RStrokeTrainingRankings;

	struct RStrokeTrainingTargetScore
	{
		srpc::RUInt16 uint1;
		srpc::RUInt16 uint2;
		srpc::RUInt16 uint3;
		srpc::RUInt8 uint4;
		srpc::RInt32 sint5;
		srpc::RInt32 sint6;
		srpc::RInt32 sint7;

		void write(srpc::OStream& ostream);
		void read(srpc::IStream& istream);

	};

	typedef srpc::RMap<RAbilityType, srpc::RVector<RStrokeTrainingTargetScore, 3>, 3> RStrokeTrainingTargetScores;

	struct RTrainingPoints
	{
		srpc::RUInt8 uint1;
		srpc::RUInt8 uint2;

		void write(srpc::OStream& ostream);
		void read(srpc::IStream& istream);

	};

	typedef srpc::RpcUIntType<srpc::UInt8, 2> RUnkTraining1;

	typedef srpc::RpcStringType<srpc::WString, 384> RNoticeString;
	typedef srpc::RVector<RNoticeString, 8> RNoticeStrings;

	typedef srpc::RVector<kat::RAddressPair, 8> RAddressPairs;

	typedef srpc::RVector<srpc::RUInt8, 16> RXtrapBytes;

	struct RPlace
	{
		srpc::RpcIntType<srpc::Int32, 4> sint2;
		srpc::RUInt16 uint3;

		void write(srpc::OStream& ostream);
		void read(srpc::IStream& istream);

	};

	struct RBuddy
	{
		RNickname nickname;
		srpc::RUInt32 uint2;
		srpc::RBool bool3;
		srpc::RBool bool4;
		RPlace place;
		srpc::RUInt32 uint7;

		void write(srpc::OStream& ostream);
		void read(srpc::IStream& istream);

	};

	typedef srpc::RSet<RBuddy, 8> RBuddies;

	struct RBuddyGroup
	{
		srpc::RUInt32 uint1;
		RNickname name;

		void write(srpc::OStream& ostream);
		void read(srpc::IStream& istream);

	};

	typedef srpc::RSet<RBuddyGroup, 8> RBuddyGroups;

	typedef srpc::RVector<srpc::RUInt32, 8> RChatVec1;

	struct RBaseUserInfo
	{
		srpc::RUInt32 uint1;
		RNickname nickname;

		void write(srpc::OStream& ostream);
		void read(srpc::IStream& istream);

	};

	typedef srpc::RVector<RBaseUserInfo, 8> RBaseUserInfos;

	typedef srpc::RpcUIntType<srpc::UInt8, 6> RChatUint1;

	struct RChannelUserInfo
	{
		srpc::RUInt32 uint1;
		RNickname nickname;
		srpc::RBool bool3;

		void write(srpc::OStream& ostream);
		void read(srpc::IStream& istream);

	};

	typedef srpc::RVector<RChannelUserInfo, 8> RChannelUserInfos;

	struct RChannelRoomInfo
	{
		srpc::RUInt16 uint1;
		RRoomTitle title;
		RChatUint1 uint3;
		srpc::RUInt8 uint4;
		srpc::RBool bool5;

		void write(srpc::OStream& ostream);
		void read(srpc::IStream& istream);

	};

	typedef srpc::RVector<RChannelRoomInfo, 8> RChannelRoomInfos;

	struct RFullChannelRoomInfo : public RChannelRoomInfo
	{
		RRoomPass str6;
		srpc::RUInt32 uint7;
		RChannelUserInfos users;

		void write(srpc::OStream& ostream);
		void read(srpc::IStream& istream);

	};

	typedef srpc::RpcStringType<srpc::WString, 384> RMailText;

	struct RMailInfo
	{
		srpc::RUInt32 uint1;
		RNickname title;
		srpc::RUInt32 uint3;
		srpc::RInt32 sint4;
		srpc::RpcIntType<srpc::Int32, 4> sint5;

		void write(srpc::OStream& ostream);
		void read(srpc::IStream& istream);

	};

	typedef srpc::RVector<RMailInfo, 16> RMailInfos;

	struct RStarwars
	{
		srpc::RUInt32 uint1;
		srpc::RpcStringType<srpc::WString, 150> str2;
		srpc::RInt32 sint3;
		srpc::RInt32 sint4;
		srpc::RpcIntType<srpc::Int32, 5> sint5;
		srpc::RpcIntType<srpc::Int32, 5> sint6;
		srpc::RInt32 sint7;
		srpc::RpcIntType<srpc::Int32, 2> sint8;
		srpc::RUInt8 sint9;
		srpc::RpcIntType<srpc::Int32, 5> sint10;
		srpc::RpcIntType<srpc::Int32, 5> sint11;
		srpc::RpcIntType<srpc::Int32, 2> sint12;
		srpc::RUInt16 uint13;
		srpc::RUInt16 uint14;
		srpc::RUInt16 uint15;

		void write(srpc::OStream& ostream);
		void read(srpc::IStream& istream);
		
	};

	typedef srpc::RVector<RStarwars, 3> RStarwarses;

	struct RGameRecords
	{
		srpc::RUInt16 uint1;
		srpc::RUInt16 uint2;
		srpc::RUInt16 uint3;
		srpc::RUInt16 uint4;

		void write(srpc::OStream& ostream);
		void read(srpc::IStream& istream);

	};

	struct RStarwarsParticipant
	{
		RNickname nickname;
		RGameRecords records;
		srpc::RInt32 sint3;

		void write(srpc::OStream& ostream);
		void read(srpc::IStream& istream);

	};

	typedef srpc::RVector<RStarwarsParticipant, 5> RStarwarsParticipants;

	struct RStarwarsCommodity
	{
		srpc::RUInt32 uint1;
		srpc::RpcIntType<srpc::Int32, 5> sint2;
		srpc::RInt32 uint3;
		srpc::RUInt16 uint4;
		srpc::RUInt32 uint5;

		void write(srpc::OStream& ostream);
		void read(srpc::IStream& istream);

	};

	typedef srpc::RMap<srpc::RUInt32, RStarwarsCommodity, 8> RStarwarsCommodities;

	//=====================================================================================================================================

	// Buddy service (for messenger)
	class RpcBuddyService
	{
	public:
		virtual ~RpcBuddyService() { };
		DECLARE_SRPC_PURE_METHOD_1(RpcBuddyService, subscribeBuddy, RNickname, nickname);
		DECLARE_SRPC_PURE_METHOD_1(RpcBuddyService, unsubscribeBuddy, srpc::RUInt32, uint1);
		DECLARE_SRPC_PURE_METHOD_1(RpcBuddyService, blockBuddy, srpc::RUInt32, uint1);
		DECLARE_SRPC_PURE_METHOD_1(RpcBuddyService, unblockBuddy, srpc::RUInt32, uint1);
		DECLARE_SRPC_PURE_METHOD_1(RpcBuddyService, addBuddyGroup, RNickname, nickname);
		DECLARE_SRPC_PURE_METHOD_1(RpcBuddyService, removeBuddyGroup, srpc::RUInt32, uint1);
		DECLARE_SRPC_PURE_METHOD_2(RpcBuddyService, changeBuddyGroupName, srpc::RUInt32, uint1, RNickname, name);
		DECLARE_SRPC_PURE_METHOD_2(RpcBuddyService, classifyBuddy, srpc::RUInt32, uint1, srpc::RUInt32, uint2);
		DECLARE_SRPC_PURE_METHOD_1(RpcBuddyService, getBuddyInfo, srpc::RUInt32, uint1);
		DECLARE_SRPC_PURE_METHOD_1(RpcBuddyService, inviteBuddy, srpc::RUInt32, uint1);
		DECLARE_SRPC_PURE_METHOD_2(RpcBuddyService, onSubscribeBuddy, RErrorCode, error_code, RBuddy, buddy);
		DECLARE_SRPC_PURE_METHOD_2(RpcBuddyService, onUnsubscribeBuddy, RErrorCode, error_code, srpc::RUInt32, uint2);
		DECLARE_SRPC_PURE_METHOD_2(RpcBuddyService, onBlockBuddy, RErrorCode, error_code, srpc::RUInt32, uint2);
		DECLARE_SRPC_PURE_METHOD_2(RpcBuddyService, onUnblockBuddy, RErrorCode, error_code, srpc::RUInt32, uint2);
		DECLARE_SRPC_PURE_METHOD_2(RpcBuddyService, onAddBuddyGroup, RErrorCode, error_code, RBuddyGroup, group);
		DECLARE_SRPC_PURE_METHOD_2(RpcBuddyService, onRemoveBuddyGroup, RErrorCode, error_code, srpc::RUInt32, uint2);
		DECLARE_SRPC_PURE_METHOD_2(RpcBuddyService, onChangeBuddyGroupName, RErrorCode, error_code, RBuddyGroup, group);
		DECLARE_SRPC_PURE_METHOD_3(RpcBuddyService, onClassifyBuddy, RErrorCode, error_code, srpc::RUInt32, uint2, srpc::RUInt32, uint3);
		DECLARE_SRPC_PURE_METHOD_3(RpcBuddyService, onGetBuddyInfo, RErrorCode, error_code, srpc::RUInt32, uint2, RFullCharacter, info);

	};

	// Buddy service event (for messenger)
	class RpcBuddyServiceEvent
	{
	public:
		virtual ~RpcBuddyServiceEvent() { };
		DECLARE_SRPC_PURE_METHOD_2(RpcBuddyServiceEvent, onBuddyRoster, RBuddyGroups, groups, RBuddies, buddies);
		DECLARE_SRPC_PURE_METHOD_2(RpcBuddyServiceEvent, onBuddySubscribed, RNickname, nickname, RPlace, place);
		DECLARE_SRPC_PURE_METHOD_2(RpcBuddyServiceEvent, onBuddyCurrentPlaceChanged, srpc::RUInt32, uint1, RPlace, place);
		DECLARE_SRPC_PURE_METHOD_3(RpcBuddyServiceEvent, onBuddyInvited, srpc::RUInt32, uint1, RPlace, place, RRoomPass, string3);

	};

	// Instant chat service (for messenger)
	class RpcInstantChatService
	{
	public:
		virtual ~RpcInstantChatService() { };
		DECLARE_SRPC_PURE_METHOD_2(RpcInstantChatService, call, RChatVec1, vec1, srpc::RUInt16, uint2);
		DECLARE_SRPC_PURE_METHOD_2(RpcInstantChatService, say, srpc::RUInt16, uint1, RChatMessage, message);
		DECLARE_SRPC_PURE_METHOD_1(RpcInstantChatService, bye, srpc::RUInt16, uint1);
		DECLARE_SRPC_PURE_METHOD_3(RpcInstantChatService, onCall, RErrorCode, error_code, RChatVec1, vec1, srpc::RUInt16, uint2);

	};

	// Instant chat service event (for messenger)
	class RpcInstantChatServiceEvent
	{
	public:
		virtual ~RpcInstantChatServiceEvent() { };
		DECLARE_SRPC_PURE_METHOD_2(RpcInstantChatServiceEvent, onCalled, srpc::RUInt16, uint1, RBaseUserInfos, users);
		DECLARE_SRPC_PURE_METHOD_2(RpcInstantChatServiceEvent, onJoined, srpc::RUInt16, uint1, RBaseUserInfos, users);
		DECLARE_SRPC_PURE_METHOD_3(RpcInstantChatServiceEvent, onSaid, srpc::RUInt16, uint1, srpc::RUInt32, uint2, RChatMessage, message);
		DECLARE_SRPC_PURE_METHOD_2(RpcInstantChatServiceEvent, onBye, srpc::RUInt16, uint1, srpc::RUInt32, uint2);

	};

	// Channel chat service (for messenger)
	class RpcChannelChattingService
	{
	public:
		virtual ~RpcChannelChattingService() { };
		DECLARE_SRPC_PURE_METHOD_3(RpcChannelChattingService, openChannelRoomDoor, RRoomTitle, str1, RRoomPass, str2, RChatUint1, uint3);
		DECLARE_SRPC_PURE_METHOD_2(RpcChannelChattingService, enterChannelRoom, srpc::RUInt16, uint1, RRoomPass, str2);
		DECLARE_SRPC_PURE_METHOD_1(RpcChannelChattingService, leaveChannelRoom, srpc::RUInt16, uint1);
		DECLARE_SRPC_PURE_METHOD_3(RpcChannelChattingService, channelChat, srpc::RUInt16, uint1, srpc::RUInt32, uint2, RChatMessage, message);
		DECLARE_SRPC_PURE_METHOD_2(RpcChannelChattingService, requestChannelRoomList, srpc::RUInt16, uint1, srpc::RUInt8, uint2);
		DECLARE_SRPC_PURE_METHOD_3(RpcChannelChattingService, searchChannelRoomList, RRoomTitle, str1, srpc::RUInt16, uint2, srpc::RUInt8, uint3);
		DECLARE_SRPC_PURE_METHOD_2(RpcChannelChattingService, kickChannelUser, srpc::RUInt16, uint1, srpc::RUInt32, uint2);
		DECLARE_SRPC_PURE_METHOD_2(RpcChannelChattingService, inviteBuddyToChannel, srpc::RUInt16, uint1, srpc::RUInt32, uint2);
		DECLARE_SRPC_PURE_METHOD_4(RpcChannelChattingService, modifyChannelRoom, srpc::RUInt16, uint1, RRoomTitle, str2, RRoomPass, str3, RChatUint1, uint4);
		DECLARE_SRPC_PURE_METHOD_2(RpcChannelChattingService, onOpenChannelRoomDoor, RErrorCode, error_code, RFullChannelRoomInfo, room_info);
		DECLARE_SRPC_PURE_METHOD_2(RpcChannelChattingService, onEnterChannelRoom, RErrorCode, error_code, RFullChannelRoomInfo, room_info);
		DECLARE_SRPC_PURE_METHOD_2(RpcChannelChattingService, onLeaveChannelRoom, RErrorCode, error_code, srpc::RUInt16, uint2);
		DECLARE_SRPC_PURE_METHOD_2(RpcChannelChattingService, onRequestChannelRoomList, RChannelRoomInfos, rooms_list, srpc::RUInt16, uint2);
		DECLARE_SRPC_PURE_METHOD_1(RpcChannelChattingService, onSearchChannelRoomList, RChannelRoomInfo, room_info);
		DECLARE_SRPC_PURE_METHOD_3(RpcChannelChattingService, onKickChannelUser, RErrorCode, error_code, srpc::RUInt16, uint2, srpc::RUInt32, uint3);
		DECLARE_SRPC_PURE_METHOD_1(RpcChannelChattingService, onInviteBuddyToChannel, RErrorCode, error_code);
		DECLARE_SRPC_PURE_METHOD_6(RpcChannelChattingService, onModifyChannelRoom, RErrorCode, error_code, srpc::RUInt16, uint2, RRoomTitle, str3, RRoomPass, str4, RChatUint1, uint5, srpc::RBool, bool5);

	};

	// Channel chat service event (for messenger)
	class RpcChannelChattingServiceEvent
	{
	public:
		virtual ~RpcChannelChattingServiceEvent() { };
		DECLARE_SRPC_PURE_METHOD_2(RpcChannelChattingServiceEvent, onChannelUserEntered, srpc::RUInt16, uint1, RChannelUserInfo, user_info);
		DECLARE_SRPC_PURE_METHOD_2(RpcChannelChattingServiceEvent, onChannelRoomLeft, srpc::RUInt16, uint1, srpc::RUInt32, uint2);
		DECLARE_SRPC_PURE_METHOD_2(RpcChannelChattingServiceEvent, onChannelRoomMasterChanged, srpc::RUInt16, uint1, srpc::RUInt32, uint2);
		DECLARE_SRPC_PURE_METHOD_3(RpcChannelChattingServiceEvent, onChannelChat, srpc::RUInt16, uint1, srpc::RUInt32, uint2, RChatMessage, message);
		DECLARE_SRPC_PURE_METHOD_2(RpcChannelChattingServiceEvent, onChannelUserKicked, srpc::RUInt16, uint1, srpc::RUInt32, uint2);
		DECLARE_SRPC_PURE_METHOD_3(RpcChannelChattingServiceEvent, onChannelUserStateChanged, srpc::RUInt16, uint1, srpc::RUInt32, uint2, srpc::RBool, bool3);
		DECLARE_SRPC_PURE_METHOD_3(RpcChannelChattingServiceEvent, onChannelInvited, srpc::RUInt16, uint1, srpc::RUInt32, uint2, RRoomPass, str3);
		DECLARE_SRPC_PURE_METHOD_4(RpcChannelChattingServiceEvent, onChannelRoomModified, srpc::RUInt16, uint1, RRoomTitle, str2, RChatUint1, uint3, srpc::RBool, bool4);

	};

	// Mail service (for messenger)
	class RpcMailService
	{
	public:
		virtual ~RpcMailService() { };
		DECLARE_SRPC_PURE_METHOD_0(RpcMailService, requestMails);
		DECLARE_SRPC_PURE_METHOD_2(RpcMailService, sendMail, RNickname, nickname, RMailText, text);
		DECLARE_SRPC_PURE_METHOD_4(RpcMailService, sendPresentMail, RNickname, nickname, srpc::RUInt32, uint2, RPayWay, pay_way, RBuyMethod, buy_method);
		DECLARE_SRPC_PURE_METHOD_2(RpcMailService, receivePresentItem, srpc::RUInt32, uint1, RMailType, mail_type);
		DECLARE_SRPC_PURE_METHOD_2(RpcMailService, readMail, srpc::RUInt32, uint1, RMailType, mail_type);
		DECLARE_SRPC_PURE_METHOD_2(RpcMailService, deleteMail, srpc::RUInt32, uint1, RMailType, mail_type);
		DECLARE_SRPC_PURE_METHOD_1(RpcMailService, sendBackMail, srpc::RUInt32, uint1);
		DECLARE_SRPC_PURE_METHOD_2(RpcMailService, onMailList, RMailInfos, mails1, RMailInfos, mails2);
		DECLARE_SRPC_PURE_METHOD_3(RpcMailService, onSendMail, RErrorCode, error_code, RPrice, price, RMailInfo, info);
		DECLARE_SRPC_PURE_METHOD_7(RpcMailService, onReceivePresentItem, RErrorCode, error_code, srpc::RUInt32, uint2, RMailType, mail_type, srpc::RUInt32, uint4, srpc::RUInt32, uint5, srpc::RUInt16, uint6, srpc::RInt32, sint7);
		DECLARE_SRPC_PURE_METHOD_5(RpcMailService, onReadMail, RErrorCode, error_code, srpc::RUInt32, uint2, RMailType, type, RMailText, text, srpc::RUInt32, uint5);
		DECLARE_SRPC_PURE_METHOD_3(RpcMailService, onDeleteMail, RErrorCode, error_code, srpc::RUInt32, uint2, RMailType, type);
		DECLARE_SRPC_PURE_METHOD_2(RpcMailService, onSendBackMail, RErrorCode, error_code, srpc::RUInt32, uint2);

	};

	// Mail service event (for messenger)
	class RpcMailServiceEvent
	{
	public:
		virtual ~RpcMailServiceEvent() { };
		DECLARE_SRPC_PURE_METHOD_2(RpcMailServiceEvent, onMailReceived, RMailType, type, RMailInfo, info);
		DECLARE_SRPC_PURE_METHOD_2(RpcMailServiceEvent, onSentMailStateChanged, srpc::RUInt32, uint1, RMailState, state);
		DECLARE_SRPC_PURE_METHOD_1(RpcMailServiceEvent, onPresentItemReceived, srpc::RUInt32, uint1);

	};

	//=====================================================================================================================================

	// Starwars service (for starwars)
	class RpcStarwarsService
	{
	public:
		virtual ~RpcStarwarsService() { };
		DECLARE_SRPC_PURE_METHOD_0(RpcStarwarsService, requestStarwarsList);
		DECLARE_SRPC_PURE_METHOD_1(RpcStarwarsService, participateStarwars, srpc::RUInt32, uint1);
		DECLARE_SRPC_PURE_METHOD_1(RpcStarwarsService, enterStarwars, srpc::RUInt32, uint1);
		DECLARE_SRPC_PURE_METHOD_0(RpcStarwarsService, leaveStarwars);
		DECLARE_SRPC_PURE_METHOD_1(RpcStarwarsService, challengeStarwars, RGameType, uint1);
		DECLARE_SRPC_PURE_METHOD_0(RpcStarwarsService, unchallengeStarwars);
		DECLARE_SRPC_PURE_METHOD_0(RpcStarwarsService, requestMyStarwarsState);
		DECLARE_SRPC_PURE_METHOD_0(RpcStarwarsService, requestStarwarsRanking);
		DECLARE_SRPC_PURE_METHOD_1(RpcStarwarsService, chargeStar, srpc::RInt32, sint1);
		DECLARE_SRPC_PURE_METHOD_0(RpcStarwarsService, requestStarwarsCommodityList);
		DECLARE_SRPC_PURE_METHOD_1(RpcStarwarsService, exchangeCommodity, srpc::RUInt32, uint1);
		DECLARE_SRPC_PURE_METHOD_1(RpcStarwarsService, onStarwarsList, RStarwarses, list);
		DECLARE_SRPC_PURE_METHOD_3(RpcStarwarsService, onParticipateStarwars, RErrorCode, error_code, srpc::RUInt32, uint2, srpc::RInt32, sint3);
		DECLARE_SRPC_PURE_METHOD_2(RpcStarwarsService, onEnterStarwars, RErrorCode, error_code, srpc::RUInt32, uint2);
		DECLARE_SRPC_PURE_METHOD_1(RpcStarwarsService, onLeaveStarwars, RErrorCode, error_code);
		DECLARE_SRPC_PURE_METHOD_1(RpcStarwarsService, onChallengeStarwars, RErrorCode, error_code);
		DECLARE_SRPC_PURE_METHOD_1(RpcStarwarsService, onUnchallengeStarwars, RErrorCode, error_code);
		DECLARE_SRPC_PURE_METHOD_3(RpcStarwarsService, onMyStarwarsState, RErrorCode, error_code, srpc::RUInt32, uint2, RGameRecords, game_records);
		DECLARE_SRPC_PURE_METHOD_2(RpcStarwarsService, onStarwarsRanking, srpc::RUInt32, uint1, RStarwarsParticipants, participants);
		DECLARE_SRPC_PURE_METHOD_2(RpcStarwarsService, onChargeStar, RErrorCode, error_code, srpc::RInt32, sint2);
		DECLARE_SRPC_PURE_METHOD_1(RpcStarwarsService, onStarwarsCommodityList, RStarwarsCommodities, commodities);
		DECLARE_SRPC_PURE_METHOD_6(RpcStarwarsService, onExchangeCommodity, RErrorCode, error_code, srpc::RUInt32, uint2, srpc::RUInt32, uint3, srpc::RUInt32, uint4, srpc::RUInt16, uint5, srpc::RInt32, sint6);

	};

	// Starwars service event (for starwars)
	class RpcStarwarsServiceEvent
	{
	public:
		virtual ~RpcStarwarsServiceEvent() { };

	};

	//=====================================================================================================================================

	// Account service (for game)
	class RpcAccountService
	{
	public:
		virtual ~RpcAccountService() { };
		DECLARE_SRPC_PURE_METHOD_2(RpcAccountService, login, kudo::RAccountLogin, login, kudo::RAccountPassword, password);
		DECLARE_SRPC_PURE_METHOD_2(RpcAccountService, onLoginResult, RErrorCode, error_code, RFullUserInfo, user_info);

	};

	// Login service (for game)
	class RpcLoginService
	{
	public:
		virtual ~RpcLoginService() { };
		DECLARE_SRPC_PURE_METHOD_0(RpcLoginService, requestCharacterTemplates);
		DECLARE_SRPC_PURE_METHOD_4(RpcLoginService, activateAccount, RNickname, nickname, srpc::RUInt16, unk_u16, RCharStyleId, char_style_id, RUnkVect1, unk_vect_u32);
		DECLARE_SRPC_PURE_METHOD_3(RpcLoginService, onCharacterTemplates, RCharacterTemplates, templates, RCharacterStyles, styles, RRawWearItems, items);
		DECLARE_SRPC_PURE_METHOD_2(RpcLoginService, onActivateAccount, RErrorCode, error_code, RFullUserInfo, user_info);

	};

	// User service (for game)
	class RpcUserService
	{
	public:
		virtual ~RpcUserService() { };
		DECLARE_SRPC_PURE_METHOD_0(RpcUserService, requestFullUserInfo);
		DECLARE_SRPC_PURE_METHOD_1(RpcUserService, onFullUserInfo, RFullUserInfo, user_info);

	};

	// Game mode service (for game)
	class RpcGameModeService
	{
	public:
		virtual ~RpcGameModeService() { };
		DECLARE_SRPC_PURE_METHOD_1(RpcGameModeService, enterGameMode, RGameMode, game_mode);
		DECLARE_SRPC_PURE_METHOD_0(RpcGameModeService, leaveGameMode);
		DECLARE_SRPC_PURE_METHOD_2(RpcGameModeService, onEnterGameMode, RErrorCode, error_code, RGameMode, game_mode);
		DECLARE_SRPC_PURE_METHOD_1(RpcGameModeService, onLeaveGameMode, RErrorCode, error_code);

	};

	// Game service (for game)
	class RpcGameService
	{
	public:
		virtual ~RpcGameService() { };
		DECLARE_SRPC_PURE_METHOD_3(RpcGameService, openGameRoomDoor, RRoomTitle, title, RGameType, game_type, RRoomPass, pass);
		DECLARE_SRPC_PURE_METHOD_3(RpcGameService, requestGameRoomList, RGameRoomType, game_room_type, srpc::RUInt16, uint2, srpc::RUInt8, limit);
		DECLARE_SRPC_PURE_METHOD_2(RpcGameService, enterGameRoom, srpc::RUInt16, uint1, RRoomPass, str2);
		DECLARE_SRPC_PURE_METHOD_0(RpcGameService, leaveGameRoom);
		DECLARE_SRPC_PURE_METHOD_1(RpcGameService, requestQuickJoinableRoomId, RGameType, game_type);
		DECLARE_SRPC_PURE_METHOD_0(RpcGameService, requestGameRoomPlayerList);
		DECLARE_SRPC_PURE_METHOD_1(RpcGameService, chat, RChatMessage, message);
		DECLARE_SRPC_PURE_METHOD_1(RpcGameService, selectGameRoomSlot, RGameRoomSlot, game_room_slot);
		DECLARE_SRPC_PURE_METHOD_0(RpcGameService, toggleReadyFlag);
		DECLARE_SRPC_PURE_METHOD_1(RpcGameService, setGameRules, RGameRules, game_rules);
		DECLARE_SRPC_PURE_METHOD_1(RpcGameService, kick, srpc::RUInt32, player_id);
		DECLARE_SRPC_PURE_METHOD_1(RpcGameService, startGame, RAddressPairs, addresses);
		DECLARE_SRPC_PURE_METHOD_0(RpcGameService, playGame);
		DECLARE_SRPC_PURE_METHOD_1(RpcGameService, stopGame, RGameResult, game_result);
		DECLARE_SRPC_PURE_METHOD_1(RpcGameService, cancelGame, RGameCancelReason, cancel_reason);
		DECLARE_SRPC_PURE_METHOD_0(RpcGameService, inviteWaiter);
		DECLARE_SRPC_PURE_METHOD_2(RpcGameService, onOpenGameRoomDoor, RErrorCode, error_code, srpc::RUInt16, room_number);
		DECLARE_SRPC_PURE_METHOD_2(RpcGameService, onGameRoomList, RSimpleGameRoomInfos, rooms_info, srpc::RUInt16, rooms_count);
		DECLARE_SRPC_PURE_METHOD_3(RpcGameService, onEnterGameRoom, RErrorCode, error_code, srpc::RUInt16, room_number, RGameRoomSlot, room_slot);
		DECLARE_SRPC_PURE_METHOD_2(RpcGameService, onLeaveGameRoom, RErrorCode, error_code, srpc::RUInt16, room_number);
		DECLARE_SRPC_PURE_METHOD_1(RpcGameService, onQuickJoinableRoomId, srpc::RUInt16, room_number);
		DECLARE_SRPC_PURE_METHOD_3(RpcGameService, onGameRoomPlayerList, srpc::RUInt16, room_number, srpc::RUInt32, master_uid, RPlayersInfo, players_info);
		DECLARE_SRPC_PURE_METHOD_3(RpcGameService, onSelectGameRoomSlot, RErrorCode, error_code, srpc::RUInt16, room_number, RGameRoomSlot, room_slot);
		DECLARE_SRPC_PURE_METHOD_2(RpcGameService, onToggleReadyFlag, srpc::RUInt16, room_number, srpc::RBool, ready_flag);
		DECLARE_SRPC_PURE_METHOD_2(RpcGameService, onSetGameRules, srpc::RUInt16, room_number, RErrorCode, error_code);
		DECLARE_SRPC_PURE_METHOD_2(RpcGameService, onStartGame, srpc::RUInt16, room_number, RErrorCode, error_code);
		DECLARE_SRPC_PURE_METHOD_2(RpcGameService, onPlayGame, srpc::RUInt16, room_number, RErrorCode, error_code);
		DECLARE_SRPC_PURE_METHOD_2(RpcGameService, onStopGame, srpc::RUInt16, room_number, RErrorCode, error_code);
		DECLARE_SRPC_PURE_METHOD_2(RpcGameService, onCancelGame, srpc::RUInt16, room_number, RErrorCode, error_code);

	};

	// Game service event (for game)
	class RpcGameServiceEvent
	{
	public:
		virtual ~RpcGameServiceEvent() { };
		DECLARE_SRPC_PURE_METHOD_2(RpcGameServiceEvent, onGameRoomInfo, srpc::RUInt16, room_number, RFullGameRoomInfo, room_info);
		DECLARE_SRPC_PURE_METHOD_2(RpcGameServiceEvent, onGameRoomUserEntered, srpc::RUInt16, room_number, RPlayerInfo, player_info);
		DECLARE_SRPC_PURE_METHOD_2(RpcGameServiceEvent, onGameRoomUserLeft, srpc::RUInt16, room_number, srpc::RUInt32, player_uid);
		DECLARE_SRPC_PURE_METHOD_2(RpcGameServiceEvent, onChat, srpc::RUInt32, player_uid, RChatMessage, message);
		DECLARE_SRPC_PURE_METHOD_3(RpcGameServiceEvent, onMasterChanged, srpc::RUInt16, room_number, srpc::RUInt32, player_uid, srpc::RBool, unk_bool);
		DECLARE_SRPC_PURE_METHOD_3(RpcGameServiceEvent, onGameRoomSlotSelected, srpc::RUInt16, room_number, srpc::RUInt32, player_uid, RGameRoomSlot, room_slot);
		DECLARE_SRPC_PURE_METHOD_3(RpcGameServiceEvent, onGameRoomReadyFlagToggled, srpc::RUInt16, room_number, srpc::RUInt32, player_uid, srpc::RBool, ready_flag);
		DECLARE_SRPC_PURE_METHOD_2(RpcGameServiceEvent, onGameRulesChanged, srpc::RUInt16, room_number, RGameRules, game_rules);
		DECLARE_SRPC_PURE_METHOD_2(RpcGameServiceEvent, onKicked, srpc::RUInt16, room_number, srpc::RUInt32, player_uid);
		DECLARE_SRPC_PURE_METHOD_2(RpcGameServiceEvent, onGameSlotsArranged, srpc::RUInt16, room_number, RDetailedSlotInfos, slots_info);
		DECLARE_SRPC_PURE_METHOD_3(RpcGameServiceEvent, onGameStarted, srpc::RUInt16, room_number, RAddressPairs, start_addresses, RBaseCharacters, characters);
		DECLARE_SRPC_PURE_METHOD_1(RpcGameServiceEvent, onGamePlayed, srpc::RUInt16, room_number);
		DECLARE_SRPC_PURE_METHOD_2(RpcGameServiceEvent, onGameStopped, srpc::RUInt16, room_number, RDetailedGameResult, game_result);
		DECLARE_SRPC_PURE_METHOD_2(RpcGameServiceEvent, onGameCanceled, srpc::RUInt16, room_number, RGameCancelReason, reason);
		DECLARE_SRPC_PURE_METHOD_2(RpcGameServiceEvent, onInvited, srpc::RUInt16, room_number, RRoomPass, str2);
		DECLARE_SRPC_PURE_METHOD_3(RpcGameServiceEvent, onWargerGameRulesChanged, srpc::RUInt16, room_number, RWagerRules, game_rules, RWagerReason, reason);

	};

	// Item service (for game)
	class RpcItemService
	{
	public:
		virtual ~RpcItemService() { };
		DECLARE_SRPC_PURE_METHOD_0(RpcItemService, requestItems);
		DECLARE_SRPC_PURE_METHOD_3(RpcItemService, buyItem, srpc::RUInt32, uint1, RPayWay, pay_way, RBuyMethod, buy_method);
		DECLARE_SRPC_PURE_METHOD_4(RpcItemService, buyCharacter, srpc::RUInt16, uint1, RCharStyleId, char_style, RUnkVect1, vect3, RPayWay, pay_way);
		DECLARE_SRPC_PURE_METHOD_2(RpcItemService, sellItem, srpc::RUInt32, uint1, RItemType, item_type);
		DECLARE_SRPC_PURE_METHOD_2(RpcItemService, destroyItem, srpc::RUInt32, uint1, RItemType, item_type);
		DECLARE_SRPC_PURE_METHOD_2(RpcItemService, restoreItem, srpc::RUInt32, uint1, RItemType, item_type);
		DECLARE_SRPC_PURE_METHOD_2(RpcItemService, adornCharacter, srpc::RUInt32, uint1, RUnkVect1, vect2);
		DECLARE_SRPC_PURE_METHOD_5(RpcItemService, onItems, RUnkVect1, vect1, RUnkVect1, vect2, RUnkVect1, vect3, RUnkVect1, vect4, RUnkVect2, vect5);
		DECLARE_SRPC_PURE_METHOD_6(RpcItemService, onBuyItem, RErrorCode, error_code, srpc::RUInt32, uint2, srpc::RUInt32, uint3, srpc::RUInt16, uint4, srpc::RInt32, sint5, RPrice, price);
		DECLARE_SRPC_PURE_METHOD_3(RpcItemService, onBuyCharacter, RErrorCode, error_code, RFullCharacter, character_info, RPrice, price);
		DECLARE_SRPC_PURE_METHOD_4(RpcItemService, onSellItem, RErrorCode, error_code, srpc::RUInt32, uint2, RItemType, item_type, srpc::RInt32, sint4);
		DECLARE_SRPC_PURE_METHOD_3(RpcItemService, onDestroyItem, RErrorCode, error_code, srpc::RUInt32, uint2, RItemType, item_type);
		DECLARE_SRPC_PURE_METHOD_3(RpcItemService, onRestoreItem, RErrorCode, error_code, srpc::RUInt32, uint2, RItemType, item_type);
		DECLARE_SRPC_PURE_METHOD_4(RpcItemService, onAdornCharacter, RErrorCode, error_code, srpc::RUInt32, uint2, RCharacter::RItems, char_items, RWearItems, wear_items);

	};

	// Item service event (for game)
	class RpcItemServiceEvent
	{
	public:
		virtual ~RpcItemServiceEvent() { };
		DECLARE_SRPC_PURE_METHOD_4(RpcItemServiceEvent, onCharacterAdorned, srpc::RUInt16, uint1, srpc::RUInt32, uint2, srpc::RUInt32, uint3, RUnkVect1, vect4);
		DECLARE_SRPC_PURE_METHOD_4(RpcItemServiceEvent, onItemVanished, srpc::RUInt16, uint1, srpc::RUInt32, uint2, srpc::RUInt32, uint3, RUnkVect1, vect4);
		DECLARE_SRPC_PURE_METHOD_3(RpcItemServiceEvent, onMapItemVanished, srpc::RUInt16, uint1, srpc::RUInt32, uint2, RUnkVect1, vect4);

	};

	// AI service (for game)
	class RpcAiService
	{
	public:
		virtual ~RpcAiService() { };
		DECLARE_SRPC_PURE_METHOD_0(RpcAiService, callAiPartner);
		DECLARE_SRPC_PURE_METHOD_0(RpcAiService, cancelAiPartner);
		DECLARE_SRPC_PURE_METHOD_1(RpcAiService, onCallAiPartner, RErrorCode, error_code);
		DECLARE_SRPC_PURE_METHOD_1(RpcAiService, onCancelAiPartner, RErrorCode, error_code);

	};

	// AI service event (for game)
	class RpcAiServiceEvent
	{
	public:
		virtual ~RpcAiServiceEvent() { };
		DECLARE_SRPC_PURE_METHOD_3(RpcAiServiceEvent, onAiPartnerCalled, srpc::RUInt16, uint1, srpc::RUInt32, uint2, srpc::RUInt32, uint3);
		DECLARE_SRPC_PURE_METHOD_2(RpcAiServiceEvent, onAiPartnerCanceled, srpc::RUInt16, uint1, srpc::RUInt32, uint2);

	};

	// Character service (for game)
	class RpcCharacterService
	{
	public:
		virtual ~RpcCharacterService() { };
		DECLARE_SRPC_PURE_METHOD_2(RpcCharacterService, castCharacter, srpc::RUInt32, uint1, RCharacterType, char_type);
		DECLARE_SRPC_PURE_METHOD_1(RpcCharacterService, onCastCharacter, RErrorCode, error_code);

	};

	// Character service event (for game)
	class RpcCharacterServiceEvent
	{
	public:
		virtual ~RpcCharacterServiceEvent() { };

	};

	// Training service (for game)
	class RpcTrainingService
	{
	public:
		virtual ~RpcTrainingService() { };
		DECLARE_SRPC_PURE_METHOD_2(RpcTrainingService, startStrokeTraining, RStrokeTrainingType, training_type, RAbilityType, ability_type);
		DECLARE_SRPC_PURE_METHOD_1(RpcTrainingService, stopStrokeTraining, srpc::RUInt16, uint1);
		DECLARE_SRPC_PURE_METHOD_2(RpcTrainingService, onEnterTrainingRoom, RStrokeTrainingRankings, rankings, RStrokeTrainingTargetScores, target_scores);
		DECLARE_SRPC_PURE_METHOD_3(RpcTrainingService, onStartStrokeTraining, RErrorCode, error_code, RStrokeTrainingType, training_type, RAbilityType, ability_type);
		DECLARE_SRPC_PURE_METHOD_6(RpcTrainingService, onStopStrokeTraining, RErrorCode, error_code, srpc::RUInt16, uint2, srpc::RInt32, sint3, srpc::RInt32, sint4, RTrainingPoints, points, RUnkTraining1, uint6);

	};

	// Manager service event (for game)
	class RpcManagerServiceEvent
	{
	public:
		virtual ~RpcManagerServiceEvent() { };
		DECLARE_SRPC_PURE_METHOD_1(RpcManagerServiceEvent, onUrgentNotice, RNoticeString, text);
		DECLARE_SRPC_PURE_METHOD_1(RpcManagerServiceEvent, onGeneralNotices, RNoticeStrings, texts);
		DECLARE_SRPC_PURE_METHOD_1(RpcManagerServiceEvent, onExpelled, RErrorCode, error_code);

	};

	// Xtrap service (for game)
	class RpcXtrapService
	{
	public:
		virtual ~RpcXtrapService() { };
		DECLARE_SRPC_PURE_METHOD_1(RpcXtrapService, xTrapCCStep2, RXtrapBytes, bytes);
		DECLARE_SRPC_PURE_METHOD_1(RpcXtrapService, xTrapCCStep1, RXtrapBytes, bytes);

	};

	// Xtrap service event (for game)
	class RpcXtrapServiceEvent
	{
	public:
		virtual ~RpcXtrapServiceEvent() { };

	};
}

//=========================================================================================================================================

#include "KudoRpc.ipp"