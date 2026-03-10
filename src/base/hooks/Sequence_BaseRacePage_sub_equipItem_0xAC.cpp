#include <base/hooking.hpp>

#include <base/features.hpp>

namespace base
{
    void    hooks::Sequence_BaseRacePage_sub_equipItem_0xAC()
    {
        asm volatile
        (
            "PUSH { R0-R3, LR } \n"
            "MOV R0, R4 \n"
            "BL __filter_btm_icon \n"
            "CMP R0, #0 \n"
            "MOVNE R4, #0 \n"
            "POP { R0-R3, PC } \n"
        );
    }

    extern "C" auto __filter_btm_icon(Item::eItemType item_type)
    {
        return base::features::filter_btm_icon(item_type);
    }
}