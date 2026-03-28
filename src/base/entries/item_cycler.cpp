#include <base/entries.hpp>

#include <RaceSys/RaceDirector.hpp>
#include <Item/ItemDirector.hpp>
#include <Item/KartItem.hpp>
#include <Item/eItemSlot.hpp>

#include <base/pointers.hpp>
#include <base/patches.hpp>
#include <base/utils.hpp>
#include <base/menu.hpp>

static constexpr std::array<Item::eItemSlot, 18> items =
{
    Item::eItemSlot::Banana,
    Item::eItemSlot::KouraG,
    Item::eItemSlot::KouraR,
    Item::eItemSlot::Kinoko,
    Item::eItemSlot::Bomhei,
    Item::eItemSlot::Gesso,
    Item::eItemSlot::KouraB,
    Item::eItemSlot::Kinoko3,
    Item::eItemSlot::Star,
    Item::eItemSlot::Killer,
    Item::eItemSlot::Thunder,
    Item::eItemSlot::KinokoP,
    Item::eItemSlot::Flower,
    Item::eItemSlot::Tail,
    Item::eItemSlot::Seven,
    Item::eItemSlot::Banana3,
    Item::eItemSlot::KouraG3,
    Item::eItemSlot::KouraR3
};

namespace base
{
    using namespace CTRPluginFramework;
    
    void    entries::item_cycler(MenuEntry *entry)
    {
        auto const data = GetArg<menu_types::item_cycler_data_t>(g_menu->m_item_cycler_entry);

        if (entry->WasJustActivated())
        {
            g_patches->m_Item_ItemDirector_initAfterStructure_0x14_patch.enable();
            g_patches->m_Item_KartItem_setItemForce_0x28_patch.enable();

            data->m_item = Item::eItemSlot::Empty;
            data->m_iterator = 0;

            if (utils::in_race())
                g_pointers->m_Item_itemDirector_clearItem(Item::GetDirector(), utils::get_master_id());
        }
        
        if (entry->IsActivated())
        {
            if (utils::in_race())
            {
                if (!utils::is_paused())
                {
                    auto kart_item = Item::GetDirector()->m_kart_items.at(utils::get_master_id());

                    if (data->m_item != Item::eItemSlot::Empty)
                        if (kart_item->m_stock_item != data->m_item)
                            g_pointers->m_Item_KartItem_setItemForce(kart_item, data->m_item);

                    if (Controller::IsKeyPressed(DPadLeft))
                    {
                        utils::get_next_index(data->m_iterator, (items.size() - 1), true);

                        data->m_item = items.at(data->m_iterator);

                        g_pointers->m_Item_KartItem_setItemForce(kart_item, data->m_item);
                    }
                    else if (Controller::IsKeyPressed(DPadRight))
                    {
                        utils::get_next_index(data->m_iterator, (items.size() - 1), false);

                        data->m_item = items.at(data->m_iterator);

                        g_pointers->m_Item_KartItem_setItemForce(kart_item, data->m_item);
                    }
                    else if (Controller::IsKeyPressed(DPadDown))
                    {
                        data->m_item = Item::eItemSlot::Empty;
                        data->m_iterator = 0;

                        if (kart_item->m_stock_item != Item::eItemSlot::Empty)
                        {
                            g_pointers->m_Item_ItemSlot_clear(kart_item->m_item_slot);

                            g_pointers->m_Sequence_Sub_LostItem(utils::get_master_id());
                        }
                    }
                }
            }
            else if (data->m_item != Item::eItemSlot::Empty)
            {
                data->m_item = Item::eItemSlot::Empty;
                data->m_iterator = 0;
            }
        }
        else
        {
            g_patches->m_Item_ItemDirector_initAfterStructure_0x14_patch.disable();
            g_patches->m_Item_KartItem_setItemForce_0x28_patch.disable();

            data->m_item = Item::eItemSlot::Empty;
            data->m_iterator = 0;
            
            if (utils::in_race())
                g_pointers->m_Item_itemDirector_clearItem(Item::GetDirector(), utils::get_master_id());
        }
    }
}