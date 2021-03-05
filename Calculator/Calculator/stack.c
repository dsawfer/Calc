#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "header.h"

int push(int stack[], int point, int digit)
{
    if (point < size)
        stack[point++] = digit;
    return point;
}

int pop(int stack[], int point)
{
    if (point)
        --point;
    return point;
}

int is_empty(int stack[], int point)
{
    return !point;
}

int top(int stack[], int point)
{
    if (!is_empty(stack, point))
        return stack[point - 1];
    return 0;
}

