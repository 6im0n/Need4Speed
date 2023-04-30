/*
** EPITECH PROJECT, 2023
** PSU
** File description:
** MINISHELL
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>

static int nb_substrings(char *input, char delimiter)
{
    int count = 0;
    for (size_t i = 0; i < strlen(input); i++) {
        if (input[i] == delimiter) {
            count++;
        }
    }
    return count + 1;
}

static void add_substring(char *substring, char **result, int *j)
{
    if (strcmp(substring, "") != 0) {
        result[*j] = (char *)malloc((strlen(substring) + 1) * sizeof(char));
        strcpy(result[*j], substring);
        (*j)++;
    }
}

char **split_str(char *input, char delimiter)
{
    int j = 0;
    int k = 0;
    int n = nb_substrings(input,delimiter);
    char **result;
    char *temp_str;
    result = (char **)malloc((n + 1) * sizeof(char *));
    result[n] = NULL;
    temp_str = (char *)malloc((strlen(input) + 1) * sizeof(char));
    for (size_t i = 0; i <= strlen(input); i++) {
        if (input[i] == delimiter || input[i] == '\0') {
            temp_str[k] = '\0';
            add_substring(temp_str, result, &j);
            k = 0;
            temp_str = (char *)malloc((strlen(input) - i) * sizeof(char));
        } else {
            temp_str[k] = input[i];
            k++;
        }
    }
    return result;
}
