cmake_minimum_required(VERSION 3.29)
project(RayTrace)

set(CMAKE_CXX_STANDARD 23)

add_executable(RayTrace main_raytracing.cpp
        Intersection.cpp
        Image.cpp
        Vec3.cpp
        HitRecord.cpp
        HitRecord.h)
