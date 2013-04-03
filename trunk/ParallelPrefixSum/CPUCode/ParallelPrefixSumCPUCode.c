#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include "Maxfiles.h"

#define SIZE 1048576
#define DEBUG 1

void ParallelPrefixSumCPU(int32_t *dataIn, int32_t *dataOut, size_t size) {
	dataOut[0] = dataIn[0];
	for (size_t i = 1; i < size; i++) {
		dataOut[i] = dataIn[i] + dataOut[i - 1];
	}
}

int main() {
	size_t dataSizeInBytes = SIZE * sizeof(int32_t);
	int32_t *dataIn = malloc(dataSizeInBytes);
	int32_t *dataOut = malloc(dataSizeInBytes);
	int32_t *dataExpected = NULL;

	if(DEBUG == 1) {
		dataExpected = malloc(dataSizeInBytes);
	}

	for (int i = 0; i < SIZE; i++) {
		dataIn[i] = (i%5)+1;
		dataOut[i] = 0;
	}

	if (DEBUG == 1) {
		printf("Running CPU...\n");
		ParallelPrefixSumCPU(dataIn, dataExpected, SIZE);
	}

	printf("Running DFE...\n");
	ParallelPrefixSum(SIZE, dataIn, dataOut);
	printf("End of DFE...\nDFE");
	if (DEBUG == 1) {
		for (int i = 0; i < SIZE; i++) {
			if (dataOut[i] == dataExpected[i]) {
				printf("dataExpected[%d] = dataOut[%d] = %d\n", i, i,
						dataOut[i]);
			} else {
				printf("dataExpected[%d] = %d\t\tdataOut[%d] = %d\n", i,
						dataExpected[i], i, dataOut[i]);
			}
		}
	}

	free(dataIn);
	free(dataOut);

	if(DEBUG == 1){
		free(dataExpected);
	}

	return 0;
}
