# Mario Kart 7 - Custom Bullet Bill
A **CTRPluginFramework-RevolutionBase** plugin for **Mario Kart 7**

> [!TIP]
> This project is strictly for educational purposes\
> Any questions? DM me on Discord: `h4x0rspooky`

## Compatibility
Mario Kart 7 USA and EUR on the latest update v1.2\
Theoretically any version and revision should work

## Build
> [!NOTE]
> The `libctrpf` included is a modified version to fix numerous issues\
> You would still want to install `libctrpf` through pacman though

- [git](https://git-scm.com/downloads)
- [python](https://www.python.org/downloads)
- [devkitPro](https://devkitpro.org/wiki/Getting_Started)

1. Clone the repository locally by running the following command
```
git clone <repo url> --depth=1 --recurse-submodules --shallow-submodules
```
2. Follow the steps to install [CTRPluginFramework](https://gitlab.com/thepixellizeross/ctrpluginframework)
3. Run `pacman -S 3gxtool` to install [3gxtool](https://gitlab.com/thepixellizeross/3gxtool)
4. Run `make` in the cloned repository

## Credits
- [MK7-Patch-Collection](https://https://github.com/Bsquo/mk7-patch-collection)
- [CTRPF-RevolutionBase](https://github.com/Anto726/CTRPluginFramework-RevolutionBase)
- [glaze (Fork by @Anto726)](https://github.com/Anto726/glaze)
- [magic_enum](https://github.com/Neargye/magic_enum)
- [MK7-Memory](https://github.com/mk7re/MK7-Memory)

## License
See [LICENSE](LICENSE)