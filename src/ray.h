//
//  ray.h
//  
//
//  Created by Anuraj Nair on 7/16/25.
//

# pragma once

#include <iostream>
#include "Vec3.h"

// Mathematical construct of a ray

class Ray {
private:
    Point origin;
    Vec3 direction;

public:
    // constructors: default and parameterized
    Ray() {}

    Ray(const Point& origin, const Vec3& direction) : origin(origin), direction(direction) {}

    // getters
    const Point& origin() const {
        return origin;
    }

    const Vec3& direction() const {
        return direction;
    }

    // at function will return where our current position is on the ray
    Point at(float scale) const {
        return origin + scale * direction;
    }
};
