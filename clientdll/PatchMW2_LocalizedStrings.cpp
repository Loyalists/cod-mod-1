// ==========================================================
// MW2 coop
// 
// Component: IW4SP
// Sub-component: clientdll
// Purpose: Localized Strings
//
// Initial author: momo5502
// Started: 2014-03-07
// ==========================================================

#include "stdinc.h"
#include "LocalizedStrings.h"

localizedEntry_s* loadLocalizeAsset(int type, const char* reference)
{
	if(isCustomLoc(reference))
	{
		static localizedEntry_s entry;
		buildCustomEntry(&entry, reference);
		return &entry;
	}
	else
	{
		return (localizedEntry_s*)DB_FindXAssetHeader(type, reference);
	}
}

void PatchMW2_LocalizedStrings()
{
	if(version == 159)
	{
		addLocStr("MENU_INVITE_FRIEND", "Quick connect");
		addLocStr("MENU_DESC_INVITE_FRIEND", "Reconnect to last player.");
		addLocStr("MENU_SP_STEAM_CHAT_HINT", "");
	}

	call(localizeAssetHookLoc, loadLocalizeAsset, PATCH_CALL);
}