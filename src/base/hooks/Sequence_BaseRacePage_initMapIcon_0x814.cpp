#include <base/hooking.hpp>

#include <Item/ItemDirector.hpp>

namespace base
{
    void    hooks::Sequence_BaseRacePage_initMapIcon_0x814()
    {
        asm volatile
        (
            "CMP R2, #9 \n"
            "BXNE LR \n"
            "PUSH { R2-R12, LR } \n"
            "BL __get_item_obj_director \n"
            "LDR R1, [R0, #0x10] \n"
            "LDR R1, [R1] \n"
            "LDRB R1, [R1, #0x156] \n"
            "POP { R2-R12, PC } \n"
        );
    }

    extern "C" auto __get_item_obj_director()
    {
        return Item::GetDirector()->m_killer_director;
    }
}