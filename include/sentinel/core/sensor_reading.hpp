#pragma once

#include <string>
#include <cstdint>
#include "sentinel/core/types.hpp"

namespace sentinel{
    enum class SensorType : uint8_t{
        Camera = 0,
        Lidar = 1,
        Radar = 2
    };

    struct SensorReading{
        SensorType type{SensorType::Camera}; 
        uint8_t sensor_id{0};
        uint64_t timestamp{0};
    };

} // namespace sentinel