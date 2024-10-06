#include <math.h>
#include <stdio.h>
#include <iostream>

struct Vec3 {
    float coord[3];

    float operator[](int i) const {return coord[i];}
};

float dot(Vec3 a, Vec3 b) {
    return a.coord[0] * b.coord[0] + a.coord[1] * b.coord[1] + a.coord[2] * b.coord[2];
}

Vec3 cross(Vec3 a, Vec3 b) {
    Vec3 result;
    result.coord[0] = a.coord[1] * b.coord[2] - a.coord[2] * b.coord[1];
    result.coord[1] = a.coord[2] * b.coord[0] - a.coord[0] * b.coord[2];
    result.coord[2] = a.coord[0] * b.coord[1] - a.coord[1] * b.coord[0];
    return result;
}

float length(Vec3 a) {
    return sqrt(dot(a, a));
}

float length2(Vec3 a) {
    return dot(a, a);
}


inline Vec3 operator+(const Vec3& a, const Vec3& b) {
    Vec3 result;
    result.coord[0] = a.coord[0]+b.coord[0];
    result.coord[1] = a.coord[1]+b.coord[1];
    result.coord[2] = a.coord[2]+b.coord[2];
    return result;
}

inline Vec3 operator-(const Vec3& a, const Vec3& b) {
    Vec3 result;
    result.coord[0] = a.coord[0]-b.coord[0];
    result.coord[1] = a.coord[1]-b.coord[1];
    result.coord[2] = a.coord[2]-b.coord[2];
    return result;
}



inline Vec3 operator*(const float a, const Vec3& b) {
    Vec3 result;
    result.coord[0] = a*b.coord[0];
    result.coord[1] = a*b.coord[1];
    result.coord[2] = a*b.coord[2];
    return result;
}

inline Vec3 operator-(const Vec3& a) {
    return -1 * a;
}

inline Vec3 operator*(const Vec3& b, const float a) {
    Vec3 result;
    result.coord[0] = a*b.coord[0];
    result.coord[1] = a*b.coord[1];
    result.coord[2] = a*b.coord[2];
    return result;
}
inline std::ostream& operator<<(std::ostream& out, const Vec3& a) {
    return out <<a.coord[0] << " " << a.coord[1] << " " << a.coord[2]<<std::endl;
}
