//
// Created by edge on 2019-10-27.
//

#ifndef RAY_TRACING_CAMERA_H
#define RAY_TRACING_CAMERA_H

#include "Vector.h"
#include "Ray.h"

class Camera {
public:
    Camera(RayTracing::Vec3 lookFrom, RayTracing::Vec3 lookTo, RayTracing::Vec3 viewUp, float vfov, float aspect, float aperture, float focusDistance);
    RayTracing::Ray getRay(float u, float v);
    RayTracing::Vec3 origin;
    RayTracing::Vec3 lowerLeftCorner;
    RayTracing::Vec3 horizontal;
    RayTracing::Vec3 vertical;
    RayTracing::Vec3 u, v, w;
    float lensRadius;
};


#endif //RAY_TRACING_CAMERA_H
