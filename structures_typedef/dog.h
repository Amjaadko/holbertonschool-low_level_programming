#ifndef DOG_H
#define DOG_H

/**
 * struct dog - معلومات عن كلب
 * @name: اسم الكلب
 * @age: عمر الكلب
 * @owner: اسم المالك
 */
struct dog
{
    char *name;
    float age;
    char *owner;
};

/**
 * dog_t - اسم جديد (typedef) للـ struct dog
 */
typedef struct dog dog_t;

#endif

