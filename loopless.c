/*
HELLO WORLD

++++++++. Gives us an H
---. Gives us an E
+++++++.. Gives us 2 Ls
+++. Gives us an O
>. Gives us a space
<++++++++. Gives us a W
--------. Gives us an O
+++. Gives us an R
------. Gives us an L
--------. Gives us a D
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAPE_SIZE 999

char tape[TAPE_SIZE];
int pointer = 0;

const static char alpha[] = " ABCDEFGHIJKLMNOPQRSTUVWXYZ!@#$%^&*()_+-=,./;'[]{}:\"<>?";

void eval(int biti) {
	switch (biti) {
    case(0):
      break;
    // Increment Cell
    case ('+'):
      if(tape[pointer] < strlen(alpha) - 1) tape[pointer]++;
      goto BITIDEF;
      break;
    // Decrement Cell
    case ('-'):
      if(tape[pointer] > 0) tape[pointer]--;
      goto BITIDEF;
      break;
    // Select previous Cell
    case ('<'):
      if (pointer > 0) pointer--;
      goto BITIDEF;
      break;
    // Select next Cell
    case ('>'):
      if (pointer < TAPE_SIZE) pointer++;
      goto BITIDEF;
      break;
    // Print Alpha of current Cell
    case ('.'):
      printf("%c", alpha[tape[pointer]]);
      goto BITIDEF;
      break;
    // Clear all Cells
    case('@'):
      for(int i = 0; i < TAPE_SIZE; ++i) tape[i] = 0;
      goto BITIDEF;
      break;
    // Clear Screen
    case ('#'):
      for (int i = 50; i > 0; --i) printf("%c", '\n');
      goto BITIDEF;
      break;
    // Print number literal of current Cell, followed by a newline. Mostly for debugging purposes.
    case('!'):
      printf("%d\r\n", tape[pointer]);
      goto BITIDEF;
      break;
    BITIDEF:
    default:
      biti = 0;
      break;
  }
}

int main(int argc, char** argv) {
	char* program;

    FILE* fp = fopen(argv[1], "r");
    if(fp == NULL) { printf("%s", "Error, file can't be opened. Does it exist?"); return -1;}

    // Read length, and allocate memory for file size.
    fseek(fp, 0, SEEK_END);
    long int size = ftell(fp);
    rewind(fp);
    program = calloc(size + 1, 1);

    //Read our data in!
    fread(program, 1, size, fp);

	for(int i = 0; i < strlen(program); ++i) {
		eval(program[i]);
	}
}