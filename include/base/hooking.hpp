#pragma once

#include <base/hook_types/all.hpp>

#include <base/hooks.hpp>

namespace base
{
    class hooking
    {
	public:
		explicit hooking();
		~hooking();

        inline bool is_enabled() const { return m_enabled; }

        void enable();
		void disable();

    private:
        friend hooks;

        bool m_enabled{};

        hook_types::vf_hook m_Item_ItemObjKiller_hook;

        hook_types::detour_hook m_Item_ItemObjKillerDirector_createBeforeStructure_hook;
        hook_types::detour_hook m_Sequence_BaseRacePage_onPagePreStep_hook;
        hook_types::detour_hook m_Item_ItemObjBase_setState_SelfMove_hook;
        hook_types::detour_hook m_Sequence_BaseRacePage_initCaption_hook;
        hook_types::detour_hook m_Sequence_BaseRacePage_initMapIcon_hook;
        hook_types::detour_hook m_Item_KartItem_calcBeforeStructure_hook;
        hook_types::detour_hook m_Item_ItemObjBase_stateEquip_Hang_hook;
        hook_types::detour_hook m_Item_ItemDirector_doReaction_hook;
        hook_types::detour_hook m_Item_ItemDirector_entryItem_hook;
        hook_types::detour_hook m_Item_ItemObjBase_stateStand_hook;
        hook_types::detour_hook m_Item_ItemObjBase_calcImpl_hook;
        
        hook_types::naked_hook m_Sequence_BaseRacePage_sub_equipItem_0xAC_hook;
        hook_types::naked_hook m_Item_ItemDirector_checkKartHitItem_0x590_hook;
        hook_types::naked_hook m_Sequence_BaseRacePage_initMapIcon_0x814_hook;
        hook_types::naked_hook m_Item_ItemObjBanana_calcOverState_0x178_hook;
        hook_types::naked_hook m_Item_ItemObjBanana_stateSelfMove_0x20_hook;
    };
    
    inline hooking *g_hooking{};
}