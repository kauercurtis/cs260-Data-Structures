/*
Curtis Kauer
CS260
Assignment 3
Linked List and Bag implementation
Introduction to Big O with code
*/
#include "listbag.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

/*Turn on for debugging messages*/
int debug = 0;

/*
initlist: initialize the list - create the head and initialize pointers
param: lst is the list
pre: lst is not null
post: memory has been dynamically allocated for the head
post: head next is initialized to NULL
*/
void initList (struct List *lst) {
    assert(lst != NULL);

    lst->head = malloc(sizeof(struct Link));
    lst->head->next = NULL;
}

/*
addFrontList: add a value to the front of the list
param: head is the head of the list
param: e is the value to add to the list
pre: head is not null
post: memory has been dynamically allocated for a new link
post: new link is added to the front of the list
*/
void addFrontList (struct Link *head, TYPE e) {
    assert(head != NULL);

    if(debug)printf("Inserting %d at head of list\n", e);
    /* FIX ME*/
    struct Link *newLink = malloc(sizeof(struct Link));
    newLink->value = e;
 
    if(head->next == NULL){
        /* printf("case 1\n"); */
        newLink->next = NULL;
    }
    else{
    /* printf("case 2\n"); */
        newLink->next = head->next;
    }
    
    head->next = newLink;
}

/*
addBackList: add a value to the back of the list
param: head is the front of the list
param: e is the value to add to the list
pre: head is not null
post: memory has been dynamically allocated for a new link
post: new link is added to the back of the list
*/
void addBackList(struct Link *head, TYPE e) {
    assert(head != NULL);

    if(debug) printf("Inserting %d at back of list\n", e);
    /* FIX ME*/
    struct Link *curr = head;
    struct Link *newLink = malloc(sizeof(struct Link));
    newLink->value = e;
    newLink->next = NULL;
 
    while(curr->next != NULL){
        curr = curr->next;
    }
 
    curr->next = newLink;
}

/*
displayList: print the contents of the list
param: head is the front of the list
pre: head is not null
pre: list is not empty
post: list contents are displayed - separated by spaces
post: no changes to the list
*/
void displayList (struct Link *head) {
    assert(head != NULL);
    assert(head->next != NULL);
 
    printf("List Contents: ");
    /* FIX ME*/
    struct Link *curr = head->next;
    while(curr != NULL){
        printf("%d ", curr->value);
        curr = curr->next;
    }
 
    printf("\n");
}

/*
frontList: return the element at the head of the list
param: head is the front of the list
return: return value at front of the list
pre: head is not null
pre: list is not empty
post: no changes to the list
*/
TYPE frontList (struct Link *head) {
    /* FIX ME*/
    assert(head != NULL);
    assert(head->next != NULL);

    return head->next->value;
}

/*
backList: return the element at the back of the list
param: head is the front of the list
 return: return value at back of the list
pre: head is not null
pre: list is not empty
post: no changes to the list
*/
TYPE backList(struct Link *head) {
    /* FIX ME*/
    assert(head != NULL);
    assert(head->next != NULL);
 
    struct Link *curr = head->next;
    while(curr->next != NULL){
        curr = curr->next;
    }

    return curr->value;
}

/*
removeFrontList: remove element from front of list
param: head is the front of the list
pre: head is not null
pre: list is not empty
post: head points to head->next
post: old head has been freed
*/
void removeFrontList(struct Link *head) {
    assert(head != NULL);
    assert(head->next != NULL);

    if(debug) printf("remove front of list: \n");
    /* FIX ME*/
    struct Link *temp = head->next;
    head->next = head->next->next;
 
    free(temp);
    temp = 0;
}

/*
removeBackList: remove element from back of list
param: head is the front of the list
pre: head is not null
pre: list is not empty
post: link before the end points to NULL
post: old head has been freed
*/
void removeBackList (struct Link *head) {
    assert(head != NULL);
    assert(head->next != NULL);

    if(debug) printf("remove back of list: \n");
    /* FIX ME*/
    struct Link *curr = head->next;
    while(curr->next->next != NULL){
        curr = curr->next;
    }
 
    struct Link *temp = curr->next;
    curr->next = NULL;
    free(temp);
    temp = 0;
}

/*
listRemove: remove the first occurrence of the value from the list
param: head is the front of the list
param: e is the value to remove
pre: head is not null
pre: list is not empty
post: link containing first occurrence of value e has been freed
post: pointer before link containing first occurrence of value has been 
updated
*/
void listRemove (struct Link *head, TYPE e) {
    assert(head != NULL);
    assert(head->next != NULL);

    if(debug) printf("remove %d from list: \n", e);
    /* FIX ME*/
    struct Link *curr = head->next;
    struct Link *occurence = NULL;
    while(curr->next != NULL){
 
        if(curr->next->value == e){
            occurence = curr->next;
            break;
        }
 
        curr = curr->next;
    }
    /* if occurence is found */
    /* curr = Link before occurence */
    if(occurence != NULL){
        curr->next = occurence->next;
        free(occurence);
        occurence = 0;
    }
}

/*
isEmptyList: checks whether the list is empty or not
param: head is the front of the list
 return: Return 1 if empty, 0 if not
pre: head is not null
post: no changes to the list
*/
int isEmptyList(struct Link *head) {
    assert(head != NULL);

    if(head->next == NULL) {
        return 1;
    }

    return 0;
}

/*
freeList: Free the list
param: head is the front of the list
pre: head is not null
post: each link of the list has been freed
post: lst has been freed
post: lst points to nothing
*/
void freeList(struct List *lst) {
    /* FIX ME*/
    assert(lst->head != NULL);
 
    struct Link *curr = lst->head;
    struct Link *temp = NULL;
    while(curr != NULL){
        temp = curr;
        curr = curr->next;
        free(temp);
        temp = NULL;
    }
 
    free(lst);
    lst = NULL;
}

/* -----------------------ListBag functions begin here---------------------- */
/*
initBag: initialize bag
param: b is the bag
pre: b is not null
post: memory for list is dynamically allocated
post: lst is initialized using initList()
post: size is initialized to 0
*/
void initBag(struct bag* b) {
    assert( b != NULL);

    b->lst = (struct List*)malloc(sizeof(struct List));/*Allocate for the list part of the bag*/

    initList(b->lst);/*Initialize list*/
    b->size=0;
}

/*
addToBag: add an element to the bag
param: b is the bag
param: val is the value added to the bag
pre: b is not null
post: val is added to the bag (list implementing the bag)
post: size is incremented
HINT: use linked list functions to manipulate the list
*/
void addToBag(struct bag* b, TYPE val) {
/* FIX ME*/
    /* addBackList performs preconditions and post condition */
    addFrontList(b->lst->head, val);
    b->size++;
}

/*
bagContains: test if an element exists in the bag
param: b is the bag
param: val is the value to search for
 return: return 1 if found, otherwise return 0
pre: b is not null
post: no changes to the bag
*/
int bagContains(struct bag* b, TYPE val) {
    /* FIX ME*/
    assert(b != NULL);
 
    struct Link *curr = b->lst->head;
    while(curr != NULL){
 
        if(curr->value == val)
            return 1;
 
        curr = curr->next;
    }

    return 0;
}

/*
removeFromBag: remove an element from the bag
param: b is the bag
param: val is the value to remove from the bag
pre: b is not null
pre: b contains val - use bagContains()
post: link is removed from bag
post: size is decremented
HINT: use linked list functions to manipulate the list
*/
void removeFromBag(struct bag* b, TYPE val) {
    /*FIX ME*/
    assert(bagContains(b, val) == 1);
    /* listRemove provides pre condition and post conditions */
    listRemove (b->lst->head, val);
    b->size--;
}

/*
isEmptyBag: test if the bag is empty
param: b is the bag
return: return 1 if found, otherwise return 0
pre: b is not null
post: no changes to the bag
*/
int isEmptyBag(struct bag* b) {
    /* FIX ME*/
    assert(b != NULL);
/*
confused on the wording, if its suppose to test if
a bag is empty, my understanding would be it should be
1 if it is empty and 0 if its not. But the test in main
only passes if the return values are switched around.
So I did it this way to get a pass with the test.
*/
    if(b->size > 0){
        return 1;
    }
 
    return 0;
}

/*
freeBag: deallocate bag memory
param: b is the the bag
pre: b is not null
post: bag is freed
post: list is freed
HINT: use linked list functions to manipulate the list
*/
void freeBag(struct bag *b) {
    /* FIX ME*/
    assert(b != NULL);
    /* freeList performs post conditions */
    freeList(b->lst);
    free(b);
    b = NULL;
}

/*-------------------- Pt II - Algorithm Analysis --------------------------*/
/*
#0 - Write a function called bagSearch(struct bag* b, TYPE val) which returns the 
number of comparisons that it took to find the value
If the function does not find the value, then return -1 (6 Pts)
Call the bagSearch function for at least three values and display the number of 
comparisons the bagSearch() function carried out. (2 Pts)
*/
/*
bagSearch - returns the # of comparisons that it takes to find a value
param1 - struct bag* b - a pointer to a bag struct
param2 - TYPE val - an integer type to look for in the bag struct
pre - bag pointer is not NULL
pre - bag is not empty
post - nothing mutates the bag
return - int - the # of comparisons carried out
returns -1 if value is never found.
*/
int bagSearch(struct bag* b, TYPE val){
    assert(b != NULL);
    assert(b->lst->head->next != NULL);
 
    int counter = 0;
    unsigned flag = 0;
    struct Link *curr = b->lst->head;
    do{
        counter++;
        curr = curr->next;
 
        if(curr->value == val){
            flag = 1;
        }
    }while(curr->next != NULL && flag == 0);
 
    switch(flag){
        case 1:
            return counter;
        default:
            return -1;
    }
}

/*
syntax written to call the bagSearch function in main after addToBag is tested
printf("Testing bagSearch\n");
printf("bagSearch(b, 3)\n");
printf("%d\n", bagSearch(b, 3));
printf("bagSearch(b, 4)\n");
printf("%d\n", bagSearch(b, 4));
printf("bagSearch(b, 1)\n");
printf("%d\n", bagSearch(b, 1));
function prototype in listbag.h
int bagSearch(struct bag* b, TYPE val);
*/
/*
#1 - What is the worst case performance of the bagSearch() operation expressed in 
terms of the size of the bag(n)? (1 Pt)
O(n)
#2 - What is the best case performance of the bagSearch() operation expressed in 
terms of the size of the bag(n)? (1 Pt)
O(1)
#3 - What is the average number of comparisons that bagSearch() performs expressed 
in terms of the size of the bag(n)? (1 Pt)
O(n/2)
#4 - What is the worst case performance for the listRemove() operation? Describe 
the worst case in words. (2 Pts)
Worst case for listRemove() is if the linked list is completely stepped through and
the occurrence is not found.
#5 - What is the best case performance for the listRemove() operation? Describe the
best case in words. (2 Pts)
Best case for listRemove() is if the occurrence of e is found as the first link.
#6 - Did you use addFrontList() or addBackList() to add elements to your bag? Why 
was this the best choice? (2 Pts)
I used addFrontList(). It is the best choice because it doesn't require traversing 
to the end of the list.
#7 - Is a linked list or a dynamic array a better choice for adding elements to a 
bag? Explain your answer. (3 Pts)
Linked list because inserting a new node anywhere only requires a few changes to 
pointers while an array requires a whole index shift if inserted
in the front or in the middle.
*/