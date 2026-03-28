#include <base/hooking.hpp>

namespace base
{
    float   hooks::Item_ItemObjKiller_getColRadius(Item::ItemObjBase *item_obj)
    {
        return 14.f;
    }
}