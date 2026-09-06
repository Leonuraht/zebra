#ifndef VECTOR_H
#define VECTOR_H

#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>

typedef struct {
    char* arr;
    size_t size;
    size_t capacity;
} Vector;

Vector* vector_create(size_t initial_capacity);
void vector_free(Vector* vec);

void vector_push(Vector* vec, char val);
void vector_pop(Vector* vec, char* out_val);
void vector_insert(Vector* vec, char val, size_t index);
void vector_delete(Vector* vec, size_t index);

#endif
