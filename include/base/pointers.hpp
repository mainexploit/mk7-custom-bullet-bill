#pragma once

#include <forward.hpp>
#include <types.hpp>

#include <random/seadGlobalRandom.h>

#include "methods.hpp"

namespace base
{
	class pointers
	{
	public:
		explicit pointers();
		~pointers();

		sead::GlobalRandom **m_global_random;
		
		methods::UI_ControlAnimator_AnimationDefine_sub_object_t m_UI_ControlAnimator_AnimationDefine_sub_object;
		methods::Render_DrawMdlCreateArgs_SetPathInfoNoLoad_t m_Render_DrawMdlCreateArgs_SetPathInfoNoLoad;
		methods::Item_ItemObjDirectorBase_emitItemImpl_t m_Item_ItemObjDirectorBase_emitItemImpl;
		methods::UI_VisualControl_CreateArg_sub_object_t m_UI_VisualControl_CreateArg_sub_object;
		methods::UI_ControlInitializer_endSetupControl_t m_UI_ControlInitializer_endSetupControl;
		methods::UI_ControlInitializer_initCreateArg_t m_UI_ControlInitializer_initCreateArg;
		methods::Util_TIndLinkList_UI_Control_append_t m_Util_TIndLinkList_UI_Control_append;
		methods::Object_Actor3DMdl_createModel_t m_Object_Actor3DMdl_createModel;
		methods::Sound_SndActorKart_holdSound_t m_Sound_SndActorKart_holdSound;
		methods::ItemObjBase_Instance_t m_Item_ItemObjKiller_exit_VanishInner;
		methods::ItemObjBase_Instance_t m_Item_ItemObjBase_stateInitSelfMove;
		methods::Item_ItemObjBase_sub_object_t m_Item_ItemObjBase_sub_object;
		methods::Item_ItemDirector_entryItem_t m_Item_ItemDirector_entryItem;
		methods::Item_ItemDirector_clearItem_t m_Item_itemDirector_clearItem;
		methods::Item_ItemObjBase_setVisible_t m_Item_ItemObjBase_setVisible;
		methods::ItemObjBase_Instance_t m_Item_ItemObjBase_stateEquip_Multi;
		methods::Render_DrawMdlCreateArgs_t m_Render_DrawMdlCreateArgs_ctor;
		methods::ItemObjBase_Instance_t m_Item_ItemObjBase_exit_VanishInner;
		methods::Item_KartItem_setItemForce_t m_Item_KartItem_setItemForce;
		methods::UI_BaseFastControl_setPosX_t m_UI_BaseFastControl_setPosX;
		methods::UI_BaseFastControl_setPosY_t m_UI_BaseFastControl_setPosY;
		methods::UI_BaseMenuViewControl_t m_UI_BaseMenuViewControl_ctor;
		methods::ItemObjBase_Instance_t m_Item_ItemObjBase_exit_Vanish;
		methods::ItemObjBase_Instance_t m_Item_ItemObjBase_react_Break;
		methods::ItemObjBase_Instance_t m_Item_ItemObjBase_stateStand;
		methods::Item_KartItem_dropEquip_t m_Item_KartItem_dropEquip;
		methods::UI_MenuCaption_animKeep_t m_UI_MenuCaption_animKeep;
		methods::UI_MenuCaption_animOut_t m_UI_MenuCaption_animOut;
		methods::UI_MenuCaption_animIn_t m_UI_MenuCaption_animIn;
		methods::Sequence_Sub_LostItem_t m_Sequence_Sub_LostItem;
		methods::Item_ItemSlot_clear_t m_Item_ItemSlot_clear;
		methods::operator_new_t m_operator_new;
		methods::c89vswprintf_t m_c89vswprintf;

		void *m_Item_ItemObjKillerDirector_createBeforeStructure;
		void *m_UI_VisualControl_CreateArg_AnimationDefine_vtbl;
		void *m_Item_ItemDirector_initAfterStructure_0x14;
		void *m_Sequence_BaseRacePage_sub_equipItem_0xAC;
		void *m_Item_ItemDirector_checkKartHitItem_0x590;
		void *m_Sequence_BaseRacePage_initMapIcon_0x6F8;
		void *m_Sequence_BaseRacePage_initMapIcon_0x814;
		void *m_Item_ItemObjBanana_calcOverState_0x178;
		void *m_Item_ItemObjBanana_stateSelfMove_0x20;
		void *m_Sequence_BaseRacePage_onPagePreStep;
		void *m_Item_ItemObjBase_setState_SelfMove;
		void *m_Item_KartItem_calcBeforeStructure;
		void *m_Sequence_BaseRacePage_initCaption;
		void *m_Sequence_BaseRacePage_initMapIcon;
		void *m_Item_ItemObjBase_stateEquip_Hang;
		void *m_Item_ItemObjBase_exit_BreakInner;
		void *m_Kart_VehicleReact_calcReact_0x20;
		void *m_Item_KartItem_setItemForce_0x28;
		void *m_Item_ItemObjKiller_stateInitUse;
		void *m_UI_VisualControl_CreateArg_vtbl;
		void *m_System_KDPadDirector_calc_0xEC;
		void *m_Item_ItemDirector_doReaction;
		void *m_UI_BaseMenuViewControl_vtbl;
		void *m_Item_ItemObjKiller_stateUse;
		void *m_Item_ItemObjBase_calcImpl;
		void *m_Item_ItemObjKiller_vtbl;
		void *m_Item_ItemObjBanana_vtbl;
		void *m_sead_SafeString_vtbl;
	};

	inline pointers *g_pointers{};
}