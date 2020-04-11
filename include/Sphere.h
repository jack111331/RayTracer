//
// Created by edge on 2019-10-27.
//


#ifndef RAY_TRACING_SPHERE_H
#define RAY_TRACING_SPHERE_H

#include "Hitable.h"
#include "Material.h"

class Sphere : public Hitable {
public:
    Sphere(const RayTracing::Vec3 &center, float radius, Material *material);
    bool isHit(float tmin, float tmax, const RayTracing::Ray &ray, HitRecord &record) const override;

    RayTracing::Vec3 center;
    float radius;
    Material *material;
};


#endif //RAY_TRACING_SPHERE_H
