#pragma once

#include <memory>

#include "Vec3.h"

using Color = Vec3;

class Image{
public:
    Image(int _width, int _height);

    ~Image();

    const Color& operator()(int x, int y) const
    {
        return pixels[y*width() + x];
    }
    Color& operator()(int x, int y)
    {
        return pixels[y*width() + x];
    }

    int width() const {return width_;}
    int height() const {return height_;}

    Image(const Image& other) = delete;
    const Image& operator=(const Image& other) = delete;
    Image(Image&& other) = delete;
    const Image& operator=(Image&& other) = delete;

private:
    int width_;
    int height_;
    Color *pixels;
};

// @todo : provide the filename as argument !
void writeImagePPM(const Image& image);