#include <base/hooking.hpp>

#include <base/features.hpp>
#include <base/pointers.hpp>

namespace base
{
    void    hooks::Item_ItemObjKiller_stateStand(Item::ItemObjBase *item_obj)
    {
        (item_obj->m_item_type == Item::eItemType::Killer && !cfg.squishy) ? g_pointers->m_Item_ItemObjBase_stateStand(item_obj) : g_pointers->m_Item_ItemObjBanana_stateStand(item_obj);
    }
}