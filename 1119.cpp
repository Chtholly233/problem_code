#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#define MAXN 210
#define MAXQ 500010
using namespace std;

int dis[MAXN][MAXN],n,m,t[MAXN],q;
int u[MAXQ],v[MAXQ],qwq[MAXQ];
int b[MAXN]={0};

int read(){
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

int main(){
	//freopen("in.in","r",stdin);
	memset(dis,0x7f7f7f7f,sizeof(dis));
	n=read();m=read();
	for (int i=0; i<n; i++)
		dis[i][i]=0;
	for(int i=0;i<n;i++)
		t[i]=read();
	for(int i=1;i<=m;i++){
		int ua=read(),va=read(),wa=read();
		dis[ua][va]=dis[va][ua]=wa;
	}
	q=read();
	for(int i=1;i<=q;i++){
		u[i]=read();v[i]=read();qwq[i]=read();
	}
	for(int kkk=1;kkk<=q;kkk++){
		for(int k=0;k<n;k++)
			if(t[k]<=qwq[kkk]&&!b[k]){
				b[k]=1;
				for(int i=0; i<n; i++)
					for(int j=0; j<n; j++) 
						if(dis[i][j]>dis[i][k]+dis[k][j]&&i!=j&&k!=i&&k!=j&&dis[i][k]<0x7f7f7f7f&&dis[k][j]<0x7f7f7f7f)
							dis[i][j]=dis[i][k]+dis[k][j];
			}
		if(t[u[kkk]]<=qwq[kkk]&&t[v[kkk]]<=qwq[kkk]&&dis[u[kkk]][v[kkk]]!=0x7f7f7f7f)printf("%d\n",dis[u[kkk]][v[kkk]]);
		else printf("-1\n");
	}
	return 0;
}
