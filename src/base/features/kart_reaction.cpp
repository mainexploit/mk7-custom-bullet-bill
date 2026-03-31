#include <base/features.hpp>

#include <Kart/Vehicle/Vehicle.hpp>
#include <Item/ItemDirector.hpp>
#include <Item/KartItem.hpp>
#include <base/pointers.hpp>

namespace base
{
    void    features::kart_reaction(Item::ItemObjBase *item_obj, Kart::Vehicle *vehicle)
    {
        if (item_obj->m_item_type == Item::eItemType::Killer && item_obj->m_col_mode != Item::ItemObjBase::eColMode::None)
        {
            auto killer_director = reinterpret_cast<Item::ItemObjDirectorBase *>(item_obj->m_parent);
            
            auto kart_item = Item::GetDirector()->m_kart_items.at(vehicle->m_player_id);

            killer_director->entry(kart_item->m_info_proxy, false, -1);
        }
    }
}