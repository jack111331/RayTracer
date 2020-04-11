#include "Vector.h"
#include <cmath>

using namespace RayTracing;

Vec3::Vec3() : x(0.0), y(0.0), z(0.0) {

}

Vec3::Vec3(float x, float y, float z) : x(x), y(y), z(z) {

}

std::istream &operator>>(std::istream &istream, Vec3 &vector) {
    istream >> vector.x >> vector.y >> vector.z;
    return istream;
}

std::ostream &operator<<(std::ostream &ostream, const Vec3 &vector) {
    ostream << vector.x << " " << vector.y << " " << vector.z;
    return ostream;
}

Vec3 Vec3::operator-() const {
    return {-x, -y, -z};
}

const Vec3 &Vec3::operator+=(const Vec3 &rhs) {
    x += rhs.x;
    y += rhs.y;
    z += rhs.z;
    return *this;
}

Vec3 Vec3::operator+(const Vec3 &rhs) const {
    Vec3 result(*this);
    result += rhs;
    return result;
}

const Vec3 &Vec3::operator-=(const Vec3 &rhs) {
    x -= rhs.x;
    y -= rhs.y;
    z -= rhs.z;
    return *this;
}

Vec3 Vec3::operator-(const Vec3 &rhs) const {
    Vec3 result(*this);
    result -= rhs;
    return result;
}

const Vec3 &Vec3::operator*=(float t) {
    x *= t;
    y *= t;
    z *= t;
    return *this;
}

Vec3 Vec3::operator*(float t) const {
    Vec3 result(*this);
    result *= t;
    return result;
}

const Vec3 &Vec3::operator*=(const Vec3 &rhs) {
    x *= rhs.x;
    y *= rhs.y;
    z *= rhs.z;
    return *this;
}

Vec3 Vec3::operator*(const Vec3 &rhs) const {
    Vec3 result(*this);
    result *= rhs;
    return result;
}

Vec3 operator*(float t, const Vec3 &lhs) {
    Vec3 result(lhs);
    result *= t;
    return result;
}

const Vec3 &Vec3::operator/=(float t) {
    x /= t;
    y /= t;
    z /= t;
    return *this;
}

Vec3 Vec3::operator/(float t) const {
    Vec3 result(*this);
    result /= t;
    return result;
}

Vec3 &Vec3::operator=(const Vec3 &rhs) {
    x = rhs.x;
    y = rhs.y;
    z = rhs.z;
    return *this;
}

float Vec3::dot(const Vec3 &lhs, const Vec3 &rhs) {
    return lhs.x * rhs.x + lhs.y * rhs.y + lhs.z * rhs.z;
}

Vec3 Vec3::cross(const Vec3 &lhs, const Vec3 &rhs) {
    return {lhs.y * rhs.z - lhs.z * rhs.y, lhs.z * rhs.x - lhs.x * rhs.z, lhs.x * rhs.y - lhs.y * rhs.x};
}

Vec3 Vec3::reflect(const Vec3 &vector, const Vec3 &normal) {
    return vector - 2 * dot(vector, normal) * normal;
}

bool Vec3::refract(const Vec3 &vector, const Vec3 &normal, float niOverNt, Vec3 &refracted) {
    Vec3 unitVector = vector.unitVector();
    float dt = dot(unitVector, normal);
    float discriminant = 1.0 - niOverNt * niOverNt * (1.0 - dt * dt);
    if(discriminant > 0.0) {
        refracted = niOverNt *(unitVector - normal * dt) - normal * sqrt(discriminant);
        return true;
    } else {
        return false;
    }
}


float Vec3::length() const {
    return sqrt(x * x + y * y + z * z);
}

float Vec3::squaredLength() const {
    return x * x + y * y + z * z;
}

Vec3 Vec3::unitVector() const {
    return *this / this->length();
}

