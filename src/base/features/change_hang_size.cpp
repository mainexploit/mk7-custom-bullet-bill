#include <base/features.hpp>

namespace base
{
    void    features::change_hang_size(Item::ItemObjBase *item_obj)
    {
        if (item_obj->m_item_type == Item::eItemType::Killer)
            item_obj->m_equip_scale = 0.25f;
    }
}