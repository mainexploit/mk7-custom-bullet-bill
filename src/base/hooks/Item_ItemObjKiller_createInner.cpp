#include <base/hooking.hpp>

#include <base/pointers.hpp>

namespace base
{
    void    hooks::Item_ItemObjKiller_createInner(Item::ItemObjBase *item_obj, const Object::ArgumentObj args)
	{
        auto create_args = g_pointers->m_Render_DrawMdlCreateArgs_ctor();

        g_pointers->m_Render_DrawMdlCreateArgs_SetPathInfoNoLoad(&create_args, _sead::safe_string("Item/itemKiller/itemKiller.bcmdl"));
        
        create_args.m_enable_async = true;
        create_args.m_lod_index = 0;
        create_args.m_anim_track_count = 2;
        create_args.m_anim_bind_mask = 4;
        create_args.m_enable_culling = true;
        create_args.m_draw_pass_mask = 1;
        
        g_pointers->m_Object_Actor3DMdl_createModel(item_obj, create_args, nullptr);
        g_pointers->m_Item_ItemObjBase_setVisible(item_obj, false, true);
	}
}