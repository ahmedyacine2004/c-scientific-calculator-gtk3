#ifndef CALC_H
#define CALC_H

#include <math.h>

// Basic operations
double add(double a, double b);
double subtract(double a, double b);
double multiply(double a, double b);
double divide(double a, double b);

// Scientific operations
double power(double a, double b);
double factorial(double n);
double sine(double x);
double cosine(double x);
double tangent(double x);
double logarithm(double x);   // log base 10
double ln(double x);          // natural log
double square_root(double x);
double exp_value(double x);   // e^x

#endif
