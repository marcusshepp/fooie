/* Bankers Algorithm
 *
 * Sources:
 * https://en.wikipedia.org/wiki/Banker%27s_algorithm
 * https://www.cs.jhu.edu/~yairamir/cs418/os4/sld029.htm
 * http://www.cs.colostate.edu/~cs551/CourseNotes/Bankers.html
 * */
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

int number_of_processes;
int number_of_resources;
int *allocations_matrix;
int *maximum_matrix;
int *resource_availability;
int *request_matrix;
const char request_met_message[100] = "***Request has been GRANTED.***\n";
const char request_denied_message[100] = "***Request has been DENIED.***\n";
const char all_processes_exhausted_message[100] = "\n\n*** All processes have been exhausted and finished\n";
int requests_granted;

/* print functions */
void print_line_seperator(){
    int i;
    for(i = 0; i <= 45; i++)
        printf("-");
    puts("\n");
}

void print_availability_array(){
    int resource;
    puts("Resource availability: ");
    for(resource = 0; resource < number_of_resources; resource++){
        printf("\tR%d: ", (resource + 1));
        printf("%d", resource_availability[resource]);
    }
    printf("\n");   
}

void print_request_matrix(){
    int resource, process;
    puts("Request Matrix");
    puts("\tR1\tR2\tR3");
    for(process = 0; process < number_of_processes; process++){
        printf("P%d", (process + 1));
        for(resource = 0; resource < number_of_resources; resource++){
            int value = *(request_matrix + process * number_of_resources + resource);
            printf("\t%d", value);
        }
        printf("\n");
    }
}

void print_request_array(int process, int request_array[number_of_resources]){
    int resource;
    puts("***REQUEST");
    printf("Process %d requesting the following amounts.\n", (process + 1));
    for(resource = 0; resource < number_of_resources; resource++){
        printf("\tR%d: ", (resource + 1));
        printf("%d", request_array[resource]);
    }
    printf("\n");
}

void print_allocations_matrix(){
    int resource, process;
    puts("Allocations Matrix");
    puts("\tR1\tR2\tR3");
    for(process = 0; process < number_of_processes; process++){
        printf("P%d", (process + 1));
        for(resource = 0; resource < number_of_resources; resource++){
            int value = *(allocations_matrix + process * number_of_resources + resource);
            printf("\t%d", value);
        }
        printf("\n");
    }
}

void print_maximum_matrix(){
    int resource, process;
    puts("Maximum Matrix");
    puts("\tR1\tR2\tR3");
    for(process = 0; process < number_of_processes; process++){
        printf("P%d", (process + 1));
        for(resource = 0; resource < number_of_resources; resource++){
            int value = *(maximum_matrix + process * number_of_resources + resource);
            printf("\t%d", value);
        }
        printf("\n");
    }
}

void print_resource_availability(){
    int resource;
    puts("Resource Availability");
    for(resource = 0; resource < number_of_resources; resource++){
        printf("\tR%d: ", (resource + 1));
        printf("%d", resource_availability[resource]);
    }
    printf("\n");
}

/* Handle input file */
int get_data_from_input_file(){
    FILE* file = fopen("input.txt", "r");;
    int line_limit = 1000;
    char buffer[line_limit];
    if(!file)
        return 1;

    // num processes
    fgets(buffer, line_limit, file); 
    fgets(buffer, line_limit, file);
    number_of_processes = atoi(&buffer[0]);

    // num resources
    fgets(buffer, line_limit, file); 
    fgets(buffer, line_limit, file);
    number_of_resources = atoi(&buffer[0]);


    int rows = number_of_processes;
    int columns = number_of_resources;

    // allocations matrix
    allocations_matrix = (int *)malloc(rows * columns * sizeof(int));
    fgets(buffer, line_limit, file);

    for(int i = 0; i < rows; i++){
        fgets(buffer, line_limit, file);
        int a, b, c;
        sscanf(buffer, "%d %d %d", &a, &b, &c);
        *(allocations_matrix + i * columns + 0) = a;
        *(allocations_matrix + i * columns + 1) = b;
        *(allocations_matrix + i * columns + 2) = c;
    }

    // maximum matrix
    maximum_matrix = (int *)malloc(rows * columns * sizeof(int));
    fgets(buffer, line_limit, file);

    for(int i = 0; i < rows; i++){
        fgets(buffer, line_limit, file);
        int a, b, c;
        sscanf(buffer, "%d %d %d", &a, &b, &c);
        *(maximum_matrix + i * columns + 0) = a;
        *(maximum_matrix + i * columns + 1) = b;
        *(maximum_matrix + i * columns + 2) = c;
    }

    // resource availablilty
    resource_availability = malloc(sizeof(int) * number_of_resources); 
    fgets(buffer, line_limit, file);
    fgets(buffer, line_limit, file);
    sscanf(
        buffer, 
        "%d %d %d", 
        &resource_availability[0], 
        &resource_availability[1], 
        &resource_availability[2]);

    // maximum matrix
    request_matrix = (int *)malloc(rows * columns * sizeof(int));
    fgets(buffer, line_limit, file);

    for(int i = 0; i < rows; i++){
        fgets(buffer, line_limit, file);
        int a, b, c;
        sscanf(buffer, "%d %d %d", &a, &b, &c);
        *(request_matrix + i * columns + 0) = a;
        *(request_matrix + i * columns + 1) = b;
        *(request_matrix + i * columns + 2) = c;
    }
    return 0;
}

int all_requests_met(){
	/* returns 1 if all requests have been met */
	int i, j;
	int all_met = 1;
	for(i = 0; i < number_of_processes; i++){
		for(j = 0; j < number_of_resources; j++){
			int value = *(request_matrix + i * number_of_resources + j);
			if(value > 0){
				all_met = 0;
			}
		}
	}
	return all_met;
}

int max_needed(int process, int resource){
    return *(maximum_matrix + process * number_of_resources + resource);
}

int whats_allocated(int process, int resource){
    return *(allocations_matrix + process * number_of_resources + resource);
}

void add_to_allocation_matrix(int process, int request[number_of_resources]){
	for(int resource = 0; resource < number_of_resources; resource++){
		int current_value = whats_allocated(process, resource);
		int new_value = current_value + request[resource];
		*(allocations_matrix + process * number_of_resources + resource) = new_value;
	}
}

int process_is_finished(int process){
	/* if each of this processes allocated resources == 
	 * that from the maximum matrix 
	 * return 1
	 * */
	int resource;
	for(resource = 0; resource < number_of_resources; resource++){
		int amount_allocated = whats_allocated(process, resource);
		int maximum_needed = max_needed(process, resource);
		if(amount_allocated < maximum_needed){
			return 0;
		}
	}
	return 1;
}

void finish_process(int process){
	// add what was allocated to this process to the availability array
	int r;
	for(r = 0; r < number_of_resources; r++){
		int allocated = *(allocations_matrix + process * number_of_resources + r);
		resource_availability[r] += allocated;
	}
    requests_granted += 1;
}

void calculate_remaining_need(int process){
	// reassign what is being requested by this process
    // by subtracting what was allcated by what the maximum is
	for(int resource = 0; resource < number_of_resources; resource++){
        int allocated = whats_allocated(process, resource);
        int maximum = max_needed(process, resource);
        int remaining_need = maximum - allocated;
        // dont let request array have a value less than zero.
        if(remaining_need < 0){
            remaining_need = 0;
        } 
		*(request_matrix + process * number_of_resources + resource) = remaining_need;
    }
}

void meet_request(int process, int request[number_of_resources]){
	// print message
	puts(request_met_message);

	// add to allocation matrix
	add_to_allocation_matrix(process, request);
    print_allocations_matrix();

    print_maximum_matrix();

    // remake request matrix for this process based on
    // maximum - allocated
    calculate_remaining_need(process);
    print_request_matrix();

	// take away from availability array
	for(int resource = 0; resource < number_of_resources; resource++)
        resource_availability[resource] -= request[resource];
    print_resource_availability();

	if(process_is_finished(process)){
        printf("Process %d is finished.\n", (process + 1));
		finish_process(process);
	}
}

int is_safe_request(int request[number_of_resources]){
	/* for all in request for resources
	 * if request for resources[i] >= available of resource[i]
	 * return 1
	 * */
	int resource;
	for(resource = 0; resource < number_of_resources; resource++){
		int available = resource_availability[resource];
		int requested = request[resource];
		if(available < requested){
			return 0;
		}
	}
	return 1;
}

void process_each_request(){
    /*
     * */
    int process, resource = 0;
    int loop = 0;
    requests_granted = 0;
    print_request_matrix();
	while(requests_granted < number_of_processes){
		for(process = 0; process < number_of_processes; process++){
			// build request array
			int request_array[number_of_resources];
			for(int i = 0; i < number_of_resources; i++){
				request_array[i] = *(request_matrix + process * number_of_resources + i);
			}
            print_request_array(process, request_array);
            print_availability_array();
			if(is_safe_request(request_array)){
				meet_request(process, request_array);
			} else {
				puts(request_denied_message);
			}
		}
        loop++;
        print_line_seperator();
	}
    if(all_requests_met()){
        puts(all_processes_exhausted_message);
    }
}


int main(){
    get_data_from_input_file();
    process_each_request();
    free(allocations_matrix);
    free(maximum_matrix);
    free(resource_availability);
    free(request_matrix);
    return 0;
}
