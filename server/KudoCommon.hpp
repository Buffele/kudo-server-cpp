#pragma once

#include <inttypes.h>

//=========================================================================================================================================

namespace kudo
{
	enum ErrorCode : uint16_t
	{
		// General
		EC_None = 0,
		EC_NotAvailable = 5,
		EC_ExpelByGm = 6,
		EC_ExpelByOtherUser = 7,
		// Login
		EC_LoginFailed = 10,
		EC_CertificateFailed = 11,
		EC_NotAuthenticated = 12,
		EC_CannotFetchUserInfo = 13,
		EC_NicknameIsAlreadySet = 14,
		EC_DuplicatedNickname = 15,
		EC_AccountAlreadyIsActivated = 16,
		EC_InvalidCharStyle = 17,
		EC_InvalidBaseWearItems = 18,
		EC_NicknameCheck = 19,
		EC_AlreadyLoggedIn = 20,
		EC_ServerIsFull = 21,
		EC_NicknameIsNotSet = 22,
		EC_InvalidCharacterId = 23,
		EC_CurrentCharacterNotFound = 24,
		EC_UnactivatedAccount = 25,
		// Room (lobby, game room, training room)
		EC_NotInLobby = 30,
		EC_NotInTrainingRoom = 31,
		// GameRoom
		EC_OpenGameRoomDoorFailed = 35,
		EC_NoGameRoomClosed = 36,
		EC_InvalidGameType = 39,
		EC_GameRoomNotExist = 40,
		EC_AlreadyEntered = 41,
		EC_TooManyPlayers = 42,
		EC_CanEnterOnlyOneGameRoom = 43,
		EC_InvalidGameRoomPassword = 44,
		EC_NotAllowedGrade = 45,
		EC_NotEntered = 50,
		EC_NotPlayer = 51,
		EC_NoPermission = 60,
		EC_NotAllowedGameType = 71,
		EC_InvalidSlot = 72,
		EC_NotEnoughPlayers = 80,
		EC_NoReady = 81,
		EC_GameStarted = 82,
		EC_GameNotStarted = 83,
		EC_GamePlaying = 84,
		EC_InvalidGameResult = 85,
		EC_InvalidGameCancelReason = 86,
		EC_CannotLeaveGameRoomOnReady = 87,
		EC_CannotSelectGameRoomSlotOnReady = 88,
		EC_CannotGameStartHasNotMap = 89,
		EC_NotRegistMap = 90,
		// Item
		EC_InvalidItem = 100,
		EC_TooManyWearItems = 101,
		EC_CannotAdornDefaultWearItem = 102,
		EC_SameWearItems = 104,
		EC_OtherCharacterWearItem = 105,
		EC_HighGradeWearItem = 106,
		EC_AiCantUseItem = 107,
		EC_CannotAdornOnReady = 108,
		EC_CannotAdornOnGameStarted = 109,
		EC_CannotUseItemShopInGameRoom = 110,
		EC_NotBuyableItem = 111,
		EC_NotSellableItem = 112,
		EC_NotDestructibleItem = 113,
		EC_CannotSellWearingItem = 114,
		EC_CannotDestroyWearingItem = 115,
		EC_CannotAdornAlreadyWearingItem = 116,
		EC_InvalidBuyMethod = 117,
		EC_HaveNoEnoughCash = 118,
		// Waget
		EC_WrongRangeWagerKu = 150,
		EC_InsufficientKuFordecreasedWagerKu = 151,
		EC_CannotStartWagerGameRoomInAiChar = 152,
		EC_InsufficientKuForChangedFriendShipGame = 153,
		EC_InsufficientKuStartGame = 154,
		// Character
		EC_NotAllowedCharacterType = 210,
		EC_CannotCastInGameRoom = 211,
		EC_NoAiPartner = 213,
		EC_TeamSlotsAreFull = 214,
		EC_CantSelectGameRoomSlotWithAiPartner = 215,
		EC_AiPartnerIsNotCalled = 216,
		EC_CannnotCallAiPartnerOnReady = 217,
		EC_AlreadyOwnedCharacter = 218,
		EC_NotBuyableCharacter = 219,
		EC_InvalidCharacterTemplateId = 220,
		EC_ThereIsPendingRequest = 300,
		// Training
		EC_InvalidStrokeTrainingType = 1000,
		EC_InvalidStrokeTrainingAbilityType = 1001,
		EC_TrainingAlreadyStarted = 1002,
		EC_TrainingNotStarted = 1003,
		EC_HaveNoEnoughGameMoney = 1004,
		EC_HaveNoTp = 1005,
		EC_TrainingNotStopped = 1006,
		// Messenger
		EC_AlreadySubscribedBuddy = 1101,
		EC_TooManyBuddies = 1102,
		EC_NicknameNotFound = 1103,
		EC_UnsubscribedBuddy = 1104,
		EC_NotBlockedBuddy = 1105,
		EC_DuplicatedBuddyGroup = 1106,
		EC_TooManyBuddyGroups = 1107,
		EC_BuddyGroupNotFound = 1108,
		EC_CannotChangeDefaultBuddyGroupName = 1109,
		EC_CannotRemoveDefaultBuddyGroup = 1110,
		EC_BuddyIsNotLoggedIn = 1111,
		EC_NotRealBuddy = 1112,
		EC_InstantChatNotExist = 1113,
		EC_InstantChatAlreadyExist = 1114,
		EC_InstantChatNotJoined = 1115,
		EC_BuddyAlreadyJoined = 1116,
		EC_CannotCallOneSelf = 1117,
		EC_CannotSubscribeOneSelf = 1118,
		EC_InstantChatIsFull = 1119,
		EC_BuddyIsBusy = 1120,
		// Channel Chatting
		EC_TooBigMaxSlotCount = 1200,
		EC_InvalidChannelRoomPassword = 1201,
		EC_TooManyChatters = 1202,
		EC_AlreadyChannelRoomEntered = 1203,
		EC_BuddyAlreadyChannelRoomEntered = 1204,
		EC_TooManyChannelRoomEntered = 1205,
		EC_ChannelRoomNotExist = 1206,
		EC_InvalidChannelMasterAuthority = 1207,
		EC_TooManyChannelRooms = 1208,
		EC_TooSmallMaxSlotCount = 1209,
		EC_ChannelRoomTitleEmpty = 1210,
		// Mail
		EC_InvalidMailId = 1300,
		EC_MailNotExist = 1301,
		EC_AlreadyReadMail = 1302,
		EC_InvalidMailType = 1303,
		EC_HaveNoPresentItem = 1304,
		EC_HavePresentItemNoDelete = 1305,
		EC_NoSentBackMailNoPresentItemReceived = 1306,
		EC_GeneralMailCannotSendBack = 1307,
		EC_NotPresentableItem = 1308,
		EC_CannotSendMailToOneSelf = 1309,
		EC_NicknameisnotinDB = 1310,
		// Game mode
		EC_InvalidGameMode = 1400,
		EC_AlreadyEnteredGameMode = 1401,
		EC_NotEnteredGameMode = 1402,
		EC_NotEnteredPlayableGameMode = 1403,
		EC_CannotLeaveGameModeInGameRoom = 1404,
		// Starwars
		EC_NotInStarwarsGameMode = 1500,
		EC_StarwarsNotExist = 1501,
		EC_AlreadyEnteredStarwars = 1502,
		EC_NotEnteredStarwars = 1503,
		EC_NotStarwarsParticipated = 1504,
		EC_AlreadyStarwarsParticipated = 1505,
		EC_CannotParticipateBecauseNoTimeLeft = 1506,
		EC_AlreadyStarwarsChallenged = 1507,
		EC_NotChallengedStarwars = 1508,
		EC_CannotLeaveStarwarsInGameRoom = 1509,
		EC_CannotChallengeWithoutStar = 1510,
		EC_CannotCastOnStarwarsParticipation = 1511,
		EC_CannotChargeStarIfStarIsNotEmpty = 1512,
		EC_NotAllowedStarChargingCount = 1513,
		EC_CannotChargeStarInGameRoom = 1514,
		EC_InvalidCommodityId = 1515,
		EC_HaveNoEnoughStar = 1516,
		EC_GameRecordsNotMatched = 1517,
		EC_CannotParticipateWithSameCharacter = 1518,
		EC_StarwarsIsNotInProgress = 1519,
		// Client
		EC_FailedToConnect = 20001,
		EC_Disconnected = 20002,
		EC_Timeout = 20003,
		EC_SendError = 20004,
		EC_ReceiveError1 = 20005,
		EC_ReceiveError2 = 20006,
		EC_ExitUnknownError = 20020,
		EC_ExitP2pMisSync = 20021,
		EC_ExitLeaving = 20022,
		EC_ExitInvalidGameResult = 20023,
		EC_ExitServerDisconnect = 20024,
		// Server
		EC_LoginServerIsDown = 32700,
		EC_AssistServerIsDown = 32701,
		EC_MessengerServerIsDown = 32702,
		EC_NoAvailableGameServer = 32764,
		EC_RelayServiceFailed = 32765,
		EC_InternalDatabaseError = 32766,
		EC_InternalServerError = 32767,
	};

	enum GameMode : uint32_t
	{
		GM_Unknown = 0,
		GM_FreeMatch = 1,
		GM_RankingMatch = 2,
		GM_Training = 3,
		GM_Starwars = 4,
	};

	enum GameType : uint32_t
	{
		GT_Singles = 0, // 1 vs 1
		GT_Doubles = 1, // 2 vs 2
	};

	enum GameRoomType : uint32_t
	{
	};

	enum GameCancelReason : uint32_t
	{
	};

	enum WagerReason : uint32_t
	{
	};

	enum PayWay : int32_t
	{
	};

	enum BuyMethod : int32_t
	{
	};

	enum ItemType : int32_t
	{
		IT_WearableItem = 1,
		IT_Map = 4,
		IT_SetItem = 9,
	};

	enum CharacterType : int32_t
	{
	};

	enum StrokeTrainingType : int32_t
	{
	};

	enum AbilityType : int32_t
	{
	};

	enum MailType : int32_t
	{
	};

	enum MailState : int32_t
	{
	};

	typedef int16_t CharStyleId;

	union ItemCode
	{
		uint32_t full;
		struct
		{
			uint32_t number : 16; // 0..16
			uint32_t sub_type : 4; // accessory_type 16..20
			uint32_t type : 4; // 20..24
			uint32_t char_index : 8; // 24..32
		};
	};

	inline uint32_t buildItemCode(uint16_t char_index, ItemType type, uint8_t sub_type/*accesory_type*/, uint16_t number)
	{
		return (((uint32_t)number & 0xFFFF) << 0) |
			(((uint32_t)sub_type & 0xF) << 16) |
			(((uint32_t)type & 0xF) << 20) |
			(((uint32_t)char_index & 0xFF) << 24);
	}

	inline void parseItemCode(uint32_t item_code, uint16_t& char_index, ItemType& type, uint8_t& sub_type/*accesory_type*/, uint16_t& number)
	{
		number = (uint16_t)((item_code >> 0) & 0xFFFF);
		sub_type = (uint8_t)((item_code >> 16) & 0xF);
		type = (ItemType)((item_code >> 20) & 0xF);
		char_index = (uint16_t)((item_code >> 24) & 0xFF);
	}
}

//=========================================================================================================================================