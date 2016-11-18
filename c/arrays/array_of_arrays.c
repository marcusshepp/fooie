#include <stdlib.h>
#include <stdio.h>

int main(int argv, char* argc[]){

    // initialize outer array
    int* outer = malloc(5 * sizeof(int));
    
    int i, j;

    // for each slot in outer array
    // create a new array and assign it
    // to that slot.
    // may seem like this is not needed
    // but without allocating memory for each inner array
    // the program will experience 
    // "unexpected behavior"
    // Meaning it might be correct 
    // or it might crash.
    // Without the allocation of memory to
    // the inner arrays I will be accessing memory that
    // wasn't allocated causing the "unexpected behavior".
    for(i = 0; i < 5; i++){
        int* inner = malloc(5 * sizeof(int));
        *(outer + i) = *inner;
    }

    // assign to each slot in each inner array
    for(i = 0; i < 5; i++)
        for(j = 0; j < 5; j++)
            *(outer + i * 5 + j) = j;

    // print each element in each inner array
    for(i = 0; i < 5; i++){
        for(j = 0; j < 5; j++){
            printf(
                "%d ", 
                *(outer + i * 5 + j)
            );
        }
        puts("");
    }
    free(outer);
}
