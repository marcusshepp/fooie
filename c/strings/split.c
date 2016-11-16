#include <stdio.h>
#include <string.h>

int main(){
    char str[] = "foo bar pop";
    char *pch; 
    pch = strtok(str, " ");
    while(pch != NULL){
        printf("%s\n", pch);
        pch = strtok(NULL, " ");
    }
    return 0;
}
