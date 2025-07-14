#include <iostream>

int main() 
{
    // image boundaries
    int width = 256;
    int height = 256;

    // rendering the image
    std::cout << "P3\n" << width << " " << "\n255" << std::endl;
    
    for(int i = 0; i < height; ++i) {
        for(int j = 0; j < width; ++j) {
            auto r = double(j) / (width - 1);
            auto g = double(i) / (height - 1);
            auto b = 0.0;
            
            int ir = int(255.999 * r);
            int ig = int(255.999 * g);
            int ib = int(255.999 * b);

            std::cout << ir << " " << ig << " " << ib << std::endl;
        }
    }

    return 0;
}