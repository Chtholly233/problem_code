#include<cstdio>
#include<queue>
#include<string.h>
using namespace std;

#define max 10010
#define INF 2147483647

int m,n,s,first[max],dist[max];
struct Edge{
	int u,v,w,next;
}edge[max];

struct node{
	int num,dist;
	bool operator()(node n1,node n2){
		return n1.dist>n2.dist;
	}
};

priority_queue<node> q;

int tot=0;
void addedge(int u,int v,int w){
	edge[++tot].u=u;edge[tot].v=v;edge[tot].w=w;edge[tot].next=first[u];first[u]=tot;
}

void dijkstra(){
	memset(dist,INF,sizeof(dist));
	dist[s]=0;
	node nn;
	nn.dist=0;nn.num=s;
	q.push(nn);
	while(q.empty()){
		node n=q.top();
		q.pop();
		if(n.dist!=dist[n.num])continue;
		for(int i=first[n.num];i>=0;i=edge[i].next){
			if(dist[n.num]+edge[i].w<dist[edge[i].v]){
				dist[edge[i].v]=dist[n.num]+edge[i].w;
				nn.dist=dist[edge[i].v];nn.num=edge[i].v;
				q.push(nn);
			}
		}
	}
}

int main(){
	scanf("%d%d",&n,&m);
	memset(first,-1,sizeof(first));
	int X,Y,Z;
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&X,&Y,&Z);
		addedge(X,Y,Z);
	}
	dijkstra();
	for(int i=1;i<=n;i++)
		printf("%d ",dist[i]);
	return 0;
}
