#include <base/menu.hpp>

#include <base/entries.hpp>
#include <base/patches.hpp>
#include <base/settings.hpp>

#include <Unicode.h>
#include <format>

#define DEFAULT_ENTRY [](MenuEntry *) {}
#define MENU_TYPE 1

namespace base
{
    using namespace CTRPluginFramework;

    menu::menu()
    :
        m_plugin_menu(new PluginMenu(NAME, ABOUT, MENU_TYPE)),

        m_item_cycler_entry(new MenuEntry("Item Cycler", entries::item_cycler)),
        m_drop_equip_entry(new MenuEntry("Drop Equip", entries::drop_equip)),
        m_clear_all_items_entry(new MenuEntry("Clear All Items", entries::clear_all_items)),
        m_debug_item_killer_entry(new MenuEntry("Debug itemKiller", entries::debug_item_killer))
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
        bool is_citra = CTRPluginFramework::System::IsCitra();

        m_item_cycler_entry->Note() = std::format("\nCycle Items: {} & {}\n\nClear Item: {}",
            (is_citra ? "D-Pad Left" : FONT_DL), (is_citra ? "D-Pad Right" : FONT_DR), (is_citra ? "D-Pad Down" : FONT_DD));;

        m_drop_equip_entry->Note() = std::format("\n\nDrop Equipment: {}", (is_citra ? "X" : FONT_X));

        m_clear_all_items_entry->Note() = std::format("\n\nVanish Items: {}", (is_citra ? "Y" : FONT_Y));

        m_debug_item_killer_entry->Note() = std::format("\nEquippable Item: {}\nThrowable Item: {}\nTrailing Item: {}\nItem Rain: {}",
            (is_citra ? "ZR" : FONT_ZR), (is_citra ? "ZL" : FONT_ZL), (is_citra ? "D-Pad Up" : FONT_DU), (is_citra ? "R" : FONT_R));

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