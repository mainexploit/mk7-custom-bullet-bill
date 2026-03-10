#include <base/hooking.hpp>

#include <base/features.hpp>

namespace base
{
    void    hooks::Item_ItemObjBanana_calcOverState_0x178()
    {
        asm volatile
        (
            "PUSH { R0-R3, LR } \n"
            "MOV R0, R4 \n"
            "BL __change_stand_size \n"
            "POP { R0-R3, PC } \n"
        );
    }

    extern "C" auto __change_stand_size(Item::ItemObjBase *item_obj)
    {
        return base::features::change_stand_size(item_obj);
    }
}