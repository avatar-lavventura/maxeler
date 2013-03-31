#include "Maxfiles.h"
#include <MaxSLiCInterface.h>
#include <stdio.h>
#define SIZE 512

void prefix_sum_cpu(int *dataIn, int *dataOut, int size) {
	dataOut[0] = dataIn[0];
	for(int i = 1; i < size; i++) {
		dataOut[i] = dataIn[i] + dataOut[i - 1];
	}
}

int main() {
	int dataIn[SIZE], dataOut[SIZE], dataExpected[SIZE];

	// initialize dataIn
	for(int i = 0; i < SIZE; i++) {
		dataIn[i] = i + 1;
	}

	// calculate expected result
	prefix_sum_cpu(dataIn, dataExpected, SIZE);

	printf("Executing...\n");

	PrefixSum(SIZE, dataIn, dataOut);

	// print result
	for(int i = 0; i < SIZE; i++) {
		if(dataOut[i] == dataExpected[i]) {
			printf("dataExpected[%d] = dataOut[%d] = %d\n", i, i, dataOut[i]);
		} else {
			printf("dataExpected[%d] = %d\t\tdataOut[%d] = %d\n",
					i, dataExpected[i], i, dataOut[i]);
		}
	}

	printf("End of execution...\n");

	return 0;
}
