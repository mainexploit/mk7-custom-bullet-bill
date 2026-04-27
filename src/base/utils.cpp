#include <base/utils.hpp>

#include <RaceSys/ModeManagerBase.hpp>
#include <RaceSys/RaceDirector.hpp>
#include <RaceSys/RaceInfo/Get.hpp>
#include <Item/ItemDirector.hpp>
#include <System/RootSystem.hpp> 
#include <base/pointers.hpp>
#include <ctrpf.hpp>

namespace base
{
    bool    utils::check_process(std::string_view name)
    {
        std::string process{};

        CTRPluginFramework::Process::GetName(process);

        return (process.compare(name) == 0);
    }

    bool    utils::is_character_engine_valid()
    {
        return (System::g_root_system->m_scene_manager->m_root_scene->get_character_engine());
    }

    bool    utils::is_paused()
    {
        if (auto system_engine = System::g_root_system->m_root_scene->get_system_engine())
            return reinterpret_cast<System::Engine *>(system_engine)->m_is_paused;

        return false;
    }

    bool    utils::is_battle()
    {
        if (auto race_info = RaceSys::GetRaceInfo())
            return (race_info->m_race_mode.m_type == RaceSys::CRaceMode::RaceType::Balloon || race_info->m_race_mode.m_type == RaceSys::CRaceMode::RaceType::Coin);
        
        return false;
    }

    bool    utils::in_race()
    {
        if (is_character_engine_valid())
            return (System::g_root_system->get_race_director() != nullptr);

        return false;
    }

    void	utils::get_next_index(size_t &index, size_t max, bool backwards)
    {
        if (!backwards)
        {
            index++;
            
            if (index > max)
                index = 0;
        }
        else
        {
            index--;
            
            if (index < 0 || index > max)
                index = max;
        }
    }

    s16     utils::get_master_id()
    {
        return System::g_root_system->get_race_director()->m_race_info.m_detail_kart_id;
    }

    u32     utils::random_u32()
    {
        return (*g_pointers->m_global_random)->getU32();
    }

    u32     utils::random_u32(u32 max)
    {
        return (*g_pointers->m_global_random)->getU32(max);
    }
    
    f32     utils::random_f32()
    {
        return (*g_pointers->m_global_random)->getF32();
    }

    f32     utils::random_f32(f32 min, f32 max)
    {
        return (*g_pointers->m_global_random)->getF32Range(min, max);
    }

    void    utils::emit_item(s32 player_id, Item::eItemType item, sead::Vector3f position, sead::Vector3f velocity)
    {
        if (auto const item_obj_director = Item::GetDirector()->getDirector_FromItemType(item); item_obj_director != nullptr)
            g_pointers->m_Item_ItemObjDirectorBase_emitItemImpl(item_obj_director, player_id, &position, &velocity);
    }
}