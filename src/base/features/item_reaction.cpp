#include <base/features.hpp>

#include <Item/ItemDirector.hpp>
#include <base/pointers.hpp>

namespace base
{
    void    features::item_reaction(Item::ItemObjBase *item_obj, Item::ItemObjBase *collided_item_obj, Item::eItemReact *item_obj_react, Item::eItemReact *collided_item_obj_react)
    {
        if (item_obj->m_item_type == Item::eItemType::Killer && collided_item_obj->m_item_type != Item::eItemType::Killer)
        {
            switch (collided_item_obj->m_item_type)
            {
                case Item::eItemType::Banana:
                case Item::eItemType::Star:
                case Item::eItemType::Gesso:
                case Item::eItemType::Kinoko:
                case Item::eItemType::Flower:
                case Item::eItemType::KouraG:
                case Item::eItemType::KouraR:
                {
                    *collided_item_obj_react = Item::eItemReact::Destroy;

                    *item_obj_react = (collided_item_obj->m_col_mode == Item::ItemObjBase::eColMode::Equip) ? Item::eItemReact::None : Item::eItemReact::Rescale;
                }
                break;

                case Item::eItemType::Bomhei:
                {
                    *collided_item_obj_react = Item::eItemReact::Destroy;
                    *item_obj_react = Item::eItemReact::Destroy;
                }
                break;

                case Item::eItemType::KouraB:
                {
                    *collided_item_obj_react = Item::eItemReact::None;
                    *item_obj_react = Item::eItemReact::Destroy;
                }
                break;

                case Item::eItemType::Tail:
                {
                    *collided_item_obj_react = Item::eItemReact::TailDestroy;
                    *item_obj_react = (collided_item_obj->m_col_mode == Item::ItemObjBase::eColMode::Equip) ? Item::eItemReact::None : Item::eItemReact::Rescale;
                }
                break;
            }
        }
        else if (item_obj->m_item_type != Item::eItemType::Killer && collided_item_obj->m_item_type == Item::eItemType::Killer)
        {
            switch (item_obj->m_item_type)
            {
                case Item::eItemType::Banana:
                case Item::eItemType::Star:
                case Item::eItemType::Gesso:
                case Item::eItemType::Kinoko:
                case Item::eItemType::Flower:
                case Item::eItemType::KouraG:
                case Item::eItemType::KouraR:
                {
                    *item_obj_react = Item::eItemReact::Destroy;

                    *collided_item_obj_react = (item_obj->m_col_mode == Item::ItemObjBase::eColMode::Equip) ? Item::eItemReact::None : Item::eItemReact::Rescale;
                }
                break;

                case Item::eItemType::Bomhei:
                {
                    *item_obj_react = Item::eItemReact::Destroy;
                    *collided_item_obj_react = Item::eItemReact::Destroy;
                }
                break;

                case Item::eItemType::KouraB:
                {
                    *item_obj_react = Item::eItemReact::None;
                    *collided_item_obj_react = Item::eItemReact::Destroy;
                }
                break;

                case Item::eItemType::Tail:
                {
                    *item_obj_react = Item::eItemReact::TailDestroy;
                    *collided_item_obj_react = (item_obj->m_col_mode == Item::ItemObjBase::eColMode::Equip) ? Item::eItemReact::None : Item::eItemReact::Rescale;
                }
                break;
            }
        }
        else if (item_obj->m_item_type == Item::eItemType::Killer && collided_item_obj->m_item_type == Item::eItemType::Killer)
        {
            if (item_obj->m_col_mode == Item::ItemObjBase::eColMode::Equip && collided_item_obj->m_col_mode != Item::ItemObjBase::eColMode::Equip)
            {
                *item_obj_react = Item::eItemReact::None;
                *collided_item_obj_react = Item::eItemReact::Rescale;
            }
            else if (item_obj->m_col_mode != Item::ItemObjBase::eColMode::Equip && collided_item_obj->m_col_mode == Item::ItemObjBase::eColMode::Equip)
            {
                *collided_item_obj_react = Item::eItemReact::None;
                *item_obj_react = Item::eItemReact::Rescale;
            }
        }

        if (!g_menu->m_config.m_squishy)
        {
            if (item_obj->m_item_type == Item::eItemType::Killer)
                if (*item_obj_react == Item::eItemReact::Rescale)
                    *item_obj_react = Item::eItemReact::None;
            
            if (collided_item_obj->m_item_type == Item::eItemType::Killer)
                if (*collided_item_obj_react == Item::eItemReact::Rescale)
                    *collided_item_obj_react = Item::eItemReact::None;
        }
    }
}