#include <base/features.hpp>

#include <Item/ItemDirector.hpp>

namespace base
{
    void    features::init_btm_icon(Sequence::BaseRacePage *base_race_page)
    {
        auto bg_race_map_item_control = reinterpret_cast<UI::BgRaceMapItemControl *>(reinterpret_cast<u32>(base_race_page) + 0x30A0);

        if (auto item_control = &bg_race_map_item_control->m_controls[std::to_underlying(Item::eItemType::Killer)])
        {
            if (item_control->capacity())
            {
                auto item_objs = &Item::GetDirector()->m_killer_director->m_it.m_ptr_array;

                for (size_t i = 0; i < item_control->size(); i++)
                {
                    auto entry = item_control->at(i);

                    entry->m_item_obj = item_objs->at(i);

                    memcpy(entry->m_tex_handle, bg_race_map_item_control->m_map_killer_r90_handle, sizeof(bg_race_map_item_control->m_map_killer_r90_handle));
                }
            }
        }
    }
}