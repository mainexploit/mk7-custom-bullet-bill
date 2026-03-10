#include <base/menu.hpp>

#include <base/entries.hpp>
#include <base/patches.hpp>
#include <base/settings.hpp>

#include <Unicode.h>

#define DEFAULT_ENTRY [](MenuEntry *) {}
#define MENU_TYPE 1

#define ITEM_CYCLER_NOTE "\nCycle Items: " FONT_DL " & " FONT_DR "\n\nClear Item: " FONT_DD
#define DROP_EQUIP_NOTE "\n\nDrop Equipment: " FONT_X
#define CLEAR_ITEMS_NOTE "\n\nVanish Items: " FONT_Y
#define DEBUG_ITEM_KILLER_NOTE "\nEquippable Item: " FONT_ZR "\nThrowable Item: " FONT_ZL "\nTrailing Item: " FONT_DU "\nItem Rain: " FONT_R

namespace base
{
    using namespace CTRPluginFramework;

    menu::menu()
    :
        m_plugin_menu(new PluginMenu(NAME, ABOUT, MENU_TYPE)),

        m_item_cycler_entry(new MenuEntry("Item Cycler", entries::item_cycler, ITEM_CYCLER_NOTE)),
        m_drop_equip_entry(new MenuEntry("Drop Equip", entries::drop_equip, DROP_EQUIP_NOTE)),
        m_clear_all_items_entry(new MenuEntry("Clear All Items", entries::clear_all_items, CLEAR_ITEMS_NOTE)),
        m_debug_item_killer_entry(new MenuEntry("Debug itemKiller", entries::debug_item_killer, DEBUG_ITEM_KILLER_NOTE))
    {
        m_plugin_menu->SynchronizeWithFrame(true);
        m_plugin_menu->ShowWelcomeMessage(false);
        m_plugin_menu->SetHexEditorState(false);

        m_plugin_menu->OnClosing = []() { g_settings.store(); };

        create();
        finalize();

        g_menu = this;
    }

    menu::~menu()
    {
        g_patches->m_Sequence_BaseRacePage_initMapIcon_0x6F8_patch.disable();

        g_menu = nullptr;

        delete m_plugin_menu;
    }

    void menu::run()
    {
        m_plugin_menu->Run();
    }

    void menu::create()
    {
        *m_plugin_menu += m_item_cycler_entry;
        *m_plugin_menu += m_drop_equip_entry;
        *m_plugin_menu += m_clear_all_items_entry;
        *m_plugin_menu += m_debug_item_killer_entry;
    }

    void menu::finalize()
    {
        if (auto data = GetArg<menu_types::item_cycler_data_t>(m_item_cycler_entry))
        {
            data->item = Item::eItemSlot::Empty;
            data->iterator = SIZE_MAX;
        }

        if (auto data = GetArg<menu_types::debug_killer_data_t>(m_debug_item_killer_entry))
        {
            data->print = false;
            data->item_rain = false;
            data->iterator = SIZE_MAX;
        }

        g_patches->m_Sequence_BaseRacePage_initMapIcon_0x6F8_patch.enable();
    }
}