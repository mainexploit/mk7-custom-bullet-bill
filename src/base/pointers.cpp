#include <base/pointers.hpp>

#include <System/RootSystem.hpp>
#include <base/memory/all.hpp>
#include <base/hooks.hpp>
#include <callback.hpp>

namespace base
{
	pointers::pointers()
	{
		auto batch = memory::batch();

		batch.add("sead::Random", "00 00 54 E3 04 00 85 E5 04 00 A0 11 00 40 A0 03", [this](memory::handle handle)
		{
			m_global_random = *handle.add(0x20).as<decltype(m_global_random) *>();
		});

		batch.add("System::RootSystem", "00 20 95 E5 70 40 BD E8", [this](memory::handle handle)
		{
			System::g_root_system = *handle.add(0x20).as<decltype(System::g_root_system) *>();
		});

		batch.add("System::GameFramework::createGameFramework", "10 10 90 E5 04 00 A0 E1 31 FF 2F E1 70 D0 8D E2", [this](memory::handle handle)
		{
			m_sead_SafeString_vtbl = *handle.add(0x38).as<decltype(m_sead_SafeString_vtbl) *>();
		});

		batch.add("Object::CharacterEngine", "34 10 9F E5 3C 10 84 E5 00 60 C0 E5 04 00 A0 E1", [this](memory::handle handle)
		{
			auto Object_CharacterEngine_creators = handle.add(0x20).as<void **>();

			auto Object_CharacterEngine_creator_2 = memory::handle(Object_CharacterEngine_creators[2]);

			m_operator_new = Object_CharacterEngine_creator_2.add(0x18C).jmp().as<decltype(m_operator_new)>();
		});

		batch.add("Item::ItemObjDirectorBase::_emitItemImpl", "F0 43 2D E9 1C D0 4D E2 01 40 A0 E1 02 60 A0 E1", [this](memory::handle handle)
		{
			m_Item_ItemObjDirectorBase_emitItemImpl = handle.as<decltype(m_Item_ItemObjDirectorBase_emitItemImpl)>();
		});

		batch.add("Item::KartItem::setItemForce", "70 40 2D E9 00 40 A0 E1 34 00 90 E5 01 50 A0 E1 ? ? ? EB 34 00 94 E5", [this](memory::handle handle)
		{
			m_Item_KartItem_setItemForce = handle.as<decltype(m_Item_KartItem_setItemForce)>();

			m_Item_KartItem_setItemForce_0x28 = handle.add(0x28).as<decltype(m_Item_KartItem_setItemForce_0x28)>();
		});

		batch.add("Item::ItemDirector::initAfterStructure", "70 40 2D E9 00 50 A0 E1 F0 00 90 E5 CC 01 90 E5", [this](memory::handle handle)
		{
			m_Item_ItemDirector_initAfterStructure_0x14 = handle.add(0x14).as<decltype(m_Item_ItemDirector_initAfterStructure_0x14)>();
		});

		batch.add("Item::KartItem::dropEquip", "BC 20 9F E5 70 40 2D E9 00 60 E0 E3 41 30 D0 E5", [this](memory::handle handle)
		{
			m_Item_KartItem_dropEquip = handle.as<decltype(m_Item_KartItem_dropEquip)>();
		});
		
		batch.add("Item::ItemObjBase::ItemObjBase__sub_object", "0E 00 99 E8 00 70 E0 E3 06 00 80 E8 B0 30 84 E5 07 00 99 E8", [this](memory::handle handle)
		{
			m_Item_ItemObjBase_sub_object = handle.sub(0x58).as<decltype(m_Item_ItemObjBase_sub_object)>();

			auto hnd = memory::handle(reinterpret_cast<void *>(m_Item_ItemObjBase_sub_object));

			auto ItemObjBase_vtbl = *memory::handle(hnd.add(0x3EC)).as<void ***>();

			m_Item_ItemObjBase_stateInitSelfMove = memory::handle(ItemObjBase_vtbl[hooks::ItemObjBase_stateInitSelfMove_index]).as<decltype(m_Item_ItemObjBase_stateInitSelfMove)>();
			m_Item_ItemObjBase_exit_VanishInner = memory::handle(ItemObjBase_vtbl[hooks::ItemObjBase_exit_VanishInner_index]).as<decltype(m_Item_ItemObjBase_exit_VanishInner)>();
			m_Item_ItemObjBase_stateEquip_Multi = memory::handle(ItemObjBase_vtbl[hooks::ItemObjBase_stateEquip_Multi_index]).as<decltype(m_Item_ItemObjBase_stateEquip_Multi)>();
			m_Item_ItemObjBase_stateEquip_Hang = memory::handle(ItemObjBase_vtbl[hooks::ItemObjBase_stateEquip_Hang_index]).as<decltype(m_Item_ItemObjBase_stateEquip_Hang)>();
			m_Item_ItemObjBase_stateStand = memory::handle(ItemObjBase_vtbl[hooks::ItemObjBase_stateStand_index]).as<decltype(m_Item_ItemObjBase_stateStand)>();
			m_Item_ItemObjBase_exit_Vanish = memory::handle(reinterpret_cast<void *>(m_Item_ItemObjBase_stateStand)).add(0x2A4).jmp().as<decltype(m_Item_ItemObjBase_exit_Vanish)>();
			m_Item_ItemObjBase_exit_BreakInner = memory::handle(ItemObjBase_vtbl[hooks::ItemObjBase_exit_BreakInner_index]).as<decltype(m_Item_ItemObjBase_exit_BreakInner)>();
		});
		
		batch.add("Item::ItemDirector::entryItem", "F8 40 2D E9 01 30 A0 E1 00 40 A0 E1 2C 10 92 E5 14 00 53 E3 02 60 A0 E1 00 00 91 E5 84 50 90 E5", [this](memory::handle handle)
		{
			m_Item_ItemDirector_entryItem = handle.as<decltype(m_Item_ItemDirector_entryItem)>();
		});

		batch.add("Item::ItemObjKiller", "00 10 A0 E3 49 11 C0 E5 4A 11 C0 E5 10 80 BD E8", [this](memory::handle handle)
		{
			m_Item_ItemObjKiller_vtbl = *memory::handle(handle.add(0x10)).as<void ***>();
			m_Item_ItemObjKiller_exit_VanishInner = memory::handle(reinterpret_cast<void **>(m_Item_ItemObjKiller_vtbl)[hooks::ItemObjBase_exit_VanishInner_index]).as<decltype(m_Item_ItemObjKiller_exit_VanishInner)>();
			m_Item_ItemObjKiller_stateInitUse = memory::handle(reinterpret_cast<void **>(m_Item_ItemObjKiller_vtbl)[hooks::ItemObjBase_stateInitUse_index]).as<decltype(m_Item_ItemObjKiller_stateInitUse)>();
			m_Item_ItemObjKiller_stateUse = memory::handle(reinterpret_cast<void **>(m_Item_ItemObjKiller_vtbl)[hooks::ItemObjBase_stateUse_index]).as<decltype(m_Item_ItemObjKiller_stateUse)>();
		});

		batch.add("Item::ItemObjBanana", "7F 0A 80 ED 80 0A 80 ED 81 0A 80 ED 00 10 E0 E3 08 12 80 E5", [this](memory::handle handle)
		{
			m_Item_ItemObjBanana_vtbl = *memory::handle(handle.add(0x24)).as<void ***>();
			
			auto stateSelfMove_hnd = memory::handle(reinterpret_cast<void **>(m_Item_ItemObjBanana_vtbl)[hooks::ItemObjBase_stateSelfMove_index]);

			m_Item_ItemObjBanana_stateSelfMove_0x20 = stateSelfMove_hnd.add(0x20).as<decltype(m_Item_ItemObjBanana_stateSelfMove_0x20)>();
		});

		batch.add("Item::ItemObjKillerDirector::createBeforeStructure", "70 40 2D E9 00 40 A0 E1 0C 00 A0 E3 ? ? ? EB 1C 00 84 E5 0C 00 84 E5", [this](memory::handle handle)
		{
			m_Item_ItemObjKillerDirector_createBeforeStructure = handle.as<decltype(m_Item_ItemObjKillerDirector_createBeforeStructure)>();
		});

		batch.add("Sequence::BaseRacePage::initMapIcon", "33 FF 2F E1 03 0A 88 E2 4D 1F 8D E2 11 20 A0 E3 A0 00 80 E2 ? ? ? EB 70 02 98 E5 ? ? 9F E5 2A 1E 88 E2 03 00 50 E3 07 00 50 13", [this](memory::handle handle)
		{
			m_Sequence_BaseRacePage_initMapIcon = handle.sub(0x5C).as<decltype(m_Sequence_BaseRacePage_initMapIcon)>();

			auto hnd = memory::handle(m_Sequence_BaseRacePage_initMapIcon);

			m_Sequence_BaseRacePage_initMapIcon_0x6F8 = hnd.add(0x6F8).as<decltype(m_Sequence_BaseRacePage_initMapIcon_0x6F8)>();
			m_Sequence_BaseRacePage_initMapIcon_0x814 = hnd.add(0x814).as<decltype(m_Sequence_BaseRacePage_initMapIcon_0x814)>();
		});

		batch.add("Sequence::BaseRacePage::sub_equipItem", "70 40 2D E9 01 40 A0 E1 10 00 54 E3 00 C0 A0 E1 03 10 A0 E1 03 0A 80 E2 84 30 84 30 B4 00 80 E2 03 01 80 30 00 30 90 E5 00 00 53 E3", [this](memory::handle handle)
		{
			m_Sequence_BaseRacePage_sub_equipItem_0xAC = handle.add(0xAC).as<decltype(m_Sequence_BaseRacePage_sub_equipItem_0xAC)>();
		});

		batch.add("Item::KartItem::calcBeforeStructure", "D0 14 D0 E1 12 00 51 E3 13 00 51 13 0E 00 51 13 0D 00 00 1A 44 20 90 E5", [this](memory::handle handle)
		{
			m_Item_KartItem_calcBeforeStructure = handle.as<decltype(m_Item_KartItem_calcBeforeStructure)>();
		});

		batch.add("Sound::SndActorKart", "70 40 2D E9 01 60 A0 E1 02 8B 2D ED ? ? ? EB ? ? 9F E5 04 30 A0 E3 03 20 A0 E1 D8 10 A0 E5", [this](memory::handle handle)
		{
			auto Sound_SndActorKart_vtbl = *memory::handle(handle.add(0x1F0)).as<void ***>();

			auto hnd = memory::handle(Sound_SndActorKart_vtbl[hooks::SndActorKart_holdSound_index]);

			m_Sound_SndActorKart_holdSound = hnd.as<decltype(m_Sound_SndActorKart_holdSound)>();
		});

		batch.add("Item::ItemObjBase::setState_SelfMove", "00 00 A0 93 ? ? ? EB 5C 20 D5 E5 03 00 A0 E3 01 10 A0 E3 5D 20 C5 E5 5C 00 C5 E5 5E 10 C5 E5 70 60 85 E5 00 10 94 E5", [this](memory::handle handle)
		{
			m_Item_ItemObjBase_setState_SelfMove = handle.sub(0x54).as<decltype(m_Item_ItemObjBase_setState_SelfMove)>();
		});

		batch.add("Item::ItemDirector::checkKartHitItem", "05 00 A0 E1 ? ? ? EB 05 00 50 E3 0E 00 50 13 10 00 00 0A 05 00 A0 E1 ? ? ? EB 00 00 50 E3 E0 61 84 15 E4 61 84 05 F0 00 98 E5 E0 01 90 E5 04 00 50 E3", [this](memory::handle handle)
		{
			m_Item_ItemDirector_checkKartHitItem_0x590 = handle.as<decltype(m_Item_ItemDirector_checkKartHitItem_0x590)>();
		});

		batch.add("Item::ItemDirector::doReaction", "F0 41 2D E9 01 50 A0 E1 00 70 A0 E1 02 40 A0 E1 02 8B 2D ED 10 D0 4D E2 68 11 91 E5 34 00 8D E2 30 60 9D E5 00 00 51 E3 68 21 94 A5 02 8A 90 EC 00 00 52 A3", [this](memory::handle handle)
		{
			m_Item_ItemDirector_doReaction = handle.as<decltype(m_Item_ItemDirector_doReaction)>();

			auto doReactionImpl_hnd = memory::handle(handle.add(0x120).jmp().as<decltype(m_Item_ItemDirector_doReaction)>());

			m_Item_ItemObjBase_react_Break = doReactionImpl_hnd.add(0xA0).jmp().as<decltype(m_Item_ItemObjBase_react_Break)>();
		});

		batch.add("Item::ItemObjBase::calcImpl", "10 40 2D E9 00 40 A0 E1 68 01 90 E5 00 00 50 E3 39 00 00 BA A8 10 94 E5 58 00 84 E2 80 11 84 E5 AC 10 94 E5 84 11 84 E5 B0 10 94 E5 88 11 84 E5", [this](memory::handle handle)
		{
			m_Item_ItemObjBase_calcImpl = handle.as<decltype(m_Item_ItemObjBase_calcImpl)>();
		});

		batch.add("Item::ItemObjBanana::_calcOverState", "30 8A 84 ED A8 10 94 E5 01 00 A0 E3 84 10 84 E5 AC 10 94 E5 94 10 84 E5 B0 10 94 E5 A4 10 84 E5 44 00 C4 E5 14 00 84 E2 78 10 84 E2", [this](memory::handle handle)
		{
			m_Item_ItemObjBanana_calcOverState_0x178 = handle.as<decltype(m_Item_ItemObjBanana_calcOverState_0x178)>();
		});

		batch.add("Render::DrawMdlCreateArgs", "10 40 2D E9 ? ? ? EB 00 20 A0 E3 8C 20 C0 E5 8D 20 C0 E5 90 20 80 E5 A8 C0 80 E2 94 20 80 E5 A0 C0 80 E5", [this](memory::handle handle)
		{
			m_Render_DrawMdlCreateArgs_ctor = handle.as<decltype(m_Render_DrawMdlCreateArgs_ctor)>();
		});

		batch.add("Render::DrawMdlCreateArgs::SetPathInfoNoLoad", "F0 47 2D E9 01 00 50 E1 00 60 A0 E1 37 00 00 0A 04 00 96 E5 00 90 A0 E3 01 70 A0 E1 09 50 A0 E1 00 90 C0 E5 01 01 96 E8 08 10 90 E5 06 00 A0 E1 31 FF 2F E1", [this](memory::handle handle)
		{
			m_Render_DrawMdlCreateArgs_SetPathInfoNoLoad = handle.as<decltype(m_Render_DrawMdlCreateArgs_SetPathInfoNoLoad)>();
		});

		batch.add("Object::Actor3DMdl::createModel", "70 40 2D E9 00 40 A0 E1 02 00 B0 E1 01 50 A0 E1 03 00 00 1A C4 00 A0 E3 ? ? ? EB 00 00 50 E3 ? ? ? 1B", [this](memory::handle handle)
		{
			m_Object_Actor3DMdl_createModel = handle.as<decltype(m_Object_Actor3DMdl_createModel)>();
		});
		
		batch.add("Item::ItemObjBase::setVisible", "70 40 2D E9 00 00 52 E3 00 40 A0 E1 01 5C 80 E2 98 11 C0 E5 03 00 00 0A 01 20 A0 E1 60 11 94 E5 D6 05 D5 E1 ? ? ? EB", [this](memory::handle handle)
		{
			m_Item_ItemObjBase_setVisible = handle.as<decltype(m_Item_ItemObjBase_setVisible)>();
		});

		batch.add("System::KDPadDirector::calc", "01 10 A0 13 85 10 C0 15 08 10 92 E5 04 20 91 E5 0C 10 91 E5 02 10 81 E1 02 08 11 E3 01 07 11 03 02 07 11 03 85 30 C0 15", [this](memory::handle handle)
		{
			m_System_KDPadDirector_calc_0xEC = handle.as<decltype(m_System_KDPadDirector_calc_0xEC)>();
		});

		batch.add("Kart::VehicleReact::calcReact", "F0 4F 2D E9 00 40 A0 E1 03 9B 80 E2 ? ? 9F ED 06 8B 2D ED 4C D0 4D E2 B0 0A 89 ED B5 0A 89 ED A3 00 D0 E5", [this](memory::handle handle)
		{
			m_Kart_VehicleReact_calcReact_0x20 = handle.add(0x20).as<decltype(m_Kart_VehicleReact_calcReact_0x20)>();
		});

		batch.add("UI::MenuCaption::animKeep", "70 40 2D E9 00 40 A0 E1 68 00 90 E5 01 50 A0 E3 00 10 90 E5 A0 20 91 E5 05 10 A0 E1 32 FF 2F E1 28 50 C4 E5 64 00 94 E5", [this](memory::handle handle)
		{
			m_UI_MenuCaption_animKeep = handle.as<decltype(m_UI_MenuCaption_animKeep)>();
		});

		batch.add("UI::BaseFastControl::setPosX", "00 00 91 E5 80 10 80 E2 0A 0A 80 ED 0C 00 90 E5 00 00 50 E3 03 0A 81 0D 02 00 00 0A 23 0A D0 ED 80 0A 30 EE 03 0A 81 ED 1E FF 2F E1", [this](memory::handle handle)
		{
			m_UI_BaseFastControl_setPosX = handle.as<decltype(m_UI_BaseFastControl_setPosX)>();
		});

		batch.add("UI::BaseFastControl::setPosY", "00 00 91 E5 80 10 80 E2 0B 0A 80 ED 0C 00 90 E5 00 00 50 E3 07 0A 81 0D 02 00 00 0A 27 0A D0 ED 80 0A 30 EE 07 0A 81 ED 1E FF 2F E1", [this](memory::handle handle)
		{
			m_UI_BaseFastControl_setPosY = handle.as<decltype(m_UI_BaseFastControl_setPosY)>();
		});

		batch.add("Sequence::BaseRacePage::onPagePreStep", "6C 02 94 E5 31 5C 84 E2 01 00 50 E3 FA 00 D5 05 00 00 50 03 03 00 00 1A 06 00 A0 E1 ? ? ? EB ? ? 9F E5 04 00 C1 E7", [this](memory::handle handle)
		{
			m_Sequence_BaseRacePage_onPagePreStep = handle.sub(0x30).as<decltype(m_Sequence_BaseRacePage_onPagePreStep)>();
		});

		batch.add("Util::TIndLinkList<T>::append", "00 30 91 E5 00 20 A0 E3 00 00 53 E3 04 30 91 05 00 00 53 03 01 00 00 0A 02 00 A0 E1 1E FF 2F E1", [this](memory::handle handle)
		{
			m_Util_TIndLinkList_UI_Control_append = handle.as<decltype(m_Util_TIndLinkList_UI_Control_append)>();
		});

		batch.add("Sequence::BaseRacePage::initCaption", "00 B0 A0 E3 25 2E 84 E2 68 B0 C4 E5 06 00 92 E8 02 00 51 E1 04 00 00 AA 58 32 94 E5 01 01 83 E7 50 12 94 E5 01 10 81 E2 50 12 84 E5 18 03 84 E5", [this](memory::handle handle)
		{
			m_Sequence_BaseRacePage_initCaption = handle.sub(0xF4).as<decltype(m_Sequence_BaseRacePage_initCaption)>();

			auto hnd = memory::handle(reinterpret_cast<void *>(m_Sequence_BaseRacePage_initCaption));

			m_UI_VisualControl_CreateArg_sub_object = hnd.add(0x58).jmp().as<decltype(m_UI_VisualControl_CreateArg_sub_object)>();
			m_UI_ControlAnimator_AnimationDefine_sub_object = hnd.add(0x64).jmp().as<decltype(m_UI_ControlAnimator_AnimationDefine_sub_object)>();
			m_UI_BaseMenuViewControl_ctor = hnd.add(0x94).jmp().as<decltype(m_UI_BaseMenuViewControl_ctor)>();
			m_UI_ControlInitializer_initCreateArg = hnd.add(0xE0).jmp().as<decltype(m_UI_ControlInitializer_initCreateArg)>();
			m_UI_ControlInitializer_endSetupControl = hnd.add(0xF0).jmp().as<decltype(m_UI_ControlInitializer_endSetupControl)>();

			m_UI_VisualControl_CreateArg_AnimationDefine_vtbl = *hnd.add(0x230).as<decltype(m_UI_VisualControl_CreateArg_AnimationDefine_vtbl) *>();
			m_UI_VisualControl_CreateArg_vtbl = *hnd.add(0x22C).as<decltype(m_UI_VisualControl_CreateArg_vtbl) *>();
			m_UI_BaseMenuViewControl_vtbl = *hnd.add(0x234).as<decltype(m_UI_BaseMenuViewControl_vtbl) *>();
		});
		
		batch.add("__c89vswprintf", "78 40 2D E9 02 C0 A0 E1 01 40 B0 E1 ? ? 2D E5 03 20 A0 E1 ? ? 9F E5 ? ? 8D E5 84 00 80 10 02 00 40 12 03 30 8F E0", [this](memory::handle handle)
		{
			m_c89vswprintf = handle.as<decltype(m_c89vswprintf)>();
		});

		batch.add("Item::ItemDirector::clearItem", "05 01 91 87 ? ? ? EB 00 00 50 E3 21 00 00 1A C0 00 94 E5 05 00 50 E1 C8 10 94 85 00 00 A0 93 05 01 91 87 00 10 A0 E3 ? ? ? EB 05 00 A0 E1 00 F0 20 E3 ? ? ? EB 10 10 97 E5", [this](memory::handle handle)
		{
			m_Item_itemDirector_clearItem = handle.sub(0x60).as<decltype(m_Item_itemDirector_clearItem)>();

			auto hnd = memory::handle(reinterpret_cast<void *>(m_Item_itemDirector_clearItem));

			m_Item_ItemSlot_clear = hnd.add(0x88).jmp().add(0xB4).jmp().as<decltype(m_Item_ItemSlot_clear)>();

			m_Sequence_Sub_LostItem = hnd.add(0x94).jmp().as<decltype(m_Sequence_Sub_LostItem)>();
		});

		batch.add("UI::MenuCaption::animOut", "10 40 2D E9 64 40 90 E5 08 10 94 E5 00 20 91 E5 14 10 92 E5 03 00 51 E3 00 00 51 13", [this](memory::handle handle)
		{
			m_UI_MenuCaption_animOut = handle.as<decltype(m_UI_MenuCaption_animOut)>();
		});

		batch.add("UI::MenuCaption::animIn", "70 40 2D E9 00 40 A0 E1 64 00 90 E5 00 10 A0 E3 08 00 90 E5 00 00 90 E5 14 00 90 E5 01 00 50 E3 02 00 50 13 A8 10 84 05", [this](memory::handle handle)
		{
			m_UI_MenuCaption_animIn = handle.as<decltype(m_UI_MenuCaption_animIn)>();
		});
		
		batch.run();
		
		g_pointers = this;
	}

	pointers::~pointers()
	{
		g_pointers = nullptr;
	}
}