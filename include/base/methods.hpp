#pragma once

#include <forward.hpp>

#include <math/seadVectorFwd.h>

#include <base/types.hpp>

namespace base::methods
{
	using Item_ItemObjDirectorBase_emitItemImpl_t = void (*)(Item::ItemObjDirectorBase *, s32, const sead::Vector3f *, const sead::Vector3f *);
	using Object_Actor3DMdl_createModel_t = void (*)(Object::Actor3DMdl *, Render::DrawMdlCreateArgs &, Render::DrawMdl *);
	using Render_DrawMdlCreateArgs_SetPathInfoNoLoad_t = void (*)(Render::DrawMdlCreateArgs *, const sead::SafeString &);
	using Sound_SndActorKart_holdSound_t = void (*)(Sound::SndActorKart *, Sound::SndID, Sound::SndHandle *);
	using Item_ItemDirector_entryItem_t = void (*)(Item::ItemDirector *, Item::eItemSlot, Item::KartItem *);
	using Item_ItemObjBase_sub_object_t = Item::ItemObjBase * (*)(void *, Item::eItemType, size_t);
	using Item_KartItem_setItemForce_t = void (*)(Item::KartItem *, Item::eItemSlot);
	using Item_ItemObjBase_setVisible_t = void (*)(Item::ItemObjBase *, bool, bool);
	using Render_DrawMdlCreateArgs_t = Render::DrawMdlCreateArgs (*)(void);
	using ItemObjBase_Instance_t = void (*)(Item::ItemObjBase *);
	using Item_KartItem_dropEquip_t = void (*)(Item::KartItem *);
	using Item_ItemSlot_clear_t = void (*)(Item::ItemSlot *);
	using operator_new_t = void * (*)(size_t count);
}