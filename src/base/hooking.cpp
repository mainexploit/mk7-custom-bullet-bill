#include <base/hooking.hpp>

#include <base/pointers.hpp>

namespace base
{
    hooking::hooking()
	:
		m_Item_ItemObjKiller_hook("Item::ItemObjKiller", g_pointers->m_Item_ItemObjKiller_vtbl, hooks::ItemObjBase_count),
		
		m_Item_ItemObjKillerDirector_createBeforeStructure_hook("Item::ItemObjKillerDirector::createBeforeStructure", g_pointers->m_Item_ItemObjKillerDirector_createBeforeStructure, reinterpret_cast<void *>(&hooks::Item_ItemObjKillerDirector_createBeforeStructure)),
		m_Sequence_BaseRacePage_onPagePreStep_hook("Sequence::BaseRacePage::onPagePreStep", g_pointers->m_Sequence_BaseRacePage_onPagePreStep, reinterpret_cast<void *>(&hooks::Sequence_BaseRacePage_onPagePreStep)),
		m_Item_ItemObjBase_setState_SelfMove_hook("Item::ItemObjBase::setState_SelfMove", g_pointers->m_Item_ItemObjBase_setState_SelfMove, reinterpret_cast<void *>(&hooks::Item_ItemObjBase_setState_SelfMove)),
		m_Sequence_BaseRacePage_initMapIcon_hook("Sequence::BaseRacePage::initMapIcon", g_pointers->m_Sequence_BaseRacePage_initMapIcon, reinterpret_cast<void *>(&hooks::Sequence_BaseRacePage_initMapIcon)),
		m_Sequence_BaseRacePage_initCaption_hook("Sequence::BaseRacePage::initCaption", g_pointers->m_Sequence_BaseRacePage_initCaption, reinterpret_cast<void *>(&hooks::Sequence_BaseRacePage_initCaption)),
		m_Item_KartItem_calcBeforeStructure_hook("Item::KartItem::calcBeforeStructure", g_pointers->m_Item_KartItem_calcBeforeStructure, reinterpret_cast<void *>(&hooks::Item_KartItem_calcBeforeStructure)),
		m_Item_ItemObjBase_stateEquip_Hang_hook("Item::ItemObjBase::stateEquip_Hang", g_pointers->m_Item_ItemObjBase_stateEquip_Hang, reinterpret_cast<void *>(&hooks::Item_ItemObjBase_stateEquip_Hang)),
		m_Item_ItemDirector_doReaction_hook("Item::ItemDirector::doReaction", g_pointers->m_Item_ItemDirector_doReaction, reinterpret_cast<void *>(&hooks::Item_ItemDirector_doReaction)),
		m_Item_ItemDirector_entryItem_hook("Item::ItemDirector::entryItem", reinterpret_cast<void *>(g_pointers->m_Item_ItemDirector_entryItem), reinterpret_cast<void *>(&hooks::Item_ItemDirector_entryItem)),
		m_Item_ItemObjBase_stateStand_hook("Item::ItemObjBase::stateStand", reinterpret_cast<void *>(g_pointers->m_Item_ItemObjBase_stateStand), reinterpret_cast<void *>(&hooks::Item_ItemObjBase_stateStand)),
		m_Item_ItemObjBase_calcImpl_hook("Item::ItemObjBase::calcImpl", g_pointers->m_Item_ItemObjBase_calcImpl, reinterpret_cast<void *>(&hooks::Item_ItemObjBase_calcImpl)),
		
		m_Sequence_BaseRacePage_sub_equipItem_0xAC_hook("Sequence::BaseRacePage::sub_equipItem+0xAC", g_pointers->m_Sequence_BaseRacePage_sub_equipItem_0xAC, reinterpret_cast<void *>(&hooks::Sequence_BaseRacePage_sub_equipItem_0xAC), CTRPluginFramework::USE_LR_TO_RETURN | CTRPluginFramework::EXECUTE_OI_AFTER_CB),
		m_Item_ItemDirector_checkKartHitItem_0x590_hook("Item::ItemDirector::checkKartHitItem+0x590", g_pointers->m_Item_ItemDirector_checkKartHitItem_0x590, reinterpret_cast<void *>(&hooks::Item_ItemDirector_checkKartHitItem_0x590), CTRPluginFramework::HOOK_DEFAULT_PARAMS),
		m_Sequence_BaseRacePage_initMapIcon_0x814_hook("Sequence::BaseRacePage::initMapIcon+0x814", g_pointers->m_Sequence_BaseRacePage_initMapIcon_0x814, reinterpret_cast<void *>(&hooks::Sequence_BaseRacePage_initMapIcon_0x814), CTRPluginFramework::HOOK_DEFAULT_PARAMS),
		m_Item_ItemObjBanana_calcOverState_0x178_hook("Item::ItemObjBanana::_calcOverState+0x178", g_pointers->m_Item_ItemObjBanana_calcOverState_0x178, reinterpret_cast<void *>(&hooks::Item_ItemObjBanana_calcOverState_0x178), CTRPluginFramework::HOOK_DEFAULT_PARAMS),
		m_Item_ItemObjBanana_stateSelfMove_0x20_hook("Item::ItemObjBanana::stateSelfMove+0x20", g_pointers->m_Item_ItemObjBanana_stateSelfMove_0x20, reinterpret_cast<void *>(&hooks::Item_ItemObjBanana_stateSelfMove_0x20), CTRPluginFramework::USE_LR_TO_RETURN)
	{
		memcpy(g_pointers->m_Item_ItemObjKiller_vtbl, g_pointers->m_Item_ItemObjBanana_vtbl, (hooks::ItemObjBase_count * 4));

		m_Item_ItemObjKiller_hook.hook(hooks::ItemObjBase_stateInitUse_index, g_pointers->m_Item_ItemObjKiller_stateInitUse);
		m_Item_ItemObjKiller_hook.hook(hooks::ItemObjBase_stateUse_index, g_pointers->m_Item_ItemObjKiller_stateUse);

		m_Item_ItemObjKiller_hook.hook(hooks::ItemObjBase_exit_BreakInner_index, reinterpret_cast<void *>(g_pointers->m_Item_ItemObjBase_exit_BreakInner));
		m_Item_ItemObjKiller_hook.hook(hooks::ItemObjBase_stateStand_index, reinterpret_cast<void *>(g_pointers->m_Item_ItemObjBase_stateStand));

		m_Item_ItemObjKiller_hook.hook(hooks::ItemObjBase_hasCollision_InUseState_index, reinterpret_cast<void *>(&hooks::Item_ItemObjKiller_hasCollision_InUseState));
		m_Item_ItemObjKiller_hook.hook(hooks::ItemObjbase_getRotVelRatio_Multi_index, reinterpret_cast<void *>(&hooks::Item_ItemObjKiller_getRotVelRatio_Multi));
		m_Item_ItemObjKiller_hook.hook(hooks::ItemObjBase_stateInitSelfMove_index, reinterpret_cast<void *>(&hooks::Item_ItemObjKiller_stateInitSelfMove));
		m_Item_ItemObjKiller_hook.hook(hooks::ItemObjBase_getOffset_Multi_Y_index, reinterpret_cast<void *>(&hooks::Item_ItemObjKiller_getOffset_Multi_Y));
		m_Item_ItemObjKiller_hook.hook(hooks::ItemObjBase_getOffset_Multi_Z_index, reinterpret_cast<void *>(&hooks::Item_ItemObjKiller_getOffset_Multi_Z));
		m_Item_ItemObjKiller_hook.hook(hooks::ItemObjBase_stateEquip_Multi_index, reinterpret_cast<void *>(&hooks::Item_ItemObjKiller_stateEquip_Multi));
		m_Item_ItemObjKiller_hook.hook(hooks::ItemObjBase_exit_VanishInner_index, reinterpret_cast<void *>(&hooks::Item_ItemObjKiller_exit_VanishInner));
		m_Item_ItemObjKiller_hook.hook(hooks::ItemObjBase_getRadius_Multi_index, reinterpret_cast<void *>(&hooks::Item_ItemObjKiller_getRadius_Multi));
		m_Item_ItemObjKiller_hook.hook(hooks::ItemObjBase_getBoxColRadius_index, reinterpret_cast<void *>(&hooks::Item_ItemObjKiller_getBoxColRadius));
		m_Item_ItemObjKiller_hook.hook(hooks::ItemObjBase_getShadowScale_index, reinterpret_cast<void *>(&hooks::Item_ItemObjKiller_getShadowScale));
		m_Item_ItemObjKiller_hook.hook(hooks::ItemObjBase_getColRadius_index, reinterpret_cast<void *>(&hooks::Item_ItemObjKiller_getColRadius));
		m_Item_ItemObjKiller_hook.hook(hooks::ItemObjBase_createInner_index, reinterpret_cast<void *>(&hooks::Item_ItemObjKiller_createInner));

		g_hooking = this;
	}
	
	hooking::~hooking()
	{
		g_hooking = nullptr;

		m_Item_ItemObjKiller_hook.unhook(hooks::ItemObjBase_stateInitUse_index);
		m_Item_ItemObjKiller_hook.unhook(hooks::ItemObjBase_stateUse_index);

		m_Item_ItemObjKiller_hook.unhook(hooks::ItemObjBase_exit_BreakInner_index);
		m_Item_ItemObjKiller_hook.unhook(hooks::ItemObjBase_stateStand_index);

		m_Item_ItemObjKiller_hook.unhook(hooks::ItemObjBase_hasCollision_InUseState_index);
		m_Item_ItemObjKiller_hook.unhook(hooks::ItemObjbase_getRotVelRatio_Multi_index);
		m_Item_ItemObjKiller_hook.unhook(hooks::ItemObjBase_stateInitSelfMove_index);
		m_Item_ItemObjKiller_hook.unhook(hooks::ItemObjBase_getOffset_Multi_Y_index);
		m_Item_ItemObjKiller_hook.unhook(hooks::ItemObjBase_getOffset_Multi_Z_index);
		m_Item_ItemObjKiller_hook.unhook(hooks::ItemObjBase_stateEquip_Multi_index);
		m_Item_ItemObjKiller_hook.unhook(hooks::ItemObjBase_exit_VanishInner_index);
		m_Item_ItemObjKiller_hook.unhook(hooks::ItemObjBase_getRadius_Multi_index);
		m_Item_ItemObjKiller_hook.unhook(hooks::ItemObjBase_getBoxColRadius_index);
		m_Item_ItemObjKiller_hook.unhook(hooks::ItemObjBase_getShadowScale_index);
		m_Item_ItemObjKiller_hook.unhook(hooks::ItemObjBase_getColRadius_index);
		m_Item_ItemObjKiller_hook.unhook(hooks::ItemObjBase_createInner_index);

		if (m_enabled)
			disable();
	}

    void hooking::enable()
	{
		m_Item_ItemObjKiller_hook.enable();

		m_Item_ItemObjKillerDirector_createBeforeStructure_hook.enable();
		m_Sequence_BaseRacePage_onPagePreStep_hook.enable();
		m_Item_ItemObjBase_setState_SelfMove_hook.enable();
		m_Sequence_BaseRacePage_initMapIcon_hook.enable();
		m_Sequence_BaseRacePage_initCaption_hook.enable();
		m_Item_KartItem_calcBeforeStructure_hook.enable();
		m_Item_ItemObjBase_stateEquip_Hang_hook.enable();
		m_Item_ItemDirector_doReaction_hook.enable();
		m_Item_ItemDirector_entryItem_hook.enable();
		m_Item_ItemObjBase_stateStand_hook.enable();
		m_Item_ItemObjBase_calcImpl_hook.enable();

		m_Sequence_BaseRacePage_sub_equipItem_0xAC_hook.enable();
		m_Item_ItemDirector_checkKartHitItem_0x590_hook.enable();
		m_Sequence_BaseRacePage_initMapIcon_0x814_hook.enable();
		m_Item_ItemObjBanana_calcOverState_0x178_hook.enable();
		m_Item_ItemObjBanana_stateSelfMove_0x20_hook.enable();

		m_enabled = true;
	}

	void hooking::disable()
	{
		m_Item_ItemObjKiller_hook.disable();

		m_Item_ItemObjKillerDirector_createBeforeStructure_hook.disable();
		m_Sequence_BaseRacePage_onPagePreStep_hook.disable();
		m_Item_ItemObjBase_setState_SelfMove_hook.disable();
		m_Sequence_BaseRacePage_initMapIcon_hook.disable();
		m_Sequence_BaseRacePage_initCaption_hook.disable();
		m_Item_KartItem_calcBeforeStructure_hook.disable();
		m_Item_ItemObjBase_stateEquip_Hang_hook.disable();
		m_Item_ItemDirector_doReaction_hook.disable();
		m_Item_ItemDirector_entryItem_hook.disable();
		m_Item_ItemObjBase_stateStand_hook.disable();
		m_Item_ItemObjBase_calcImpl_hook.disable();
		
		m_Sequence_BaseRacePage_sub_equipItem_0xAC_hook.disable();
		m_Item_ItemDirector_checkKartHitItem_0x590_hook.disable();
		m_Sequence_BaseRacePage_initMapIcon_0x814_hook.disable();
		m_Item_ItemObjBanana_calcOverState_0x178_hook.disable();
		m_Item_ItemObjBanana_stateSelfMove_0x20_hook.disable();

		m_enabled = false;
	}
}