#include <stdio.h>

#define N 10000
//慢速合并
//每次合并树,将被合并树(高为2)的所有的节点flat化(高为1),并作为合并树的子节点而合并入合并树
//由于没有只有 子->父 关系 (即id[子]=父),而flat过程是 父->子 的过程,所以需要遍历整个id数组
main() {
	int i,p,q,t,id[N];
	for(i=0;i<N;i++) id[i] = i;
	while(scanf("%d %d",&p,&q) == 2)
	{
		if(id[p] == id[q]) continue;
		for(t = id[p],i=0;i<N;i++) {
			if(id[i] == t) id[i] == id[q];
		}
		printf("%d %d\n",p,q);
	}
}
