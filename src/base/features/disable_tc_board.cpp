#include <base/features.hpp>

namespace base
{
    bool    features::disable_tc_board(Item::ItemObjBase *item_obj)
    {
        if (item_obj->m_item_type == Item::eItemType::Killer)
        {
            item_obj->m_is_tc_board_area = false;

            return true;
        }

        return false;
    }
}