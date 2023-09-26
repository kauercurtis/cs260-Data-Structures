/*
Curtis Kauer
CS260
Lab 3
Doubly linked lists and pointer syntax
*/
/***********************
WEEK 3 Lab - SKELETON
**********************/
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#define TYPE double

/*links with forward (next) and back (prev) pointers*/
struct DLink {
    TYPE value;
    struct DLink *next;
    struct DLink *prev;
};

/*doubly linked list contains a sentinel (head) link along with size*/
struct List {
    struct DLink *head;
    int size;
};

/*
 function: initList - memory is allocated for head sentinel and the doubly 
linked list is initialized
 param1 - lst - doubly linked list
 pre: lst is not null
 post: memory has been allocated for head
 post: head->next points to NULL
 post: head->prev points to NULL
 post: size set to 0
*/
void initList(struct List *lst) {
    printf("List initialized\n");
    /* FIX ME */
    assert(lst != NULL);
 
    lst->head = malloc(sizeof(struct DLink));
    lst->head->next = NULL;
    lst->head->prev = NULL;
    lst->size = 0;
}

/*
 function: addFront - add new DLink to the front of the doubly linked list
 param1 - lst - doubly linked list
 param2 - val - value to insert
 pre: lst is not null
 post: memory for a new DLink has been allocated dynamically
 post: new DLink has value - val
 post: new DLink has been added to the front of the doubly linked list - 
pointers have been updated
 post: head->next points to the new link
*/
void addFront(struct List *lst, TYPE val) {
    printf("addFront: %.1f \n", val);
    /* FIX ME */
    assert(lst != NULL);
 
    struct DLink *newDLink = malloc(sizeof(struct DLink));
    newDLink->value = val;
    if(lst->head->next == NULL){
        printf("case 1\n");
        newDLink->next = NULL;
    }
    else{
        printf("case 2\n");
        newDLink->next = lst->head->next;
        lst->head->next->prev = newDLink;
    }
 
    lst->head->next = newDLink;
    newDLink->prev = lst->head;
    lst->size++;
}

/*
 function: addBack- add new DLink to the back of the doubly linked list
 param1 - lst - doubly linked list
 param2 - val - value to insert
 pre: lst is not null
 post: memory for a new DLink has been allocated dynamically
 post: new DLink has value - val
 post: new DLink has been added to the back of the doubly linked list - pointers
have been updated
*/
void addBack(struct List *lst, TYPE val) {
    printf("addBack: %.1f \n", val);
    /* FIX ME */
    assert(lst != NULL);
 
    struct DLink *curr = lst->head->next;
    struct DLink *newDLink = malloc(sizeof(struct DLink));
    newDLink->value = val;
    while(curr->next != NULL){
        curr = curr->next;
    }
 
    curr->next = newDLink;
    newDLink->prev = curr;
    newDLink->next = NULL;
    lst->size++;
}

/*
 function: printForward - print from front DLink to back DLink
 param1 - lst - doubly linked list
 pre: lst is not null
 post: lst has been printed forward to standard output - output is separated by
spaces
 post: no changes to the list
*/
void printForward(struct List *lst) {
    printf("Print list: ");
    /* FIX ME */
    assert(lst != NULL);
 
    struct DLink *curr = lst->head->next;
    while(curr != NULL){
        printf("%.1f ", curr->value);
        curr = curr->next;
    }
 
    printf("\n");
}

/*
 function: printBackward - print from back DLink to front DLink
 param1 - lst - doubly linked list
 pre: lst is not null
 post: lst has been printed backwards to standard output - output is separated 
by spaces
 post: no changes to the list
*/
void printBackward(struct List *lst) {
    printf("Print list backwards: ");
    /* FIX ME */
    assert(lst != NULL);
 
    struct DLink *curr = lst->head;
    while(curr->next != NULL){
        curr = curr->next;
    }
 
    while(curr != lst->head){
        printf("%.1f ", curr->value);
        curr = curr->prev;
    }
 
    printf("\n");
}

/*
 function: removeFront - front DLink is removed from the doubly linked list
 param1 - lst - doubly linked list
 pre: lst is not null
 pre: lst is not empty
 post: a DLink has been removed from front of the doubly linked list - pointers 
have been updated
 post: the DLink has been freed
*/
void removeFront(struct List *lst) {
    printf("removeFront\n");
    /* FIX ME */
    assert(lst != NULL);
    assert(lst->size != 0);
 
    struct DLink *temp = lst->head->next;
    lst->head->next = temp->next;
    lst->head->next->prev = lst->head;
    
    free(temp);
    temp = NULL;
    lst->size--;
}

/*
 function: removeBack - back DLink is removed from the doubly linked list
 param1 - lst - doubly linked doubly linked list
 pre: lst is not null
 pre: lst is not empty
 post: a DLink has been removed from back of the doubly linked list - pointers 
have been updated
 post: the DLink has been freed
*/
void removeBack(struct List *lst) {
    printf("removeBack\n");
    /* FIX ME */
    assert(lst != NULL);
    assert(lst->size != 0);
 
    struct DLink *curr = lst->head;
    while(curr->next != NULL){
        curr = curr->next;
    }
 
    curr->prev->next = NULL;
    free(curr);
    curr = NULL;
    lst->size--;
}

int main() {
    struct List *lst = malloc(sizeof(struct List));
    initList(lst);
    printf("------------testing addFront()------------\n");
    addFront(lst, 2);
    printForward(lst);
    printBackward(lst);
    
    addFront(lst, 8);
    printForward(lst);
    printBackward(lst);

    printf("------------testing addBack()------------\n");
    addBack(lst, 1);
    printForward(lst);
    printBackward(lst);

    addBack(lst, 7);
    printForward(lst);
    printBackward(lst);

    printf("------------testing removeFront()------------\n");
    removeFront(lst);
    printForward(lst);
    printBackward(lst);
 
    printf("------------testing removeBack()------------\n");
    removeBack(lst);
    printForward(lst);
    printBackward(lst);
    return 0;
}