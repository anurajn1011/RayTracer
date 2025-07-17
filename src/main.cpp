#include <iostream>
#include <fstream>
#include "Vec3.h"
#include "color.h"

int main() 
{
    // image boundaries
    int width = 256;
    int height = 256;
    
    // output
    std::ofstream out("sample_image.ppm", std::ios::binary);

    // rendering the image
    out << "P6\n" << width << " " << height << "\n255\n";
    
    for(int i = 0; i < height; ++i) {
        for(int j = 0; j < width; ++j) {
            auto pixel = Color(j, i, 0);
            color_out(out, pixel);
        }
    }
    
    out.close();

    return 0;
}
