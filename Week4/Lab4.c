/*
Curtis Kauer
CS260
Lab 4
Deques and Linked Lists
*/
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "deque.h"

/*
 function: initList - the deque is initialized
 param1 - d - deque
 pre: d is not null
 post: head points to NULL
 post: tail points null
 post: size set to 0
*/
void initList(struct Deque *d) {
    printf("Deque initialized\n");
    /* FIX ME */
    assert(d != NULL);
 
    d->head = NULL;
    d->tail = NULL;
    d->size = 0;
}

/*
 function: addFront - add new DLink to the front of the deque
 param1 - d - deque
 param2 - val - value to insert
 pre: d is not null
 post: memory for a new Link has been allocated dynamically
 post: new Link has value - val
 post: new Link has been added to the head of the deque
 post: pointers have been updated
 HINT: A list with one link is a special case
*/
void addFront(struct Deque *d, TYPE val) {
    printf("addFront: %.1f \n", val);
    /* FIX ME */
    assert(d != NULL);
 
    struct Link *newLink = malloc(sizeof(struct Link));
    newLink->value = val;
 
    if(d->tail == NULL){
        d->tail = newLink;
        newLink->next = NULL;
    }
 
    newLink->next = d->head;
    d->head = newLink;
    d->size++;
}

/*
 function: addBack- add new Link to the back of the deque
 param1 - d - deque
 param2 - val - value to insert
 pre: d is not null
 post: memory for a new Link has been allocated dynamically
 post: new Link has value - val
 post: new Link has been added to the tail of the deque
 post: pointers have been updated
 HINT: A list with one link is a special case
*/
void addBack(struct Deque *d, TYPE val) {
    printf("addBack: %.1f \n", val);
    /* FIX ME */
    assert(d != NULL);
    
    struct Link *newLink = malloc(sizeof(struct Link));
    newLink->value = val;
    newLink->next = NULL;
 
    if(d->head == NULL){
        d->head = newLink;
    }
 
    d->tail->next = newLink;
    d->tail = newLink;
    d->size++;
}

/*
 function: print - print from front head to tail
 param1 - d - deque
 pre: d is not null
 post: d has been printed to standard output - output is separated by spaces
 post: no changes to the deque
*/
void print(struct Deque *d) {
    if(d->size == 0) {
        printf("Empty deque\n");
    }
 
    /* FIX ME */
    assert(d != NULL);
 
    struct Link *curr = d->head;
    while(curr != NULL){
        printf("%.1f ", curr->value);
        curr = curr->next;
    }
    
    printf("\n");
}

/*
 function: printReverse - recursive function to print from front tail to head
 param1 - d - deque
 pre: none
 post: d has been printed to standard output - output is separated by spaces
 post: no changes to the deque
*/
void printReverse(struct Link *curr) {
    /* FIX ME */
    if(curr == NULL){
        printf("\n");
        return;
    }
 
    printReverse(curr->next);
    printf("%.1f ", curr->value);
}

/*
 function: getFront - value of the head Link is returned
 param1 - d - deque
 ret: value of the head Link
 pre: d is not null
 pre: d is not empty
 post: no changes to the deque
*/
TYPE getFront(struct Deque *d) {
    /* FIX ME */
    assert(d != NULL);
    assert(d->size != 0);
 
    return d->head->value;
}

/*
 function: getBack - value of the tail Link is returned
 param1 - d - deque
 ret: value of the tail Link
 pre: d is not null
 pre: d is not empty
 post: no changes to the deque
*/
TYPE getBack(struct Deque *d) {
    /* FIX ME */
    assert(d != NULL);
    assert(d->size != 0);
 
    return d->tail->value;
}

/*
 function: removeFront - front Link is removed from the deque
 param1 - d - linked list
 pre: d is not null
 pre: d is not empty
 post: front of the linked list has been removed from the list
 post: memory has been freed for the Link
 post: size is decremented
 HINT: A list with one link is a special case
*/
void removeFront(struct Deque *d) {
    printf("removeFront\n");
 
    /* FIX ME */
    assert(d != NULL);
    assert(d->size != 0);
 
    struct Link *temp = d->head;
    if(d->size == 1){
        d->head = NULL;
        d->tail = NULL;
    }
    else{
        d->head = d->head->next;
    }
 
    free(temp);
    temp = NULL;
    d->size--;
}

/*
 function: removeBack - back Link is removed from the deque
 param1 - d - linked list
 pre: d is not null
 pre: d is not empty
 post: back of the linked list has been removed from the list
 post: memory has been freed for the Link
 post: size is decremented
 HINT: A list with one link is a special case
*/
void removeBack(struct Deque *d) {
    printf("removeBack\n");
    /* FIX ME */
    assert(d != NULL);
    assert(d->size != 0);
 
    struct Link *temp = d->head;
    struct Link *prevLink = temp;
 
    if(d->size == 1){
        d->head = NULL;
        d->tail = NULL;
    }
    else{
 
        while(temp->next != d->tail){
            prevLink = temp;
            temp = temp->next;
        }
 
        prevLink->next = NULL;
        d->tail = prevLink;
    }
 
    free(temp);
    temp = NULL;
    d->size--;
}

/*
 function: freeDeque - free all of the links in the deque
 param1 - d - linked list
 pre: d is not null
 post: all links have been freed
 post: the deque has been freed
*/
void freeDeque(struct Deque *d) {
    /* FIX ME */
    assert(d != NULL);
 
    struct Link *curr = d->head;
    struct Link *prevLink = curr;
 
    while(curr != NULL){
        prevLink = curr->next;
        curr = curr->next;
 
        free(prevLink);
        prevLink = NULL;
    }
 
    free(d);
    d = NULL;
}