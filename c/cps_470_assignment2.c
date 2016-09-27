#include <stdio.h>
#include <pthread.h>


void *thread_function(void *arg){
    printf("bar foo\n");
    return NULL;
}


int main(void){
    // thread identifier
    pthread_t my_thread;
    int i = 0;

    // create the thread
    pthread_create(&my_thread, NULL, thread_function, NULL);
    
    // wait for the thread to finish
    pthread_join(my_thread, NULL);

    printf("foo bar\n");
    return 0;
}
