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



int main() {
    SetConsoleOutputCP(CP_UTF8);
    // Image image;
    // Color a = {{1,2,3}};
    // image(8,6) = a;
    // a = {{5,5,5}};
    // std::cout << image(8,6) << std::endl;

    Image image = createGradientImage();
    createFile(image);
}