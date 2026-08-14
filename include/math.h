#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#define PI      3.14159265358979

int abs(int n);
long labs(long n);
long long llabs(long long n);
double fabs(double x);

double cos(double arg);
double sin(double arg);
double tan(double arg);
double acos(double arg);
double asin(double arg);
double atan(double arg);
double atan2(double y, double x);
double cosh(double arg);
double sinh(double arg);
double tanh(double arg);

double fmod(double x, double y);

double sqrt(double arg);

double ceil(double arg);

double exp(double arg);

double log(double arg);
double log2(double arg);
double log10(double arg);

double pow(double base, double e);

double floor(double arg);

#ifdef __cplusplus
}
#endif