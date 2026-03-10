#pragma once

#include <3ds/types.h>

#include <map>
#include <set>

namespace base
{
	class settings
	{
	public:
		bool load();
		bool store();
		bool reset();

		struct options
		{
		}
		m_options{};

	private:
		bool load_impl();
	};

	inline settings g_settings;
}
