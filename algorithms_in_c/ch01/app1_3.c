#include <stdio.h>

#define N 10000
//加权快速合并
//为了解决app1_2的最坏情况,引入权值数组sz
//sz记录了每个节点i的子节点数sz[i]
//所以每次根据权值大小,决定哪个是被合并树,哪个是合并树
//但是最坏情况:每次合并的两颗树的高度相同,所以每次这种都会让结果树高度+1
main() {
    int i,j,p,q,id[N],sz[N];
    for(i=0;i<N;i++) {
        id[i] = i;
        sz[i] = 1;
    }

    while(scanf("%d,%d\n",&p,&q) == 2) {
        for(i=p;i!=id[i];i=id[i]);
        for(j=q;j!=id[j];j=id[j]);
        if(i == j) continue;
        if(sz[i] < sz[j])
        {
            id[i] = j;sz[j] += sz[i];
        } else {
            id[j] = i;sz[i] += sz[j];
        }
        printf("%d %d\n",p,q);
    }
}
