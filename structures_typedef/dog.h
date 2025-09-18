#ifndef DOG_H
#define DOG_H

/**
 * struct dog - structure defining a dog
 * @name: name of the dog (string)
 * @age: age of the dog (float)
 * @owner: owner of the dog (string)
 */
struct dog
{
	char *name;
	float age;
	char *owner;
}
typedef struct dog dog_t;

#endif /* DOG_H */

