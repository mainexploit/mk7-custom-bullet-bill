#include <base/hooking.hpp>

#include <base/features.hpp>

namespace base
{
    void    hooks::Item_ItemObjBase_setState_SelfMove(Item::ItemObjBase *item_obj, sead::Vector2f *move)
    {
        if (features::consume_equip(item_obj))
            return;

        g_hooking->m_Item_ItemObjBase_setState_SelfMove_hook.call_original<void, Item::ItemObjBase *, sead::Vector2f *>(item_obj, move);
    }
}