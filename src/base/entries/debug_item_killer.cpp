#include <base/entries.hpp>

#include <magic_enum/magic_enum.hpp>
#include <base/features.hpp>
#include <base/patches.hpp>
#include <base/types.hpp>
#include <base/utils.hpp>
#include <base/menu.hpp>
#include <format>

#include <RaceSys/ModeManagerBase.hpp>
#include <Kart/Vehicle/Vehicle.hpp>
#include <RaceSys/RaceDirector.hpp>
#include <System/RootSystem.hpp>
#include <Kart/Director.hpp>

namespace base
{
    using namespace CTRPluginFramework;
    
    void    entries::debug_item_killer(CTRPluginFramework::MenuEntry *entry)
    {
        const auto data = GetArg<menu_types::debug_killer_data_t>(g_menu->m_debug_item_killer_entry);

        if (entry->WasJustActivated())
        {
            g_patches->m_Kart_VehicleReact_calcReact_0x20_patch.enable();
            g_patches->m_System_KDPadDirector_calc_0xEC_patch.enable();
        }

        if (entry->IsActivated())
        {
            if (utils::in_race())
            {
                if (Controller::IsKeyPressed(ZR))
                {
                    auto state = std::to_underlying(g_menu->m_config.m_state);

                    state++;

                    if (state > static_cast<u8>(Debug::EntryState::Seven))
                        state = static_cast<u8>(Debug::EntryState::Use);
                    
                    g_menu->m_config.m_state = static_cast<Debug::EntryState>(state);
                }

                if (Controller::IsKeyPressed(ZL))
                    g_menu->m_config.m_self_move ^= true;

                if (Controller::IsKeyPressed(DPadUp))
                    data->m_item_rain ^= true;

                if (!utils::is_paused() && data->m_item_rain)
                {
                    auto race_state = System::g_root_system->get_race_director()->m_mode_manager->m_race_state;

                    if (race_state != RaceSys::ModeManagerBase::RaceState_Race)
                    {
                        if (data->m_item_rain)
                        {
                            data->m_item_rain = false;
                            data->m_iterator = 0;
                        }
                    }
                    else
                    {
                        if (data->m_iterator < 20)
                        {
                            data->m_iterator++;

                            return;
                        }

                        if (auto vehicle = Kart::GetDirector()->getKart(utils::get_master_id()))
                        {
                            sead::Vector3f position =
                            {
                                vehicle->m_position->x + utils::random_f32(-128.f, +128.f),
                                vehicle->m_position->y + 128.f,
                                vehicle->m_position->z + utils::random_f32(-128.f, +128.f)
                            };
                            
                            sead::Vector3f angular_velocity
                            {
                                utils::random_f32(-1.f, +1.f),
                                utils::random_f32(-1.f, +1.f),
                                utils::random_f32(-1.f, +1.f)
                            };
                            
                            utils::emit_item(vehicle->m_player_id, Item::eItemType::Killer, position, angular_velocity);
                            
                            data->m_iterator = 0;
                        }
                    }
                }
            }
        }
        else
        {
            data->m_item_rain = false;
            data->m_iterator = 0;

            g_patches->m_Kart_VehicleReact_calcReact_0x20_patch.disable();
            g_patches->m_System_KDPadDirector_calc_0xEC_patch.disable();
        }
    }
}