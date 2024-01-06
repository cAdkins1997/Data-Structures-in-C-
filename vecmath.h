
#pragma once
#include <type_traits>
#include <ostream>

namespace vecmath {

    template<typename T>
    requires std::is_arithmetic_v<T>
    struct Vec3 {
        T x, y, z;

        Vec3() : x(T(0)), y(T(0)), z(T(0)) {};
        Vec3(int _x, int _y, int _z) : x(_x), y(_y), z(_z) {};
        explicit Vec3(const T& _x) : x(_x), y(_x), z(_x) {};

        Vec3& operator = (const Vec3& vec) {
            x = vec.x;
            y = vec.y;
            z = vec.z;

            return *this;
        }

        Vec3<T> operator + (const Vec3<T> &v) const
        { return Vec3<T>(x + v.x, y + v.y, z + v.z); }

        Vec3<T> operator - (const Vec3<T> &v) const
        { return Vec3<T>(x - v.x, y - v.y, z - v.z); }

        Vec3<T> operator * (const T &r) const
        { return Vec3<T>(x * r, y * r, z * r); }

        friend std::ostream& operator<<(std::ostream& os, const Vec3& vec) {
            os << "X: " << vec.x << ", Y: " << vec.y << " Z: " << vec.z;
            return os;
        }

        T length() {
            return sqrt(x * x + y * y + z * z);
        }

        Vec3<T>& normalize()
        {
            T len2 = dot(*this);
            if (len2 > 0) {
                T invLen = 1 / sqrt(len2);
                x *= invLen, y *= invLen, z *= invLen;
            }

            return *this;
        }

        T dot(const Vec3<T> &v) const
        {
            return x * v.x + y * v.y + z * v.z;
        }

        Vec3<T> cross(const Vec3<T> &v) const
        {
            return Vec3<T>(
                    y * v.z - z * v.y,
                    z * v.x - x * v.z,
                    x * v.y - y * v.x);
        }
    };

    template<typename T>
    requires std::is_arithmetic_v<T>
    T length(const Vec3<T> &v) { return sqrt(v.x * v.x + v.y * v.y + v.z * v.z); }

    template<typename T>
    requires std::is_arithmetic_v<T>
    void normalize(Vec3<T> &v)
    {
        T len2 = v.x * v.x + v.y * v.y + v.z * v.z;

        if (len2 > 0) {
            T invLen = 1 / sqrt(len2);
            v.x *= invLen, v.y *= invLen, v.z *= invLen;
        }
    }

    template<typename T>
    requires std::is_arithmetic_v<T>
    T dot(const Vec3<T> &a, const Vec3<T> &b)
    { return a.x * b.x + a.y * b.y + a.z * b.z; }

    template<typename T>
    requires std::is_arithmetic_v<T>
    Vec3<T> cross(const Vec3<T>  &a, const Vec3<T> &b)
    {
        return Vec3<T>(
                a.y * b.z - a.z * b.y,
                a.z * b.x - a.x * b.z,
                a.x * b.y - a.y * b.x);
    }
}