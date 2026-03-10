#pragma once

#include "types.hpp"

#include "memory/patch.hpp"

namespace base
{
    class patches
    {
    public:
        explicit patches();
        ~patches();

        memory::patch<u32> m_Item_ItemDirector_initAfterStructure_0x14_patch;
        memory::patch<u32> m_Sequence_BaseRacePage_initMapIcon_0x6F8_patch;
        memory::patch<u32> m_Kart_VehicleReact_calcReact_0x20_patch;
        memory::patch<u32> m_Item_KartItem_setItemForce_0x28_patch;
        memory::patch<u32> m_System_KDPadDirector_calc_0xEC_patch;
    };

    inline patches *g_patches{};
}