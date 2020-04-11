//
// Created by edge on 2019-10-27.
//

#include <cmath>
#include <Utility.h>
#include "Camera.h"
#include "Vector.h"

using namespace RayTracing;

Camera::Camera(Vec3 lookFrom, Vec3 lookTo, Vec3 viewUp, float vfov, float aspect, float aperture, float focusDistance) {
    lensRadius = aperture / 2.0;
    float theta = vfov * acos(-1) / 180;
    float halfHeight = tan(theta / 2.0);
    float halfWidth = aspect * halfHeight;
    origin = lookFrom;
    w = (lookFrom - lookTo).unitVector();
    u = Vec3::cross(viewUp, w).unitVector();
    v = Vec3::cross(w, u);

    lowerLeftCorner = origin - halfWidth * focusDistance * u - halfHeight * focusDistance * v - focusDistance * w;
    horizontal = 2 * halfWidth * focusDistance * u;
    vertical = 2 * halfHeight * focusDistance * v;
}

RayTracing::Ray Camera::getRay(float s, float t) {
    Vec3 randomDisk = lensRadius * randomInUnitDisk();
    Vec3 offset = u * randomDisk.x + v * randomDisk.y;
    return {origin + offset, lowerLeftCorner + s * horizontal + t * vertical - origin - offset};
}
