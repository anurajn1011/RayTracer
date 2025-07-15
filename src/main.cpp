#include <iostream>
#include <fstream>

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
            unsigned char r = static_cast<unsigned char> (j);
            unsigned char g = static_cast<unsigned char> (i);
            unsigned char b = 0;
            
            out.write(reinterpret_cast<const char*>(&r), 1);
            out.write(reinterpret_cast<const char*>(&g), 1);
            out.write(reinterpret_cast<const char*>(&b), 1);
        }
    }
    
    out.close();

    return 0;
}
