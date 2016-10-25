#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <dispatch/dispatch.h>
#include <pthread.h>

#define PHIL_COUNT 5
#define FORK_COUNT 5
#define SLEEP_COUNT 3


pthread_t phil[PHIL_COUNT];
dispatch_semaphore_t forks[PHIL_COUNT];

void *func(int n){
	// think
	printf ("\nPhilosopher %d is thinking\n", n + 1);

	// pick up forks n
  	dispatch_semaphore_wait(forks[n], DISPATCH_TIME_FOREVER);

	// pick up forks n + 1
    dispatch_semaphore_wait(forks[ ( n + 1 ) % PHIL_COUNT ], DISPATCH_TIME_FOREVER);

	// eat with said forkss
	printf ("\nPhilosopher %d is eating\nwith forks %d and %d\n", n + 1, n, ((n + 1) % PHIL_COUNT));
    sleep(SLEEP_COUNT);

	// put down forks n
    dispatch_semaphore_signal(forks[n]);

	// put down forks n + 1
    dispatch_semaphore_signal(forks[ ( n + 1 ) % PHIL_COUNT ]);

	// go back to thinking
	printf ("\nPhilosopher %d finished eating\n",n);

	return(NULL);
}

int main(){
	long i;
	for(i = 0; i < PHIL_COUNT; i++)
		dispatch_semaphore_create(i);

	for(i = 0; i < PHIL_COUNT; i++){
		pthread_create(&forks[i], NULL, (void *)func, (void *)(size_t)i);
	}
	for(i = 0; i < PHIL_COUNT; i++){
		pthread_join(forks[i], NULL);
	}
	for(i = 0; i < PHIL_COUNT; i++){
		dispatch_release(forks[i]);
	}
	return 0;
}
