#include <base/hooking.hpp>

#include <base/features.hpp>

namespace base
{
    void    hooks::Sequence_BaseRacePage_initCaption(Sequence::BaseRacePage *base_race_page)
    {
        g_hooking->m_Sequence_BaseRacePage_initCaption_hook.call_original<void, Sequence::BaseRacePage *>(base_race_page);

        features::create_caption(base_race_page);
    }
}