#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<queue>
using namespace std;
const int MAX = 500010;
//#define debug

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

int s,p,n,m,atm[MAX],ext[MAX],first[MAX],dis[MAX];

struct edge{
	int u,v,next;
}e[MAX];

int tott=0;
inline void insert(int u,int v){
	++tott;e[tott].u=u;e[tott].v=v;e[tott].next=first[u];first[u]=tott;
}

int ins[MAX],stack[MAX],top=0,low[MAX],dfn[MAX];
int family[MAX],famtot=0;
int w[MAX],jb[MAX]={0};
int deepdark=0;
void tarjan(int u){//注意处理点权，酒吧和起始点 
	low[u]=dfn[u]=++deepdark;
	stack[++top]=u;ins[u]=1;
	for(int i=first[u];i!=-1;i=e[i].next){
		int v=e[i].v;
		if(!dfn[v]){
			tarjan(v);
			low[u]=min(low[u],low[v]);
		}
		else if(ins[v]){
			low[u]=min(low[u],dfn[v]);
		}
	}
	int mcnt=0,jbb=0,isstart=0;
	if(dfn[u]==low[u]){
		++famtot;
		while(stack[top]!=u){
			int i=stack[top];--top;
			ins[i]=0;
			family[i]=famtot;
			mcnt+=atm[i];
			if(ext[i])jbb=1;
			if(i==s)isstart=1;
		}
		int i=stack[top];--top;
		ins[i]=0;
		family[i]=famtot;
		mcnt+=atm[i];
		if(ext[i])jbb=1;
		if(i==s)isstart=1;
		w[famtot]=mcnt;
		if(jbb)jb[famtot]=1;
		if(isstart)s=famtot;
	}
}

void rebuild(){
	tott=0;memset(first,-1,sizeof(first));
	for(int i=1;i<=m;i++){
        if(family[e[i].u]!=family[e[i].v]){
            insert(family[e[i].u],family[e[i].v]);
        }
    }
}

int ans=0,inq[MAX]={0};
queue<int> q;
void solve(){//最长路
	dis[s]=w[s];q.push(s);inq[s]=1;
	while(!q.empty()){
		int u=q.front();q.pop();inq[u]=0;
		for(int i=first[u];i!=-1;i=e[i].next){
			int v=e[i].v,ccf=w[e[i].v];
			if(dis[v]<dis[u]+ccf){
				dis[v]=dis[u]+ccf;
				if(jb[v])ans=max(dis[v],ans);
				//w[v]=0;
				if(!inq[v]){
					inq[v]=1;
					q.push(v);
				}
			}
		}
	}
}

int main(){
	memset(first,-1,sizeof(first));
	n=read();m=read();
	for(int i=1;i<=m;i++){
		int u=read(),v=read();
		insert(u,v);
	}
	for(int i=1;i<=n;i++)
		atm[i]=read();
	s=read();p=read();
	for(int i=1;i<=p;i++){
		int x=read();
		ext[x]=1;
	}
	for(int i=1;i<=n;i++)
		if(!dfn[i])
			tarjan(i);
	rebuild();
	solve();
	printf("%d",ans);
	return 0;
}
