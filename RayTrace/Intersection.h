#pragma once
#include <span>

#include "Geometry.h"
#include "HitRecord.h"
#include "Ray.h"

float intersect(const Ray& ray, const Sphere& sphere);

HitRecord intersect(const Ray& ray, std::span<const Sphere> spheres);
