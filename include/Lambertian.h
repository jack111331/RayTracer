//
// Created by edge on 2019-10-30.
//

#ifndef RAY_TRACING_LAMBERTIAN_H
#define RAY_TRACING_LAMBERTIAN_H

#include "Material.h"

class Lambertian : public Material {
public:
    Lambertian(const RayTracing::Vec3 &albedo);
    bool scatter(const RayTracing::Ray &rayIn, const HitRecord &record, RayTracing::Vec3 &attenuation, RayTracing::Ray &scattered) const override;
    RayTracing::Vec3 albedo;
};


#endif //RAY_TRACING_LAMBERTIAN_H
