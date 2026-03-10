#include <base/hooking.hpp>

#include <base/features.hpp>

namespace base
{
    void    hooks::Item_ItemObjBase_stateStand(Item::ItemObjBase *item_obj)
    {
        if (features::disable_tc_board(item_obj))
            return;

        g_hooking->m_Item_ItemObjBase_stateStand_hook.call_original<void, Item::ItemObjBase *>(item_obj);
    }
}