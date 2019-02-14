#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<queue>
using namespace std;
const int MAXN = 1010,MAXM = 100010;
const int INF = 0x3f;

int n,m,first1[MAXN],dis[MAXN],first2[MAXN]; ;
int ans=0;

void comput(){
	for(int i=1;i<=n;i++)
		ans+=dis[i];
}

inline int read(){
	int x=0,w=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')w=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<3)+(x<<1)+c-'0';
		c=getchar();
	}
	return x*w;
}

struct edge{
	int u,v,w,next;
}e1[MAXM],e2[MAXM];

struct node{
	int u,dis;
	int operator <(const node &qwq) const{
		return dis>qwq.dis;
	}
};

int qwq=0;
void insert1(int u,int v,int w){
	++qwq;e1[qwq].u=u;e1[qwq].v=v;e1[qwq].w=w;e1[qwq].next=first1[u];first1[u]=qwq;
}

int tt=0;
void insert2(int u,int v,int w){
	++tt;e2[tt].u=u;e2[tt].v=v;e2[tt].w=w;e2[tt].next=first2[u];first2[u]=tt;
}


void dijkstra(int first[],edge e[]){
	priority_queue<node> q;
	node start;start.u=1;start.dis=0;
	dis[1]=0;
	q.push(start);
	while(!q.empty()){
		node fr=q.top();
		q.pop();
		int u=fr.u,d=fr.dis;
		if(d!=dis[u])continue;
		for(int i=first[u];i!=-1;i=e[i].next){
			int v=e[i].v,w=e[i].w;
			if(dis[v]>dis[u]+w){
				dis[v]=dis[u]+w;
				node rxz;rxz.dis=dis[v];rxz.u=v;
				q.push(rxz);
			}
		}
	}
}

int main(){
	memset(first1,-1,sizeof(first1));memset(first2,-1,sizeof(first2));
	memset(dis,INF,sizeof(dis));
	n=read();m=read();
	for(int i=1;i<=m;i++){
		int u=read(),v=read(),w=read();
		insert1(u,v,w);
		insert2(v,u,w);
	}
	dijkstra(first1,e1);
	comput();
	memset(dis,INF,sizeof(dis));
	dijkstra(first2,e2);
	comput();
	printf("%d\n",ans);
	return 0;
}
