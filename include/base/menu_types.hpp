#pragma once

#include <types.h>

#include <Item/eItemSlot.hpp>

namespace base::menu_types
{
    struct item_cycler_data_t
    {
        Item::eItemSlot m_item = Item::eItemSlot::Empty;
        size_t m_iterator = SIZE_MAX;
    };

    struct debug_killer_data_t
    {
        bool m_item_rain = false;
        size_t m_iterator = SIZE_MAX;
    };
}