#pragma once

//=========================================================================================================================================

inline void kudo::RCharacter::write(srpc::OStream& ostream)
{
	person.write(ostream);
	for (size_t i = 0; i < 6; i++)
		status[i].write(ostream);
	bool3.write(ostream);
	visible.write(ostream);
}
inline void kudo::RCharacter::read(srpc::IStream& istream)
{
	person.read(istream);
	for (size_t i = 0; i < 6; i++)
		status[i].read(istream);
	bool3.read(istream);
	visible.read(istream);
}

inline void kudo::RCharacter::RItem::write(srpc::OStream& ostream)
{
	uint1.write(ostream);
	uint2.write(ostream);
}
inline void kudo::RCharacter::RItem::read(srpc::IStream& istream)
{
	uint1.read(istream);
	uint2.read(istream);
}

inline void kudo::RBaseCharacter::write(srpc::OStream& ostream)
{
	RCharacter::write(ostream);
	uint5.write(ostream);
	sint6.write(ostream);
	uint7.write(ostream);
	sint8.write(ostream);
}
inline void kudo::RBaseCharacter::read(srpc::IStream& istream)
{
	RCharacter::read(istream);
	uint5.read(istream);
	sint6.read(istream);
	uint7.read(istream);
	sint8.read(istream);
}

inline void kudo::RSubInfo2::write(srpc::OStream& ostream)
{
	uint1.write(ostream);
	uint2.write(ostream);
	uint3.write(ostream);
	uint4.write(ostream);
}
inline void kudo::RSubInfo2::read(srpc::IStream& istream)
{
	uint1.read(istream);
	uint2.read(istream);
	uint3.read(istream);
	uint4.read(istream);
}

inline void kudo::RFullCharacter::write(srpc::OStream& ostream)
{
	RCharacter::write(ostream);
	id.write(ostream);
	type.write(ostream);
	exp.write(ostream);
	minor_grade.write(ostream);
	items9.write(ostream);
	vect10.write(ostream);
	map11.write(ostream);
	uint12.write(ostream);
	uint13.write(ostream);
}
inline void kudo::RFullCharacter::read(srpc::IStream& istream)
{
	RCharacter::read(istream);
	id.read(istream);
	type.read(istream);
	exp.read(istream);
	minor_grade.read(istream);
	items9.read(istream);
	vect10.read(istream);
	map11.read(istream);
	uint12.read(istream);
	uint13.read(istream);
}

inline void kudo::RSubInfo3::write(srpc::OStream& ostream)
{
	item_code.write(ostream);
	sint2.write(ostream);
	bool3.write(ostream);
	bool4.write(ostream);
	bool5.write(ostream);
	bool6.write(ostream);
	bool7.write(ostream);
	sint8.write(ostream);
	sint9.write(ostream);
	for (size_t i = 0; i < 6; i++)
		uints10[i].write(ostream);
}
inline void kudo::RSubInfo3::read(srpc::IStream& istream)
{
	item_code.read(istream);
	sint2.read(istream);
	bool3.read(istream);
	bool4.read(istream);
	bool5.read(istream);
	bool6.read(istream);
	bool7.read(istream);
	sint8.read(istream);
	sint9.read(istream);
	for (size_t i = 0; i < 6; i++)
		uints10[i].read(istream);
}

inline void kudo::RWearItem::write(srpc::OStream& ostream)
{
	RSubInfo3::write(ostream);
	uint11.write(ostream);
	uint12.write(ostream);
	bool13.write(ostream);
	sint14.write(ostream);
	uint15.write(ostream);
	uint16.write(ostream);
}
inline void kudo::RWearItem::read(srpc::IStream& istream)
{
	RSubInfo3::read(istream);
	uint11.read(istream);
	uint12.read(istream);
	bool13.read(istream);
	sint14.read(istream);
	uint15.read(istream);
	uint16.read(istream);
}

inline void kudo::RUnk1Item::write(srpc::OStream& ostream)
{
	RSubInfo3::write(ostream);
	uint11.write(ostream);
	uint12.write(ostream);
	uint13.write(ostream);
	bool14.write(ostream);
	sint15.write(ostream);
	uint16.write(ostream);
	sint17.write(ostream);
}
inline void kudo::RUnk1Item::read(srpc::IStream& istream)
{
	RSubInfo3::read(istream);
	uint11.read(istream);
	uint12.read(istream);
	uint13.read(istream);
	bool14.read(istream);
	sint15.read(istream);
	uint16.read(istream);
	sint17.read(istream);
}

inline void kudo::RRawWearItem::write(srpc::OStream& ostream)
{
	RSubInfo3::write(ostream);
	uint11.write(ostream);
}
inline void kudo::RRawWearItem::read(srpc::IStream& istream)
{
	RSubInfo3::read(istream);
	uint11.read(istream);
}

inline void kudo::RUnkInfo4::write(srpc::OStream& ostream)
{
	uint1.write(ostream);
	uint2.write(ostream);
	uint3.write(ostream);
	uint4.write(ostream);
	uint5.write(ostream);
	uint6.write(ostream);
	uint7.write(ostream);
	uint8.write(ostream);
	uint9.write(ostream);
	uint10.write(ostream);
	uint11.write(ostream);
	uint12.write(ostream);
	uint13.write(ostream);
	uint14.write(ostream);
}
inline void kudo::RUnkInfo4::read(srpc::IStream& istream)
{
	uint1.read(istream);
	uint2.read(istream);
	uint3.read(istream);
	uint4.read(istream);
	uint5.read(istream);
	uint6.read(istream);
	uint7.read(istream);
	uint8.read(istream);
	uint9.read(istream);
	uint10.read(istream);
	uint11.read(istream);
	uint12.read(istream);
	uint13.read(istream);
	uint14.read(istream);
}

inline void kudo::RUnkInfo5::write(srpc::OStream& ostream)
{
	RUnkInfo4::write(ostream);
	uint15.write(ostream);
	uint16.write(ostream);
	uint17.write(ostream);
	uint18.write(ostream);
	uint19.write(ostream);
	uint20.write(ostream);
	uint21.write(ostream);
}
inline void kudo::RUnkInfo5::read(srpc::IStream& istream)
{
	RUnkInfo4::read(istream);
	uint15.read(istream);
	uint16.read(istream);
	uint17.read(istream);
	uint18.read(istream);
	uint19.read(istream);
	uint20.read(istream);
	uint21.read(istream);
}

inline void kudo::RFullUserInfo::write(srpc::OStream& ostream)
{
	uid.write(ostream);
	nickname.write(ostream);
	str3.write(ostream);
	characters.write(ostream);
	sint5.write(ostream);
	sint6.write(ostream);
	wear_items.write(ostream);
	items8.write(ostream);
	data9.write(ostream);
}
inline void kudo::RFullUserInfo::read(srpc::IStream& istream)
{
	uid.read(istream);
	nickname.read(istream);
	str3.read(istream);
	characters.read(istream);
	sint5.read(istream);
	sint6.read(istream);
	wear_items.read(istream);
	items8.read(istream);
	data9.read(istream);
}

inline void kudo::RCharacterTemplate::write(srpc::OStream& ostream)
{
	RCharacter::write(ostream);
	sint5.write(ostream);
	sint6.write(ostream);
	sint7.write(ostream);
	uint8.write(ostream);
	uint9.write(ostream);
}
inline void kudo::RCharacterTemplate::read(srpc::IStream& istream)
{
	RCharacter::read(istream);
	sint5.read(istream);
	sint6.read(istream);
	sint7.read(istream);
	uint8.read(istream);
	uint9.read(istream);
}

inline void kudo::RCharacterStyle::write(srpc::OStream& ostream)
{
	uint1.write(ostream);
	sint2.write(ostream);
	for (size_t i = 0; i < 6; i++)
		uints3[i].write(ostream);
}
inline void kudo::RCharacterStyle::read(srpc::IStream& istream)
{
	uint1.read(istream);
	sint2.read(istream);
	for (size_t i = 0; i < 6; i++)
		uints3[i].read(istream);
}

inline void kudo::RGameRules::write(srpc::OStream& ostream)
{
	match_mode.write(ostream);
	set_count.write(ostream);
	game_count.write(ostream);
	bool4.write(ostream);
	bool5.write(ostream);
	bool6.write(ostream);
	map_id.write(ostream);
	sint8.write(ostream);
	sint9.write(ostream);
}
inline void kudo::RGameRules::read(srpc::IStream& istream)
{
	match_mode.read(istream);
	set_count.read(istream);
	game_count.read(istream);
	bool4.read(istream);
	bool5.read(istream);
	bool6.read(istream);
	map_id.read(istream);
	sint8.read(istream);
	sint9.read(istream);
}

inline void kudo::RWagerRules::write(srpc::OStream& ostream)
{
	sint1.write(ostream);
	sint2.write(ostream);
}
inline void kudo::RWagerRules::read(srpc::IStream& istream)
{
	sint1.read(istream);
	sint2.read(istream);
}

inline void kudo::RPlayerReward::write(srpc::OStream& ostream)
{
	player_uid.write(ostream);
	uint2.write(ostream);
	game_mode.write(ostream);
	sint4.write(ostream);
	sint5.write(ostream);
	uint6.write(ostream);
	uint7.write(ostream);
	if (game_mode == 1 || game_mode == 2 || game_mode == 5)
	{
		uint8.write(ostream);
		sint9.write(ostream);
		uint10.write(ostream);
		uint11.write(ostream);
		for (size_t i = 0; i < 6; i++)
			uints12[i].write(ostream);
		uint13.write(ostream);
		uint14.write(ostream);
	}
	if (game_mode == 4)
	{
		sint15.write(ostream);
	}
}
inline void kudo::RPlayerReward::read(srpc::IStream& istream)
{
	player_uid.read(istream);
	uint2.read(istream);
	game_mode.read(istream);
	sint4.read(istream);
	sint5.read(istream);
	uint6.read(istream);
	uint7.read(istream);
	if (game_mode == 1 || game_mode == 2 || game_mode == 5)
	{
		uint8.read(istream);
		sint9.read(istream);
		uint10.read(istream);
		uint11.read(istream);
		for (size_t i = 0; i < 6; i++)
			uints12[i].read(istream);
		uint13.read(istream);
		uint14.read(istream);
	}
	if (game_mode == 4)
	{
		sint15.read(istream);
	}
}

inline void kudo::RSubInfo5::write(srpc::OStream& ostream)
{
	uint1.write(ostream);
	uint2.write(ostream);
}
inline void kudo::RSubInfo5::read(srpc::IStream& istream)
{
	uint1.read(istream);
	uint2.read(istream);
}

inline void kudo::RGameResult::write(srpc::OStream& ostream)
{
	winner.write(ostream);
	info2.write(ostream);
	info3.write(ostream);
	uint4.write(ostream);
}
inline void kudo::RGameResult::read(srpc::IStream& istream)
{
	winner.read(istream);
	info2.read(istream);
	info3.read(istream);
	uint4.read(istream);
}

inline void kudo::RDetailedGameResult::write(srpc::OStream& ostream)
{
	RGameResult::write(ostream);
	rewards.write(ostream);
}
inline void kudo::RDetailedGameResult::read(srpc::IStream& istream)
{
	RGameResult::read(istream);
	rewards.read(istream);
}

inline void kudo::RPlayerInfo::write(srpc::OStream& ostream)
{
	uid.write(ostream);
	nickname.write(ostream);
	characters.write(ostream);
	slot.write(ostream);
	ready.write(ostream);
	sint6.write(ostream);
}
inline void kudo::RPlayerInfo::read(srpc::IStream& istream)
{
	uid.read(istream);
	nickname.read(istream);
	characters.read(istream);
	slot.read(istream);
	ready.read(istream);
	sint6.read(istream);
}

inline void kudo::RSimplePlayerInfo::write(srpc::OStream& ostream)
{
	slot.write(ostream);
	nickname.write(ostream);
	uint3.write(ostream);
	vect4.write(ostream);
	vect5.write(ostream);
}
inline void kudo::RSimplePlayerInfo::read(srpc::IStream& istream)
{
	slot.read(istream);
	nickname.read(istream);
	uint3.read(istream);
	vect4.read(istream);
	vect5.read(istream);
}

inline void kudo::RGameRoomInfo::write(srpc::OStream& ostream)
{
	title.write(ostream);
	game_rules.write(ostream);
	grade_mode.write(ostream);
	locked.write(ostream);
	bool5.write(ostream);
}
inline void kudo::RGameRoomInfo::read(srpc::IStream& istream)
{
	title.read(istream);
	game_rules.read(istream);
	grade_mode.read(istream);
	locked.read(istream);
	bool5.read(istream);
}

inline void kudo::RSimpleGameRoomInfo::write(srpc::OStream& ostream)
{
	RGameRoomInfo::write(ostream);
	room_number.write(ostream);
	players.write(ostream);
}
inline void kudo::RSimpleGameRoomInfo::read(srpc::IStream& istream)
{
	RGameRoomInfo::read(istream);
	room_number.read(istream);
	players.read(istream);
}

inline void kudo::RFullGameRoomInfo::write(srpc::OStream& ostream)
{
	RGameRoomInfo::write(ostream);
	master_uid.write(ostream);
	players.write(ostream);
	relay_addr.write(ostream);
	relay_port.write(ostream);
	relay_key.write(ostream);
	pass.write(ostream);
}
inline void kudo::RFullGameRoomInfo::read(srpc::IStream& istream)
{
	RGameRoomInfo::read(istream);
	master_uid.read(istream);
	players.read(istream);
	relay_addr.read(istream);
	relay_port.read(istream);
	relay_key.read(istream);
	pass.read(istream);
}

inline void kudo::RDetailedSlotInfo::write(srpc::OStream& ostream)
{
	slot.write(ostream);
	bool2.write(ostream);
	user_uid.write(ostream);
}
inline void kudo::RDetailedSlotInfo::read(srpc::IStream& istream)
{
	slot.read(istream);
	bool2.read(istream);
	user_uid.read(istream);
}

inline void kudo::RPrice::write(srpc::OStream& ostream)
{
	sint1.write(ostream);
	sint2.write(ostream);
}
inline void kudo::RPrice::read(srpc::IStream& istream)
{
	sint1.read(istream);
	sint2.read(istream);
}

inline void kudo::RStrokeTrainingRanking::write(srpc::OStream& ostream)
{
	str1.write(ostream);
	uint2.write(ostream);
}
inline void kudo::RStrokeTrainingRanking::read(srpc::IStream& istream)
{
	str1.read(istream);
	uint2.read(istream);
}

inline void kudo::RStrokeTrainingTargetScore::write(srpc::OStream& ostream)
{
	uint1.write(ostream);
	uint2.write(ostream);
	uint3.write(ostream);
	uint4.write(ostream);
	sint5.write(ostream);
	sint6.write(ostream);
	sint7.write(ostream);
}
inline void kudo::RStrokeTrainingTargetScore::read(srpc::IStream& istream)
{
	uint1.read(istream);
	uint2.read(istream);
	uint3.read(istream);
	uint4.read(istream);
	sint5.read(istream);
	sint6.read(istream);
	sint7.read(istream);
}

inline void kudo::RTrainingPoints::write(srpc::OStream& ostream)
{
	uint1.write(ostream);
	uint2.write(ostream);
}
inline void kudo::RTrainingPoints::read(srpc::IStream& istream)
{
	uint1.read(istream);
	uint2.read(istream);
}

inline void kudo::RPlace::write(srpc::OStream& ostream)
{
	sint2.write(ostream);
	uint3.write(ostream);
}
inline void kudo::RPlace::read(srpc::IStream& istream)
{
	sint2.read(istream);
	uint3.read(istream);
}

inline void kudo::RBuddy::write(srpc::OStream& ostream)
{
	nickname.write(ostream);
	uint2.write(ostream);
	bool3.write(ostream);
	bool4.write(ostream);
	place.write(ostream);
	uint7.write(ostream);
}
inline void kudo::RBuddy::read(srpc::IStream& istream)
{
	nickname.read(istream);
	uint2.read(istream);
	bool3.read(istream);
	bool4.read(istream);
	place.read(istream);
	uint7.read(istream);
}

inline void kudo::RBuddyGroup::write(srpc::OStream& ostream)
{
	uint1.write(ostream);
	name.write(ostream);
}
inline void kudo::RBuddyGroup::read(srpc::IStream& istream)
{
	uint1.read(istream);
	name.read(istream);
}

inline void kudo::RBaseUserInfo::write(srpc::OStream& ostream)
{
	uint1.write(ostream);
	nickname.write(ostream);
}
inline void kudo::RBaseUserInfo::read(srpc::IStream& istream)
{
	uint1.read(istream);
	nickname.read(istream);
}

inline void kudo::RChannelUserInfo::write(srpc::OStream& ostream)
{
	uint1.write(ostream);
	nickname.write(ostream);
	bool3.write(ostream);
}
inline void kudo::RChannelUserInfo::read(srpc::IStream& istream)
{
	uint1.read(istream);
	nickname.read(istream);
	bool3.read(istream);
}

inline void kudo::RChannelRoomInfo::write(srpc::OStream& ostream)
{
	uint1.write(ostream);
	title.write(ostream);
	uint3.write(ostream);
	uint4.write(ostream);
	bool5.write(ostream);
}
inline void kudo::RChannelRoomInfo::read(srpc::IStream& istream)
{
	uint1.read(istream);
	title.read(istream);
	uint3.read(istream);
	uint4.read(istream);
	bool5.read(istream);
}

inline void kudo::RFullChannelRoomInfo::write(srpc::OStream& ostream)
{
	RChannelRoomInfo::write(ostream);
	str6.write(ostream);
	uint7.write(ostream);
	users.write(ostream);
}
inline void kudo::RFullChannelRoomInfo::read(srpc::IStream& istream)
{
	RChannelRoomInfo::read(istream);
	str6.read(istream);
	uint7.read(istream);
	users.read(istream);
}

inline void kudo::RMailInfo::write(srpc::OStream& ostream)
{
	uint1.write(ostream);
	title.write(ostream);
	uint3.write(ostream);
	sint4.write(ostream);
	sint5.write(ostream);
}
inline void kudo::RMailInfo::read(srpc::IStream& istream)
{
	uint1.read(istream);
	title.read(istream);
	uint3.read(istream);
	sint4.read(istream);
	sint5.read(istream);
}

inline void kudo::RGameRecords::write(srpc::OStream& ostream)
{
	uint1.write(ostream);
	uint2.write(ostream);
	uint3.write(ostream);
	uint4.write(ostream);
}
inline void kudo::RGameRecords::read(srpc::IStream& istream)
{
	uint1.read(istream);
	uint2.read(istream);
	uint3.read(istream);
	uint4.read(istream);
}

inline void kudo::RStarwars::write(srpc::OStream& ostream)
{
	uint1.write(ostream);
	str2.write(ostream);
	sint3.write(ostream);
	sint4.write(ostream);
	sint5.write(ostream);
	sint6.write(ostream);
	sint7.write(ostream);
	sint8.write(ostream);
	sint9.write(ostream);
	sint10.write(ostream);
	sint11.write(ostream);
	sint12.write(ostream);
	uint13.write(ostream);
	uint14.write(ostream);
	uint15.write(ostream);
}
inline void kudo::RStarwars::read(srpc::IStream& istream)
{
	uint1.read(istream);
	str2.read(istream);
	sint3.read(istream);
	sint4.read(istream);
	sint5.read(istream);
	sint6.read(istream);
	sint7.read(istream);
	sint8.read(istream);
	sint9.read(istream);
	sint10.read(istream);
	sint11.read(istream);
	sint12.read(istream);
	uint13.read(istream);
	uint14.read(istream);
	uint15.read(istream);
}

inline void kudo::RStarwarsParticipant::write(srpc::OStream& ostream)
{
	nickname.write(ostream);
	records.write(ostream);
	sint3.write(ostream);
}
inline void kudo::RStarwarsParticipant::read(srpc::IStream& istream)
{
	nickname.read(istream);
	records.read(istream);
	sint3.read(istream);
}

inline void kudo::RStarwarsCommodity::write(srpc::OStream& ostream)
{
	uint1.write(ostream);
	sint2.write(ostream);
	uint3.write(ostream);
	uint4.write(ostream);
	uint5.write(ostream);
}
inline void kudo::RStarwarsCommodity::read(srpc::IStream& istream)
{
	uint1.read(istream);
	sint2.read(istream);
	uint3.read(istream);
	uint4.read(istream);
	uint5.read(istream);
}

//=========================================================================================================================================