#pragma once

#include <math/seadVectorFwd.h>
#include <UI/MenuCaption.hpp>
#include <base/types.hpp>
#include <forward.hpp>

namespace base::methods
{
	using UI_ControlInitializer_initCreateArg_t = void (*)(UI::ControlInitializer *, UI::Control::CreateArg *, const sead::SafeString &, const sead::SafeString &);
	using Item_ItemObjDirectorBase_emitItemImpl_t = void (*)(Item::ItemObjDirectorBase *, s32, const sead::Vector3f *, const sead::Vector3f *);
	using Util_TIndLinkList_UI_Control_append_t = bool (*)(Util::TIndLinkList<UI::Control> *, Util::TLinkNode<UI::Control> *);
	using Object_Actor3DMdl_createModel_t = void (*)(Object::Actor3DMdl *, Render::DrawMdlCreateArgs &, Render::DrawMdl *);
	using Render_DrawMdlCreateArgs_SetPathInfoNoLoad_t = void (*)(Render::DrawMdlCreateArgs *, const sead::SafeString &);
	using UI_BaseFastControl_setPosX_t = void (*)(UI::BaseFastControl *, UI::ControlSight::ElementHandle &, float);
	using UI_BaseFastControl_setPosY_t = void (*)(UI::BaseFastControl *, UI::ControlSight::ElementHandle &, float);
	using UI_ControlInitializer_endSetupControl_t = void (*)(UI::ControlInitializer *, UI::Control::CreateArg *);
	using UI_ControlAnimator_AnimationDefine_sub_object_t = UI::ControlAnimator::AnimationDefine * (*)(void *);
	using Sound_SndActorKart_holdSound_t = void (*)(Sound::SndActorKart *, Sound::SndID, Sound::SndHandle *);
	using Item_ItemDirector_entryItem_t = void (*)(Item::ItemDirector *, Item::eItemSlot, Item::KartItem *);
	using Item_ItemObjBase_sub_object_t = Item::ItemObjBase * (*)(void *, Item::eItemType, size_t);
	using UI_VisualControl_CreateArg_sub_object_t = UI::VisualControl::CreateArg * (*)(void *);
	using Item_KartItem_setItemForce_t = void (*)(Item::KartItem *, Item::eItemSlot);
	using Item_ItemObjBase_setVisible_t = void (*)(Item::ItemObjBase *, bool, bool);
	using Render_DrawMdlCreateArgs_t = Render::DrawMdlCreateArgs (*)(void);
	using UI_BaseMenuViewControl_t = UI::BaseMenuViewControl * (*)(void *);
	using Kart_VehicleMove_startKiller_t = void (*)(Kart::VehicleMove *);
	using UI_MenuCaption_animKeep_t = void (*)(UI::MenuCaption *);
	using ItemObjBase_Instance_t = void (*)(Item::ItemObjBase *);
	using Item_KartItem_dropEquip_t = void (*)(Item::KartItem *);
	using Item_ItemSlot_clear_t = void (*)(Item::ItemSlot *);
	using operator_new_t = void * (*)(size_t count);
}