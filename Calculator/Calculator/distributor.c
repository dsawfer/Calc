#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include "header.h"

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
    }
    return 0;
}

int prio(char symb)
{
    switch (symb)
    {
    case '+':
        return 2;
    case '-':
        return 2;
    case '*':
        return 1;
    case '/':
        return 1;
    }
    return 10;
}

int calculate(int a, int b, char operator)
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

int parse(char* numb)
{
    int digit = 0;
    if (numb[0] == '!') numb[0] = '-';
    sscanf(numb, "%d", &digit);
    return digit;
}

distributor(char** data)
{
    int stack[size] = { 0 };                //массив выхода
    int op_stack[size] = { 0 };
    int point = 0, op_point = 0;
    int step = 0;

    char expression[size] = { 0 };          //главное выражение
    strcpy(expression, data[0]);

    char numb[size] = { 0 };

    while (expression[step]) {
        char symb = expression[step];
        if (!is_operator(symb)) {           //если не оператор, то продолжить
            addSymb(numb, symb);
            step++;
            continue;
        }
        int digit = parse(numb);
        point = push(stack, point, digit);

        while(prio(symb) >= prio(top(op_stack, op_point))) {
            int operator = top(op_stack, op_point);                     //выталкивает оператор из стека операторов
            op_point = pop(op_stack, op_point);                         //

            int b = top(stack, point);
            point = pop(stack, point);
            int a = top(stack, point);
            point = pop(stack, point);

            point = push(stack, point, calculate(a, b, operator));
        }
        op_point = push(op_stack, op_point, symb);

        memset(numb, '\0', size);                                       //обнуляет numb
        step++;
    }
    if (numb) {
        int digit = parse(numb);
        point = push(stack, point, digit);
    }
    while (!is_empty(op_stack, op_point))
    {
        int operator = top(op_stack, op_point);
        op_point = pop(op_stack, op_point);

        int b = top(stack, point);
        point = pop(stack, point);
        int a = top(stack, point);
        point = pop(stack, point);

        point = push(stack, point, calculate(a, b, operator));
    }
    printf("%d", top(stack, point));
}