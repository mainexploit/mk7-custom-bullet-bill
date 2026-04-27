#include <base/hooking.hpp>

#include <base/features.hpp>

namespace base
{
    void    hooks::Item_ItemObjKoura_calc_GndColCheck_0x4E0()
    {
        asm volatile
        (
            "PUSH { R0-R3, LR } \n"
            "VPUSH { S1 } \n"
            "MOV R0, R4 \n"
            "VMOV S1, S16 \n"
            "BL __calc_throw_height_0x4E0 \n"
            "VPOP { S1 } \n"
            "POP { R0-R3, PC } \n"
        );
    }

    extern "C" auto __calc_throw_height_0x4E0(Item::ItemObjBase *item_obj, float scale, float height)
    {
        return base::features::calc_throw_height(item_obj, scale, height);
    }
}