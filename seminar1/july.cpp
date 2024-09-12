#include <stdlib.h>
#include <stdio.h>
#include "cs_mipt_faki/term2/seminar01_overload/homework/code/complex.h"


mipt::Complex f(mipt::Complex z, mipt::Complex c) {
    return z * z + c;
}

struct Color {
    unsigned char r, g, b;
};

int main(int argc, const char* argv[]) {
    int pixels_width  = 800;
    int pixels_height = 800;
    int N = 20;

    mipt::Complex c = {-2, -2};

    switch (argc) {
        case (1):
            break;
        case (4):
            sscanf(argv[1], "%f", &c.re);
            sscanf(argv[2], "%f", &c.im);
            sscanf(argv[3], "%d", &N);
            break;
        default:
            printf("Wrong number of aguments: expected 3, got %d\n", argc);
            return -1;
    }

    mipt::Complex z = {};
    Color* data = (Color*)std::calloc(sizeof(Color), pixels_width * pixels_height);
    for (int l = 0; l < 800; l++) {
        c.re += 1.0 / 400;
        c.im += 1.0 / 400;
        for (int i = 0; i < pixels_width; i++) {
            for (int j = 0; j < pixels_height; j++) {
                z.re = (i - (double)(pixels_width)  / 2.0) / pixels_width  * 2.0 * (1 + l / 800.0);
                z.im = (j - (double)(pixels_height) / 2.0) / pixels_height * 2.0 * (1 + l / 800.0);

                for ( int k = N; k > 0; k-- ) {
                    z = f(z, c);
                }

                data[j + i * pixels_width].r = (int)(z.re * pixels_width) % 256;
                data[j + i * pixels_width].g = 0;
                data[j + i * pixels_width].b = (int)(z.im * pixels_height) % 256;
            }
        }
        char name[100] = {};
        std::sprintf(name, "anim/complex_image%03d.ppm", l);
        FILE* file = std::fopen(name, "wb");
        std::fprintf(file, "P6\n%d %d\n255\n", pixels_width, pixels_height);
        std::fwrite(data, sizeof(Color), pixels_height * pixels_width, file);
        std::fclose(file);
    }
    std::free(data);
    return 0;
}
