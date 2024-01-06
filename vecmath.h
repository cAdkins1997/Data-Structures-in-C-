
#pragma once
#include <type_traits>
#include <ostream>

template<typename T>
requires std::is_arithmetic_v<T>
struct Vec3 {
    int x, y, z;

    Vec3(int _x, int _y, int _z) : x(_x), y(_y), z(_z) {};
    explicit Vec3(int _x) : x(_x), y(_x), z(_x) {};

    Vec3& operator = (const Vec3& vec) {
        x = vec.x;
        y = vec.y;
        z = vec.z;

        return *this;
    }

    friend std::ostream& operator<<(std::ostream& os, const Vec3& vec) {
        os << "X: " << vec.x << ", Y: " << vec.y << " Z: " << vec.z;
        return os;
    }
};