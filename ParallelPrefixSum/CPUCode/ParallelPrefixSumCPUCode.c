#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include "Maxfiles.h"

#define SIZE 1024
#define DEBUG 1

void ParallelPrefixSumCPU(int64_t *dataIn, int64_t *dataOut, size_t size) {
	dataOut[0] = dataIn[0];
	for (size_t i = 1; i < size; i++) {
		dataOut[i] = dataIn[i] + dataOut[i - 1];
	}
}

int main() {
	size_t dataSizeInBytes = SIZE * sizeof(int64_t);
	int64_t *dataIn = malloc(dataSizeInBytes);
	int64_t *dataOut = malloc(dataSizeInBytes);
	int64_t *dataExpected = malloc(dataSizeInBytes);

	for (int i = 0; i < SIZE; i++) {
		dataIn[i] = i + 1;
		dataOut[i] = 0;
	}

	if (DEBUG == 1) {
		printf("Running CPU...\n");
		ParallelPrefixSumCPU(dataIn, dataExpected, SIZE);
	}

	printf("Running DFE...\n");
	ParallelPrefixSum(SIZE, dataIn, dataOut);
	printf("End of DFE...\n");
	if (DEBUG == 1) {
		for (int i = 0; i < SIZE; i++) {
			if (dataOut[i] == dataExpected[i]) {
				printf("dataExpected[%d] = dataOut[%d] = %ld\n", i, i,
						dataOut[i]);
			} else {
				printf("dataExpected[%d] = %ld\t\tdataOut[%d] = %ld\n", i,
						dataExpected[i], i, dataOut[i]);
			}
		}
	}

	free(dataIn);
	free(dataOut);
	free(dataExpected);

	return 0;
}
