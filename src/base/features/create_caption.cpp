#include <base/features.hpp>

#include <base/utils.hpp>

namespace base
{
    void    features::create_caption(Sequence::BaseRacePage *base_race_page)
    {
        g_menu->m_caption->init(base_race_page);

        g_menu->m_caption->set_color(nw::ut::Color8(255, 250, 200, 255), nw::lyt::TEXTCOLOR_TOP);
        g_menu->m_caption->set_color(nw::ut::Color8(255, 250, 0, 255), nw::lyt::TEXTCOLOR_BOTTOM);
        g_menu->m_caption->set_line_space(-3.0f);
        g_menu->m_caption->set_text_alignment(nw::lyt::ALIGN_TOP_LEFT);
    }
}