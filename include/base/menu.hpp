#pragma once

#include <ctrpf.hpp>

#include <base/menu_types.hpp>
#include <get_arg.hpp>

namespace base
{
    class menu
    {
    public:
		explicit menu();
		~menu();

        void run();

    private:
        friend struct entries;
        friend class features;
        
        void create();
        void finalize();

        CTRPluginFramework::PluginMenu *m_plugin_menu;

        CTRPluginFramework::MenuEntry *m_item_cycler_entry;
        CTRPluginFramework::MenuEntry *m_drop_equip_entry;
        CTRPluginFramework::MenuEntry *m_clear_all_items_entry;
        CTRPluginFramework::MenuEntry *m_debug_item_killer_entry;
    };

    inline menu *g_menu{};
}