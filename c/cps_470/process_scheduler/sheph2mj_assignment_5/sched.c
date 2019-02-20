#include <stdio.h>
#include <stdlib.h>

#define num_procs 5


typedef struct{
	int pid;
	int burst;
	int temp_burst;
	int waiting;
	int turnaround;
	int arrival;
	int done;
}Process;

double average_waiting;
double average_turnaround;
int total_waiting;
int total_turnaround;

void print_seperator(){
	int i;
	for(i=0;i<=35;i++){
		printf("-");
	}
	printf("\n");
}

void output(Process p[]){
	int i;
	printf("pid\tarrival time\tburst\twaiting time\tturnaround time\t\n");
	for(i=0;i<num_procs;i++){
		printf("%d\t%d\t\t%d\t%d\t\t%d\n", 
				p[i].pid, p[i].arrival, p[i].burst, p[i].waiting, p[i].turnaround);
	}
}

void calculate_waiting_time(Process p[]){
    int i;
	total_waiting = 0;
	p[0].waiting = 0;
	for(i=1; i<num_procs; i++) {
		int start_time = p[i-1].burst + p[i-1].arrival;
		p[i].waiting = start_time - p[i].arrival;
		total_waiting += p[i].waiting;
	}
}

void calculate_turnaround_time(Process p[]){
    int i;
	total_turnaround = 0;
	p[0].turnaround = 0;
	for(i=1; i<num_procs; i++) {
		p[i].turnaround = p[i].waiting + p[i].burst;
		total_turnaround += p[i].turnaround;
	}
}

void first_come_first_serve(Process p[]){
    int i, j;
	Process temp;
	for(i=0; i<num_procs-1; i++) {
		for(j=0; j<num_procs-1-i; j++) {
			if(p[j].arrival > p[j+1].arrival) {
				temp = p[j];
				p[j] = p[j+1];
				p[j+1] = temp;
			}
		}
	}
}

void shortest_job_first(Process p[]){
	printf("shortest job first\n");
    int i, j;
	Process temp;
	for(i=0; i<num_procs-1; i++) {
		for(j=0; j<num_procs-1-i; j++) {
			if(p[j].burst > p[j+1].burst) {
				temp = p[j];
				p[j] = p[j+1];
				p[j+1] = temp;
			}
		}
	}
}

void round_robin(Process p[]){
	/* Processes are ordered by arrival time.
	 * Each process is ran for given quantum time.
	 * If the quantum time exhausts the processes burst time
	 * that process it popped from the queue.
	 * If the burst time of the process is greater than the quantum time
	 * that process runs for the quantum time and subtracts that from
	 * its burst time and is put at the end of the queue.
	 * */
	printf("\nround robin\n");
	// order by arrival time
	first_come_first_serve(p);	
	
	// quantum time
	int quan = 10;
	printf("Quantum Time: %d\n", quan);

	int foo = 1;

	while(foo == 1){
		int bar = 0;

		for(int i = 0; i < num_procs; i++){

			if(!p[i].done){
				// if this p[i]esses.temp_burst is less than the quantum time
				printf("\nPROC %d IS NOT DONE\n", p[i].pid);
				printf("PROC %d HAS %d BURST LEFT.\n", p[i].pid, p[i].temp_burst);

				if(p[i].temp_burst < quan){

					p[i].temp_burst = p[i].temp_burst - quan;
					// this p[i] is done
					// because its.temp_burst was less than the quan
					p[i].done = 1;
					bar += 1;
					printf("PROC %d IS DONE\n", p[i].pid);
				} else {

					p[i].temp_burst = p[i].temp_burst - quan;
					// if this p[i]s.temp_burst has run out set done to true.
					if(p[i].temp_burst <= 0){
						p[i].done = 1;	
						bar += 1;
						printf("PROC %d IS DONE\n", p[i].pid);
					}

				}

				printf("PROC %d HAS %d BURST LEFT.\n", p[i].pid, p[i].temp_burst);

			} else {
				printf("PROC %d IS DONE\n", p[i].pid);
				bar += 1;
			}

		}
		if(bar == num_procs){
			// all procs are done
			printf("\nAll Processes are done.\n");
			foo = 0;
		}
	}
}

void driver(int hold){
	FILE* f = fopen("input.txt", "rt");
	// skip first line
	char buffer[250];
	fgets(buffer, 250, f);

	// processes
	Process p1;
	Process p2;
	Process p3;
	Process p4;
	Process p5;

	// assign attr to processes bases on
	// file input.
	int pid, arrival, burst, priority;
	int i = 1;

	while(fscanf(f, "%d %d %d %d", &pid, &arrival, &burst, &priority) == 4){

		if(i==1){
			p1.pid = pid;
			p1.arrival = arrival;
			p1.burst = burst;
			p1.done = 0;
			p1.temp_burst = burst;
		} else if (i==2){
			p2.pid = pid;
			p2.arrival = arrival;
			p2.burst = burst;
			p2.done = 0;
			p2.temp_burst = burst;
		} else if (i==3){
			p3.pid = pid;
			p3.arrival = arrival;
			p3.burst = burst;
			p3.done = 0;
			p3.temp_burst = burst;
		} else if (i==4){
			p4.pid = pid;
			p4.arrival = arrival;
			p4.burst = burst;
			p4.done = 0;
			p4.temp_burst = burst;
		} else if (i==5){
			p5.pid = pid;
			p5.arrival = arrival;
			p5.burst = burst;
			p5.done = 0;
			p5.temp_burst = burst;
		}
		i++;

	}
    // close file
	fclose(f);

	Process p[num_procs] = {p1, p2, p3, p4, p5};

	int choice;
	printf("1. FCFS (first come first serve)\n");
	printf("2. SJF (shortest job first)\n");
	printf("3. RR (round robin)\n");
	printf("Which algorithm would you like to run?\n");
	scanf("%d", &choice);
	if (choice > 3 || choice < 1){
		printf("Please enter a value between 1 and 3.\n");
		driver(0);
	} else {
		hold = 1;
	}
	if (hold){
		printf("Choice was: %d\n", choice);
	}
	if (choice == 1){
		first_come_first_serve(p);
	} else if (choice == 2){
		shortest_job_first(p);
	} else if (choice == 3){
		round_robin(p);
	}


	calculate_waiting_time(p);
	calculate_turnaround_time(p);

	output(p);

	average_waiting = (double)((double)total_waiting / (double)num_procs);
	printf("\n\nAverage Waiting Time: %f\n", average_waiting);

	average_turnaround = (double)((double)total_turnaround / (double)num_procs);
	printf("Average Turnaround Time: %f\n", average_turnaround);
}

int main(){
    // start algorithm
	driver(1);
	return 0;
}
