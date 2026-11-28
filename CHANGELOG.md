# Changelog

What changed in each KJ-BatteryHub release. The release workflow copies a version's section into its GitHub
release, so every version tag needs a section here, headed `## <version>`. Changes made in the original
BatteryHub are listed in its own releases.

## 1.3.3 (not released yet)

- **Brand colors in the panel:** with *Brand colors* on, the Devices tab draws each device's icon (with its glow)
  and level mark in its brand color, the History tab its latest level, and the hover card's icon glows too.
- **Your own color for any device:** right-click it on the Devices tab (or its *...* button) and choose
  *Choose color...*; it is used on the taskbar, tray icon, card and panel, with or without *Brand colors*. Very dark
  or very light picks are adjusted so they stay readable. *Reset color* goes back; *Forget device* removes it.
- **Glow strength:** *Glow behind colored icons* (Settings > Taskbar) goes from Off through Soft, Normal (as
  before), Strong and Very strong.
- **Keychron / Lemokey mice on receivers with vendor id 362D** are now tried with the same Launcher protocols as
  Keychron's own 3434 receivers (hardware untested).
- **Rapoo VT7 Max V2 and VT7 V2** show their model name.

## 1.3.2 (2026-11-26)

- **Export CSV** on the History tab saves the shown period of a device's readings (UTC and local time,
  percent, charging), ready for Excel or LibreOffice.
- **History tab tidied:** the device options are a *...* button next to the device buttons, *Custom...* sits with
  the other periods, and the links below the chart are Export CSV, Open in a window and Clear device history.
- **HeadsetControl is optional in Setup** (ticked by default). It reads the battery of more headsets, for example
  Logitech G, SteelSeries Arctis, Corsair Void and HyperX Cloud. To add it later, run Setup again and tick it;
  updates keep your choice.
- Settings > General no longer has the buttons for the original project's sponsor and GitHub pages (the About
  text and README still credit it). This fork can be sponsored at github.com/sponsors/Kjerne.
- Smaller exe: phrases the app no longer uses were removed from every built-in language.

## 1.3.1 (2026-11-24)

- **ATK A9 Plus on its USB cable:** the mouse is now found in wired mode, not only on its 2.4 GHz / NearLink
  dongle. Cable and dongle show as one entry, with the charging mark while it is plugged in.
- **AULA keyboards on the cable (F99 Pro, F75, F87, F68):** the battery level no longer sticks at 17 % in wired
  mode. The level is read with AULA's own wired query and the keyboard shows as charging.

## 1.3.0 (2026-11-24)

- **New name everywhere: KJ-BatteryHub.** The exe is `KJ-BatteryHub.exe`, the installer
  `KJ-BatteryHub-Setup-<version>.exe` and the portable zip `KJ-BatteryHub-<version>-portable.zip`. The app now
  installs to a `KJ-BatteryHub` folder and keeps its data in `%LOCALAPPDATA%\KJ-BatteryHub`,
  `%APPDATA%\KJ-BatteryHub` and `HKCU\Software\KJ-BatteryHub`. On its first start it copies your settings,
  battery history and own translations from the old `WirelessBattery` locations (the old copies stay as a
  backup), and the installer moves the old installation and its startup entry. **Updating from 1.2.x:** the
  in-app updater cannot find this version, so download the installer from the release page once.
  `status.json` moved too: point status-bar scripts at `%LOCALAPPDATA%\KJ-BatteryHub\status.json` (the YASB
  script in `docs/` looks in both places).
- **New installer options:** check for updates automatically, and a desktop shortcut (off by default), next to
  starting with Windows.
- **Linux downloads:** every release now has `.deb`, `.rpm` and `.tar.gz` packages (`kj-batteryhub`), listed in
  `SHA256SUMS.txt`. They replace the older `wireless-device-battery-monitor` package and copy its settings.
- **History tab:** charging shows as a green dashed line instead of a gap, stretches without readings as a
  faint dotted line, the time axis shows hours, weekdays or dates, a period longer than the device's history
  starts at its first reading, and hovering the chart shows the level and time of a reading. *Used* (total
  drain) and *Charged* (how many charges) replace *Change*, which only compared the first and last reading.
  Cards without data show a dash instead of "2013".
- **Sharper text:** the panel and history window draw Segoe UI with ClearType, like the rest of Windows.
- **Smaller and lighter:** the exe went from 2.7 MB to 1.9 MB, and the built-in translations are no longer copied
  into memory at startup (only the language in use is).

## 1.2.1 (2026-11-23)

- **Keep battery history for 30 days, 90 days, 1 year or all time** (Settings > Devices). New installs keep
  90 days. If you already have older history, it stays on All time, so updating never deletes readings.
  Choosing a shorter period asks first and says how many readings it deletes.
- **No more swapping places with other taskbar widgets** (for example F1DockTimers' countdown): a widget
  outside the strip no longer pushes it, and the strip waits 4 seconds before moving into a gap toward the
  clock, so two apps docking at the same moment settle instead of leapfrogging.
- **Auto-hide taskbar on a second monitor:** the strip no longer covers the clock for a few seconds each time
  the taskbar slides in.
- **Request support for a device** now opens a filled-in issue on this fork's GitHub page in your browser,
  instead of sending to the original project's request site. The app itself sends nothing.
- **Tabs look clickable:** unselected tabs, settings pages, periods and device buttons now have an outline,
  like the drop-down fields, and a little more space between them.
- **One typeface:** the panel, card and history window use Segoe UI throughout. Noto Sans drawn by Windows'
  GDI came out with uneven letters at small sizes (for example the About text).
- **Linux build fixed:** six drivers the Linux port uses (Zebronics, Keychron, Lamzu, Aula, Ninjutso, Rapoo)
  were missing from its build, so Linux packages failed to link.
- New README taskbar picture, made by `scripts/strip-screenshot.py` (`BatteryHub.exe --demo --strip-shot`).

## 1.2.0 (2026-11-22)

- **A panel instead of the menu**, in the same look as the maintainer's F1DockTimers app. A click (left or
  right) on the taskbar strip or a tray icon opens it. **Devices:** level, state, connection and time to empty
  for each device; click one for its history, right-click it (or its *...* button) to show or hide it, move
  it, rename it, set its battery alert or forget it. **History:** the history viewer inside the panel, with
  buttons for three devices and a list for the rest. **Settings:** everything the menu had, on four pages,
  saving the same settings as before. Esc or a click elsewhere closes it; the pin keeps it open.
- **Forget device:** removes an old device's battery history, own name, place and alert, and hides it.
- The hover card and the larger history window use the panel's colours and the built-in Noto Sans typeface.
- The app calls itself **KJ-BatteryHub**: panel, tooltips, the exe's details (publisher Kjerne) and the installer
  (Start menu shortcut, Apps list). Settings > General > About links to this fork and to the original BatteryHub.
  The exe keeps its name, BatteryHub.exe, so updates and the startup entry keep working.
- **README rewritten for this fork:** what it changes, how updates work, and how to install it over the
  official BatteryHub. Donation, Discord and other links that belonged to the original project are gone.
- The button in Settings is now **Support the original project...**, and the README has a section about supporting
  the original project.
- The repository page no longer shows the original project's Sponsor button, and releases no longer post to
  the original project's Discord.

## 1.1.2 (2026-11-22)

- **Updates come from this fork:** *Check for updates* installs only KJ-BatteryHub releases signed with this
  fork's own key, never the official BatteryHub (which keeps only 30 days of history).
- Installer and portable zip, built by GitHub like the original project's, with HeadsetControl included.

## 1.1.1 (2026-11-22)

First release of the fork.

- **Battery history is kept for the device's lifetime.** The last 30 days keep every reading; older readings
  are thinned to the lowest and highest level per 6 hours, and readings older than a year to one pair per day.
- **History window:** a button per device, Last year, All time and Custom periods, dates under the chart, and
  the size of the saved history.
- **Left-click a device** on the taskbar or its tray icon to open its history (an option, on by default), and
  *Battery history...* in the main menu.
- **Hover card:** *Card chart period* setting (24 hours to 30 days, default 30), one time scale around "Now",
  and a "Click for full history" hint.
- **Tidier menu:** shorter device lines, details in each device's submenu, and receivers named the same way
  for every brand.
- One separator after *Display settings* instead of two.
