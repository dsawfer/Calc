#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "header.h"

madeExpression(char* exp, char* expression, int step)
{
    step += 1;
    int point = 0, hooks = 1;
    while (hooks) {
        if (expression[step] == ')') hooks--;
        if (expression[step] == '(') hooks++;
        exp[point++] = expression[step++];
    }
    exp[point - 1] = '\0';
}

double calcFunction(char* expression, int step, int func, char** data)
{
    char exp[size] = { 0 };
    madeExpression(exp, expression, step);
    double digit = distributor(exp, data);
    switch (func)
    {
    case 1:
        return sin(digit);
    case 2:
        return cos(digit);
    case 3:
        return (sin(digit) / cos(digit));
    case 4:
        return (cos(digit) / sin(digit));
    case 5:
        return log10(digit);
    case 6:
        return log(digit);
    case 7:
        return abs(digit);
    }
    return 0;
}