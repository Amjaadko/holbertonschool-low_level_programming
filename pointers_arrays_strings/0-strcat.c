#include "main.h"

/**
 * _strcat - concatenates src to the end of dest
 * @dest: destination string
 * @src: source string
 *
 * Return: pointer to dest
 */
char *_strcat(char *dest, char *src)
{
    int i = 0, j = 0;

    /* move i to the end of dest */
    while (dest[i] != '\0')
        i++;

    /* copy src to dest starting from the end */
    while (src[j] != '\0')
    {
        dest[i] = src[j];
        i++;
        j++;
    }

    /* null terminate */
    dest[i] = '\0';

    return dest;
}

