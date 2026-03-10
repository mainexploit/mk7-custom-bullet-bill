#include <base/hooking.hpp>

#include <base/features.hpp>

namespace base
{
    void    hooks::Item_ItemDirector_checkKartHitItem_0x590()
    {
        asm volatile
        (
            "PUSH { R0-R1, LR } \n"
            "MOV R0, R4 \n"
            "MOV R1, R7 \n"
            "BL __kart_reaction \n"
            "CMP R0, #0 \n"
            "POP { R0-R1, LR } \n"
            "BXEQ LR \n"
            "ADD SP, SP, #0x3C \n"
            "VPOP { D8 } \n"
            "POP { R4-R11, PC } \n"
        );
    }

    extern "C" auto __kart_reaction(Item::ItemObjBase *item_obj, Kart::Vehicle *vehicle)
    {
        return base::features::kart_reaction(item_obj, vehicle);
    }
}