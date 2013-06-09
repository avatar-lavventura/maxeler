#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <sys/time.h>
#include "Maxfiles.h"

int main() {
	FILE* fp = fopen("tinyGeneratedCSR.txt","r");
	float *values, *result;
	int *flag , *row_begin;
	uint32_t *col_indices;
	int n,m,i,j;

	fscanf(fp,"%d %d", &n, &m);

	row_begin = malloc((n + 1) * sizeof(int));

	for (i = 0; i <= n; i++) {
		fscanf(fp,"%d", row_begin + i);
	}

	flag = malloc(m * sizeof(int));

	for(i=0, j=0; i<m; i++){
		if(j <= n && row_begin[j] - 1 == i){
			flag[i] = 1;
			j++;
		}else{
			flag[i] = 0;
		}
	}

	free(row_begin);

	col_indices = malloc(m * sizeof(int));

	for (j = 0; j < m; j++) {
		fscanf(fp,"%d", col_indices + j);
		col_indices[j]--;
	}

	values = malloc(m* sizeof(float));

	for (j = 0; j < m; j++) {
		fscanf(fp,"%e", values + j);
	}

	fclose(fp);

	result = malloc(n * sizeof(float));

	printf("Started Maxeler execution!\n");
	struct timeval start, end;
	gettimeofday(&start, NULL);
	max_run_t *execStatus = SparseMatrixMultiplication_nonblock(m,n,flag,col_indices,values,result);
	max_wait(execStatus);
	gettimeofday(&end, NULL);
	printf("Maxeler execution finished!\n");
	printf("%ld microseconds card execution\n", ((end.tv_sec * 1000000 + end.tv_usec)
				 - (start.tv_sec * 1000000 + start.tv_usec)));


	fp = fopen("maxelerTinyGeneratedOut.txt","w");
	for(i = 0; i < n; i++){
		fprintf(fp,"%f\n",result[i]);
	}
	fclose(fp);
	free(values);
	free(col_indices);
	free(result);
	free(flag);
	return 0;

}
