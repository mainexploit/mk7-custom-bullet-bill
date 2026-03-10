#include <base/patches.hpp>

#include <base/pointers.hpp>

namespace base
{
    patches::patches()
    :
        m_Item_ItemDirector_initAfterStructure_0x14_patch(g_pointers->m_Item_ItemDirector_initAfterStructure_0x14, { 0xEA00000F }),
        m_Sequence_BaseRacePage_initMapIcon_0x6F8_patch(g_pointers->m_Sequence_BaseRacePage_initMapIcon_0x6F8, { 0xE3A0000A }),
        m_Kart_VehicleReact_calcReact_0x20_patch(g_pointers->m_Kart_VehicleReact_calcReact_0x20, { 0xE3A00000 }),
        m_Item_KartItem_setItemForce_0x28_patch(g_pointers->m_Item_KartItem_setItemForce_0x28, { 0xE3E00000 }),
        m_System_KDPadDirector_calc_0xEC_patch(g_pointers->m_System_KDPadDirector_calc_0xEC, { 0xE3A01000 })
    {
        g_patches = this;
    }

    patches::~patches()
    {
        g_patches = nullptr;
    }
}