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
const char request_met_message[100] = "Request has been met.";
const char request_denied_message[100] = "Request has been denied.";


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

void add_to_allocation_matrix(int process, int request[number_of_resources]){
	for(int r = 0; r < number_of_resources; r++){
		int current_value = *(allocations_matrix + process * number_of_resources + r);
		int new_value = current_value + request[r];
		*(allocations_matrix + process * number_of_resources + r) = new_value;
	}
}

int process_is_finished(int process){
	/* if each of this processes allocated resources == 
	 * that from the maximum matrix 
	 * return 1
	 * */
	int resource;
	for(resource = 0; resource < number_of_resources; resource++){
		int amount_allocated = *(
				allocations_matrix + process * number_of_resources + resource);	
		int maximum_needed = *(
				maximum_matrix + process * number_of_resources + resource);
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
}

void meet_request(int process, int request[number_of_resources]){
	// print message
	puts(request_met_message);

	// take away from request matrix
	for(int resource = 0; resource < number_of_resources; resource++)
		*(request_matrix + process * number_of_resources + resource) -= request[resource];

	// add to allocation matrix
	add_to_allocation_matrix(process, request);

	// take away from availability array
	for(int resource = 0; resource < number_of_resources; resource++)
		*(request_matrix + process * number_of_resources + resource) -= request[resource];

	if(process_is_finished(process)){
		finish_process(process);
	}
}

void copy_availability_array(int *temp_resource_availability){
	/* Copys whats in the resource availability array
	 *	into a new space in memory.
	 *	Used to check if the next request will create an
	 *	unsafe state without affecting the values in
	 *	the actual resource availability array.
	 * */
	temp_resource_availability = malloc(number_of_resources * sizeof(int));
	memcpy(
		temp_resource_availability, 
		resource_availability, 
		number_of_resources * sizeof(int));
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
    /* print each request, print available resources
     * create temp available
     * subtract request from temp available
	 * if all temp avail resouces are >= 0
     *      print allowed message
     *      allow request to take from actual available array
     *      add to allocation
	 *      take away from request matrix -- this way the request has been made if it <= 0
     *  else
     *      print denied request message
     *
     * questions:
     *  what to do after denial of request.
     *  could keep a var that represents how many requests have been 
     *  granted and break once var == number of resources
     *
     *
     * */
    int process, resource = 0;
	while(!all_requests_met()){
		for(process = 0; process < number_of_processes; process++){
			// build request array
			int request_array[number_of_resources];
			for(int i = 0; i < number_of_resources; i++){
				request_array[i] = *(request_matrix + process * number_of_resources + i);
			}
			if(is_safe_request(request_array)){
				meet_request(process, request_array);
			} else {
				puts(request_denied_message);
			}
		}
	}
}


int main(){
    get_data_from_input_file();
    process_each_request();
	all_requests_met();
    free(allocations_matrix);
    free(maximum_matrix);
    free(resource_availability);
    free(request_matrix);
    return 0;
}
