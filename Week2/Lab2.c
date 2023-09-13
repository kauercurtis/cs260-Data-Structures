/*
dynArr.c: Dynamic Array implementation & a stack built on top of it
*/
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include "dynArr.h"

/*
 DynArr - Dynamic array struct
 data - pointer to the data array of type int
 size - number of elements currently stored in the array
 capacity - capacity of the array
*/
struct DynArr {
    int *data;
    int size;
    int capacity;
};

/* ------------------Dynamic Array Functions--------------------- */
/* 
createDynArr: create dynamic array and call init to initialize members
param: cap is the desired capacity for the dynamic array
ret: the pointer to the newly created dynArr of cap capacity is returned
pre: cap is greater than 0
post: memory has been allocated for the dynamic array
initDynArr() is used to initialize the DynArr members
*/
DynArr* createDynArr(int cap) {
    printf("Called createDynArr()\n");
/*FIX ME: You will write this function*/
    assert(cap > 0);
    
    DynArr *d = malloc(sizeof(DynArr));
    initDynArr(d, cap);
    
    return d;
}

/* 
initDynArr: initialize dynamic array members and allocate member to the data 
array
param: d is the pointer to the dynamic array
param: cap is the capacity of the dynamic array
pre: d is not null
pre: capacity is greater than 0
post: memory has been allocated for data array based on cap
post: size is 0 for the dynamic array
post: cap is set for the dynamic array
*/
void initDynArr(DynArr *d, int cap) {
    printf("Called initDynArr()\n");
/*FIX ME: You will write this function*/
    assert(cap > 0);
    assert(d != NULL);
 
    d->data = malloc(sizeof(int) * cap);
    d->size = 0;
    d->capacity = cap;
}

/* 
addDynArr: adds an element to the end of the dynamic array
param: d is the pointer to the dynamic array
param: val is the value to add to the end of the dynamic array
pre: the dynArry is not null
post: size increases by 1
post: if reached capacity, capacity is doubled
post: val is in the last utilized position in the array
*/
void addDynArr(DynArr *d, int val) {
    printf("Called addDynArr(%d)\n", val);
/*FIX ME: You will write this function*/
    assert(d != NULL);
 
    if(d->size == d->capacity){
        d->capacity *= 2;
        d->data = realloc(d->data, sizeof(int) * d->capacity);
    }
 
    d->data[d->size] = val;
    d->size++;
}

/* 
getDynArr: get an element from the dynamic array from a specified position
param: d is the pointer to the dynamic array
param: pos is the index position to get the element from
ret: value stored at index pos is returned
pre: d is not null
pre: d is not empty
pre: pos >= 0
pre: pos < size
post: no changes to the dyn Array
*/
int getDynArr(DynArr *d, int pos) {
    printf("Called getDynArr(%d)\n", pos);
/*FIX ME: You will write this function*/
    assert(d != NULL);
    assert(d->size != 0);
    assert(pos >= 0);
    assert(pos < d->size);

    return d->data[pos];
}

/* 
putDynArr: put an item into the dynamic array at the specified location, 
overwriting the element that was there
param: d is the pointer to the dynamic array
param: pos is the index position where val will be inserted
param: val the value to insert
pre: d is not null
pre: pos >= 0
pre: pos < size of the array
post: index pos contains new value, val
*/
void putDynArr(DynArr *d, int pos, int val) {
    printf("Called putDynArr(%d, %d)\n", pos, val);
/*FIX ME: You will write this function*/
    assert(d != NULL);
    assert(pos >= 0);
    assert(pos < d->size);
 
    d->data[pos] = val;
}

/* 
removeAtDynArr: remove the element at the specified location from the array, 
shifts other elements back one to fill the gap
param: d is the pointer to the dynamic array
param: pos is the location of element to remove
pre: d is not null
pre: pos >= 0
pre: pos < size
post: the element at pos is removed
post: the elements past pos are shifted back
post: size is decremented
*/
void removeAtDynArr(DynArr *d, int pos) {
    printf("Called removeAtDynArr(%d)\n", pos);
/*FIX ME: You will write this function*/
    assert(d != NULL);
    assert(pos >= 0);
    assert(pos < d->size);

    /* Use pos as counter variable */
    while(pos < d->size - 1){
        d->data[pos] = d->data[pos + 1];
        pos++;
    }
 
    d->size--;
}

/* 
dispArr: display the elements in the dynamic array
param: d is the pointer to the dynamic array
pre: d is not null
post: d->data has been printed - separated by spaces - there is a line break
at the end
post: no changes to the dynamic array
*/
void dispArr(DynArr *d) {
    printf("Array contents: ");
/*FIX ME: You will write this function*/
    assert(d != NULL);
    
    unsigned counter = 0;
    
    for(; counter < d->size; counter++)
        printf("%d ", d->data[counter]);
        
    printf("\n");
}

/* 
freeDynArr: free the data array in dynamic array
param: d is the pointer to the dynamic array
pre: d is not null
post: d->data has been freed
 post: d->data points to null
*/
void freeDynArr(DynArr *d) {
    printf("Called freeDynArr()\n");
/*FIX ME: You will write this function*/
    assert(d != NULL);
 
    free(d->data);
    d->data = NULL;
}

/* 
deleteDynArr: free memory for the dynamic array
param: d is the pointer to the dynamic array
pre: d is not null
post: the memory used by d is freed
 post: the memory used by d->data is freed - use freeDynArr
*/
void deleteDynArr(DynArr *d) {
    printf("Called deleteDynArr()\n");
/*FIX ME: You will write this function*/
    assert(d != NULL);
 
    freeDynArr(d);
    free(d);
    d = NULL;
}

/* 
sizeDynArr: get the size of the dynamic array
param: d is the pointer to the dynamic array
ret: the size of the dynamic array
pre: d is not null
post: none
*/
int sizeDynArr(DynArr *d) {
    printf("Called sizeDynArr()\n");
 /*FIX ME: You will write this function*/
    assert(d != NULL);
    return d->size;
}

/* ------------------Stack Interface Functions------------------ */
/* 
push: adds an element to the top of the stack
param: s pointer to the stack
param: val the value to add to the stack
pre: d is not null
post: size is incremented by 1
post: stack contains one more element
HINT - Call a function that you already wrote in DynArr
*/
void push(DynArr *s, int val) {
    printf("Called push(%d)\n", val);
/*FIX ME: You will write this function*/
    addDynArr(s, val);
}

/* 
peek: returns the value of the top element in the stack
param: s pointer to the stack
ret: the value of the top of the stack is returned
pre: d is not null
pre: d is not empty
post: no changes have been made to the stack
HINT - Call a function that you already wrote in DynArr
*/
int peek(DynArr *s) {
    printf("Called peek()\n");
/*FIX ME: You will write this function*/
    return getDynArr(s, s->size - 1);
}

/* 
pop: remove the top element of the stack
param: s pointer to the stack
pre: d is not null
pre: d is not empty
post: the top of the stack is removed
post: size is decremented
HINT - Call a function that you already wrote in DynArr
*/
void pop(DynArr *s) {
    printf("Called pop()\n");
/*FIX ME: You will write this function*/
    removeAtDynArr(s, s->size - 1);
}