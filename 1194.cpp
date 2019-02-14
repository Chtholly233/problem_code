#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
using namespace std;

int a,b,family[510];

struct edge{
	int u,v,w;
}e[134750];

int cmp(edge aa,edge bb){
	return aa.w<bb.w;
}

int m=0;
void build(int u,int v,int w){
	m++;
	e[m].u=u;e[m].v=v;e[m].w=w;
}

int find(int x){
	if(family[x]==x)return x;
	return family[x]=find(family[x]);
}

int ans=0,tot=0;
int main(){
	scanf("%d%d",&a,&b);
	for(int i=1;i<=b;i++)
		for(int j=1;j<=b;j++){
			int k;
			scanf("%d",&k);
			if(k!=0&&i<j)build(i,j,k);
		}
	for(int i=1;i<=b;i++)
		build(0,i,a);
	for(int i=0;i<=b;i++)
		family[i]=i;
	sort(e+1,e+m+1,cmp);
	for(int i=1;i<=m;i++){
		int f1=find(e[i].u),f2=find(e[i].v);
		if(f1!=f2){
			family[f1]=f2;
			ans+=e[i].w;
			tot++;
			if(tot==b)
				break;
		}
	}
	printf("%d",ans);
	return 0;
}
