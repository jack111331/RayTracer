//
// Created by edge on 2019-10-27.
//

#ifndef RAY_TRACING_HITABLE_H
#define RAY_TRACING_HITABLE_H

#include "Vector.h"
#include "Ray.h"

class Material;

struct HitRecord {
    float t;
    RayTracing::Vec3 p;
    RayTracing::Vec3 normal;
    Material *material;
};

class Hitable {
public:
    virtual bool isHit(float tmin, float tmax, const RayTracing::Ray &ray, HitRecord &record) const = 0;
};


#endif //RAY_TRACING_HITABLE_H
