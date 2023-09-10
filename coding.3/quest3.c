#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
	int rc = fork();
	if  (rc < 0) {
		fprintf(stderr, "fork failed\n");
	} else if (rc == 0) {
		printf("hello");
	} else {
		sleep(3);
		printf("goodbye");
	}

}

/********************************

Christopher Anderson:
Question 1: The value of the variable is the same as the value of the variable in the parent.
Quesiton 2: When the values of x are changed by both the parent and the child, the value is only afected once, 
			this means that they each have their own reference to a different variable it seems.

********************************/