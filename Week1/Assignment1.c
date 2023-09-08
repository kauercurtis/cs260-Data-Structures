/*
CS260 - Assignment 1
Name: Curtis Kauer
Date: 9/22/2022
Solution description:
Practice with structs, c syntax, and allocating memory with pointers
*/
#include <stdio.h>
#include <stdlib.h>
/*
struct Dog
age - int - 0 to 16 years
sex - char - (M)ale or (F)email
*/
struct Dog{
    int age;
    char sex;
};

struct Dog* allocate();
void generate(struct Dog* dogs);
void output(struct Dog* dogs);
void stats(struct Dog* dogs);
void deallocate(struct Dog* dogs);
void foo(int* ptr);
int bar(int*, int*, int);

int main() {
    /*#1*/
    printf("#1 \n");
    /*declare an integer x*/
    int x = 5;
    /*print the address of x*/
 /*HINT - You might get warnings about format specifiers not agreeing with 
address formats when printing - Don't worry about it*/
    printf("Address of x: %p\n", &x);
    /*Write foo - see below main*/
    /*Call foo() with the address of x*/
    printf("foo(x);\n");
    foo(&x);
    /*print the value of x*/
    printf("Value of x: %d\n", x);
    /*#2*/
    printf("#2 \n");
    /*Declare three integers a, b and c and initialize them to 11, 12, & 13 
    respectively*/
    int a = 11, b = 12, c = 13;
    /*Print the values of x, y and z*/
    printf("Value of a: %d\n", a);
    printf("Value of b: %d\n", b);
    printf("Value of c: %d\n", c);
    /*Write the bar() function*/
/*The next two steps are one line of code
Call bar() appropriately, passing x,y,z as parameters
Print the value returned by bar from this function call
*/
    printf("bar(&a, &b, c): %d\n", bar(&a, &b, c));
 /*Print the values of x, y and z again*/
    printf("Value of a: %d\n", a);
    printf("Value of b: %d\n", b);
    printf("Value of c: %d\n", c);
/*Is the return value different than the value of c? Why?
Express your short answer as a comment below
The return value is different than the value of c because c was passed by 
value while a and b were passed by reference.
*/
 /*#3*/
    printf("#3 \n");
 /*create a pointer to Dog struct called dogs*/
    struct Dog *dogs;
    dogs = 0;
 /*Write the allocate function*/
 /*
 call the allocate() function
set dogs to the pointer returned by the allocate function
*/
    printf("dogs = allocate();\n");
    dogs = allocate();
/*Write the generate function*/
 /*call generate*/
    printf("generate(dogs);\n");
    generate(dogs);
 /*Write the output function*/
 /*call output*/
    printf("output(dogs);\n");
    output(dogs);
 /*Write the stats function*/
 /*call stats*/
    printf("stats(dogs);\n");
    stats(dogs);
 /*Write the deallocate function*/
 /*call deallocate*/
    printf("deallocate(dogs);\n");
    deallocate(dogs);
    
    return 0;
}

/*
function: foo - the function prints various things about the argument and parameter
arg1: int pointer
return: none
precondition: ptr is not null
postcondition: output has been written to the console
*/
void foo(int* ptr) {
 /*Print the value pointed to by ptr*/
    printf("Value of ptr: %d\n", *ptr);
 /*Print the address pointed to by ptr*/
    printf("Address pointed to by ptr: %p\n", &*ptr);
 /*Print the address of ptr itself*/
    printf("Address of ptr: %p\n", &ptr);
}

/*
function: bar - nonsense. alters the value of arguments and returns a meaningless 
value
arg1: a - int pointer
arg2: b - int pointer
arg3: c - any integer
return: int - nonsense based on modified values of params a and b
preconditions: a and b are not null
postconditions: the value of a is doubled, the value of b is halved
*/
int bar(int* a, int* b, int c){
 /*Set a to double its original value*/
    *a *= 2;
 /*Set b to half its original value*/
    *b /= 2;
 /*Assign a+b to c*/
    c = *a + *b;
 /*Return c*/
    return c;/*don't return 0 - I did this to make it compile*/
}

/*
allocate: uses malloc to allocate memory for 10 dog structs
args: none
return: Dog ptr
precondition: none
postcondition - memory has been allocated for 10 dogs
*/
struct Dog* allocate() {
 /*Allocate memory for ten dogs - use malloc*/
    struct Dog *_dogs = malloc(sizeof(struct Dog) * 10);
    return _dogs;
}

/*
function: generate - ages and sexes are randomly assigned to 10 dogs
arg1: dogs - Pointer to Dog struct - memory has been allocated for 10 dogs
return: nothing
precondition: dogs is not null
postcondition - 10 dogs have been initialized
*/
void generate(struct Dog* dogs) {
 
 /*
 Generate random age and sex for 10 Dogs and store in dogs
 Age is between 0 and 16
 sex is either M or F
 HINT - generate a random between 0 and 1 and convert to char
 HINT - chars use ' vs "
 Calculate random numbers between using rand().
 Simply assigning ages 9, 10, 11.. is not sufficient
 0 = M, 1 = F
 */
    unsigned counter = 0;
    unsigned sex = 0;
    
    while(counter < 10){
        dogs[counter].age = rand() % 16 + 1;
        sex = rand() % 2;
    
        if(sex == 1)
            dogs[counter].sex = 'F';
        else
            dogs[counter].sex = 'M';
    
        counter++;
    }
}

/*
function: output - used to display the values assigned to the age and sex members 
of dog structs
arg1: dogs - Pointer to Dog struct - memory has been allocated for 10 dogs and dogs
have been assigned
return: nothing
precondition: dogs is not null
precondition: memory has been allocated for 10 dogs
postcondition - age and sex of 10 dogs are displayed to the console
*/
void output(struct Dog* dogs) {
 /*
 Output information about the ten dogs in the format:
 Dog 1: Age: varAge Sex: varSex
 ...
 Dog 10: Age: varAge Sex: varSex
 */
    unsigned counter = 0;
    
    while(counter < 10){
        printf("Dog %d: Age: %d Sex: %c\n", counter + 1, dogs[counter].age, 
        dogs[counter].sex);
        counter++;
    }
}

/*
function: stats - used to display the max, min and average age members of dog 
structs
arg1: dogs - Pointer to Dog struct
return: nothing
precondition: dogs is not null
precondition: memory has been allocated for 10 dogs and dogs have been assigned
postcondition: min, max and average of 10 dogs are displayed to the console
*/
void stats(struct Dog* dogs) {
 /*Compute and print the minimum, maximum and average age of the ten dogs*/
    int min = dogs[0].age;
    int max = dogs[0].age;
    int avg = 0;
    unsigned counter = 0;
    
    while(counter < 10){
        if(dogs[counter].age < min)
            min = dogs[counter].age;
        if(dogs[counter].age > max)
            max = dogs[counter].age;
            avg += dogs[counter].age;
        counter++;
 }
    
    avg /= counter;
    printf("Maximum dog age: %d years\n", max);
    printf("Minimum dog age: %d years\n", min);
    printf("Average dog age: %d years\n", avg);
}

/*
function: deallocate - free the memory allocated to dogs
arg1: dogs - Pointer to Dog struct
return: nothing
precondition: dogs is not null
precondition: memory has been allocated for 10 dogs
postcondition: memory has been freed for dogs
*/
void deallocate(struct Dog* dogs) {
 /*Deallocate memory from dogs by calling free()*/
    free(dogs);
    dogs = 0;
}