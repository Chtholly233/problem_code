#include<cstdio>
#include<cstring>
using namespace std;

int n,m,t,ans=0,map[10][10],vis[10][10],sx,sy,tx,ty;

int walkx[]={0,-1,1,0,0},walky[]={0,0,0,-1,1};

void dfs(int x,int y){
	if(x==tx&&y==ty){
		ans++;return;
	}
	
	for(int kk=1;kk<=4;kk++){
		int ttx=x+walkx[kk],tty=y+walky[kk];
		if(map[ttx][tty]&&!vis[ttx][tty]&&ttx<=n&&tty<=m&&ttx>=1&&tty>=1){
			vis[ttx][tty]=1;
			dfs(ttx,tty);
			vis[ttx][tty]=0;
		}
	}
}

int main(){
	memset(map,1,sizeof(map));
	memset(vis,0,sizeof(vis));
	scanf("%d%d%d%d%d%d%d",&n,&m,&t,&sx,&sy,&tx,&ty);
	int xx, yy;
	for(int i=1;i<=t;i++){
		scanf("%d%d",&xx,&yy);
		map[xx][yy]=0;
	}
	vis[sx][sy]=1;
	dfs(sx,sy);
	printf("%d",ans);
	return 0;
} 
