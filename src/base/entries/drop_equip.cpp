#include <base/entries.hpp>

#include <Item/ItemDirector.hpp>
#include <base/pointers.hpp>
#include <base/utils.hpp>

namespace base
{
    using namespace CTRPluginFramework;

    void    entries::drop_equip(MenuEntry *entry)
    {
        if (Controller::IsKeyPressed(X) && utils::in_race() && !utils::is_paused())
            g_pointers->m_Item_KartItem_dropEquip(Item::GetDirector()->m_kart_items.at(utils::get_master_id()));
    }
}