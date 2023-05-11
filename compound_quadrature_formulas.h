#ifndef COMPOUND_QUADRATURE_FORMULAS_H_INCLUDED
#define COMPOUND_QUADRATURE_FORMULAS_H_INCLUDED
#include "functions.h"

double leftRectangles (size_t num, double w, double step)
{
    switch (num){
        case 0:
            return step*(polinom0degree()+w);
        case 1:
            return step*(polinom1degree(0)+w);
        case 2:
            return step*(polinom2degree(0)+w);
        case 3:
            return step*(polinom3degree(0)+w);
        case 4:
            return step*(func(0)+w);
        case 5:
            return step*(f(0)+w);
        }
    return 0;
}

double rightRectangles (size_t num, double w, double step, double n)
{
    switch (num){
        case 0:
            return step*(polinom0degree()+w);
        case 1:
            return step*(polinom1degree(n)+w);
        case 2:
            return step*(polinom2degree(n)+w);
        case 3:
            return step*(polinom3degree(n)+w);
        case 4:
            return step*(func(n)+w);
        case 5:
            return step*(f(n)+w);
        }
    return 0;
}

double middleRectangles(size_t num, double q, double step)
{
    return step*q;
}

double trapeze(size_t num, double w, double step, double n)
{
    switch (num){
        case 0:
            return step*(polinom0degree()+polinom0degree()+2*w)/2;
        case 1:
            return step*(polinom1degree(0)+polinom1degree(n)+2*w)/2;
        case 2:
            return step*(polinom2degree(0)+polinom2degree(n)+2*w)/2;
        case 3:
            return step*(polinom3degree(0)+polinom3degree(n)+2*w)/2;
        case 4:
            return step*(func(0)+func(n)+2*w)/2;
        case 5:
            return step*(f(0)+f(n)+2*w)/2;
        }
    return 0;
}

double simpson(size_t num, double w, double q, double step, double n)
{
    switch (num){
        case 0:
            return step*(polinom0degree()+polinom0degree()+2*w+4*q)/6;
        case 1:
            return step*(polinom1degree(0)+polinom1degree(n)+2*w+4*q)/6;
        case 2:
            return step*(polinom2degree(0)+polinom2degree(n)+2*w+4*q)/6;
        case 3:
            return step*(polinom3degree(0)+polinom3degree(n)+2*w+4*q)/6;
        case 4:
            return step*(func(0)+func(n)+2*w+4*q)/6;
        case 5:
            return step*(f(0)+f(n)+2*w+4*q)/6;
        }
    return 0;
}

#endif // COMPOUND_QUADRATURE_FORMULAS_H_INCLUDED
