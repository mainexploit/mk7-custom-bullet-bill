#pragma once

#include <types.h>

#include <forward.hpp>

#include <base/types.hpp>

namespace base
{
    struct hooks
    {
        static constexpr size_t ItemObjBase_count = 70;
        static constexpr size_t ItemObjBase_getColRadius_index = 22;
        static constexpr size_t ItemObjBase_getBoxColRadius_index = 23;
        static constexpr size_t ItemObjBase_getColScale_index = 24;
        static constexpr size_t ItemObjBase_createInner_index = 30;
        static constexpr size_t ItemObjBase_exit_VanishInner_index = 34;
        static constexpr size_t ItemObjBase_exit_BreakInner_index = 37;
        static constexpr size_t ItemObjBase_hasCollision_InUseState_index = 42;
        static constexpr size_t ItemObjBase_getShadowScale_index = 43;
        static constexpr size_t ItemObjBase_getOffset_Multi_Y_index = 47;
        static constexpr size_t ItemObjBase_getOffset_Multi_Z_index = 48;
        static constexpr size_t ItemObjbase_getRotVelRatio_Multi_index = 49;
        static constexpr size_t ItemObjBase_getRadius_Multi_index = 50;
        static constexpr size_t ItemObjBase_stateEquip_Hang_index = 55;
        static constexpr size_t ItemObjBase_stateEquip_Multi_index = 57;
        static constexpr size_t ItemObjBase_stateInitSelfMove_index = 58;
        static constexpr size_t ItemObjBase_stateStand_index = 63;
        static constexpr size_t ItemObjBase_stateInitUse_index = 64;
        static constexpr size_t ItemObjBase_stateUse_index = 65;
        static constexpr size_t SndActorKart_holdSound_index = 34;

        static void Item_ItemDirector_doReaction(Item::ItemDirector *, Item::ItemObjBase *, Item::ItemObjBase *, Item::eItemReact *, Item::eItemReact *, sead::Vector3f *, sead::Vector3f *);
        static void Item_ItemObjKillerDirector_createBeforeStructure(Item::ItemObjDirectorBase *, const Object::ArgumentObj);
        static void Item_ItemDirector_entryItem(Item::ItemDirector *, Item::eItemSlot , Item::KartItem *);
        static void Item_ItemObjBase_setState_SelfMove(Item::ItemObjBase *, sead::Vector2f *);
        static void Sequence_BaseRacePage_initMapIcon(Sequence::BaseRacePage *);
        static void Item_ItemObjBase_stateEquip_Hang(Item::ItemObjBase *);
        static void Item_KartItem_calcBeforeStructure(Item::KartItem *);
        static void Item_ItemObjBase_stateStand(Item::ItemObjBase *);
        static void Item_ItemObjBase_calcImpl(Item::ItemObjBase *);

        static NAKED void Sequence_BaseRacePage_sub_equipItem_0xAC();
        static NAKED void Item_ItemDirector_checkKartHitItem_0x590();
        static NAKED void Sequence_BaseRacePage_initMapIcon_0x814();
        static NAKED void Item_ItemObjBanana_calcOverState_0x178();
        static NAKED void Item_ItemObjBanana_stateStand_0x3D8();
        static NAKED void Item_ItemObjBanana_stateStand_0x78C();

        static void Item_ItemObjKiller_createInner(Item::ItemObjBase *, const Object::ArgumentObj);
        static bool Item_ItemObjKiller_hasCollision_InUseState(Item::ItemObjBase *);
        static float Item_ItemObjKiller_getRotVelRatio_Multi(Item::ItemObjBase *);
        static float Item_ItemObjKiller_getOffset_Multi_Y(Item::ItemObjBase *);
        static float Item_ItemObjKiller_getOffset_Multi_Z(Item::ItemObjBase *);
        static void Item_ItemObjKiller_stateInitSelfMove(Item::ItemObjBase *);
        static float Item_ItemObjKiller_getBoxColRadius(Item::ItemObjBase *);
        static float Item_ItemObjKiller_getRadius_Multi(Item::ItemObjBase *);
        static void Item_ItemObjKiller_exit_VanishInner(Item::ItemObjBase *);
        static void Item_ItemObjKiller_stateEquip_Multi(Item::ItemObjBase *);
        static float Item_ItemObjKiller_getShadowScale(Item::ItemObjBase *);
        static float Item_ItemObjKiller_getColRadius(Item::ItemObjBase *);
        static float Item_ItemObjKiller_getColScale(Item::ItemObjBase *);
        static void Item_ItemObjKiller_stateStand(Item::ItemObjBase *);
    };
}