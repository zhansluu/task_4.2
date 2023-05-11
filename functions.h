#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED
#include <cmath>

double f (double x)
{
    return 1.27*pow(x,5)+2.04*x;
}

double F (double x)
{
    return (1.27*pow(x,6)+6.12*x*x)/6;
}

double rho ()
{
    return 1;
}

double polinom0degree ()
{
    return 12;
}

double polinom1degree (double x)
{
    return x-4;
}

double polinom2degree (double x)
{
    return 3*x*x+4*x-3;
}

double polinom3degree (double x)
{
    return 4*x*x*x-6*x*x+7*x-10;
}

double func (double x)
{
    return 6*x*x+cos(x)*exp(4*x);
}


double integralOfPolinom0degree (double x)
{
    return 12*x;
}

double integralOfPolinom1degree (double x)
{
    return 0.5*x*x-4*x;
}

double integralOfPolinom2degree (double x)
{
    return x*x*x+2*x*x-3*x;
}

double integralOfPolinom3degree (double x)
{
    return x*x*x*x-2*x*x*x+3.5*x*x-10*x;
}

double integralOfFunc (double x)
{
    return 2*x*x*x+(exp(4*x)*sin(x)+4*cos(x)*exp(4*x))/17;
}

#endif // FUNCTIONS_H_INCLUDED
