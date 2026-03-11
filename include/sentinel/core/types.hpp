#pragma once

#include <cstdint>
#include <cmath>
#include <string>

namespace sentinel{

    struct Vec3{
        double x{0.0};
        double y{0.0};
        double z{0.0};

        Vec3 operator+ (const Vec3& other) const {
            return {x + other.x, y+other.y, z + other.z};
        }

        Vec3 operator- (const Vec3& other) const{
            return {x - other.x, y - other.y, z - other.z};
        }

        Vec3 operator* (double scalar) const{
            return {x * scalar, y * scalar, z * scalar};
        }

        double norm() const{
            return std::sqrt(x*x + y*y + z*z);
        }

        double dot(const Vec3& other) const{
            return  x * other.x + y * other.y + z * other.z;
        }
    };

    struct Point3D{
        float x{0.0f};
        float y{0.0f};
        float z{0.0f};
        float intensity{0.0f};
    };

     struct BoundingBox{
            Vec3 center;
            Vec3 size;
            double yaw{0.0};
    };

    enum class ObjectClass : uint8_t{
        Unknown = 0,
        Car = 1,
        Truck = 2,
        Pedestrian = 3,
        Cyclist = 4,
        Motorbike = 5
    };

    inline std::string to_string(ObjectClass cls){
        switch (cls){
            case ObjectClass::Car:  return "Car";
            case ObjectClass::Truck:  return "Truck";
            case ObjectClass::Pedestrian: return "Pedestrian";
            case ObjectClass::Cyclist: return "Cyclist";
            case ObjectClass::Motorbike: return "Motorbike"; 
            default: return "Unknown";
        }
    }
        
} // namespace sentinel