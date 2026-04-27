#include <base/features.hpp>

namespace base
{
    float    features::calc_throw_height(Item::ItemObjBase *item_obj, float scale, float height)
    {
        return ((item_obj->m_item_type == Item::eItemType::Killer) ? 0.1f : scale) * height;
    }
}