#include<stdio.h>

int u[10001],v[10001],w[10001],n,m,first[10001],next[10001];

int main(){
	scanf("%d %d",&n,&m);
	int i;
	for(i=1;i<=n;i++)
	    first[i]=-1;
	for(i=1;i<=m;i++){
		scanf("%d %d %d",&u[i],&v[i],&w[i]);
		
		//把这条线插入到第一个和第二个之间  
		next[i]=first[u[i]]; 
		first[u[i]]=i;
	
	}
	int k;
	for(i=1;i<=n;i++){
		k=first[i];
		while(k!=-1){
			printf("%d %d %d\n",u[k],v[k],w[k]);
			k=next[k];
		}
	}
	return 0;
} 
