#include <stdio.h>
#include <pthread.h>
#include <dispatch/dispatch.h>

int i = 0;
dispatch_semaphore_t mutex;

void first_func(){
	dispatch_semaphore_wait(mutex, DISPATCH_TIME_FOREVER);
	printf("first func\n");
	printf("Before addition: i: %d\n", i);
	i++;
	printf("After addition: i: %d\n", i);
	dispatch_semaphore_signal(mutex);
	pthread_exit(0);
}

void second_func(){
	dispatch_semaphore_wait(mutex, DISPATCH_TIME_FOREVER);
	printf("second func\n");
	printf("before subtraction i: %d\n", i);
	i--;
	printf("after subtraction: i: %d\n", i);
	dispatch_semaphore_signal(mutex);
	pthread_exit(0);
}

int main(){
	pthread_t first_thread;
	pthread_t second_thread;
	
	long count = 1;

	mutex = dispatch_semaphore_create(count);

	pthread_create(&first_thread, NULL, (void *)&first_func, NULL);	
	pthread_create(&second_thread, NULL, (void *)&second_func, NULL);	

	pthread_join(first_thread, NULL);
	pthread_join(second_thread, NULL);

	dispatch_release(mutex);

	return 0;
}
