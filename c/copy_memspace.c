/* Copy a memory space
 * */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	int *foo = malloc(3 * sizeof(int));
	int i;

	for(i = 0; i < 3; i++)
		foo[i] = i;

	for(i = 0; i < 3; i++)
		printf("foo[%d]: %d\n", i, foo[i]);	

	int *bar = malloc(3 * sizeof(int));
	memcpy(bar, foo, 3 * sizeof(int));

	for(i = 0; i < 3; i++)
		printf("bar[%d]: %d\n", i, bar[i]);	

	return 0;
}
