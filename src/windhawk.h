#pragma once
// Windhawk (windhawk.net) customizes Explorer with mods, several of which change the taskbar: its height, its
// edge, the clock's width, the notification area's layout, or (Windows 11 Taskbar Styler) move the tray and
// clock with XAML margins while the taskbar's own child windows stay where they were. Experimental support:
// the app only reads which mods are installed and turned on; it never changes Windhawk or its mods.
#include <string>
#include <vector>

namespace windhawk {

struct Mod {
    std::wstring id;    // e.g. "windows-11-taskbar-styler"
    std::wstring name;  // e.g. "Windows 11 Taskbar Styler" (the id when unknown)
};

// Windhawk is installed (its settings key exists) or running.
bool Found();
// The turned-on mods that change the taskbar, from HKLM\SOFTWARE\Windhawk\Engine\Mods (a normal install;
// portable installs keep them in ini files and are not read).
std::vector<Mod> TaskbarMods();
// One of those mods by id, turned on.
bool ModOn(const std::vector<Mod>& mods, const wchar_t* id);

}  // namespace windhawk
