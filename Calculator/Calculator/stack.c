#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "header.h"

int push(double stack[], int point, double digit)
{
    if (point < size)
        stack[point++] = digit;
    return point;
}

int pop(double stack[], int point)
{
    if (point)
        --point;
    return point;
}

int is_empty(double stack[], int point)
{
    return !point;
}

double top(double stack[], int point)
{
    if (!is_empty(stack, point))
        return stack[point - 1];
    return 0;
}

