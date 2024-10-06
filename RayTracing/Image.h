#include <math.h>
#include <stdio.h>
#include <iostream>
#include "Vec3.h"

using Color = Vec3;

struct Image {
    static constexpr int height = 256;
    static constexpr int width = 384;
    Color data[height*width];


    const Color& operator()(int x, int y) const {
        return data[y*width+x];
    }

    Color& operator()(int x, int y) {
        return data[y*width+x];
    }
};