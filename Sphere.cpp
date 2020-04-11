//
// Created by edge on 2019-10-27.
//

#include "Sphere.h"
#include <cmath>

using namespace RayTracing;

Sphere::Sphere(const RayTracing::Vec3 &center, float radius, Material *material) : center(center), radius(radius), material(material) {

}

bool Sphere::isHit(float tmin, float tmax, const Ray &ray, HitRecord &record) const {
    float a = Vec3::dot(ray.direction, ray.direction);
    float b = 2.0 * Vec3::dot(ray.direction, ray.origin - center);
    float c = Vec3::dot(ray.origin - center, ray.origin - center) - radius * radius;
    float determinant = b * b - 4 * a * c;
    if (determinant > 0.0) {
        float temp = (-b - sqrt(determinant)) / (2.0 * a);
        if (temp < tmax && temp > tmin) {
            record.t = temp;
            record.p = ray.pointAtParameter(record.t);
            record.normal = (record.p - center) / radius;
            record.material = material;
            return true;
        }
        temp = (-b + sqrt(determinant)) / (2.0 * a);
        if (temp < tmax && temp > tmin) {
            record.t = temp;
            record.p = ray.pointAtParameter(record.t);
            record.normal = (record.p - center) / radius;
            record.material = material;
            return true;
        }
    }
    return false;

}