#include <base/hooking.hpp>

#include <base/features.hpp>
#include <base/pointers.hpp>

namespace base
{
    void    hooks::Sequence_BaseRacePage_onPagePreStep(Sequence::BaseRacePage *base_race_page)
    {
        g_hooking->m_Sequence_BaseRacePage_onPagePreStep_hook.call_original<void, Sequence::BaseRacePage *>(base_race_page);

        features::calc_caption(base_race_page);
    }
}