#include <base/hooking.hpp>

namespace base
{
    float   hooks::Item_ItemObjKiller_getRotVelRatio_Multi(Item::ItemObjBase *item_obj)
    {
        return (item_obj->m_multi_amount < 1 ? 0.12f : 0.05f);
    }
}