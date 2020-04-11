//
// Created by edge on 2019-10-30.
//

#ifndef RAY_TRACING_METAL_H
#define RAY_TRACING_METAL_H

#include "Material.h"

class Metal : public Material {
public:
    Metal(const RayTracing::Vec3 &albedo, float fuzz);
    bool scatter(const RayTracing::Ray &rayIn, const HitRecord &record, RayTracing::Vec3 &attenuation, RayTracing::Ray &scattered) const override;
    RayTracing::Vec3 albedo;
    float fuzz;
};


#endif //RAY_TRACING_METAL_H
