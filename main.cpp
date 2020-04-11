//
// Created by Edge on 2019/10/25.
//
#include <fstream>
#include "Ray.h"
#include <cmath>
#include <HitableList.h>
#include <Sphere.h>
#include <values.h>
#include <Camera.h>
#include <Material.h>
#include <Lambertian.h>
#include <Metal.h>
#include <Dielectric.h>

using namespace RayTracing;

Vec3 color(const Ray &ray, Hitable *hitable, int depth) {
    HitRecord record;
    if (hitable->isHit(0.001, MAXFLOAT, ray, record)) {
        Ray scattered;
        Vec3 attenuation;
        if (depth < 50 && record.material->scatter(ray, record, attenuation, scattered)) {
            return attenuation * color(scattered, hitable, depth + 1);
        }
        return Vec3(0.0, 0.0, 0.0);
    } else {
        Vec3 unitDirection = ray.direction.unitVector();
        float t = 0.5 * (unitDirection.y + 1.0);
        return (1.0 - t) * Vec3(1.0, 1.0, 1.0) + t * Vec3(0.5, 0.7, 1.0);

    }
}

Hitable *randomScene() {
    int n = 500;
    HitableList *hitableList = new HitableList();
    hitableList->hitableList.push_back(new Sphere(Vec3(0.0, -1000.0, 0.0), 1000.0, new Lambertian(Vec3(0.5, 0.5, 0.5))));
    for (int a = -11; a < 11; a++) {
        for (int b = -11; b < 11; b++) {
            float chooseMaterial = drand48();
            Vec3 center(a + 0.9 * drand48(), 0.2, b + 0.9 * drand48());
            if ((center - Vec3(4.0, 0.2, 0.0)).length() > 0.9) {
                if (chooseMaterial < 0.8) {
                    hitableList->hitableList.push_back(new Sphere(center, 0.2, new Lambertian(
                            Vec3(drand48() * drand48(), drand48() * drand48(), drand48() * drand48()))));
                } else if (chooseMaterial < 0.95) {
                    hitableList->hitableList.push_back(new Sphere(center, 0.2, new Metal(
                            Vec3(0.5 * (1 + drand48()), 0.5 * (1 + drand48()), 0.5 * (1 + drand48())),
                            0.5 * drand48())));

                } else {
                    hitableList->hitableList.push_back(new Sphere(center, 0.2, new Dielectric(1.5)));
                }
            }
        }
    }
    hitableList->hitableList.push_back(new Sphere(Vec3(0.0, 1.0, 0.0), 1.0, new Dielectric(1.5)));
    hitableList->hitableList.push_back(new Sphere(Vec3(-4.0, 1.0, 0.0), 1.0, new Lambertian(Vec3(0.4, 0.2, 0.1))));
    hitableList->hitableList.push_back(new Sphere(Vec3(4.0, 1.0, 0.0), 1.0, new Metal(Vec3(0.7, 0.6, 0.5), 0.0)));
    return hitableList;
}

int main() {
    int nx = 200;
    int ny = 100;
    int ns = 100;

    std::fstream fs;
    fs.open("ray.ppm", std::ios::out);

    fs << "P3\n" << nx << " " << ny << "\n255\n";
    Vec3 lookFrom = Vec3(3.0, 2.0, 1.0);
    Vec3 lookTo = Vec3(0.0, 0.0, -1.0);
    Camera camera(lookFrom, lookTo, Vec3(0.0, 1.0, 0.0), 60, float(nx) / float(ny), 0.01, (lookFrom - lookTo).length());
    Hitable *hitable = randomScene();
    for (int j = ny - 1; j >= 0; j--) {
        for (int i = 0; i < nx; i++) {
            std::cout << i << " " << j << std::endl;
            Vec3 colorOfRay(0.0, 0.0, 0.0);
            for (int k = 0; k < ns; k++) {
                float u = float(i + drand48()) / float(nx);
                float v = float(j + drand48()) / float(ny);
                Ray ray = camera.getRay(u, v);
                colorOfRay += color(ray, hitable, 0);
            }
            colorOfRay /= float(ns);
            colorOfRay = Vec3(sqrt(colorOfRay.r), sqrt(colorOfRay.g), sqrt(colorOfRay.b));
            int ir = int(255.99 * colorOfRay.r);
            int ig = int(255.99 * colorOfRay.g);
            int ib = int(255.99 * colorOfRay.b);

            fs << ir << " " << ig << " " << ib << std::endl;
        }
    }
}


