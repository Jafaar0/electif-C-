//
// Created by hhaym on 12/11/2024.
//

#ifndef HITRECORD_H
#define HITRECORD_H
#include "Vec3.h"


struct HitRecord {
    Vec3 position;
    Vec3 normal;
    float t_min = std::numeric_limits<float>::infinity();
};



#endif //HITRECORD_H
