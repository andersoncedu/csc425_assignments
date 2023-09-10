#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
	int rc = fork();
	if  (rc < 0) {
		fprintf(stderr, "fork failed\n");
	} else if (rc == 0) {
		printf("hello\n");
	} else {
		sleep(3);
		printf("goodbye\n");
	}

}

/********************************

Christopher Anderson:
Question 1: I can do this without calling wait by making the parent process take a long to complete.

********************************/