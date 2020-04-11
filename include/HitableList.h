//
// Created by edge on 2019-10-27.
//

#ifndef RAY_TRACING_HITABLELIST_H
#define RAY_TRACING_HITABLELIST_H

#include <vector>
#include "Hitable.h"

class HitableList : public Hitable {
public:
    bool isHit(float tmin, float tmax, const RayTracing::Ray &ray, HitRecord &record) const override;
    std::vector<Hitable *> hitableList;
};


#endif //RAY_TRACING_HITABLELIST_H
