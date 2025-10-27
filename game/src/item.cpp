// in void CItem::Initialize()
//add:
	#ifdef ENABLE_RENEWAL_DROP
	m_dwDropOwnerPID = 0;
	m_bOwnerOnlyVisible = false;
	#endif
	
// search: void CItem::EncodeInsertPacket
// before: const PIXEL_POSITION& pos = GetXYZ();
//add:
	#ifdef ENABLE_RENEWAL_DROP
	if (!IsVisibleTo (ch))
	{
		return;
	}
	#endif
	
// search: void CItem::EncodeRemovePacket
// before: packet_item_ground_del pack{};
// add:
	#ifdef ENABLE_RENEWAL_DROP
	if (!IsVisibleTo (ch))
	{
		return;
	}
	#endif
	
// add new function:
#ifdef ENABLE_RENEWAL_DROP
bool CItem::IsVisibleTo (LPCHARACTER ch) const
{
	if (!ch)
	{
		return false;
	}

	if (!m_bOwnerOnlyVisible) // item normal -> vizibil tuturor
	{
		return true;
	}

	if (ch->IsGM())
	{
		return true;
	}

	return ch->GetPlayerID() == m_dwDropOwnerPID;
}
#endif