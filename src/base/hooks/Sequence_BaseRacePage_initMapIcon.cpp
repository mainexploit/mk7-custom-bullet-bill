#include <base/hooking.hpp>

#include <base/features.hpp>

namespace base
{
    void    hooks::Sequence_BaseRacePage_initMapIcon(Sequence::BaseRacePage *base_race_page)
    {
        g_hooking->m_Sequence_BaseRacePage_initMapIcon_hook.call_original<void, Sequence::BaseRacePage *>(base_race_page);

        features::init_btm_icon(base_race_page);
    }
}