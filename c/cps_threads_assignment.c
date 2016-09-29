/*
Multithreaded simple stats on a given list of integers.

usage:
gcc -pthread -o <this_script> <this_script>.c
./<this_script>

Marcus Shepherd (sheph2mj)
CPS 470 Introduction to Operating Systems
Activity 3
9/27/16
*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>


struct thread_args {
    float nums[100];
    float length;
};


void *Average(void* arg){
	/*
	Takes in a pointer. Is passed a pointer to a struct.
	Finds the average using the float array and the length
	of the array from the struct.
	*/
    struct thread_args *my_struct = (struct thread_args*)arg;
	
	int i;
   	float sum, average;
    for(i = 0; i < (*my_struct).length; i++)
		sum += (*my_struct).nums[i];

	average = sum/(*my_struct).length;
	printf("Average: %.2f\n", average);
	pthread_exit(NULL);
}


void *Minimum(void *arg){
	struct thread_args *my_struct = (struct thread_args*)arg;
	float minimum = (*my_struct).nums[0];
	for(int i = 0; i < (*my_struct).length; i++){
		if((*my_struct).nums[i] < minimum){
			minimum = (*my_struct).nums[i];
		}
	}
	printf("Minimum: %.2f\n", minimum);
	pthread_exit(NULL);
}


void *Maximum(void *arg){
	struct thread_args *my_struct = (struct thread_args*)arg;
	float maximum = (*my_struct).nums[0];
	for(int i = 0; i < (*my_struct).length; i++){
		if((*my_struct).nums[i] > maximum){
			maximum = (*my_struct).nums[i];
		}
	}
	printf("Maximum: %.2f\n", maximum);
	pthread_exit(NULL);
}


int main(void){

	// Read in numbers to be operated on.
	float number_of_numbers;
    int num[100];
    printf("Please, enter how many numbers you would like to submit: ");
    scanf("%f", &number_of_numbers);
    
    struct thread_args intake;
    intake.length = number_of_numbers;
	
	for(int i = 0; i<number_of_numbers; i++){
        // for i in range number of numbers
        // ask for another number
        // assign numbers[i] to that number.
        printf("Enter integer %d: ", i+1);
        scanf("%f", &intake.nums[i]);
    } 
    
	// Split operations into three seperate threads respectively.
	// average
    pthread_t average_thread;
    pthread_create(&average_thread, NULL, Average, &intake);
    pthread_join(average_thread, NULL);

	// minimum
	pthread_t minimum_thread;
	pthread_create(&minimum_thread, NULL, Minimum, &intake);
	pthread_join(minimum_thread, NULL);

	// maximum
	pthread_t maximum_thread;
	pthread_create(&maximum_thread, NULL, Maximum, &intake);
	pthread_join(maximum_thread, NULL);

	pthread_exit(NULL);
}
