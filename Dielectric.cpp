//
// Created by edge on 2019-10-31.
//

#include <Utility.h>
#include "Dielectric.h"
#include "Vector.h"

using namespace RayTracing;

Dielectric::Dielectric(float ri) : referenceIndex(ri) {

}

bool Dielectric::scatter(const RayTracing::Ray &rayIn, const HitRecord &record, RayTracing::Vec3 &attenuation,
                         RayTracing::Ray &scattered) const {
    Vec3 outwardNormal;
    Vec3 reflected = Vec3::reflect(rayIn.direction, record.normal);
    float niOverNt;
    attenuation = Vec3(1.0, 1.0, 1.0);
    Vec3 refracted;
    float reflectProb;
    float cosine;
    if (Vec3::dot(rayIn.direction, record.normal) > 0.0) {
        outwardNormal = -record.normal;
        niOverNt = referenceIndex;
        cosine = referenceIndex * Vec3::dot(rayIn.direction, record.normal) / rayIn.direction.length();
    } else {
        outwardNormal = record.normal;
        niOverNt = 1.0 / referenceIndex;
        cosine = -Vec3::dot(rayIn.direction, record.normal) / rayIn.direction.length();
    }
    if (Vec3::refract(rayIn.direction, outwardNormal, niOverNt, refracted)) {
        reflectProb = schlick(cosine, referenceIndex);
    } else {
        reflectProb = 1.0;
    }
    if (drand48() < reflectProb) {
        scattered = Ray(record.p, reflected);
    } else {
        scattered = Ray(record.p, refracted);
    }
    return true;
}
