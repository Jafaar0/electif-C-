//
// Created by hhaym on 05/11/2024.
//

#include "vector.h"


Vector::Vector() {
    data_= new float[capacity_];
}
Vector::Vector(int count, float value) {
    capacity_ = count;
    size_ = count;
    data_= new float[capacity_];
    for (int i = 0; i < count; i++) {
        data_[i] = value;
    }
}

Vector::Vector(const Vector& other) {
    capacity_ = other.capacity_;
    data_ = new float[capacity_];
    if (other.data_!=nullptr) {
        for (int i = 0; i < other.size_; i++) {
            data_[i] = other.data_[i];
        }
    }
    size_ = other.size_;
}

Vector& Vector::operator=(const Vector& other) {
    if(&other!=this) {
        delete[] data_;
        capacity_ = other.capacity_;
        data_ = new float[capacity_];
        if (other.data_!=nullptr) {
            for (int i = 0; i < other.size_; i++) {
                data_[i] = other.data_[i];
            }
        }
        size_ = other.size_;
    }
    return *this;
}
void Vector::push_back(const float& f) {
    if (capacity_==size_) {
        reserve(2*capacity_);
    }
    data_[++size_] = f;
}

void Vector::reserve(int new_cap) {
    if (new_cap>capacity_) {
        float* new_ptr = new float[capacity_];
        for (int i=0; i<size_; ++i) {
            new_ptr[i] = this->data_[i];
        }
        delete[](this->data_);
        data_ = new_ptr;
    }
}

Vector::Vector(Vector &&other)  noexcept {
    capacity_ = other.capacity_;
    size_ = other.size_;
    data_ = other.data_;
    other.data_ = nullptr;
    other.capacity_ = 0;
    other.size_ = 0;
}

Vector& Vector::operator=(Vector &&other) noexcept {
    if(&other!=this) {
        delete[] data_;
        capacity_ = other.capacity_;
        size_ = other.size_;
        data_ = other.data_;
        other.data_ = nullptr;
        other.capacity_ = 0;
        other.size_ = 0;

    }
    return *this;
}




