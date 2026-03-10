#include <base/hooking.hpp>

#include <base/features.hpp>

namespace base
{
    void    hooks::Item_ItemDirector_entryItem(Item::ItemDirector *item_director, Item::eItemSlot item_slot, Item::KartItem *kart_item)
    {
        if (features::entry_item(item_director, item_slot, kart_item))
            return;

        g_hooking->m_Item_ItemDirector_entryItem_hook.call_original<void, Item::ItemDirector *, Item::eItemSlot, Item::KartItem *>(item_director, item_slot, kart_item);
    }
}