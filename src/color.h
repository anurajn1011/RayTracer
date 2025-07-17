//
//  color.h
//  
//
//  Created by Anuraj Nair on 7/16/25.
//

# pragma once

#include <iostream>
#include <fstream>
#include "vec3.h"

/*
    Method to write a single pixel's color.
*/

void color_out(std::ostream& out, const color& pixel){
    unsigned char r = static_cast<unsigned char> pixel.x();
    unsigned char g = static_cast<unsigned char> pixel.y();
    unsigned char b = static_cast<unsigned char> pixel.z();
    
    out.write(reinterpret_cast<const char*>(&r), 1);
    out.write(reinterpret_cast<const char*>(&g), 1);
    out.write(reinterpret_cast<const char*>(&b), 1);
}
