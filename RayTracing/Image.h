#include <math.h>
#include <stdio.h>
#include <iostream>
#include "Vec3.h"

using Color = Vec3;

struct Image {
    static constexpr int height = 384;
    static constexpr int width = 256;
    Color data[height][width];
};