#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
	int rc_0 = fork();
	int pipefd[2];
	char buf;
	if(pipe(pipefd)==-1) {
		perror("pipe");
		exit(EXIT_FAILURE);
	}

	if  (rc_0 < 0) {
		fprintf(stderr, "fork failed\n");
	} else if (rc_0 == 0) {
		close(pipefd[1]);
		while (read(pipefd[0], &buf, 1)>0) {
			write(STDOUT_FILENO, &buf, 1);
		}
		write(STDOUT_FILENO, "\n", 1);
		close(pipefd[0]);
		_exit(EXIT_SUCCESS);
	} else {	
		int rc_1 = fork();
		if  (rc_1 < 0) {
			fprintf(stderr, "fork failed\n");
		} else if (rc_1 == 0) {
			close(pipefd[0]);
			write(pipefd[1], argv[1], strlen(argv[1]));
			close(pipefd[1]);
			exit(EXIT_SUCCESS);
		} else {
	
		}
	}
}

/********************************

Christopher Anderson:
Question 1: N/A

********************************/