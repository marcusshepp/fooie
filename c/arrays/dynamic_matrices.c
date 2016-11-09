#include <stdio.h>
#include <stdlib.h>

int main(){
    int rows = 3, columns = 4;
    int *arr = (int *)malloc(rows * columns * sizeof(int));

    int i, j, count = 0;
    for(i = 0; i < rows; i++)
        for(j = 0; j < columns; j++)
            *(arr + i * columns + j) = ++count;
    for(i = 0; i < rows; i++)
        for(j = 0; j < columns; j++)
            printf("%d ", *(arr + i * columns + j));
    free(arr);

    return 0;
}
