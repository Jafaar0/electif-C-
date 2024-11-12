#include "Intersection.h"

#include <span>

float intersect(const Ray& ray, const Sphere& sphere)
{
    //TODO make it more robust....
    Vec3 oc = sphere.center - ray.origin;
    auto a = dot(ray.direction, ray.direction);
    auto b = -2.0F * dot(ray.direction, oc);
    auto c = dot(oc, oc) - sphere.radius*sphere.radius;
    auto discriminant = b*b - 4.0F*a*c;

    if (discriminant < 0) {
        return std::numeric_limits<float>::infinity();
    } else {
        return (-b - std::sqrt(discriminant) ) / (2.0F*a);
    }
}

HitRecord intersect(const Ray& ray, std::span<const Sphere> spheres)
{
    HitRecord intersection{};

    for (int id = 0; id<spheres.size(); ++id) {
        float t_sphere = intersect(ray, spheres[id]);
        if (t_sphere != std::numeric_limits<float>::infinity() && t_sphere<intersection.t_min) {
            intersection.t_min = t_sphere;
            intersection.position=ray.origin+t_sphere*ray.direction;
            intersection.normal=normalFromPosition(spheres[id],intersection.position);
        }
    }

    return intersection;
}
