#include "vector.h"
#include <stddef.h>
#define INIT_VEC_SIZE 64
#include <stdio.h>

// typedef struct {
//     char* arr;
//     size_t size;
//     size_t capacity;
// } Vector;

static bool vec_expand(Vector *vec) {
  if (vec == NULL)
    return false;
  size_t new_capacity = vec->capacity << 1;
  char *new_arr = (char *)malloc(new_capacity);
  if (new_arr == NULL) {
    printf("ARRAY MEMORY RE ALLOC FAILED");
    return false;
  }
  for (size_t i = 0; i < vec->capacity; i++) {
    new_arr[i] = vec->arr[i];
  }
  char *k = vec->arr;
  vec->arr = new_arr;
  vec->capacity = new_capacity;
  free(k);
  return true;
}

Vector *vector_create(size_t initial_capacity) {
  if (initial_capacity < INIT_VEC_SIZE) {
    initial_capacity = INIT_VEC_SIZE;
  }
  Vector *vec = malloc(sizeof(Vector));
  if (vec == NULL)
    return NULL;
  vec->arr = (char *)malloc(initial_capacity);
  if (vec->arr == NULL) {
    free(vec);
    return NULL;
  }
  vec->size = 0;
  vec->capacity = initial_capacity;
  return vec;
}

void vector_free(Vector *vec) {
  free(vec->arr);
  free(vec);
}

void vector_push(Vector *vec, char val) {
  if (vec->size >= vec->capacity) {
    bool out_check = vec_expand(vec);
    if (!out_check)
      return;
  }
  vec->arr[vec->size] = val;
  vec->size++;
}
void vector_pop(Vector *vec, char *out_val) {
  if (vec->size == 0) {
    printf("\nSTACK UNDERFLOW ERROR\n");
  } else {
    if (out_val != NULL)
      *out_val = vec->arr[vec->size - 1];
    vec->size--;
  }
}
void vector_insert(Vector *vec, char val, size_t index) {
  if (vec->size >= vec->capacity) {
    bool out_check = vec_expand(vec);
    if (!out_check)
      return;
  }
  if (index >= vec->size) {
    vector_push(vec, val);
  } else {
    char temp1 = vec->arr[index], temp2;
    for (size_t i = index; i < vec->size; i++) {
      temp2 = vec->arr[i + 1];
      vec->arr[i + 1] = temp1;
      temp1 = temp2;
    }
    vec->arr[index] = val;
    vec->size++;
  }
}
void vector_delete(Vector *vec, size_t index) {
  if (index >= vec->size - 1) {
    vector_pop(vec, NULL);
  } else {
    for (size_t i = index; i < vec->size - 1; i++) {
      vec->arr[i] = vec->arr[i + 1];
    }
    vec->arr[vec->size - 1] = 0;
    vec->size--;
  }
}
