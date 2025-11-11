#include "calc.h"
#include <math.h>

// Basic operations
double add(double a, double b) { return a + b; }
double subtract(double a, double b) { return a - b; }
double multiply(double a, double b) { return a * b; }
double divide(double a, double b) { return b != 0 ? a / b : 0; }

// Scientific operations
double power(double a, double b) { return pow(a, b); }
double factorial(double n) {
    if (n < 0) return 0;
    if (n == 0) return 1;
    double res = 1;
    for(int i=1; i<=n; i++) res *= i;
    return res;
}
double sine(double x) { return sin(x); }
double cosine(double x) { return cos(x); }
double tangent(double x) { return tan(x); }
double logarithm(double x) { return x > 0 ? log10(x) : 0; }
double ln(double x) { return x > 0 ? log(x) : 0; }
double square_root(double x) { return x >= 0 ? sqrt(x) : 0; }
double exp_value(double x) { return exp(x); }
