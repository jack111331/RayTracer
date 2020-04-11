//
// Created by edge on 2019-10-26.
//

#include "Ray.h"
using namespace RayTracing;
Ray::Ray() {

}
Ray::Ray(const Vec3 &origin, const Vec3 &direction) : origin(origin), direction(direction) {

}
Vec3 Ray::pointAtParameter(float t) const {
    return Vec3(origin + t * direction);
}
