/*
CS260 - Lab 1
Name: Curtis Kauer
Date: 9/22/2022
Solution description:
Lab 1 - Pointers, structs, and allocating memory
*/
#include <stdio.h>
#include <stdlib.h>

/*
struct Kitty
age - int - 0 to 20 years
*/
struct Kitty{
    int age;
};

void baz(int* ptr);

int main() {
 /*declare an integer num*/
    int num = 5;
 /*print the address of num*/
    printf("Memory address of num: %p\n", &num);
 /*print the value of num*/
    printf("Value of num: %d\n", num);
 /*Call baz() with the address of num*/
    printf("baz(&num);\n");
    baz(&num);
 /*print the value of num*/
    printf("Value of num: %d\n", num);
 /*create a pointer to a Kitty*/
    struct Kitty *kitties;
 /*
 use malloc to allocate memory for 3 Kitty structs
 store the memory as the pointer created above
 */
    kitties = malloc(sizeof(struct Kitty) * 3);
 /*assign random ages to each Kitty in kitties*/
    unsigned int i = 0;
 
    while(i < 3){
        kitties[i].age = rand() % 21;
        i++;
    }
    
    i = 0;
 
    int oldest = kitties[0].age;
 
    while(i < 3){
        printf("kitty %d: %d\n", i + 1, kitties[i].age);
 
        if(kitties[i].age > oldest){
            oldest = kitties[i].age;
        }
        i++;
    }
 
    printf("Oldest Kitty Age: %d\n", oldest);
 /*print the age of each Kitty in kitties*/
 /*find the age of the oldest Kitty in kitties*/
 /*print the age of the oldest Kitty in kitties*/
 /*free kitties*/
    free(kitties);
    kitties = 0;
    
    return 0;
}

/*
function - baz - the function doubles the value of the parameter
arg1 - int pointer - prt should be initialized
postcondition - ptr argument has been doubled
*/
void baz(int* ptr) {
/*double the value of ptr*/
    *ptr *= 2;
}