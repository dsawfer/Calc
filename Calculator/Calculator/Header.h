#pragma once

#define size 100
#define length 10		//количество строк в input

int push(double stack[], int point, double digit);
int pop(double stack[], int point);
int is_empty(double stack[], int point);
double top(double stack[], int point);

double distributor(char* expression, char** data);