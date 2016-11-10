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

int get_data_from_input_file(){
    FILE* file = fopen("input.txt", "r");;
    int line_limit = 1000;
    char buffer[line_limit];
    if(!file)
        return 1;

    // num processes
    fgets(buffer, line_limit, file); 
    printf("first buffer: %s\n", buffer);
    fgets(buffer, line_limit, file);
    printf("next buffer: %s\n", buffer);
    number_of_processes = atoi(&buffer[0]);
    printf("num proc: %d\n", number_of_processes);

    // num resources
    fgets(buffer, line_limit, file); 
    printf("first buffer: %s\n", buffer);
    fgets(buffer, line_limit, file);
    printf("next buffer: %s\n", buffer);
    number_of_resources = atoi(&buffer[0]);
    printf("num resc: %d\n", number_of_resources);


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
    sscanf(buffer, "%d %d %d", &resource_availability[0], &resource_availability[1], &resource_availability[2]);

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



int main(){
    get_data_from_input_file();
    free(allocations_matrix);
    free(maximum_matrix);
    free(resource_availability);
    free(request_matrix);
    return 0;
}
