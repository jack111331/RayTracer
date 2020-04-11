//
// Created by edge on 2019-10-26.
//

#ifndef RAY_TRACING_RAY_H
#define RAY_TRACING_RAY_H

#include "Vector.h"

namespace RayTracing {
    class Ray {
    public:
        Ray();
        Ray(const Vec3 &origin, const Vec3 &direction);
        Vec3 pointAtParameter(float t) const;

        Vec3 origin, direction;
    };

}


#endif //RAY_TRACING_RAY_H
