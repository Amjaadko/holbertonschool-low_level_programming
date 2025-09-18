#ifndef DOG_H
#define DOG_H

/**
 * struct dog - معلومات عن كلب
 * @name: اسم الكلب
 * @age: عمر الكلب
 * @owner: صاحب الكلب
 *
 * Description: هيكل يحتوي على تفاصيل الكلب
 */
struct dog
{
	char *name;
	float age;
	char *owner;
};

/**
 * dog_t - تعريف جديد للـ struct dog
 */
typedef struct dog dog_t;

#endif /* DOG_H */

