#include <stdio.h>
#include <stdlib.h>


typedef struct {
	int pid;
	int arrival_time;
	int burst;
	int priority;
} Process;

void first_come_first_serve(){
	printf("first come first serve\n");
}

void shortest_job_first(){
	printf("shortest job first\n");
}

void round_robin(){
	printf("round robin\n");
}
void driver(int hold){
	int choice;
	printf("1. FCFS (first come first serve)\n");
	printf("2. SJB (shortest job first)\n");
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
		first_come_first_serve();
	} else if (choice == 2){
		shortest_job_first();
	} else if (choice == 3){
		round_robin();
	}
}


int main(){
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
	int pid, arrival_time, burst, priority;
	int i = 1;
	while(fscanf(f, "%d %d %d %d", &pid, &arrival_time, &burst, &priority) == 4){
		// printf("%d\n%d\n%d\n%d", a, b, c, d);
		if(i==1){
			p1.pid = pid;
			p1.arrival_time = arrival_time;
			p1.burst = burst;
			p1.priority = priority;
		} else if (i==2){
			p2.pid = pid;
			p2.arrival_time = arrival_time;
			p2.burst = burst;
			p2.priority = priority;
		} else if (i==3){
			p3.pid = pid;
			p3.arrival_time = arrival_time;
			p3.burst = burst;
			p3.priority = priority;
		} else if (i==4){
			p4.pid = pid;
			p4.arrival_time = arrival_time;
			p4.burst = burst;
			p4.priority = priority;
		} else if (i==5){
			p5.pid = pid;
			p5.arrival_time = arrival_time;
			p5.burst = burst;
			p5.priority = priority;
		}
		i++;
	}

	fclose(f);
	driver(1);
	return 0;
}
