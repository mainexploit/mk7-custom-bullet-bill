#pragma once

#include <memory>
#include <string_view>

namespace base::hook_types
{
    class vf_hook
	{
	public:
		explicit vf_hook(std::string_view name, void *obj, size_t num_funcs);
		~vf_hook();

		vf_hook(vf_hook &&) = delete;
		vf_hook(vf_hook const &) = delete;
		vf_hook &operator=(vf_hook &&) = delete;
		vf_hook &operator=(vf_hook const &) = delete;

		void hook(size_t index, void *func);
		void unhook(size_t index);

		void enable();
		void disable();

		template <typename t>
		t get_original(size_t index);

	private:
		std::string_view m_name;
		void **m_object;
		std::size_t m_num_funcs;
		void **m_current_table;
		std::unique_ptr<void *[]> m_original_table;
	};

	template <typename t>
	inline t vf_hook::get_original(size_t index)
	{
		return reinterpret_cast<t>(m_original_table[index]);
	}
}