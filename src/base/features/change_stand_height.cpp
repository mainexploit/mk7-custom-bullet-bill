#include <base/features.hpp>

#include <Kart/InfoProxy.hpp>

namespace base
{
    float     features::change_stand_height(Item::ItemObjBase *item_obj, float height)
    {
        return (item_obj->m_item_type == Item::eItemType::Killer) ? 50.f : height;
    }
}