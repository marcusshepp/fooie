/* Arrays in C are pointers to the first elements space in memory.
 * So Arrays and pointers are very similiar.
 * Creating a pointer to the first element of a
 * sequence of allocated memory spaces is essentially the
 * same as creating an array with a fixed size.
 *
 * */
#include <stdlib.h>
#include <stdio.h>


int main(){
    // create a pointer to the first element
    // of 10 allocated spaces of memory
    int *arr = malloc(sizeof(int)*10);
    arr[0] = 1;
    arr[3] = 4;
    // assigning to the next spot in memory.
    // greater than the original amount of allocated memory spots.
    arr[11] = 99;
    for(int i = 0; i < 12; i++){
        printf("%d\n", arr[i]);
    }
    puts("\n");
    // release the memory slots when finished
    free(arr);
    return 0;
}
