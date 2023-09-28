#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int main(int argc, char* argv[]) {
	int size = atoi(argv[1]);
	int * allocate = malloc(size*1024*1024);
	long int times = atoi(argv[2]);
	long int iterator = 0;

	while(iterator < times) {
		for (int i =0; i<sizeof(allocate); i++) {
			allocate[i]=i;
			// printf("Hello"); //for debugging
			
		}
		iterator++;
	}
	free(allocate);
}