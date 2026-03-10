#include <base/features.hpp>

#include <Item/ItemDirector.hpp>
#include <base/pointers.hpp>

namespace base
{
    bool    features::consume_equip(Item::ItemObjBase *item_obj)
    {
        if (!cfg.selfmove)
        {
            if (item_obj->m_item_type == Item::eItemType::Killer)
            {
                Item::GetDirector()->m_killer_director->entry(item_obj->m_info_proxy, false, -1);

                g_pointers->m_Item_ItemObjBase_exit_Vanish(item_obj);

                return true;
            }
        }

        return false;
    }
}