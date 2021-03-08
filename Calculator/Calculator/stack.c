#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <math.h>
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

int is_operator(char symb)
{
    switch (symb)
    {
    case '+':
        return 1;
    case '-':
        return 2;
    case '*':
        return 3;
    case '/':
        return 4;
    case '(':
        return 5;
    case ')':
        return 6;
    case '^':
        return 7;
    case '|':
        return 8;
    }
    return 0;
}

int prio(char symb)
{
    switch (symb)
    {
    case '+':
        return 4;
    case '-':
        return 4;
    case '*':
        return 3;
    case '/':
        return 3;
    case '(':
        return 1;
    case ')':
        return 5;
    case '^':
        return 2;
    case '|':
        return 2;
    }
    return 10;
}

double calculate(double a, double b, char operator)
{
    switch (operator)
    {
    case '+':
        return (a + b);
    case '-':
        return (a - b);
    case '*':
        return (a * b);
    case '/':
        return (a / b);
    case '^':
        return (pow(a, b));
    case '|':
        return (sqrt(a));
    default:
        return 0;
    }
}