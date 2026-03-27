#include <base/features.hpp>

#include <Kart/Vehicle/Vehicle.hpp>
#include <Item/ItemDirector.hpp>
#include <Item/KartItem.hpp>
#include <base/pointers.hpp>

namespace base
{
    bool    features::kart_reaction(Item::ItemObjBase *item_obj, Kart::Vehicle *vehicle)
    {
        if (item_obj->m_item_type == Item::eItemType::Killer)
        {
            auto item_director = Item::GetDirector();

            auto kart_item = item_director->m_kart_items.at(vehicle->m_player_id);

            item_director->m_killer_director->entry(kart_item->m_info_proxy, false, -1);

            g_pointers->m_Item_ItemObjBase_exit_Vanish(item_obj);

            return true;
        }

        return false;
    }
}