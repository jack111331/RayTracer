//
// Created by edge on 2019-10-30.
//

#ifndef RAY_TRACING_MATERIAL_H
#define RAY_TRACING_MATERIAL_H

#include "Ray.h"
#include "Hitable.h"

class Material {
public:
    virtual bool scatter(const RayTracing::Ray &rayIn, const HitRecord &record, RayTracing::Vec3 &attenuation, RayTracing::Ray &scattered) const = 0;
};

#endif //RAY_TRACING_MATERIAL_H
