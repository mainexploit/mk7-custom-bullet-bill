#pragma once

#include <types.h>

#include <Item/eItemSlot.hpp>

namespace base::menu_types
{
    struct item_cycler_data_t
    {
        Item::eItemSlot item;
        size_t iterator;
    };

    struct debug_killer_data_t
    {
        bool print;
        bool item_rain;
        size_t iterator;
    };
}