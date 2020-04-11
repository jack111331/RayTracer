//
// Created by edge on 2019-10-30.
//

#include <Utility.h>
#include "Lambertian.h"

using namespace RayTracing;

Lambertian::Lambertian(const Vec3 &albedo) : albedo(albedo) {

}

bool Lambertian::scatter(const RayTracing::Ray &rayIn, const HitRecord &record, RayTracing::Vec3 &attenuation,
                         RayTracing::Ray &scattered) const {
    Vec3 target = record.p + record.normal + randomInUnitSphere();
    scattered = Ray(record.p, target - record.p);
    attenuation = albedo;
    return true;
}
