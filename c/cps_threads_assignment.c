/*
Multithreaded simple stats on a given list of integers.

usage:
gcc -pthread -o <this_script> <this_script>.c
./<this_script>
*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>


void *Average(void* arg){
	int *nums = (int*)arg;
	for(int i = 0; i < 4; i++){
		printf("%i\n", nums[i]);
	}
	pthread_exit(NULL);
}


void *Minimum(void *arg){
    printf("minimum\n");
	pthread_exit(NULL);
}


void *Maximum(void *arg){
    printf("maximum\n");
	pthread_exit(NULL);
}


int main(void){

	// Read in space seperated integers.
//	char *line = NULL;
//	size_t len = 0;
//	ssize_t read = 0;
//	while (read != -1){
//		puts("Please, enter a list of integers seperated by spaces.\n");
//		read = getline(&line, &len, stdin);
//		printf("line = %s\n", line);
//		printf("line length = %zu\n", read);
//		puts("");
//	}
//	free(line);

	int numbers[5] = {1, 2, 3, 4, 5};

	// Split operations into three seperate threads respectively.
	// average
    pthread_t average_thread;
    pthread_create(&average_thread, NULL, Average, numbers);
    pthread_join(average_thread, NULL);

	// minimum
	pthread_t minimum_thread;
	pthread_create(&minimum_thread, NULL, Minimum, NULL);
	pthread_join(minimum_thread, NULL);

	// maximum
	pthread_t maximum_thread;
	pthread_create(&maximum_thread, NULL, Maximum, NULL);
	pthread_join(maximum_thread, NULL);

	pthread_exit(NULL);
}
