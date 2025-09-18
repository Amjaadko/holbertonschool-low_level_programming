#include <stdlib.h>
#include "dog.h"

/* helper function to calculate string length */
int _strlen(char *s)
{
    int i = 0;
    while (s[i])
        i++;
    return (i);
}

/* helper function to copy string manually */
void _strcpy(char *dest, char *src)
{
    int i = 0;
    while (src[i])
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}

dog_t *new_dog(char *name, float age, char *owner)
{
    dog_t *d;
    int len_name, len_owner;

    if (!name || !owner)
        return (NULL);

    d = malloc(sizeof(dog_t));
    if (!d)
        return (NULL);

    len_name = _strlen(name);
    d->name = malloc(len_name + 1);
    if (!d->name)
    {
        free(d);
        return (NULL);
    }
    _strcpy(d->name, name);

    len_owner = _strlen(owner);
    d->owner = malloc(len_owner + 1);
    if (!d->owner)
    {
        free(d->name);
        free(d);
        return (NULL);
    }
    _strcpy(d->owner, owner);

    d->age = age;

    return (d);
}

