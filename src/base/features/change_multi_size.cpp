#include <base/features.hpp>

namespace base
{
    void    features::change_multi_size(Item::ItemObjBase *item_obj)
    {
        if (item_obj->m_item_type == Item::eItemType::Killer)
            item_obj->m_equip_scale = ((item_obj->m_is_multi_trail || cfg.trailing) ? 0.15f : 0.25f);
    }
}