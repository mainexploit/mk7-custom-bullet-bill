#include <base/hooking.hpp>

namespace base
{
    float   hooks::Item_ItemObjKiller_getOffset_Multi_Z(Item::ItemObjBase *item_obj)
    {
        return (item_obj->m_multi_amount < 1 ? 1.f : 4.f);
    }
}