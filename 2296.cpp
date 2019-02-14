#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<queue>
using namespace std;
const int MAXN = 10010,MAXM = 200010,INF = 2147483647;
#define makenode(name,uu,dd); node name;name.u=(uu);name.d=(dd);

int N,M,S,T,first[MAXN],dis[MAXN];

struct edge{
	int u,v,next;
}e[MAXM];

inline int read(){
	int x=0,w=1;char c=getchar();
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

int mm=0;
void insert(int u,int v){
	++mm;e[mm].u=u;e[mm].v=v;e[mm].next=first[u];first[u]=mm;
}

int tcan[MAXN]={0},can[MAXN];
void bj(int n){
	tcan[n]=1;
	for(int i=first[n];i!=-1;i=e[i].next){
		int v=e[i].v;
		if(!tcan[v])bj(v);
	}
}

void start(){
	bj(T);
	memcpy(can,tcan,sizeof(tcan));
	for(int u=1;u<=N;u++)
		if(!tcan[u])
			for(int i=first[u];i!=-1;i=e[i].next)
				can[e[i].v]=0;
}

struct node{
	int u,d;
	bool operator <(const node &cmpp) const{
		return d>cmpp.d;
	}
};

void solve(){
	dis[T]=0;
	queue<int> q;
	q.push(T);
    while(!q.empty()){
        int no=q.front();
        q.pop();
        for(int i=first[no];i!=-1;i=e[i].next)
            if(can[e[i].v]){
                q.push(e[i].v);
                can[e[i].v]=0;
                dis[e[i].v]=dis[no]+1;
            }
    }
}

void print(){
	if(dis[S]==INF)printf("-1");
	else printf("%d",dis[S]);
}

int main(){
	memset(first,-1,sizeof(first));
	memset(dis,INF,sizeof(dis));
	N=read();M=read();
	for(int i=1;i<=M;i++){
		int u=read(),v=read();
		if(u!=v)insert(v,u);
	}
	S=read();T=read();
	start();
	solve();
	print();
	return 0;
} 
