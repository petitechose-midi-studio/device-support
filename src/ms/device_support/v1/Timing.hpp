#pragma once

#include <cstdint>

namespace ms::device_support::v1::timing {

inline constexpr std::uint32_t INPUT_APP_ADMISSION_HZ = 1'920;
inline constexpr std::uint32_t LVGL_SERVICE_HZ = 240;
// Service LVGL twice per displayed UI frame. This preserves responsive LVGL
// timers while giving every retained projection one shared 120 Hz budget.
inline constexpr std::uint32_t UI_FRAME_SERVICE_DIVISOR = 2U;
inline constexpr std::uint32_t UI_FRAME_HZ =
    LVGL_SERVICE_HZ / UI_FRAME_SERVICE_DIVISOR;

inline constexpr std::uint32_t DEBOUNCE_MS = 12;
inline constexpr std::uint32_t LONG_PRESS_MS = 500;
inline constexpr std::uint32_t LATCH_THRESHOLD_MS = 200;
inline constexpr std::uint32_t DOUBLE_TAP_MS = 300;

static_assert(INPUT_APP_ADMISSION_HZ % LVGL_SERVICE_HZ == 0);
static_assert(UI_FRAME_SERVICE_DIVISOR > 0);
static_assert(LVGL_SERVICE_HZ % UI_FRAME_SERVICE_DIVISOR == 0);
static_assert(UI_FRAME_HZ > 0);

}  // namespace ms::device_support::v1::timing
