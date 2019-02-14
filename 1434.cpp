#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
using namespace std;

inline int read(){
	char c=getchar();int x=0,w=1;
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

int r,c,G[101][101],mem[101][101]={0},ans=0;

int nx[]={-1,1,0,0},ny[]={0,0,-1,1};

int dfs(int x,int y){
	if(mem[x][y])return mem[x][y];
	int flag=1;
	for(int kk=0;kk<4;kk++){
		int tagx=x+nx[kk],tagy=y+ny[kk];
		if(tagx>=1&&tagx<=r&&tagy>=1&&tagy<=c&&G[x][y]>G[tagx][tagy]){
			flag=max(dfs(tagx,tagy)+1,flag);
		}
	}
	mem[x][y]=flag;
	return flag;
}

int main(){
	r=read();c=read();
	for(int i=1;i<=r;i++)
		for(int j=1;j<=c;j++)
			G[i][j]=read();
	for(int i=1;i<=r;i++)
		for(int j=1;j<=c;j++){
			mem[i][j]=dfs(i,j);
			ans=max(ans,mem[i][j]);
		}
	printf("%d\n",ans);
	return 0;
} 
