#pragma once

#include <cstddef>
#include <cstdint>

#include <ms/device_support/v1/Timing.hpp>

#include <oc/hal/teensy/Ili9341.hpp>
#include <oc/ui/lvgl/Bridge.hpp>

namespace ms::device_support::v1::display {

inline constexpr std::uint8_t VSYNC_SPACING = 1;
inline constexpr std::uint32_t SPI_SPEED_HZ = 60'000'000;
inline constexpr std::uint16_t DIFF_GAP = 8;
// Teensy IRQ priorities are inverse: lower values preempt higher values. Keep
// display DMA below the 1 kHz musical timer without pushing it to the bottom.
inline constexpr std::uint8_t IRQ_PRIORITY = 160;
// Keep panel scanout and retained UI publication on the same cadence. The
// driver selects the closest physical mode and reports the measured rate.
inline constexpr std::uint32_t PHYSICAL_REFRESH_TARGET_HZ = timing::UI_FRAME_HZ;

static_assert(timing::LVGL_SERVICE_HZ > 0);
static_assert(timing::LVGL_SERVICE_HZ % VSYNC_SPACING == 0);
static_assert(timing::UI_FRAME_HZ > 0);
static_assert(VSYNC_SPACING > 0);
static_assert(timing::MUSICAL_REALTIME_IRQ_PRIORITY < IRQ_PRIORITY);

inline constexpr oc::hal::teensy::Ili9341Config CONFIG{
    320,
    240,
    28,
    0,
    29,
    26,
    27,
    1,
    SPI_SPEED_HZ,
    3,
    true,
    VSYNC_SPACING,
    DIFF_GAP,
    IRQ_PRIORITY,
    0.2f,
    PHYSICAL_REFRESH_TARGET_HZ,
};

inline constexpr std::size_t FRAMEBUFFER_PIXEL_COUNT =
    CONFIG.framebufferSize();
inline constexpr std::size_t DIFF_BUFFER_SIZE_BYTES = 8'192;

inline constexpr oc::ui::lvgl::BridgeConfig LVGL_CONFIG{
    LV_DISPLAY_RENDER_MODE_DIRECT,
    nullptr,
    timing::UI_FRAME_HZ,
    {},
};

}  // namespace ms::device_support::v1::display
