#ifndef RAY_TRACING_VECTOR_H
#define RAY_TRACING_VECTOR_H

#include <iostream>

namespace RayTracing {
    class Vec3 {
    public:
        Vec3();

        Vec3(float x, float y, float z);

        Vec3 operator-() const;

        const Vec3 &operator+=(const Vec3 &rhs);

        Vec3 operator+(const Vec3 &rhs) const;

        const Vec3 &operator-=(const Vec3 &rhs);

        Vec3 operator-(const Vec3 &rhs) const;

        const Vec3 &operator*=(float t);

        Vec3 operator*(float t) const;

        const Vec3 &operator*=(const Vec3 &rhs);

        Vec3 operator*(const Vec3 &rhs) const;

        const Vec3 &operator/=(float t);

        Vec3 operator/(float t) const;

        Vec3 &operator=(const Vec3 &rhs);

        static float dot(const Vec3 &lhs, const Vec3 &rhs);

        static Vec3 cross(const Vec3 &lhs, const Vec3 &rhs);

        static Vec3 reflect(const Vec3 &vector, const Vec3 &normal);

        static bool refract(const Vec3 &vector, const Vec3 &normal, float niOverNt, Vec3 &refracted);

        float length() const;

        float squaredLength() const;

        Vec3 unitVector() const;


        union {
            float x;
            float r;
        };
        union {
            float y;
            float g;
        };
        union {
            float z;
            float b;
        };
    };
}
RayTracing::Vec3 operator*(float t, const RayTracing::Vec3 &lhs);

std::istream &operator >>(std::istream &istream, RayTracing::Vec3 &vector);

std::ostream &operator <<(std::ostream &istream, const RayTracing::Vec3 &vector);

#endif //RAY_TRACING_VECTOR_H
