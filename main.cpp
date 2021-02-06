#include <iostream>

int main(int argc, char* argv[]) {
    // Image Properties
    int image_width = 1024;
    int image_height = 1024;

    /*
    PPN Image Generator
    https://en.wikipedia.org/wiki/Netpbm#File_formats
    */

    std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";

    for(int i = 0; i < image_width; i++){ // From Left to Right
        std::cerr << "\rScanlines Remaining: " << i << '/' << image_width - 1 << std::flush;
        for(int j = image_height - 1; j >= 0; j--){ // From Top to Bottom
            // Pixel Colours (Red, Green Blue)
            double red = (double)i / (image_width - 1);
            double green = (double)j / (image_height - 1);
            double blue = 0.25;

            /* 
            Casting to int for PPM format
                Note from Multimedia Systems
                ints are easier to do math with
                therefore more efficient
            */

            int intR = (unsigned int)(red * 255.999);
            int intG = (unsigned int)(green * 255.999);
            int intB = (unsigned int)(blue * 255.999);

            std::cout << intR << ' ' << intG << ' ' << intB << '\n';
        }
    }

    std::cerr << "\nDone!\n";

}