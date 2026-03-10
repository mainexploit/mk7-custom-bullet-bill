#include <base/features.hpp>

namespace base
{
    bool    features::filter_btm_icon(Item::eItemType item_type)
    {
        return (item_type == Item::eItemType::Killer);
    }
}