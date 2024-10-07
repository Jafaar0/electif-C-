#include <ostream>
#include "Image.h"
#include <fstream>
#include <windows.h>

void createFile(const Image& image) {
    std::ofstream file_stream{ "C:/Users/hhaym/Documents/TD C++/electif-C-/RayTracing/Img.ppm" };
    if (!file_stream) {
        std::cerr << "Erreur : impossible de créer le fichier 'Img.ppm'" << std::endl;
        return;
    }

    file_stream << "P3\n" << image.width << " " << image.height << "\n255\n";
    for (int i = 0; i < image.width * image.height; i++) {
        Color color =
            {{
                static_cast<float>(static_cast<int>(image.data[i][0] * 255)),
                static_cast<float>(static_cast<int>(image.data[i][1] * 255)),
                static_cast<float>(static_cast<int>(image.data[i][2] * 255))
            }};
        file_stream << color << "\n";
    }
    std::cout << "Fichier image créé avec succès.\n";
}

Image createGradientImage() {
    Image image;
    for (int x = 0; x < Image::width; x++) {
        for (int y = 0; y < Image::height; y++) {
            float grad = static_cast<float>(x)/ Image::width;
            // un gradient de couleur de blanc à bleu
            image(x,y) = Color {{1-grad,1-grad,1}};
        }
    }
    return image;
}

Image createCocoricoImage() {
    Image image;
    for (int x = 0; x < Image::width; x++) {
        for (int y = 0; y < Image::height; y++) {
            if(x<Image::width/3) {
                image(x,y) = Color {{0,0,1}};
            }
            else if(x>2*Image::width/3) {
                image(x,y) = Color {{1,0,0}};
            }
            else {
                image(x,y) = Color {{1,1,1}};
            }
        }
    }
    return image;
}

Image createBlankImage() {
    Image image;
    for (int x = 0; x < Image::width; x++) {
        for (int y = 0; y < Image::height; y++) {
            image(x,y) = Color {{1,1,1}};
        }
    }
    return image;
}

double intersect(const Sphere& sphere, const Ray& ray) {
    double a = dot(ray.direction,ray.direction);
    double b = -2*dot(ray.direction,sphere.center-ray.center);
    double c = dot(sphere.center-ray.center,sphere.center-ray.center) - sphere.radius*sphere.radius;

    double discriminant = b*b - 4*a*c;
    if (discriminant < 0) {
        return -1;
    }
    else if(discriminant == 0) {
        return -b/(2*a);
    }
    else {
        return (-b - sqrt(discriminant))/(2*a);
    }
}

Image drawSphereWithRay(const Sphere& sphere) {
    Image image = createBlankImage();
    Ray ray = {{1,1,0}};
    for (float x = 0; x < Image::width; x++) {
        for (float y = 0; y < Image::height; y++) {
            // Ray ray = {{x/Image::width*2-1,y/Image::height*2-1,0}};
            float t = intersect(sphere,ray);
            if (t>=0) {
                // std::cout<<t<<"\n"<<std::endl;
                image(x,y) = Color {{0,0,0}};
            }

        }
    }
    return image;

}



int main() {
    SetConsoleOutputCP(CP_UTF8);
    // Image image;
    // Color a = {{1,2,3}};
    // image(8,6) = a;
    // a = {{5,5,5}};
    // std::cout << image(8,6) << std::endl;

    // Image image = createGradientImage();

    std::cout<<"a\n";
    Image image = drawSphereWithRay(Sphere({100,100,-1,50}));
    std::cout<<"b\n";
    createFile(image);
}