#include <base/hooking.hpp>

namespace base
{
    float   hooks::Item_ItemObjKiller_getShadowScale(Item::ItemObjBase *item_obj)
    {
        return 40.f;
    }
}