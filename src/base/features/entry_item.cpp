#include <base/features.hpp>

#include <Item/ItemDirector.hpp>
#include <Item/KartItem.hpp>

namespace base
{
    bool    features::entry_item(Item::ItemDirector *item_director, Item::eItemSlot item_slot, Item::KartItem *kart_item)
    {
        if (item_slot == Item::eItemSlot::Killer)
        {
            if (!kart_item->m_info_proxy->isMaster())
            {
                item_director->m_killer_director->entry(kart_item->m_info_proxy, false, -1);

                return true;
            }

            switch (g_menu->m_config.m_state)
            {
                case Debug::EntryState::Use:
                    item_director->m_killer_director->entry(kart_item->m_info_proxy, false, -1);
                break;

                case Debug::EntryState::Hang:
                    if (item_director->m_killer_director->entry(kart_item->m_info_proxy, true, -1))
                        kart_item->setEquipInfo(item_slot, Item::eEquipType::Hang, 1, true);
                break;

                case Debug::EntryState::Multi:
                    if (item_director->m_killer_director->entry(kart_item->m_info_proxy, false, 3))
                        kart_item->setEquipInfo(item_slot, Item::eEquipType::Multi, 3, true);
                break;

                case Debug::EntryState::Seven:
                    if (item_director->m_killer_director->entry(kart_item->m_info_proxy, false, 7))
                        kart_item->setEquipInfo(item_slot, Item::eEquipType::Multi, 7, true);
                break;
            }
            
            return true;
        }

        return false;
    }
}