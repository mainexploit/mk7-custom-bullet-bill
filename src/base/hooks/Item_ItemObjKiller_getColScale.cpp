#include <base/hooking.hpp>

namespace base
{
    float   hooks::Item_ItemObjKiller_getColScale(Item::ItemObjBase *item_obj)
    {
        return 0.5f;
    }
}