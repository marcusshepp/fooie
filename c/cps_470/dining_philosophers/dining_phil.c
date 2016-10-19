#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

#define PHIL_COUNT 5
#define FORK_COUNT 5
#define SLEEP_COUNT 1

pthread_t p[PHIL_COUNT];
pthread_mutex_t c[PHIL_COUNT];

void *func(int n){
	// think
	printf ("\nPhilosopher %d is thinking\n", n + 1);
    sleep(SLEEP_COUNT);

	// pick up fork n
  	pthread_mutex_lock(&c[n]);

	// pick up fork n + 1
    pthread_mutex_lock(&c[ ( n + 1 ) % PHIL_COUNT ]);

	// eat with said forks
	printf ("\nPhilosopher %d is eating\nwith fork %d and %d\n", n + 1, n + 1, n + 2);
    sleep(SLEEP_COUNT);

	// put down fork n
    pthread_mutex_unlock(&c[n]);

	// put down fork n + 1
    pthread_mutex_unlock(&c[ ( n + 1 ) % PHIL_COUNT ]);

	// go back to thinking
	printf ("\nPhilosopher %d finished eating\n",n);

	return(NULL);
}

int main(){
	int i;
	for(i = 0; i < PHIL_COUNT; i++){
		pthread_mutex_init(&c[i], NULL);
	}
	for(i = 0; i < PHIL_COUNT; i++){
		pthread_create(&p[i], NULL, (void *)func, (void *)(size_t)i);
	}
	for(i = 0; i < PHIL_COUNT; i++){
		pthread_join(p[i], NULL);
	}
	for(i = 0; i < PHIL_COUNT; i++){
		pthread_mutex_destroy(&c[i]);
	}
	return 0;
}
