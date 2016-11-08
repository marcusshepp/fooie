/* Test prompt for the Zilla programming language.
 *
 * Run with:
 * cc -std=c99 -Wall interactive_prompt.c -ledit -o out
 * ./out
 *
 * http://www.buildyourownlisp.com/chapter4_interactive_prompt
 *
 * */
#include <stdio.h>
#include <stdlib.h>
#include <editline/readline.h>


int main(int argc, char** argv){

    puts("Zilla Version 0.0.0.0.0.0.0.0.1");
    puts("Press Ctrl+c to Exit\n");

    while(1){
        /* prompt and get input */
        char* input = readline("zilla> ");

        /* add input to history for use of up and down arrows */
        add_history(input);

        printf("%s\n", input);

        free(input);
    }
    return 0;
}
