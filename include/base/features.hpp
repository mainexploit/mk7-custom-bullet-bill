#pragma once

#include <base/menu.hpp>
#include <forward.hpp>

namespace base
{
	struct features
	{
		static void item_reaction(Item::ItemObjBase *, Item::ItemObjBase *, Item::eItemReact *, Item::eItemReact *);
		static bool entry_item(Item::ItemDirector *, Item::eItemSlot, Item::KartItem *);
		static void kart_reaction(Item::ItemObjBase *, Kart::Vehicle *);
		static float change_height(Item::ItemObjBase *, float);
		static void create_caption(Sequence::BaseRacePage *);
		static void init_btm_icon(Sequence::BaseRacePage *);
		static void calc_caption(Sequence::BaseRacePage *);
		static void change_multi_size(Item::ItemObjBase *);
		static void change_stand_size(Item::ItemObjBase *);
		static bool disable_tc_board(Item::ItemObjBase *);
		static void change_hang_size(Item::ItemObjBase *);
		static bool consume_equip(Item::ItemObjBase *);
		static bool filter_btm_icon(Item::eItemType);
	};
}