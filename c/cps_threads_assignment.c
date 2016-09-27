/*
Multithreaded simple stats on a given list of integers.

usage:
gcc -pthread -o <this_script> <this_script>.c
./<this_script>
*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>


struct thread_args {
    int nums[];
    int length;
};


void *Average(void* arg){
    struct thread_args my_struct;
    
	int *nums = (int*)arg;
	int sum = 0;
    
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

	// Read in numbers to be operated on.
    int number_of_numbers, i;
    int num[];
    printf("Please, enter how many numbers you would like to submit: ");
    scanf("%d", &number_of_numbers);
    printf("%d\n", number_of_numbers);
    
    for(i=0; i<number_of_numbers; i++){
        // for i in range number of numbers
        // ask for another number
        // assign numbers[i] to that number.
        printf("Enter integer %d: ", i+1);
        scanf("%d", &num[i]);
    } 
    
    struct thread_args intake;
    intake.nums = num;    
    intake.length = number_of_numbers;

	// Split operations into three seperate threads respectively.
	// average
    pthread_t average_thread;
    pthread_create(&average_thread, NULL, Average, &num);
    pthread_join(average_thread, NULL);

	// minimum
	pthread_t minimum_thread;
	pthread_create(&minimum_thread, NULL, Minimum, num);
	pthread_join(minimum_thread, NULL);

	// maximum
	pthread_t maximum_thread;
	pthread_create(&maximum_thread, NULL, Maximum, num);
	pthread_join(maximum_thread, NULL);

	pthread_exit(NULL);
}
