
#define SIZE 64

int main() {
	size_t sizeInBytes = SIZE * sizeof(uint32_t);
	uint32_t *dataIn = malloc(sizeInBytes);
	uint32_t *dataOut = malloc(sizeInBytes);

	for(int i = 0; i < SIZE; i++) {
		dataIn[i] = i + 1;
		dataOut[i] = 0;
	}

	printf("Running DFE.\n");
	ParallelPrefixSum(SIZE, dataIn, dataOut);
	for(int i = 0; i < SIZE; i++) {
		printf("dataOut[%d] = %d\n", i, dataOut[i]);
	}
	printf("End of DFE.\n");

	free(dataIn);
	free(dataOut);

	return 0;
}

