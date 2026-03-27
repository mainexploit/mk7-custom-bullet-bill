#include <base/hooking.hpp>

#include <base/features.hpp>
#include <base/pointers.hpp>

namespace base
{
    void    hooks::Item_ItemObjKiller_stateEquip_Multi(Item::ItemObjBase *item_obj)
    {
        item_obj->m_is_multi_trail = false;

        if (g_menu->m_config.m_state == Debug::EntryState::Seven)
            item_obj->m_multi_amount = 7;

        g_pointers->m_Item_ItemObjBase_stateEquip_Multi(item_obj);
    }
}