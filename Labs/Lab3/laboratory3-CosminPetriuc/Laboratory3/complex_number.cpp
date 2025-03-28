#include <math.h>
#include <stdio.h>

#include "complex_number.h"


Complex complex_create(float real, float imag) {
	Complex c;
	c.real = real;
	c.imag = imag;
	return c;
}

float get_real(Complex c)
{
	return c.real;
}
float get_imag(Complex c)
{
	return c.imag;
}

void set_real(Complex* c, float real)
{
	c->real = real;
}
void set_imag(Complex* c, float imag)
{
	c->imag = imag;
}

void complex_display(Complex c) {
	if (c.imag < 0) {
		printf("%.2f - %.2fi\n", c.real, -c.imag);
	}
	else {
		printf("%.2f + %.2fi\n", c.real, c.imag);
	}
}

Complex complex_add(Complex c1, Complex c2) {
	return complex_create(c1.real + c2.real, c1.imag + c2.imag);
}

Complex complex_subtract(Complex c1, Complex c2) 
{
	return complex_create(c1.real - c2.real, c1.imag - c2.imag);
}

Complex complex_multiply(Complex c1, Complex c2) {
	float real = c1.real * c2.real - c1.imag * c2.imag;
	float imag = c1.real * c2.imag + c1.imag * c2.real;
	return complex_create(real, imag);
}

bool complex_equals(Complex c1, Complex c2) 
{
	return (c1.real == c2.real) && (c1.imag == c2.imag);
}

Complex complex_conjugate(Complex c){
	Complex c_conjugate;
	c_conjugate.real = c.real;
	c_conjugate.imag = -c.imag;
	return c_conjugate;
}

void complex_scalar_mult(Complex* c, float s) {
	c->real *= s;
	c->imag *= s;
}

float complex_mag(Complex c) 
{
	return sqrt(c.real * c.real + c.imag * c.imag);
}

float complex_phase(Complex c)
{
	return atan2(c.imag, c.real);
}

void complex_to_polar(Complex c, float* r, float* theta) {
	*r = sqrt(c.real * c.real + c.imag * c.imag);
	*theta = atan2(c.imag, c.real);

}