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

/* if compiling on Windows compile the following functions */
#ifdef _WIN32
#include <string.h>

static char buffer[2048];

/* Fake readline function */
char* readline(char* prompt){
    fputs(prompt, stdout);
    fgets(buffer, 2048, stdin);
    char* cpy = malloc(strlen(buffer) + 1);
    strcpy(cpy, buffer);
    cpy[strlen(cpy) - 1] = "\0";
    return cpy;
}

/* Fake add_history function */
void add_history(char* unused){}

/* Otherwise include editline functions */
#else

#include <editline/readline.h>

#endif

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
