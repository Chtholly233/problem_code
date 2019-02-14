#include<stdio.h>
#define MAXN 2333333

struct edge{
	int to,next,w;
}e[MAXN];
int last[MAXN],cnt=1;
inline void insert(int u,int v,int w){
	cnt++;
	e[cnt].to=v;
	
	//把这条线插入到第一个和第二个之间 
	e[cnt].next=last[u];
	last[u]=cnt;
	
	e[cnt].w=w;
} 
int n,m;
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		last[i]=-1;
	}
	int u,v,w;
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&u,&v,&w);
		insert(u,v,w);
	}
	for(int i=1;i<=n;i++){
		for(int j=last[i];j!=-1;i=e[i].next){
			printf("%d %d %d",i,e[j].to,e[j].w);
		}
	}
	return 0;
} 
