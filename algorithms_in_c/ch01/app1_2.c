#include <stdio.h>

#define N 10000
//快速合并
//被合并树未flat,被合并树的根节点作为合并树根节点的子节点合并入合并树
//所以树的高度不会像慢速合并一定小于等于2
//缺点:导致树的高度在最坏的情况是n (n为 输入(p,q)的组数)
main() {
    int i,j,p,q,id[N];
	for(i=0;i<N;i++) id[i] = i;
    while(scanf("%d %d",&p,&q) == 2)
    {
        for(i=p;i!=id[i];i=id[i]);
        for(j=q;j!=id[j];j=id[j]);
        if(i == j) continue;
        id[i] = j;
        printf("%d %d\n",p,q);
    }
}