#include <base/hooking.hpp>

#include <Item/KartItem.hpp>
#include <base/features.hpp>
#include <base/pointers.hpp>
#include <base/types.hpp>

namespace base
{
    void    hooks::Item_KartItem_calcBeforeStructure(Item::KartItem *kart_item)
    {
        if (kart_item->m_equip_type == Item::eEquipType::Multi && kart_item->m_equip_item == Item::eItemSlot::Killer ||
            kart_item->m_equip_item == Item::eItemSlot::KouraG3 || kart_item->m_equip_item == Item::eItemSlot::KouraR3 || kart_item->m_equip_item == Item::eItemSlot::Seven)
        {
            Sound::SndID current_sound = Sound::SndID::SingleRotate;
            
            if (kart_item->m_equip_item_amount >= 3)
                current_sound = Sound::SndID::TripleRotate;
            else if (kart_item->m_equip_item_amount == 2)
                current_sound = Sound::SndID::DoubleRotate;

            g_pointers->m_Sound_SndActorKart_holdSound(kart_item->m_info_proxy->m_vehicle->m_snd_actor_kart, current_sound, nullptr);
        }
    }
}