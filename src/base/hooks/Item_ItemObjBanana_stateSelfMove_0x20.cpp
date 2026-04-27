#include <base/hooking.hpp>

#include <base/features.hpp>

namespace base
{
    void    hooks::Item_ItemObjBanana_stateSelfMove_0x20()
    {
        asm volatile
        (
            "PUSH { R0-R3, LR } \n"
            "VPUSH { S0 } \n"
            "MOV R0, R5 \n"
            "VLDR S0, [R8, #0x2C] \n"
            "BL __change_stand_height \n"
            "VMOV.F32 S16, S0 \n"
            "VPOP { S0 } \n"
            "POP { R0-R3, PC } \n"
        );
    }

    extern "C" auto __change_stand_height(Item::ItemObjBase *item_obj, float height)
    {
        return base::features::change_stand_height(item_obj, height);
    }
}