//
//  vec3.h
//  
//
//  Created by Anuraj Nair on 7/15/25.
//

#pragma once

#include <iostream>
#include <cmath>

class vec3 {
public:
    double coord[3];

    vec3() : coord{0, 0, 0} {}
    vec3(double coord0, double coord1, double coord2) : coord{coord1, coord2, coord3}
    
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
    vec3 operator-() const {
        return vec3(-coord[0], -coord[1], -coord[2]);
    }
    
    double operator-[](int i) const {
        // for const instances of vec3, prevents writing
        return coord[i];
    }
    
    double& operator-[](int i) {
        return coord[i];
    }
    
    // binary operators
    vec3& operator+=(const vec3& v) {
        coord[0] += v.coord[0];
        coord[1] += v.coord[1];
        coord[2] += v.coord[2];
        return *this;
    }
    
    vec3& operator*-(double i) {
        coord[0] *= i;
        coord[1] *= i;
        coord[2] *= i;
        return *this;
    }
    
    vec3& operator/=(double i) {
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

// aliases for vec3
using color = vec3;
using point = vec3;

// functions for vector manipulation
inline vec3 operator+(const vec3& v, const vec3& u){
    return vec3(v.coord[0] + u.coord[0], v.coord[1] + u.coord[1], v.coord[2] + u.coord[2]);
}

inline vec3 operator-(const vec3& v, const vec3& u){
    return vec3(v.coord[0] - u.coord[0], v.coord[1] - u.coord[1], v.coord[2] - u.coord[2]);
}

inline vec3 operator*(const vec3& v, const vec3& u){
    // Hadamard product
    return vec3(v.coord[0] * u.coord[0], v.coord[1] * u.coord[1], v.coord[2] * u.coord[2]);
}
