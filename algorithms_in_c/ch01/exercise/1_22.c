#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 1000000

int sum = 0;

void process(int* id,int i,int j) {
	if(i == j) return;
	for(;i!=id[i];i=id[i]);
	for(;j!=id[j];j=id[j]);
	if(i == j) return;
	id[i] = j;
	sum++;
}

int main() {
	int id[N];
	for(int i=0;i<N;i++)
		id[i] = i;
	srand(time(NULL));
	for(int n=0;n<N-1;n++) {
		int i = rand()%N;
		int j = rand()%N;
		process(id,i,j);
	}
	printf("sum of edges: %d \n",sum);
	return 0;
}
