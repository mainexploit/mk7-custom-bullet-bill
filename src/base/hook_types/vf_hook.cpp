#include <base/hook_types/vf_hook.hpp>

#include <base/logger.hpp>

namespace base::hook_types
{	
    vf_hook::vf_hook(std::string_view name, void *obj, size_t num_funcs)
    :
		m_name(std::move(name)),
		m_object(static_cast<void **>(obj)),
		m_num_funcs(num_funcs),
		m_current_table(m_object),
		m_original_table(std::make_unique<void *[]>(m_num_funcs))
	{
		memcpy(m_original_table.get(), m_object, m_num_funcs);
		g_logger.debug("VF hook '{}' created.", m_name);
	}

	vf_hook::~vf_hook()
	{
        g_logger.debug("VF hook '{}' deleted.", m_name);
	}

	void vf_hook::hook(size_t index, void *func)
	{
		m_current_table[index] = func;
		g_logger.debug("VF hook member '{}[{}]' hooked.", m_name, index);
	}

	void vf_hook::unhook(size_t index)
	{
		m_current_table[index] = m_original_table[index];
		g_logger.debug("VF hook member '{}[{}]' unhooked.", m_name, index);
	}

	void vf_hook::enable()
	{
		memcpy(m_object, m_current_table, m_num_funcs);
		g_logger.debug("VF hook '{}' enabled.", m_name);
	}

	void vf_hook::disable()
	{
		memcpy(m_object, m_original_table.get(), m_num_funcs);
		g_logger.debug("VF hook '{}' disabled.", m_name);
	}
}