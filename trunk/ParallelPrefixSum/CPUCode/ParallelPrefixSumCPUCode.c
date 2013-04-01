#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include "Maxfiles.h"

#define SIZE 4096

void prefix_sum_cpu(uint32_t *dataIn, uint32_t *dataOut, int size) {
	dataOut[0] = dataIn[0];
	for(int i = 1; i < size; i++) {
		dataOut[i] = dataIn[i] + dataOut[i - 1];
	}
}

int main() {
	size_t sizeInBytes = SIZE * sizeof(uint32_t);
	uint32_t *dataIn = malloc(sizeInBytes);
	uint32_t *dataOut = malloc(sizeInBytes);
	uint32_t *dataExpected = malloc(sizeInBytes);

	for(int i = 0; i < SIZE; i++) {
		dataIn[i] = i+1;
		dataOut[i] = 0;
	}
	printf("Running CPU \n");
	prefix_sum_cpu(dataIn, dataExpected, SIZE);

	printf("Running DFE.\n");
	ParallelPrefixSum(SIZE, dataIn, dataOut);
	for(int i = 0; i < SIZE; i++) {
			if(dataOut[i] == dataExpected[i]) {
				printf("dataExpected[%d] = dataOut[%d] = %d\n", i, i, dataOut[i]);
			} else {
				printf("dataExpected[%d] = %d\t\tdataOut[%d] = %d\n",
						i, dataExpected[i], i, dataOut[i]);
			}
		}
	printf("End of DFE.\n");


	free(dataIn);
	free(dataOut);
	free(dataExpected);

	return 0;
}

