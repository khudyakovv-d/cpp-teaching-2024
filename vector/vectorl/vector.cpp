#include "vector.h"
#include <iostream>

Vector::Vector() {
    this->arr_ = new int[0]{};
    this->size_ = 0;
    std::cout << "Create vector " << this << "\n";
}

Vector::Vector(int size) {
    this->arr_ = new int[size]{};
    this->size_ = size;
    std::cout << "Create vector " << this << " with size " << size << "\n";
}

int &Vector::operator[](int i) {
    return this->arr_[i];
}

int const &Vector::operator[](int i) const {
    return this->arr_[i];
}

int Vector::size() const {
    return this->size_;
}

Vector::~Vector() {
    delete[] this->arr_;
    std::cout << "Delete vector " << this << "\n";
}

Vector::Vector(const Vector &vec) : arr_(new int[vec.size()]), size_(vec.size()) {
    for (int i = 0; i < vec.size(); i++) {
        this->arr_[i] = vec[i];
    }
    std::cout << "Create " << this << " from " << &vec << "\n";
}

Vector &Vector::operator=(const Vector &vec) {
    delete[] this->arr_;

    this->size_ = vec.size();
    this->arr_ = new int[vec.size()];

    for (int i = 0; i < vec.size(); i++) {
        this->arr_[i] = vec[i];
    }

    std::cout << "Copy " << &vec << " to " << this << "\n";
    return *this;
}

Vector operator+(const Vector &vec1, const Vector &vec2) {
    if (vec1.size() != vec2.size()) {
        throw std::length_error("Vectors must be same size");
    }

    Vector v = Vector(vec1.size());

    for (int i = 0; i < vec1.size(); i++) {
        v[i] = vec1[i] + vec2[i];
    }

    std::cout << "Sum " << &vec1 << " and " << &vec2 << " to " << &v << "\n";

    return v;
}

Vector::Vector(Vector &&vec) noexcept {
    this->arr_ = vec.arr_;
    this->size_ = vec.size_;
    vec.arr_ = nullptr;
    vec.size_ = 0;
    std::cout << "Create vector " << this << " with move " << &vec << "\n";
}
