#include "vector.h"
#define INIT_VEC_SIZE 64
#include <stdio.h>



// typedef struct {
//     char* arr;
//     size_t size;
//     size_t capacity;
// } Vector;

static void vec_expand(Vector* vec){
  if(vec == NULL) return;
  size_t new_capacity = vec->capacity << 1;
  char* new_arr = (char*) malloc(new_capacity); 
  if(new_arr == NULL) return;
  for(int i = 0;i < vec->capacity;i++){
    new_arr[i] = vec->arr[i];
  }
  char* k = vec->arr;
  vec->arr = new_arr;
  vec->capacity = new_capacity;
  free(k);
  return;
}


Vector* vector_create(size_t initial_capacity){
  Vector* vec = malloc(sizeof(Vector));
  if(vec == NULL) return NULL;
  vec->arr = (char*) malloc(initial_capacity);
  if(vec->arr == NULL) {
    free(vec);
    return NULL;
  }
  vec->size = 0;
  vec->capacity = initial_capacity;
  return  vec;
}


void vector_free(Vector* vec){
  free(vec->arr);
  free(vec);
}

void vector_push(Vector* vec, char val){
  if((vec->size + 1) >= vec->capacity){
    vec_expand(vec); 
  }
  vec->arr[vec->size] = val;
  vec->size++;
}
void vector_pop(Vector* vec, char* out_val){
  if(vec->size == 0){
    printf("\nSTACK UNDERFLOW ERROR\n");
  }else{
    if(out_val != NULL) *out_val = vec->arr[vec->size-1];
    vec->size--;
  }
}
void vector_insert(Vector* vec, char val, size_t index){
  if(index >= vec->size){
    vector_push(vec,val);
  }else{
    char temp1 = vec->arr[index],temp2;
    for(int i = index;i < vec->size;i++){
      temp2 = vec->arr[i+1];
      vec->arr[i+1] = temp1;
      temp1 = temp2;
    }
    vec->arr[index] = val;
  }
}
void vector_delete(Vector* vec, size_t index){
  if(index >= vec->size){
    vector_pop(vec,NULL);
  }
  else{
    char temp1 = vec->arr[index+1];
    for(int i = index;i < vec->size - 1;i++){
       vec->arr[i] = vec->arr[i+1];
    }
    vec->arr[vec->size-1] = 0;
    vec->size--;
  }
}


