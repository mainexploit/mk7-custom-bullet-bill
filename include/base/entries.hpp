#pragma once

#include <ctrpf.hpp>

namespace base
{
	struct entries
	{
		static void item_cycler(CTRPluginFramework::MenuEntry *);
		static void drop_equip(CTRPluginFramework::MenuEntry *);
		static void clear_all_items(CTRPluginFramework::MenuEntry *);
		static void debug_item_killer(CTRPluginFramework::MenuEntry *);
	};
}