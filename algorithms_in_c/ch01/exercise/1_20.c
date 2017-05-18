#include <stdio.h>
#define N 10000
int main() {
	int i,j,id[N],ht[N];
	for(i=0;i<N;i++) {
		id[i] = i;
		ht[i] = 1;
	}

	while(scanf("%d %d",&i,&j) == 2) {
		for(;i!=id[i];i=id[i]);
		for(;j!=id[j];j=id[j]);
		if(ht[i] > ht[j]) {
			id[j] = i;
			ht[i] += ht[j];
		} else {
			id[i] = j;
			ht[j] += ht[i];
		}
	}
	return 0;
}
