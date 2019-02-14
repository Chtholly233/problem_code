#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
using namespace std;

long long m,n,hx,hy;
long long f[20][20]={0},G[20][20]={0};

int main(){
	scanf("%lld%lld%lld%lld",&n,&m,&hx,&hy);
	f[0][0]=1;
	G[hx][hy]=G[hx-1][hy+2]=G[hx+1][hy+2]=G[hx+2][hy+1]=G[hx+2][hy-1]=G[hx+1][hy-2]=G[hx-1][hy-2]=G[hx-2][hy-1]=G[hx-2][hy+1]=1;
	for(int i=0;i<=n;i++){
		for(int j=0;j<=m;j++){
			if(!G[i][j]){
				if(i)f[i][j]+=f[i-1][j];
				if(j)f[i][j]+=f[i][j-1];
			}
		}
	}
	printf("%lld",f[n][m]);
	return 0;
}
