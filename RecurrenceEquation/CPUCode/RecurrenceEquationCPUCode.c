#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <sys/time.h>
#include "Maxfiles.h"

#define SIZE 16

int main() {
	size_t dataSizeInBytes = SIZE * sizeof(int32_t);
	int32_t *a = malloc(dataSizeInBytes);
	int32_t *b = malloc(dataSizeInBytes);
	int32_t *z = malloc(dataSizeInBytes);
	int32_t z0 = 1, z1 = 2;

	for (int i = 0; i < SIZE; i++) {
		a[i] = 1;
		b[i] = 1;
	}

	struct timeval start, end;
	printf("Running DFE...\n");
	gettimeofday(&start, NULL);
	max_run_t *execStatus = RecurrenceEquation_nonblock(SIZE, z0, z1, a, b, z);
	max_wait(execStatus);
	gettimeofday(&end, NULL);
	printf("DFE: %ld microseconds\n", ((end.tv_sec * 1000000 + end.tv_usec)
				 - (start.tv_sec * 1000000 + start.tv_usec)));
	printf("End of DFE...\n");

	free(a);
	free(b);
	free(z);

	return 0;
}
