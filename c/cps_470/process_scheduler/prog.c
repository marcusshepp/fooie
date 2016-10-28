#include <stdio.h>
#include <stdlib.h>

#define num_proc 5

typedef struct {
	int pid;
	int arrival_time;
	int burst;
	int priority;
} Process;

void output(
        int order[num_proc], 
        int remaining_time[num_proc], 
        int turnaround_time[num_proc], 
        int waiting_time[num_proc]){
    int average_turnaround_time;
    int average_waiting_time;
    /* 1. the order in which the processes are scheduled to run
     * 2. the remaining time of each process after it has run for the given CPU quantum
     * 3. the turnaround time and waiting time for each process
     * 4. the average turnaround time and average waiting time
     * */
}

void first_come_first_serve(
        Process p1, 
        Process p2,
        Process p3, 
        Process p4,
        Process p5){
    /* Jobs are executed on first come, first serve basis.
     * It is a non-preemptive, pre-emptive scheduling algorithm.
     * Its implementation is based on FIFO queue.
     * Poor in performance as average wait time is high.
     * */
	printf("Executing First Come First Serve\n");

    Process procs[num_proc];
    procs[0] = p1;
    procs[1] = p2;
    procs[2] = p3;
    procs[3] = p4;
    procs[4] = p5;

    // find the process that arrived first
    int first_proc_arrival_time = 999;
    int pid_first_arrival;
    for(int i = 0; i < num_proc - 1; i++){
       if(procs[i].arrival_time < first_proc_arrival_time){
            first_proc_arrival_time = procs[i].arrival_time;
            pid_first_arrival = procs[i].pid;
       } 
    }
    printf("pid first arrival: %d\narrival time: %d\n", pid_first_arrival, first_proc_arrival_time);
    
    // find the process that arrived second
    int sec_proc_arrival_time = 999;
    int pid_sec_arrival;
    for(int i = 0; i < num_proc - 1; i++){
        if(procs[i].pid != pid_first_arrival){
            if(procs[i].arrival_time < sec_proc_arrival_time){
                sec_proc_arrival_time = procs[i].arrival_time;
                pid_sec_arrival = procs[i].pid;
            } 
        }
    }
    printf("pid sec arrival: %d\narrival time: %d\n", pid_sec_arrival, sec_proc_arrival_time);

    // find the process that arrived third
    int third_proc_arrival_time = 999;
    int pid_third_arrival;
    for(int i = 0; i < num_proc - 1; i++){
        if((procs[i].pid != pid_first_arrival) && (procs[i].pid != pid_sec_arrival)){
            if(procs[i].arrival_time < third_proc_arrival_time){
                third_proc_arrival_time = procs[i].arrival_time;
                pid_third_arrival = procs[i].pid;
            } 
        }
    }
    printf("pid third arrival: %d\narrival time: %d\n", pid_third_arrival, third_proc_arrival_time);

    // find the process that arrived fourth
    int fourth_proc_arrival_time = 999;
    int pid_fourth_arrival;
    for(int i = 0; i < num_proc - 1; i++){
        if((procs[i].pid != pid_first_arrival) && 
                (procs[i].pid != pid_sec_arrival) &&
                (procs[i].pid != pid_third_arrival)){
            if(procs[i].arrival_time < fourth_proc_arrival_time){
                fourth_proc_arrival_time = procs[i].arrival_time;
                pid_fourth_arrival = procs[i].pid;
            } 
        }
    }
    printf("pid fourth arrival: %d\narrival time: %d\n", pid_fourth_arrival, fourth_proc_arrival_time);

    // find the process that arrived fifth
    int pid_fifth_arrival = procs[num_proc - 1].pid;
    printf("pid fifth arrival: %d\n", pid_fifth_arrival);
}

void shortest_job_first(
        Process p1, 
        Process p2,
        Process p3, 
        Process p4,
        Process p5){
	printf("shortest job first\n");
}

void round_robin(
        Process p1, 
        Process p2,
        Process p3, 
        Process p4,
        Process p5){
	printf("round robin\n");
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
	int pid, arrival_time, burst, priority;
	int i = 1;

	while(fscanf(f, "%d %d %d %d", &pid, &arrival_time, &burst, &priority) == 4){

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
    // close file
	fclose(f);

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
		first_come_first_serve(p1, p2, p3, p4, p5);
	} else if (choice == 2){
		shortest_job_first(p1, p2, p3, p4, p5);
	} else if (choice == 3){
		round_robin(p1, p2, p3, p4, p5);
	}
}

int main(){
    // start algorithm
	driver(1);
	return 0;
}
