#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
	int rc = fork();
	if  (rc < 0) {
		fprintf(stderr, "fork failed\n");
	} else if (rc == 0) {
		close(STDOUT_FILENO);
		printf("hello\n");
	} else {
		sleep(3);
		printf("goodbye\n");
	}

}

/********************************

Christopher Anderson:
Question 1: It seems as though the output is not printed and it never reaches that line.

********************************/