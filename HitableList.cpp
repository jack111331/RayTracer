//
// Created by edge on 2019-10-27.
//

#include "HitableList.h"

bool HitableList::isHit(float tmin, float tmax, const RayTracing::Ray &ray, HitRecord &record) const {
    HitRecord tempRecord;
    bool hitAnything = false;
    float closestHit = tmax;
    for (const auto &hitable : hitableList) {
        if (hitable->isHit(tmin, closestHit, ray, tempRecord)) {
            closestHit = tempRecord.t;
            record = tempRecord;
            hitAnything = true;
        }
    }
    return hitAnything;
}
