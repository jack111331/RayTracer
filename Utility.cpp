//
// Created by edge on 2019-10-31.
//
#include <cmath>
#include "Utility.h"

using namespace RayTracing;

Vec3 RayTracing::randomInUnitSphere() {
    Vec3 p;
    do {
        p = 2.0 * Vec3(drand48(), drand48(), drand48()) - Vec3(1.0, 1.0, 1.0);
    } while (p.squaredLength() >= 1.0);
    return p;
}

Vec3 RayTracing::randomInUnitDisk() {
    Vec3 p;
    do {
        p = 2.0 * Vec3(drand48(), drand48(), drand48()) - Vec3(1.0, 1.0, 1.0);
    } while (p.squaredLength() >= 1.0);
    return p;
}

float RayTracing::schlick(float cosine, float referenceIndex) {
    float r0 = (1 - referenceIndex) / (1 + referenceIndex);
    r0 = r0 * r0;
    return r0 + (1 - r0) * pow((1.0 - cosine), 5);
}

