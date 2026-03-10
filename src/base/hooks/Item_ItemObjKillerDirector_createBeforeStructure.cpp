#include <base/hooking.hpp>

#include <Item/ItemObjDirector/ItemObjDirectorBase.hpp>
#include <base/pointers.hpp>

#define ITEM_AMOUNT 20
#define EXTRA_AMOUNT 10

namespace base
{
    void    hooks::Item_ItemObjKillerDirector_createBeforeStructure(Item::ItemObjDirectorBase *item_obj_director, const Object::ArgumentObj args)
    {
        item_obj_director->m_item_objs_num = ITEM_AMOUNT + EXTRA_AMOUNT;

        sead::PtrArray<Item::ItemObjBase> item_obj_array;

        item_obj_array.setBuffer(item_obj_director->m_item_objs_num, g_pointers->m_operator_new(item_obj_director->m_item_objs_num * 4));

        for (size_t i = 0; i < item_obj_director->m_item_objs_num; i++)
        {
            if (auto item_obj = reinterpret_cast<Item::ItemObjBase *>(g_pointers->m_operator_new(sizeof(Item::ItemObjBase))))
            {
                item_obj = g_pointers->m_Item_ItemObjBase_sub_object(item_obj, Item::eItemType::Killer, i);

                item_obj->m_has_vanish_effect = true;
                item_obj->m_has_shadow = true;

                *reinterpret_cast<void **>(item_obj) = g_pointers->m_Item_ItemObjKiller_vtbl;

                item_obj->m_parent = item_obj_director;
                
                item_obj_array.pushBack(item_obj);
            }
        }

        item_obj_director->m_it.m_ptr_array = item_obj_array;
    }
}