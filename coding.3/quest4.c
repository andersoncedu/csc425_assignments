#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
	int rc = fork();
	if  (rc < 0) {
		fprintf(stderr, "fork failed\n");
	} else if (rc == 0) {
		char filepath[] = "/bin/ls";
		char *const argv[] = {"ls", NULL};
		// char *const nullList[] = {NULL};
		// execvp(argv[0], argv);
		// execl("/bin/ls", argv[0], NULL);
		// execl(argv[0], argv[0], NULL);
		// execle("/bin/ls", argv[0], NULL, nullList);
		execv(filepath, argv);
		// execvpe(argv[0], argv, nullList);

	} else {
		sleep(3);
		printf("goodbye\n");
	}

}

/********************************

Christopher Anderson:
Question 1: I think there's so many variations jsut to give the user more options of how to call things.

********************************/