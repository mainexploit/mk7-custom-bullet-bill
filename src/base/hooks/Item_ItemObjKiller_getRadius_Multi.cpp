#include <base/hooking.hpp>

namespace base
{
    float   hooks::Item_ItemObjKiller_getRadius_Multi(Item::ItemObjBase *item_obj)
    {
        return (item_obj->m_multi_amount < 1 ? 15.f : 20.f);
    }
}