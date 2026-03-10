#include <base/entries.hpp>

#include <magic_enum/magic_enum.hpp>
#include <base/features.hpp>
#include <base/patches.hpp>
#include <base/types.hpp>
#include <base/utils.hpp>
#include <base/menu.hpp>
#include <format>

#include <RaceSys/ModeManagerBase.hpp>
#include <RaceSys/RaceDirector.hpp>
#include <Kart/Vehicle/Vehicle.hpp>
#include <System/RootSystem.hpp>
#include <Kart/Director.hpp>

#include <OSDManager.hpp>
#define OSD_AMOUNT 4

namespace base
{
    using namespace CTRPluginFramework;

    inline  std::string left_pad(const std::string &value, size_t length = 5)
    {
        if (value.size() >= length)
            return value.substr(0, length);

        size_t space_pads = length - value.size();

        return std::string(space_pads, ' ') + value;
    }
    
    void    entries::debug_item_killer(MenuEntry *entry)
    {
        const auto data = GetArg<menu_types::debug_killer_data_t>(g_menu->m_debug_item_killer_entry);

        if (entry->WasJustActivated())
        {
            g_patches->m_System_KDPadDirector_calc_0xEC_patch.enable();
            g_patches->m_Kart_VehicleReact_calcReact_0x20_patch.enable();

            for (size_t i = 0; i < OSD_AMOUNT; i++)
                OSDManager[i].SetScreen(true).SetPos(10, 190 + (i * 10)).Disable();
        }

        if (entry->IsActivated())
        {
            if (utils::in_race())
            {
                if (Controller::IsKeyPressed(ZR))
                {
                    auto state = std::to_underlying(cfg.state);

                    state++;

                    if (state > static_cast<u8>(Debug::EntryState::Seven))
                        state = static_cast<u8>(Debug::EntryState::Use);
                    
                    cfg.state = static_cast<Debug::EntryState>(state);

                    if (cfg.state == Debug::EntryState::Use)
                        cfg.selfmove = false;
                    
                    if (cfg.state != Debug::EntryState::Multi)
                        cfg.trailing = false;
                }

                if (Controller::IsKeyPressed(ZL))
                    if (cfg.state != Debug::EntryState::Use)
                        cfg.selfmove ^= true;

                if (Controller::IsKeyPressed(DPadUp))
                    if (cfg.state == Debug::EntryState::Multi)
                        cfg.trailing ^= true;
                
                if (Controller::IsKeyPressed(R))
                    data->item_rain ^= true;
                
                const std::vector<std::string> values =
                {
                    Color::SkyBlue << "  State  : " << Color::LimeGreen << left_pad(std::string(magic_enum::enum_name(cfg.state))),
                    Color::SkyBlue << "Self Move: " << Color::LimeGreen << left_pad(std::format("{}", cfg.selfmove)),
                    Color::SkyBlue << "  Trail  : " << Color::LimeGreen << left_pad(std::format("{}", cfg.trailing)),
                    Color::SkyBlue << "Item Rain: " << Color::LimeGreen << left_pad(std::format("{}", data->item_rain))
                };

                for (size_t i = 0; i < OSD_AMOUNT; i++)
                    OSDManager[i] = values[i];

                if (!data->print)
                {
                    for (size_t i = 0; i < OSD_AMOUNT; i++)
                        OSDManager[i].Enable();
                    
                    data->print = true;
                }

                if (!utils::is_paused() && data->item_rain)
                {
                    if (System::g_root_system->get_race_director()->m_mode_manager->m_race_state == RaceSys::ModeManagerBase::RaceState_Race)
                    {
                        if (data->iterator >= 20)
                        {
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
                                
                                data->iterator = 0;
                            }
                        }
                        else
                            data->iterator++;
                    }
                }
            }
            else if (data->print)
            {
                for (size_t i = 0; i < OSD_AMOUNT; i++)
                    OSDManager[i].Disable();
                
                data->print = false;
                data->item_rain = false;
                data->iterator = 0;
            }
        }
        else
        {
            for (size_t i = 0; i < OSD_AMOUNT; i++)
            {
                OSDManager[i].Disable();
                OSDManager.Remove(i);
            }

            data->print = false;
            data->item_rain = false;
            data->iterator = 0;

            cfg.state = Debug::EntryState::Use;
            cfg.selfmove = false;
            cfg.trailing = false;

            g_patches->m_System_KDPadDirector_calc_0xEC_patch.disable();
            g_patches->m_Kart_VehicleReact_calcReact_0x20_patch.disable();
        }
    }
}