#include <base/hooking.hpp>

#include <base/features.hpp>

namespace base
{
    void    hooks::Item_ItemDirector_doReaction(Item::ItemDirector *item_director, Item::ItemObjBase *item_obj, Item::ItemObjBase *collided_item_obj, Item::eItemReact *item_obj_react, Item::eItemReact *collided_item_obj_react, sead::Vector3f *item_obj_position, sead::Vector3f *collided_item_obj_position)
    {
        features::item_reaction(item_obj, collided_item_obj, item_obj_react, collided_item_obj_react);

        g_hooking->m_Item_ItemDirector_doReaction_hook.call_original<void, Item::ItemDirector *, Item::ItemObjBase *, Item::ItemObjBase *, Item::eItemReact *, Item::eItemReact *, sead::Vector3f *, sead::Vector3f *>(item_director, item_obj, collided_item_obj, item_obj_react, collided_item_obj_react, item_obj_position, collided_item_obj_position);
    }
}