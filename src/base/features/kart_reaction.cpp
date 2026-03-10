#include <base/features.hpp>

#include <Kart/Vehicle/Vehicle.hpp>
#include <Item/ItemDirector.hpp>
#include <base/pointers.hpp>

namespace base
{
    bool    features::kart_reaction(Item::ItemObjBase *item_obj, Kart::Vehicle *vehicle)
    {
        if (item_obj->m_item_type == Item::eItemType::Killer)
        {
            if (vehicle->m_is_master)
                cfg.collided = true;
            
            g_pointers->m_Item_ItemObjBase_react_Break(item_obj);

            auto item_director = Item::GetDirector();

            auto kart_item = item_director->m_kart_items.at(vehicle->m_player_id);

            g_pointers->m_Item_ItemDirector_entryItem(item_director, Item::eItemSlot::Killer, kart_item);

            return true;
        }

        return false;
    }
}