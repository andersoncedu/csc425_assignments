#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {

	int rc = fork();

	if  (rc < 0) {
		fprintf(stderr, "fork failed\n");
	} else if (rc == 0) {
		int file = open("test.txt", O_RDWR);
		write(file, "Child's contribution", strlen("Child's contribution"));
		printf("Child: %d\n", file);
	} else {
		int file =  open("test.txt", O_RDWR);
		write(file, "Parent's contribution", strlen("Parent's contribution"));
		printf("Parent: %d\n", file);
	}
	int file =  open("test.txt", O_RDWR);
	printf("%d\n", file);
}

/********************************

Christopher Anderson:
Question 1: It seems that both the child and parent can access the file descriptor
Quesiton 2: It seems they overwrite each other's changes.

********************************/