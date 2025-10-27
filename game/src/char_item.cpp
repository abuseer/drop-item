// search bool CHARACTER::DropItem 
	PIXEL_POSITION pxPos = GetXYZ();
// add after:

	#ifdef ENABLE_RENEWAL_DROP
		pkItemToDrop->SetOwnerOnlyVisible (GetPlayerID());
	#endif
	
	
//search: bool CHARACTER::PickupItem
bool CHARACTER::PickupItem (DWORD dwVID)
{
	LPITEM item = ITEM_MANAGER::instance().FindByVID(dwVID);

	if (IsObserverMode())
		return false;

	if (!item || !item->GetSectree())
		return false;
	
//add: 
#ifdef ENABLE_RENEWAL_DROP
	if (item->IsOwnerOnlyVisible() && item->GetDropOwnerPID() != GetPlayerID() && !IsGM())
		return false;
#endif