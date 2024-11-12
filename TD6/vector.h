//
// Created by hhaym on 05/11/2024.
//

#ifndef VECTOR_H
#define VECTOR_H



class Vector {
public:
    Vector();
    Vector(int count, float value);
    ~Vector() {delete data_;}
    Vector(const Vector& other);
    Vector& operator=(const Vector& other);
    int size() const {return size_;}
    void push_back(const float& f);
    float& operator[](int index) {return data_[index];}
    const float& operator[](int index) const {return data_[index];}
    void reserve(int new_cap);

    Vector(Vector&& other) noexcept;
    Vector& operator=(Vector&& other) noexcept;
private:
    int size_ = 0;
    float* data_;
    int capacity_ = 10;

};



#endif //VECTOR_H
