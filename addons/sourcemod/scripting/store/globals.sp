new g_cvarChatTag = -1;
#define CHAT_TAG g_eCvars[g_cvarChatTag][sCache]

#define ITEM_NAME_LENGTH 64
#define STORE_MAX_ITEMS 2048
#define STORE_MAX_HANDLERS 64
#define STORE_MAX_PLANS 8
#define STORE_MAX_SLOTS 4

enum Item_Plan
{
	String:szName[ITEM_NAME_LENGTH],
	iPrice,
	iTime
}

enum Store_Item
{
	String:szName[ITEM_NAME_LENGTH],
	String:szUniqueId[PLATFORM_MAX_PATH],
	String:szShortcut[64],
	iId,
	iPrice,
	iParent,
	iHandler,
	iFlagBits,
	iData,
	iPlans,
	bool:bBuyable,
	bool:bIgnoreVIP,
	Handle:hAttributes
}

enum Type_Handler
{
	String:szType[64],
	String:szUniqueKey[32],
	bool:bEquipable,
	bool:bRaw,
	Handle:hPlugin,
	Function:fnMapStart,
	Function:fnReset,
	Function:fnConfig,
	Function:fnUse,
	Function:fnRemove
}

enum Client_Item
{
	iId,
	iUniqueId,
	bool:bSynced,
	bool:bDeleted,
	iDateOfPurchase,
	iDateOfExpiration,
	iPriceOfPurchase,
}