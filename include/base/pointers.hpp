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

		Net::NetworkEngine **m_network_engine;
		sead::GlobalRandom **m_global_random;
		
		methods::Render_DrawMdlCreateArgs_SetPathInfoNoLoad_t m_Render_DrawMdlCreateArgs_SetPathInfoNoLoad;
		methods::Item_ItemObjDirectorBase_emitItemImpl_t m_Item_ItemObjDirectorBase_emitItemImpl;
		methods::Object_Actor3DMdl_createModel_t m_Object_Actor3DMdl_createModel;
		methods::Sound_SndActorKart_holdSound_t m_Sound_SndActorKart_holdSound;
		methods::ItemObjBase_Instance_t m_Item_ItemObjKiller_exit_VanishInner;
		methods::ItemObjBase_Instance_t m_Item_ItemObjBanana_stateEquip_Multi;
		methods::ItemObjBase_Instance_t m_Item_ItemObjBase_stateInitSelfMove;
		methods::Item_ItemObjBase_sub_object_t m_Item_ItemObjBase_sub_object;
		methods::Item_ItemDirector_entryItem_t m_Item_ItemDirector_entryItem;
		methods::Item_ItemObjBase_setVisible_t m_Item_ItemObjBase_setVisible;
		methods::ItemObjBase_Instance_t m_Item_ItemObjBase_stateEquip_Multi;
		methods::Render_DrawMdlCreateArgs_t m_Render_DrawMdlCreateArgs_ctor;
		methods::ItemObjBase_Instance_t m_Item_ItemObjBase_exit_VanishInner;
		methods::Item_KartItem_setItemForce_t m_Item_KartItem_setItemForce;
		methods::ItemObjBase_Instance_t m_Item_ItemObjBanana_stateStand;
		methods::ItemObjBase_Instance_t m_Item_ItemObjBase_stateStand;
		methods::ItemObjBase_Instance_t m_Item_ItemObjBase_exit_Vanish;
		methods::ItemObjBase_Instance_t m_Item_ItemObjBase_react_Break;
		methods::Item_KartItem_dropEquip_t m_Item_KartItem_dropEquip;
		methods::Item_ItemSlot_clear_t m_Item_ItemSlot_clear;
		methods::operator_new_t m_operator_new;
		
		void *m_Item_ItemObjKillerDirector_createBeforeStructure;
		void *m_Item_ItemDirector_initAfterStructure_0x14;
		void *m_Sequence_BaseRacePage_sub_equipItem_0xAC;
		void *m_Item_ItemDirector_checkKartHitItem_0x590;
		void *m_Sequence_BaseRacePage_initMapIcon_0x6F8;
		void *m_Sequence_BaseRacePage_initMapIcon_0x814;
		void *m_Item_ItemObjBanana_calcOverState_0x178;
		void *m_Item_ItemObjBanana_stateStand_0x3D8;
		void *m_Item_ItemObjBanana_stateStand_0x78C;
		void *m_Item_ItemObjBase_setState_SelfMove;
		void *m_Item_KartItem_calcBeforeStructure;
		void *m_Sequence_BaseRacePage_initMapIcon;
		void *m_Item_ItemObjBase_stateEquip_Hang;
		void *m_Kart_VehicleReact_calcReact_0x20;
		void *m_Item_KartItem_setItemForce_0x28;
		void *m_Item_ItemObjKiller_stateInitUse;
		void *m_System_KDPadDirector_calc_0xEC;
		void *m_Item_ItemDirector_doReaction;
		void *m_Item_ItemObjKiller_stateUse;
		void *m_Item_ItemObjBase_calcImpl;
		void *m_Item_ItemObjKiller_vtbl;
		void *m_Item_ItemObjBanana_vtbl;
		void *m_sead_SafeString_vtbl;
	};

	inline pointers *g_pointers{};
}