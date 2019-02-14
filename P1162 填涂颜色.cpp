#include<cstdio>
#include<cstring>

int n,G[50][50],fl[50][50],vis[50][50]={0};

int h[]={0,-1,1,0,0},l[]={0,0,0,-1,1};

int dfs(int x,int y){
	if(G[x][y]==-1)return -1;
	if(fl[x][y]!=1)return fl[x][y];
	for(int i=1;i<=4;i++){
		int tagx=x+h[i],tagy=y+l[i];
		if(G[tagx][tagy]!=1&&!vis[tagx][tagy]){
			vis[tagx][tagy]=1;
			fl[x][y]=dfs(tagx,tagy);
			vis[tagx][tagy]=0;
		}
	}
}

int main(){
	memset(G,-1,sizeof(G));
	memset(fl,1,sizeof(fl));
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			scanf("%d",&G[i][j]);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(G[i][j]!=1){
				vis[i][j]=1;
				dfs(i,j);
			}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(fl[i][j]==1)G[i][j]=2;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)
			printf("%d ",fl[i][j]);
		printf("\n");
	}
	return 0;
} 
