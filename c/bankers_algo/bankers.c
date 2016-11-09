/* Bankers Algorithm
 *
 * Sources:
 * https://en.wikipedia.org/wiki/Banker%27s_algorithm
 * https://www.cs.jhu.edu/~yairamir/cs418/os4/sld029.htm
 * http://www.cs.colostate.edu/~cs551/CourseNotes/Bankers.html
 * */
#include <stdlib.h>
#include <stdio.h>

int number_of_processes;
int number_of_resources;
int allocations_matrix = malloc(sizeof(int)*10);
int maximum_matrix = malloc(sizeof(int)*10);
int resource_availability;
int request_matrix = malloc(sizeof(int)*10);

int main(){
    // get_data_from_input_file();
    return 0;
}
