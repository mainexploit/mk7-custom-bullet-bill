#include <base/entries.hpp>

#include <Item/ItemDirector.hpp>
#include <base/pointers.hpp>
#include <base/utils.hpp>

#define MAX_TIME_ALIVE 0x1000

namespace base
{
    using namespace CTRPluginFramework;

    void    entries::clear_all_items(MenuEntry *entry)
    {
        if (Controller::IsKeyPressed(Y) && utils::in_race() && !utils::is_paused())
        {
            auto item_director = Item::GetDirector();

            for (size_t i = 0; i < item_director->m_equip_item_objs.size(); i++)
                if (auto instance = item_director->m_equip_item_objs.at(i))
                    instance->m_current_life = MAX_TIME_ALIVE;
            
            for (size_t i = 0; i < item_director->m_selfmove_item_objs.size(); i++)
                if (auto instance = item_director->m_selfmove_item_objs.at(i))
                    instance->m_current_life = MAX_TIME_ALIVE;
            
            for (size_t i = 0; i < item_director->m_stand_item_objs.size(); i++)
                if (auto instance = item_director->m_stand_item_objs.at(i))
                    instance->m_current_life = MAX_TIME_ALIVE;
        }
    }
}