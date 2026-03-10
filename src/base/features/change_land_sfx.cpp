#include <base/features.hpp>

namespace base
{
    Sound::SndID    features::change_land_sfx(Item::ItemObjBase *item_obj)
    {
        return (item_obj->m_item_type == Item::eItemType::Killer) ? Sound::SndID::BombLand : Sound::SndID::BananaLand;
    }
}