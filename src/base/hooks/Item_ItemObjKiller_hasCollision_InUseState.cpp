#include <base/hooking.hpp>

namespace base
{
    bool    hooks::Item_ItemObjKiller_hasCollision_InUseState(Item::ItemObjBase *item_obj)
    {
        return true;
    }
}