#include <base/hooking.hpp>

#include <base/pointers.hpp>

namespace base
{
    void    hooks::Item_ItemObjKiller_stateInitSelfMove(Item::ItemObjBase *item_obj)
    {
        item_obj->m_is_dropped = true;

        g_pointers->m_Item_ItemObjBase_stateInitSelfMove(item_obj);
    }
}