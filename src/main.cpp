#include <base/notifier.hpp>
#include <base/files.hpp>
#include <base/logger.hpp>
#include <base/settings.hpp>
#include <base/menu.hpp>
#include <base/patches.hpp>
#include <base/pointers.hpp>
#include <base/hooking.hpp>

#include <base/utils.hpp>
#include <plgldr.h>

namespace CTRPluginFramework
{
    using namespace base;

    int main()
    {
        if (!utils::check_process("MarioKar"))
        {
            Sleep(Seconds(1));

            Process::ReturnToHomeMenu();

            return EXIT_FAILURE;
        }

        auto files_instance = std::make_unique<files>();
        g_logger.info("Greetings from " NAME "!");

        g_settings.load();
        g_logger.info("Settings loaded.");

        auto pointers_instance = std::make_unique<pointers>();
        g_logger.info("Pointers initialized.");

        auto hooking_instance = std::make_unique<hooking>();
        g_logger.info("Hooking initialized.");

        auto patches_instance = std::make_unique<patches>();
        g_logger.info("Patches initialized.");

        auto menu_instance = std::make_unique<menu>();
        g_logger.info("Menu created.");

        g_hooking->enable();
        g_logger.info("Hooking enabled.");

        g_notifier.send(NAME);
        g_menu->run();

        g_hooking->disable();
        g_logger.info("Hooking disabled.");

        menu_instance.reset();
        g_logger.info("Menu deleted.");

        patches_instance.reset();
        g_logger.info("Patches uninitialized.");

        hooking_instance.reset();
        g_logger.info("Hooking uninitialized.");

        pointers_instance.reset();
        g_logger.info("Pointers uninitialized.");

        g_settings.store();
        g_logger.info("Settings stored.");

        g_logger.info("Farewell!");
        files_instance.reset();

        return EXIT_SUCCESS;
    }

    void PatchProcess(FwkSettings &settings)
    {
        settings.ThreadPriority = 0x3E;
        settings.WaitTimeToBoot = Time::Zero;
        settings.SetThemeDefault();

        settings.CachedDrawMode = false;
		settings.AllowActionReplay = false;
		settings.AllowSearchEngine = false;
        settings.TryLoadSDSounds = false;

        files::set_working_directory();
    }
}