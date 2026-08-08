# MIDI Studio device support

`ms-device-support` is the narrow, versioned Teensy 4.1 hardware boundary
shared by MIDI Studio firmware products. It contains board constants, input
IDs and stable control layout, input policy, display/buffer configuration,
`lv_conf.h`, and the single LVGL PSRAM provider.

Consumers include only the contract they use, for example:

```cpp
#include <ms/device_support/v1/Display.hpp>
#include <ms/device_support/v1/Buffers.hpp>
```

There is intentionally no umbrella header. Application state, UI composition,
MIDI routing and `InputAPI` are not part of this package.

The public path and namespace carry API version `v1`. The package manifest
version is independent and follows normal semantic-version release rules.

Logical input IDs and their ordered control layout are stable product API.
Board wiring in this package is the compiled safe default; a future validated
wiring-profile override may replace physical routing at boot, but must never
renumber those logical IDs or add work to the real-time input loop.

Run `pio run -e dev` from a complete `ms-dev-env` workspace for local
qualification. CI uses `pio run -e release` with commit-pinned OpenControl
dependencies so this repository remains independently buildable.
