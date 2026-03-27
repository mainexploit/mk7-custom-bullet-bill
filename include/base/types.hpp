#pragma once

#include <types.h>
#include <utility>

#include <Item/ItemObj/ItemObjBase.hpp>
#include <base/sead/safe_string.hpp>
#include <container/seadPtrArray.h>

#include <Item/eItemType.hpp>
#include <Item/eItemSlot.hpp>

namespace Debug
{
    enum class EntryState : u8
    {
        Use,
        Hang,
        Multi,
        Seven
    };

    struct Config
    {
        EntryState m_state = EntryState::Use;
        bool m_self_move = false;
        bool m_squishy = false;
    };
}

namespace System
{
    struct Engine
    {
        u8 pad[0x7F];
        bool m_is_paused;
    };
}

namespace UI
{
    struct BgMapItem
    {
        u8 pad0[0x80];
        Item::ItemObjBase *m_item_obj;
        u8 pad1[0x594];
        u8 m_tex_handle[17];
    };

    struct BgRaceMapItemControl
    {
        u8 m_map_killer_r90_handle[17];
        sead::PtrArray<BgMapItem> m_controls[std::to_underlying(Item::eItemType::MAX)];
    };
    static_assert(sizeof(BgRaceMapItemControl) == 0xD4);
}

namespace Sound
{
    enum class SndID : u32
    {
        SingleRotate = 0x1000553,
        DoubleRotate = 0x1000554,
        TripleRotate = 0x1000555,
        BananaLand = 0x1000557,
        BombLand = 0x100055D
    };
}

namespace Item
{
    enum class eItemReact : u8
    {
        None = 0,
        Destroy = 1,
        Ricochet = 2,
        Rescale = 3,
        TailDestroy = 4,
        TailDeflect = 5,
        Intangible = 6
    };
}

namespace Render
{
    struct DrawMdlCreateArgs
    {
        sead::FixedSafeString<128> m_res_mdl_path;
        bool m_enable_preload = false;
        bool m_enable_async = false;
        u32 m_heap_option = 0;
        u32 m_heap_alignment = 0;
        s32 m_lod_index = -1;
        sead::FixedSafeString<64> m_mdl_name;
        s32 m_anim_track_count = -1;
        u32 m_anim_bind_mask = 0;
        u32 m_render_option_flags = 0;
        u32 m_shared_instance_count = 0;
        u32 m_instance_count = 1;
        bool m_enable_draw = true;
        bool m_enable_shadow = false;
        bool m_enable_visibility_anim = false;
        bool m_enable_culling = false;
        s32 m_root_bone_index = -2;
        s32 m_parent_bone_index = -2;
        s32 m_attach_bone_index = -2;
        s32 m_visibility_node_index = -2;
        u32 m_render_layer = 0;
        u32 m_render_sort_key = 0;
        bool m_enable_frustum_cull = false;
        bool m_enable_backface_cull = false;
        bool m_enable_depth_test = true;
        bool m_enable_depth_write = true;
        u32 m_user_param = 0;
        u32 m_draw_pass_mask = 11;
    };
    static_assert(sizeof(DrawMdlCreateArgs) == 0x124);
}