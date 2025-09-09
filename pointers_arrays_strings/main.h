#ifndef MAIN_H
#define MAIN_H

/* Standard library headers */
#include <stddef.h>

/* Function prototypes */
int _putchar(char c);
unsigned int _strspn(char *s, char *accept);
char *_strpbrk(char *s, char *accept);
void print_rev(char *s);
char *_strstr(char *haystack, char *needle);
void print_chessboard(char (*a)[8]);
void print_diagsums(int *a, int size);

/* Add here prototypes for your other functions as needed */

#endif /* MAIN_H */

