#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
using namespace std;

//#define debug

int n,m,G[101][101],family[101][101],ans=0;

int nx[]={-1,1,0,0},ny[]={0,0,-1,1};

void dfs(int x,int y,int fami){
	family[x][y]=fami;
	for(int dir=0;dir<4;dir++){
		int tagx=x+nx[dir],tagy=y+ny[dir];
		if(G[tagx][tagy]!=0&&family[tagx][tagy]==0&&tagx>0&&tagx<=n&&tagy>0&&tagy<=m){
			dfs(tagx,tagy,fami);
		}
	}
}

int main(){
	scanf("%d%d\n",&n,&m);
	
	char s[201];
	for(int i=1;i<=n;i++){
		gets(s);
		for(int j=1;j<=m;j++)
			G[i][j]=s[j-1]-'0';
	}
	
	/*
	//**error insert**
	char c;
	for(int i=1;i<=n;i++){
		c=getchar();
		for(int j=1;j<=m;j++){
			c=getchar();
			G[i][j]=c-'0';
		}
	}*/
	memset(family,0,sizeof(family));
	#ifdef debug
		printf("%d\n",G[1][1]);
	#endif
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(family[i][j]==0&&G[i][j]!=0){
				ans++;
				dfs(i,j,ans);
			}
	printf("%d\n",ans);
	#ifdef debug
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++)
				printf("%d",family[i][j]);
			printf("\n");
		}
	#endif
	return 0;
} 
