#include <base/hooking.hpp>

#include <base/features.hpp>

namespace base
{
    void    hooks::Item_ItemObjBanana_stateStand_0x3D8()
    {
        asm volatile
        (
            "PUSH { R0, R2-R3, LR } \n"
            "MOV R0, R4 \n"
            "BL __change_land_sfx \n"
            "MOV R1, R0 \n"
            "POP { R0, R2-R3, PC } \n"
        );
    }

    extern "C" auto __change_land_sfx(Item::ItemObjBase *item_obj)
    {
        return base::features::change_land_sfx(item_obj);
    }
}