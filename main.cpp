#include <iostream> // For Printing
#include <cstring> // For String Comparisons

int main(int argc, char* argv[]) {
    // Image Properties
    int image_width = 512;
    int image_height = 512;

    if(argc == 1){
        std::cerr << "Will use defaults size of 512x512\n";
    }
    else if(argc > 5){
        std::cerr << "Too Many Arguments!\nWill use defaults size of 512x512\n";
    }
    else{
        /*
            flag[0] = Image Width
            flag[1] = Image Height
        */
        int* flag = new int[2];
        for(int i = 1; i < argc; i += 2){
            if(strcmp(argv[i], "-w") == 0){
                flag[0] = atoi(argv[i + 1]);
            }
            else if(strcmp(argv[i], "-h") == 0){
                flag[1] = atoi(argv[i + 1]);
            }
        }

        if(flag[0] && flag[1]){
            image_width = flag[0];
            image_height = flag[1];
        }
        else{
            std::cerr << "Error with arguments.\nWill use defaults size of 512x512\n";
        }
        delete flag;
    }

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
            double blue = red / green;

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