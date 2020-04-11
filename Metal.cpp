//
// Created by edge on 2019-10-30.
//

#include "Metal.h"
#include "Utility.h"
using namespace RayTracing;
Metal::Metal(const Vec3 &albedo, float fuzz) : albedo(albedo), fuzz(fuzz) {

}

bool Metal::scatter(const RayTracing::Ray &rayIn, const HitRecord &record, RayTracing::Vec3 &attenuation,
                         RayTracing::Ray &scattered) const {
    Vec3 reflected = Vec3::reflect(rayIn.direction.unitVector(), record.normal);
    scattered = Ray(record.p, reflected + fuzz * randomInUnitSphere());
    attenuation = albedo;
    return (Vec3::dot(scattered.direction, record.normal) > 0);
}
