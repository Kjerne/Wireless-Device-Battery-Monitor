#include "windhawk.h"

#include <windows.h>
#include <tlhelp32.h>

#include <cwchar>

namespace windhawk {
namespace {

// Where a normal install keeps its mods: windhawk.ini's RegistryKey (HKLM\SOFTWARE\Windhawk) + engine.ini's
// "Engine", then one subkey per mod id with a DWORD "Disabled" (github.com/ramensoftware/windhawk,
// src/windhawk/engine/storage_manager.cpp and mod.cpp).
const wchar_t* kModsKey = L"SOFTWARE\\Windhawk\\Engine\\Mods";

struct Known { const wchar_t* id; const wchar_t* name; };
// Mods from github.com/ramensoftware/windhawk-mods that change where things are on the taskbar or how it looks.
const Known kKnown[] = {
    { L"windows-11-taskbar-styler", L"Windows 11 Taskbar Styler" },
    { L"taskbar-icon-size", L"Taskbar height and icon size" },
    { L"taskbar-on-top", L"Taskbar on top" },
    { L"taskbar-vertical", L"Vertical Taskbar" },
    { L"taskbar-clock-customization", L"Taskbar Clock Customization" },
    { L"taskbar-notification-icon-spacing", L"Taskbar tray icon spacing" },
    { L"taskbar-tray-system-icon-tweaks", L"Taskbar tray system icon tweaks" },
    { L"taskbar-auto-hide-when-maximized", L"Taskbar auto-hide when maximized" },
    { L"taskbar-multirow", L"Multirow taskbar" },
};

bool Running() {
    HANDLE snap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
    if (snap == INVALID_HANDLE_VALUE) return false;
    PROCESSENTRY32W pe{ sizeof(pe) };
    bool found = false;
    for (BOOL ok = Process32FirstW(snap, &pe); ok && !found; ok = Process32NextW(snap, &pe))
        found = _wcsicmp(pe.szExeFile, L"windhawk.exe") == 0;
    CloseHandle(snap);
    return found;
}

}  // namespace

bool Found() {
    HKEY k = nullptr;
    if (RegOpenKeyExW(HKEY_LOCAL_MACHINE, L"SOFTWARE\\Windhawk", 0, KEY_READ | KEY_WOW64_64KEY, &k) == ERROR_SUCCESS) {
        RegCloseKey(k);
        return true;
    }
    return Running();
}

std::vector<Mod> TaskbarMods() {
    std::vector<Mod> out;
    HKEY mods = nullptr;
    if (RegOpenKeyExW(HKEY_LOCAL_MACHINE, kModsKey, 0, KEY_READ | KEY_WOW64_64KEY, &mods) != ERROR_SUCCESS) return out;
    wchar_t id[256];
    for (DWORD i = 0;; i++) {
        DWORD len = ARRAYSIZE(id);
        if (RegEnumKeyExW(mods, i, id, &len, nullptr, nullptr, nullptr, nullptr) != ERROR_SUCCESS) break;
        DWORD disabled = 0, sz = sizeof(disabled);
        RegGetValueW(mods, id, L"Disabled", RRF_RT_REG_DWORD, nullptr, &disabled, &sz);
        if (disabled) continue;
        const wchar_t* name = nullptr;
        for (const auto& k : kKnown)
            if (_wcsicmp(k.id, id) == 0) name = k.name;
        // Other mods whose id names the taskbar may move things too ("taskbar-...", "...-taskbar-...").
        if (!name && !wcsstr(id, L"taskbar")) continue;
        out.push_back({ id, name ? name : id });
    }
    RegCloseKey(mods);
    return out;
}

bool ModOn(const std::vector<Mod>& mods, const wchar_t* id) {
    for (const auto& m : mods)
        if (_wcsicmp(m.id.c_str(), id) == 0) return true;
    return false;
}

}  // namespace windhawk
