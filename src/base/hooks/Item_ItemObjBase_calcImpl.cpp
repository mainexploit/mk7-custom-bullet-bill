#include <base/hooking.hpp>

#include <base/features.hpp>

namespace base
{
    void    hooks::Item_ItemObjBase_calcImpl(Item::ItemObjBase *item_obj)
    {
        g_hooking->m_Item_ItemObjBase_calcImpl_hook.call_original<void, Item::ItemObjBase *>(item_obj);

        features::change_multi_size(item_obj);
    }
}