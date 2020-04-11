//
// Created by edge on 2019-10-31.
//

#ifndef RAY_TRACING_DIELECTRIC_H
#define RAY_TRACING_DIELECTRIC_H

#include "Material.h"

class Dielectric : public Material {
public:
    Dielectric(float ri);
    bool scatter(const RayTracing::Ray &rayIn, const HitRecord &record, RayTracing::Vec3 &attenuation, RayTracing::Ray &scattered) const override;
    float referenceIndex;
};


#endif //RAY_TRACING_DIELECTRIC_H
