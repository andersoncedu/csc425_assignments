#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
	int rc = fork();
	if  (rc < 0) {
		fprintf(stderr, "fork failed\n");
	} else if (rc == 0) {
		int rc_wait = wait(NULL);
		printf("hello\n");
		printf("child pid: %d", getpid());
		printf("%d", rc_wait);

	} else {
		int rc_wait = wait(NULL);
		printf("goodbye\n");
		printf("parent pid: %d", getpid());
		printf("%d", rc_wait);
	}

}

/********************************

Christopher Anderson:
Question 1: Wait returns the child PID when used in the parent.
Question 2: When used by the child node it returns -1, which would be the parent pid, the current id -1, at leas in the case of my program

********************************/