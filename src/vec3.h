//
//  Vec3.h
//  
//
//  Created by Anuraj Nair on 7/15/25.
//

#pragma once

#include <iostream>
#include <cmath>

class Vec3 {
private:
    double coord[3];
    
public:
    // constructors; default and parameterized
    Vec3() : coord{0, 0, 0} {}
    Vec3(double coord0, double coord1, double coord2) : coord{coord0, coord1, coord2} {}
    
    // getters, const functions
    double x() const {
        return coord[0];
    }
    double y() const {
        return coord[1];
    }
    double z() const {
        return coord[2];
    }
    
    // unary operator definitions (overloads)
    Vec3 operator-() const {
        return Vec3(-coord[0], -coord[1], -coord[2]);
    }
    
    double operator[](int i) const {
        // for const instances of Vec3, prevents writing
        return coord[i];
    }
    
    double& operator[](int i) {
        return coord[i];
    }
    
    // binary operators
    Vec3& operator+=(const Vec3& v) {
        coord[0] += v.coord[0];
        coord[1] += v.coord[1];
        coord[2] += v.coord[2];
        return *this;
    }
    
    Vec3& operator*=(double i) {
        coord[0] *= i;
        coord[1] *= i;
        coord[2] *= i;
        return *this;
    }
    
    Vec3& operator/=(double i) {
        return *this *= 1/i;
    }
    
    // length of vectors
    double euclidean_norm_radicand() const {
        return pow(coord[0], 2) + pow(coord[1], 2) + pow(coord[2], 2);
    }
    
    double euclidean_norm() const {
        return std::sqrt(euclidean_norm_radicand());
    }
};

// aliases for Vec3
using Color = Vec3;
using Point = Vec3;

// functions for vector manipulation
inline Vec3 operator+(const Vec3& v, const Vec3& u){
    return Vec3(v.x() + u.x(), v.y() + u.y(), v.z() + u.z());
}

inline Vec3 operator-(const Vec3& v, const Vec3& u){
    return Vec3(v.x() - u.x(), v.y() - u.y(), v.z() - u.z());
}

inline Vec3 operator*(const Vec3& v, const Vec3& u){
    // Hadamard product
    return Vec3(v.x() * u.x(), v.y() * u.y(), v.z() * u.z());
}

// scalar multiplication
inline Vec3 operator*(const double f, const Vec3& v){
    return Vec3(f * v.x(), f * v.y(), f * v.z());
}

inline Vec3 operator*(const Vec3& v, const double f){
    return Vec3(f * v.x(), f * v.y(), f * v.z());
}

inline Vec3 operator/(const Vec3& v, double f){
    return v * (1/f);
}

inline double dot_product(const Vec3& v, const Vec3& u){
    return v.x() * u.x() + v.y() * u.y() + v.z() * u.z();
}

inline Vec3 cross_product(const Vec3& v, const Vec3& u){
    return Vec3(v.y() * u.z() - v.z() * u.y(),
                v.z() * u.x() - v.x() * u.z(),
                v.x() * u.y() - v.y() * u.x()
                );
}

// unit vector along a given Vec3
inline Vec3 unit_vector(const Vec3& v){
    return v / v.euclidean_norm();
}

// write vector out
inline std::ostream& operator<<(std::ostream& out, const Vec3& v){
    return out << v.x() << " " << v.y() << " " << v.z();
}
