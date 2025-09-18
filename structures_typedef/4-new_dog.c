#include <stdlib.h>
#include <string.h>
#include "dog.h"

/**
 * new_dog - ينشئ كلب جديد
 * @name: اسم الكلب
 * @age: عمر الكلب
 * @owner: صاحب الكلب
 *
 * Return: مؤشر للكلب الجديد، أو NULL إذا فشل
 */
dog_t *new_dog(char *name, float age, char *owner)
{
	dog_t *d;
	char *new_name, *new_owner;

	d = malloc(sizeof(dog_t));
	if (!d)
		return (NULL);

	new_name = malloc(strlen(name) + 1);
	if (!new_name)
	{
		free(d);
		return (NULL);
	}
	strcpy(new_name, name);

	new_owner = malloc(strlen(owner) + 1);
	if (!new_owner)
	{
		free(new_name);
		free(d);
		return (NULL);
	}
	strcpy(new_owner, owner);

	d->name = new_name;
	d->age = age;
	d->owner = new_owner;

	return (d);
}

