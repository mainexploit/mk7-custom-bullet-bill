#include <base/hooking.hpp>

namespace base
{
    float   hooks::Item_ItemObjKiller_getOffset_Multi_Y(Item::ItemObjBase *item_obj)
    {
        return 5.5f;
    }
}