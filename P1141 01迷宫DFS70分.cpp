//LG1141 01√‘π¨ DFS 70∑÷ 
#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;

int n,m,G[10010][10010],vis[10010][10010];
int walkx[]={-1,1,0,0},walky[]={0,0,-1,1};

void startvis(){
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			vis[i][j]=0;
}

int dfs(int x,int y){
	int tagx,tagy,w=1;
	for(int dir=0;dir<4;dir++){
		tagx=x+walkx[dir];tagy=y+walky[dir];
		if(!vis[tagx][tagy]&&G[tagx][tagy]!=G[x][y]&&G[tagx][tagy]!=-1){
			vis[tagx][tagy]=1;
			w+=dfs(tagx,tagy);
		}
	}
	return w;
}

int main(){
	//freopen("testdata.in","r",stdin);
	//freopen("test.out","w",stdout); 
	
	memset(G,-1,sizeof(G));
	scanf("%d%d",&n,&m);
	char c;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin>>c;
			G[i][j]=c-'0';
		}
	}
	
	int askx,asky,max;
	for(int t=1;t<=m;t++){
		scanf("%d%d",&askx,&asky);
		startvis();
		vis[askx][asky]=1;
		max=dfs(askx,asky);
		printf("%d\n",max);
	}
	return 0;
} 
