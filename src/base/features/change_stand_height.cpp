#include <base/features.hpp>

namespace base
{
    float     features::change_height(Item::ItemObjBase *item_obj, float height)
    {
        return (item_obj->m_item_type == Item::eItemType::Killer) ? 10.f : height;
    }
}