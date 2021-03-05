#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include "header.h"

char** readFile();

int main()
{
	char** data;
	data = readFile();
	distributor(data);

	for (int i = 0; i < length; i++)
		free(data[i]);
	free(data);
}

char** readFile()
{
	FILE* input = fopen("input.txt", "rt");
	char str[100] = { 0 };

	char** tmp = { 0 };
	tmp = (char**)malloc(length * sizeof(char*));
	for (int i = 0; i < length; i++) {
		tmp[i] = (char*)malloc(size * sizeof(char));
	}

	int step = 0;
	while (!feof(input))
	{
		fgets(str, 100, input);
		int len = (strlen(str) - 1);
		if (str[len] == '\n')
			str[len] = '\0';
		strcpy(tmp[step++], str);
	}

	fclose(input);
	return tmp;
}