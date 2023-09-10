#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
	int rc = fork();
	int status;
	if  (rc < 0) {
		fprintf(stderr, "fork failed\n");
	} else if (rc == 0) {
		int rc_wait = waitpid(rc, &status, WNOHANG);
		printf("hello\n");
		printf("child pid: %d", getpid());
		printf("%d", rc_wait);

	} else {
		int rc_wait = waitpid(rc, &status, WNOHANG);
		printf("goodbye\n");
		printf("parent pid: %d", getpid());
		printf("%d", rc_wait);
	}

}

/********************************

Christopher Anderson:
Question 1: Waitpid could be useful if you want to specify a pid that you want to be waited on, or have more control over the wait.

********************************/