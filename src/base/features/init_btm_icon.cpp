#include <base/features.hpp>

#include <Item/ItemDirector.hpp>

namespace base
{
    void    features::init_btm_icon(Sequence::BaseRacePage *base_race_page)
    {
        auto bg_race_map_item_control = reinterpret_cast<UI::BgRaceMapItemControl *>(reinterpret_cast<u32>(base_race_page) + 0x30A0);

        auto item_control_array = &bg_race_map_item_control->controls[std::to_underlying(Item::eItemType::Killer)];
        
        auto item_obj_array = &Item::GetDirector()->m_killer_director->m_it.m_ptr_array;

        if (item_control_array->capacity())
        {
            for (size_t i = 0; i < item_control_array->size(); i++)
            {
                auto entry = item_control_array->at(i);

                entry->item_obj = item_obj_array->at(i);

                memcpy(entry->tex_handle, bg_race_map_item_control->map_killer_r90_handle, sizeof(bg_race_map_item_control->map_killer_r90_handle));
            }
        }
    }
}