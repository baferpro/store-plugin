#if defined _store_included
	#endinput
#endif
#define _store_included

public SharedPlugin __pl_store = 
{
	name = "store",
	file = "store.smx",
#if defined REQUIRE_PLUGIN
    required = 1
#else
    required = 0
#endif
};

public Extension __ext_store_sm =
{
	name = "Store - The Resurrection",
	file = "store_sm.ext",
#if defined AUTOLOAD_EXTENSIONS
	autoload = 1,
#else
	autoload = 0,
#endif
#if defined REQUIRE_PLUGIN
    required = 1
#else
    required = 0
#endif
};

#if !defined REQUIRE_PLUGIN
public void __pl_store_SetNTVOptional()
{
	MarkNativeAsOptional("Store_RegisterHandler");
	MarkNativeAsOptional("Store_RegisterMenuHandler");
	MarkNativeAsOptional("Store_SetDataIndex");
	MarkNativeAsOptional("Store_GetDataIndex");
	MarkNativeAsOptional("Store_GetEquippedItem");
	MarkNativeAsOptional("Store_IsClientLoaded");
	MarkNativeAsOptional("Store_DisplayPreviousMenu");
	MarkNativeAsOptional("Store_SetClientMenu");
	MarkNativeAsOptional("Store_GetClientCredits");
	MarkNativeAsOptional("Store_SetClientCredits");
	MarkNativeAsOptional("Store_IsClientVIP");
	MarkNativeAsOptional("Store_IsItemInBoughtPackage");
	MarkNativeAsOptional("Store_ShouldConfirm");
	MarkNativeAsOptional("Store_DisplayConfirmMenu");
	MarkNativeAsOptional("Store_GetItem");
	MarkNativeAsOptional("Store_GetHandler");
	MarkNativeAsOptional("Store_GiveItem");
	MarkNativeAsOptional("Store_RemoveItem");
	MarkNativeAsOptional("Store_GetClientItem");
	MarkNativeAsOptional("Store_GetClientTarget");
	MarkNativeAsOptional("Store_GiveClientItem");
	MarkNativeAsOptional("Store_HasClientItem");
	MarkNativeAsOptional("Store_IterateEquippedItems");
}
#endif

native Store_RegisterHandler(String:type[], String:uniquekey[], Function:mapstart, Function:reset, Function:config, Function:use, Function:remove, bool:equipable = true, bool:raw = false);
native Store_RegisterMenuHandler(String:identifier[], Function:menu, Function:handler);
native Store_SetDataIndex(itemid, index);
native Store_GetDataIndex(itemid);
native Store_GetEquippedItem(client, String:type[], slot=0);
native Store_IsClientLoaded(client);
native Store_DisplayPreviousMenu(client);
native Store_SetClientMenu(client, num);
native Store_GetClientCredits(client);
native Store_SetClientCredits(client, credits);
native Store_IsClientVIP(client);
native Store_IsItemInBoughtPackage(client, itemid, uid=-1);
native Store_ShouldConfirm();
native Store_DisplayConfirmMenu(client, String:title[], Function:callback, data);
native Store_GetItem(itemid, output[Store_Item]);
native Store_GetHandler(index, output[Type_Handler]);
native Store_GiveItem(client, itemid, purchase=0, expiration=0, price=0);
native Store_RemoveItem(client, itemid);
native Store_GetClientItem(client, itemid, output[Client_Item]);
native Store_GetClientTarget(client);
native Store_GiveClientItem(client, recipient, itemid);
native Store_HasClientItem(client, itemid);
native Store_IterateEquippedItems(client, &start, bool:attributes=false);

forward Store_OnClientModelChanged(client, String:model[]);