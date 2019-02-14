
//Ê÷µÄÖ±¾¶
 
#include<bits/stdc++.h>
const int N=1000010;
using namespace std;
int n,m,head[N],tot,dis[N],cur,mx;
inline int read(){
	int f=1,x=0;char ch;
	do{ch=getchar();if(ch=='-')f=-1;}while(ch<'0'||ch>'9');
	do{x=x*10+ch-'0';ch=getchar();}while(ch>='0'&&ch<='9');
	return f*x;
}
struct Edge{
	int u,v,w,next;
}G[N<<1];
inline void addedge(int u,int v,int w){
	G[++tot].u=u;G[tot].v=v;G[tot].w=w;G[tot].next=head[u];head[u]=tot;
	G[++tot].u=v;G[tot].v=u;G[tot].w=w;G[tot].next=head[v];head[v]=tot;
}
inline void dfs(int u,int fa){
	for(int i=head[u];i;i=G[i].next){
		int v=G[i].v;if(v==fa)continue;
		dis[v]=dis[u]+G[i].w;
		if(dis[v]>mx)cur=v,mx=dis[v];
		dfs(v,u);
	}
}
int main(){
	n=read();
	for(int i=1;i<n;i++){
		int u=read(),v=read(),w=read();
		addedge(u,v,w);
	}
	dfs(1,0);mx=0;memset(dis,0,sizeof(dis));
	dfs(cur,0);
	printf("%d\n",mx); 
}
