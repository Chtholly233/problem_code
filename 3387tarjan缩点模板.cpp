#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
using namespace std;

const int MAXN=10010,MAXM=100010;

int n,m,ans=0,family[MAXN],fnum=0,val[MAXN],nval[MAXN]={0};
int first[MAXN];

struct edge{
    int u,v,next;
}e[MAXM];

int tot=0;
void insert(int u,int v){
    tot++;e[tot].u=u;e[tot].v=v;e[tot].next=first[u];first[u]=tot;
}

int stack[MAXN],top=0;
int deepdark=0;
int dfn[MAXN]={0},low[MAXN]={0},ins[MAXN]={0};
void tarjan(int u){
    dfn[u]=low[u]=++deepdark;
    ins[u]=1;
    top++;stack[top]=u;
    for(int i=first[u];i!=-1;i=e[i].next){
        int v=e[i].v;
        if(dfn[v]==0){
            tarjan(v);
            low[u]=min(low[u],low[v]);
        }
        else if(ins[v]){
            low[u]=min(low[u],dfn[v]);
        }
    }
    if(dfn[u]==low[u]){
        ++fnum;
        while(stack[top]!=u){
            family[stack[top]]=fnum;
            nval[fnum]+=val[stack[top]];
            ins[stack[top]]=0;
            top--;
        }
        family[u]=fnum;
        ins[u]=0;
        nval[fnum]+=val[u];
        top--;
    }
}

int f[MAXN]={0};
void search(int u){
    if(f[u])return;
    f[u]=nval[u];
    int maxsum=0;
    for(int i=first[u];i!=-1;i=e[i].next){
        int v=e[i].v;
        search(v);
        maxsum=max(maxsum,f[v]);
    }
    f[u]+=maxsum;
}

int main(){
    memset(first,-1,sizeof(first));
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d",&val[i]);
    int x,y;
    for(int i=1;i<=m;i++){
        scanf("%d%d",&x,&y);
        insert(x,y);
    }
    for(int i=1;i<=n;i++)if(dfn[i]==0)tarjan(i);
    tot=0;
    memset(first,-1,sizeof(first));
    //memset(e,0,sizeof(struct edge)*MAXM);
    for(int i=1;i<=m;i++){
        if(family[e[i].u]!=family[e[i].v]){
            insert(family[e[i].u],family[e[i].v]);
        }
    }
    for(int i=1;i<=fnum;i++){
        if(!f[i]){
            search(i);
            ans=max(ans,f[i]);
        }
    }
    printf("%d",ans);
    return 0;
}
