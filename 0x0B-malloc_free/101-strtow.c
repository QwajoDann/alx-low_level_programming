#include <stdlib.h>
#include "main.h"

/**
 * count_word - helper function to count the number of words in a string
 * @s: string to evaluate
 *
 * Return: number of words
 */
int count_word(char *s)
{
    int flag = 0;
    int wordCount = 0;

    for (int i = 0; s[i] != '\0'; i++)
    {
        if (s[i] == ' ')
        {
            flag = 0;
        }
        else if (flag == 0)
        {
            flag = 1;
            wordCount++;
        }
    }

    return wordCount;
}

/**
 * strtow - splits a string into words
 * @str: string to split
 *
 * Return: pointer to an array of strings (Success)
 * or NULL (Error)
 */
char **strtow(char *str)
{
    if (str == NULL)
    {
        return NULL; // Handle NULL input gracefully
    }

    int len = strlen(str);
    int words = count_word(str);

    if (words == 0)
    {
        return NULL; // No words in the input
    }

    char **matrix = (char **)malloc(sizeof(char *) * (words + 1));

    if (matrix == NULL)
    {
        return NULL; // Memory allocation failed
    }

    int wordIndex = 0;
    int start = -1;

    for (int i = 0; i <= len; i++)
    {
        if (str[i] == ' ' || str[i] == '\0')
        {
            if (start != -1)
            {
                int wordLength = i - start;
                matrix[wordIndex] = (char *)malloc(sizeof(char) * (wordLength + 1));

                if (matrix[wordIndex] == NULL)
                {
                    // Handle memory allocation failure
                    free_matrix(matrix, wordIndex);
                    return NULL;
                }

                strncpy(matrix[wordIndex], str + start, wordLength);
                matrix[wordIndex][wordLength] = '\0';

                wordIndex++;
                start = -1;
            }
        }
        else if (start == -1)
        {
            start = i;
        }
    }

    matrix[wordIndex] = NULL;

    return matrix;
}

// Helper function to free the allocated memory
void free_matrix(char **matrix, int count)
{
    for (int i = 0; i < count; i++)
    {
        free(matrix[i]);
    }
    free(matrix);
}
