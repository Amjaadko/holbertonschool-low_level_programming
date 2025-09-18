#include <stdlib.h>
#include "dog.h"

/**
 * _strlen - returns the length of a string
 * @s: the string
 *
 * Return: length of the string
 */
int _strlen(char *s)
{
	int i = 0;

	while (s[i])
		i++;
	return (i);
}

/**
 * _strcpy - copies string from src to dest
 * @dest: destination string
 * @src: source string
 */
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

/**
 * new_dog - creates a new dog
 * @name: name of the dog
 * @age: age of the dog
 * @owner: owner of the dog
 *
 * Return: pointer to new dog, or NULL if fails
 */
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

