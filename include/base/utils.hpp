#pragma once

#include <base/types.hpp>
#include <string>

namespace base
{
    namespace utils
    {
        bool check_process(std::string_view);
        bool is_character_engine_valid();
        bool is_system_engine_valid();
        bool is_paused();
        bool is_battle();
        bool in_race();
        
        void get_next_index(size_t &, size_t, bool);
        s16 get_master_id();

        u32 random_u32();
        u32 random_u32(u32);
        f32 random_f32();
        f32 random_f32(f32, f32);

        void emit_item(s32, Item::eItemType, sead::Vector3f, sead::Vector3f);
    }
}