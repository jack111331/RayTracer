//
// Created by edge on 2019-10-31.
//

#ifndef RAY_TRACING_UTILITY_H
#define RAY_TRACING_UTILITY_H

#include "Vector.h"

namespace RayTracing {
    Vec3 randomInUnitSphere();

    Vec3 randomInUnitDisk();

    float schlick(float cosine, float referenceIndex);
}


#endif //RAY_TRACING_UTILITY_H
