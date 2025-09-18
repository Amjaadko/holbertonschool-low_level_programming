#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dog.h"

dog_t *new_dog(char *name, float age, char *owner)
{
    dog_t *d;

    if (!name || !owner)
        return (NULL);

    d = malloc(sizeof(dog_t));
    if (!d)
        return (NULL);

    d->name = malloc(strlen(name) + 1);
    if (!d->name)
    {
        free(d);
        return (NULL);
    }
    strcpy(d->name, name);

    d->owner = malloc(strlen(owner) + 1);
    if (!d->owner)
    {
        free(d->name);
        free(d);
        return (NULL);
    }
    strcpy(d->owner, owner);

    d->age = age;

    return (d);
}

