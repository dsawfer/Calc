#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "header.h"

int is_digit(char* numb)
{
    int step = 0;
    while (numb[step])
        if (numb[step] < '0' || numb[step] > '9')
            return 0;
        else step++;
    return 1;
}

makeExpression(char* expression, char** data, int row, int col)
{
    int step = 0;
    while (data[row][col]) {
        expression[step++] = data[row][col++];
    }
}

double findSolution(char* numb, char** data)    //переделать
{
    int row = 1, col = 0;
    while (data[row][col] && data[row][col] != ' ') {
        if (numb[col] != data[row][col]) {
            row++;
            col = 0;
            continue;
        }
        else
        {
            col++;
            continue;
        }
    }
    char expression[size] = { 0 };
    makeExpression(expression, data, row, col + 3);
    double digit = distributor(expression, data);
    return digit;
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

addSymb(char* numb, char symb)
{
    int step = 0;
    while (numb[step++])
    {
    }
    numb[step - 1] = symb;
}

double parse(char* numb)
{
    double digit = 0;
    if (numb[0] == '!') numb[0] = '-';
    sscanf(numb, "%lf", &digit);
    return digit;
}

double distributor(char* expression, char** data)
{
    double stack[size] = { 0 };
    double op_stack[size] = { 0 };          //стек операторов
    int point = 0, op_point = 0;
    int step = 0;

    char numb[size] = { 0 };

    while (expression[step]) {
        char symb = expression[step];
        if (!is_operator(symb)) {           //если не оператор, то продолжить
            addSymb(numb, symb);
            step++;
            continue;
        }

        if (numb[0] && is_digit(numb)) {
            double digit = parse(numb);
            point = push(stack, point, digit);
        }
        else {
            if (numb[0]) {
                double digit = findSolution(numb, data);
                point = push(stack, point, digit);
            }
        }
       
        while(prio(symb) >= prio(top(op_stack, op_point)) && top(op_stack, op_point) != '(') {
            int operator = top(op_stack, op_point);                     //выталкивает оператор из стека операторов
            op_point = pop(op_stack, op_point);                         //

            if (operator == '|') {
                double a = top(stack, point);
                point = pop(stack, point);

                point = push(stack, point, calculate(a, 0, operator));
            }
            else {
                double b = top(stack, point);
                point = pop(stack, point);
                double a = top(stack, point);
                point = pop(stack, point);

                point = push(stack, point, calculate(a, b, operator));
            }
        }

        if (symb == ')' && top(op_stack, op_point) == '(') {
            op_point = pop(op_stack, op_point);
        }
        else op_point = push(op_stack, op_point, symb);
        

        memset(numb, '\0', size);                                       //обнуляет numb
        step++;
    }

    if (numb[0]) {
        double digit = parse(numb);
        point = push(stack, point, digit);
    }

    while (!is_empty(op_stack, op_point))
    {
        int operator = top(op_stack, op_point);
        op_point = pop(op_stack, op_point);

        if (operator == '|') {
            double a = top(stack, point);
            point = pop(stack, point);

            point = push(stack, point, calculate(a, 0, operator));
        }
        else {
            double b = top(stack, point);
            point = pop(stack, point);
            double a = top(stack, point);
            point = pop(stack, point);

            point = push(stack, point, calculate(a, b, operator));
        }
    }
    return top(stack, point);
}