# Hash Tables Project

This project implements basic hash table functions in C.

## Files
- **0-hash_table_create.c** - Creates a new hash table.
- **hash_tables.h** - Header file containing struct definitions and function prototypes.
- **README.md** - Project description.

## Function
### `hash_table_t *hash_table_create(unsigned long int size);`
Creates a hash table with a given size and returns a pointer to it.

**Return:**
- Pointer to the newly created hash table.
- `NULL` if memory allocation fails.

## Compilation
```bash
gcc -Wall -Wextra -Werror -pedantic -std=gnu89 0-main.c 0-hash_table_create.c -o a

