#include <cstdio>
#include <cstdlib>
#include "complex_test.h"
#include "complex_number.h"
#define M "\033[0;32m"
#define W "\033[0;m"
#define C "\033[0;35m"

void display_mandelbrot(int width, int height, int max_its) {
    const float x_start = -3.0f;
    const float x_fin = 1.0f;
    const float y_start = -1.0f;
    const float y_fin = 1.0f;
    double dx = (x_fin - x_start) / (width - 1);
    double dy = (y_fin - y_start) / (height - 1);
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            Complex z = complex_create(0, 0);
            Complex c = complex_create(x_start + x * dx, y_start + y * dy);

            int iteration = 0;
            while (complex_mag(z) < 2 && ++iteration < max_its) {
                z = complex_add(complex_multiply(z, z), c);
            }

            if (iteration == max_its) {
                printf(C"*");
            }
            else {
                printf(M"-");
            }
        }
        printf("\n");
    }
}


int main(int argc, char** argv) {

    run_complex_tests(true);

    // complex allocated on the stack
    Complex c1;
    c1.real = 5;
    c1.imag = 4;
    float c1_phase = complex_phase(c1);
    float c1_mag = complex_mag(c1);
    float r, theta;
    printf(M"Complex number allocated on the stack:");
   
    complex_display(c1);
    printf(W"\n\n");

    /*These functions are already called in complex_to_polar function
    printf("Magnitude: %f", c1_mag);
    printf("\n");
    printf("Phase: %f", c1_phase);
    printf("\n\n");
    */

    complex_to_polar(c1, &r, &theta);
    printf("Polar coordinates\nMagnitude: %f\nPhase: %f radians.", r, theta);
    printf("\n\n");

    printf("Conjugate\n");
    complex_display(complex_conjugate(c1));
    printf("\n\n");

    float scalar = 3;
    complex_scalar_mult(&c1, scalar);
    printf("Multiplication with the scalar %f\n", scalar);
    complex_display(c1);
    printf("\n\n\n");


    // complex allocated on the heap
    Complex* c2 = (Complex*)malloc(sizeof(Complex));
    c2->real = 3;
    c2->imag = 12;
    float c2_mag = complex_mag(*c2);
    float r2, theta2;
    printf(M"Complex number allocated on the heap:");

    complex_display(*c2);
    printf(W"\n\n");

    /*These functions are already called in complex_to_polar function
    printf("Magnitude: %f", c2_mag);
    printf("\n");
    printf("Phase: %f", c2_phase);
    printf("\n\n");
    */

    complex_to_polar(*c2, &r2, &theta2);
    printf("Polar coordinates\nMagnitude: %f\nPhase: %f", r, theta);
    printf("\n\n");

    printf("Conjugate\n");
    complex_display(complex_conjugate(*c2));
    printf("\n\n");

    float scalar2 = 4;
    complex_scalar_mult(c2, scalar2);
    printf("Multiplication with the scalar %f\n", scalar2);
    complex_display(*c2);
    printf("\n\n\n");


    // operations with complex
    printf(M"Operations with the complex numbers\n\n\n");
    

    printf(W"Addition:\n");
    complex_display(complex_add(c1, *c2));
    printf("\n\n");

    printf("Subtraction:\n");
    complex_display(complex_subtract(c1, *c2));
    printf("\n\n");

    printf("Multiplication:\n");
    complex_display(complex_multiply(c1, *c2));
    printf("\n\n");

    Complex c2_inv;
    c2_inv.real = 2 / c2->real;
    c2_inv.imag = 3 / c2->imag;
    printf("Division:\n");
    complex_display(complex_multiply(c1, c2_inv));
    printf("\n\n");

    free(c2);

    display_mandelbrot(100, 25, 100);
    (void)getchar();

    return 0;
}