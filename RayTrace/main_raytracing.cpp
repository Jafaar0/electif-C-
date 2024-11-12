#include "Image.h"
#include "Intersection.h"
#include "Ray.h"

int main()
{
    Image image(400,400);
    constexpr int num_spheres = 6;
    Sphere spheres[num_spheres] = {
        { .center = {{ 0, 0, 5 }}, .radius = 0.3 },
        { .center = {{ -0.35, 0, 5 }}, .radius = 0.2 },
        { .center = {{ 0.45, 0.35, 5 }}, .radius = 0.1 },
        { .center = {{ 1.0, 1.0, 5 }}, .radius = 0.1 },
        { .center = {{ -1, -1, 5 }}, .radius = 0.5 },
        { .center = {{ 1.25, -0.25, 5 }}, .radius = 0.6 }
        };

    for (int j = 0; j < image.height(); j++) {
        for (int i = 0; i < image.width(); i++) {

            float x = 2.0F*static_cast<float>(i) / static_cast<float>(image.height()-1) - 1.0F;
            float y = 2.0F*static_cast<float>(j) / static_cast<float>(image.height()-1) - 1.0F;

            Ray ray = { .origin = { x, y, 0 }, .direction = { 0, 0, 1 } };
            HitRecord intersection = intersect(ray, spheres);
            if (intersection.t_min!=std::numeric_limits<float>::infinity()) {
                Vec3 normal = intersection.normal;
                Color color = 0.5* Color{{ normal[0]+1, normal[1]+1, normal[2]+1 }};
                image(i,j) = color;
            } else {
                image(i,j) = Color{{1.0F,1.0F,1.0F}};
            }
        }
    }

    writeImagePPM(image);
}


//TODO faire une class Hittable qui a comme méthodes : virtual bool hit(const Ray &ray, HitRecord& record const =0)