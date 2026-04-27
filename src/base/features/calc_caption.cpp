#include <base/features.hpp>

#include <magic_enum/magic_enum.hpp>
#include <base/utils.hpp>

namespace base
{
    void    features::calc_caption(Sequence::BaseRacePage *base_race_page)
    {
        const auto data = GetArg<menu_types::debug_killer_data_t>(g_menu->m_debug_item_killer_entry);
        
        g_menu->m_caption.printf
        (
            "State: {}\n"
            "Self Move: {}\n"
            "Item Rain: {}",
            std::string(magic_enum::enum_name(g_menu->m_config.m_state)),
            (g_menu->m_config.m_self_move ? "ON" : "OFF"),
            (data->m_item_rain ? "ON" : "OFF")
        );
    }
}