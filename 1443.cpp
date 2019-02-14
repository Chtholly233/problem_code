#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;

int dist[401][401],n,m,sx,sy;

int nx[]={-2,-1,1,2,2,1,-1,-2},ny[]={1,2,2,1,-1,-2,-2,-1};

struct Node{
	int x,y;
};

int main(){
	scanf("%d%d%d%d",&n,&m,&sx,&sy);
	queue<Node> q;
	q.push((Node){sx,sy});
	memset(dist,-1,sizeof(dist));
	dist[sx][sy]=0;
	while(!q.empty()){
		Node fr=q.front();q.pop();
		int x=fr.x,y=fr.y;
		for(int dir=0;dir<8;dir++){
			int tagx=x+nx[dir],tagy=y+ny[dir];
			if(dist[tagx][tagy]==-1&&tagx>0&&tagx<=n&&tagy>0&&tagy<=m){
				//if(dist[tagx][tagy]<dist[x][y]+1){
					dist[tagx][tagy]=dist[x][y]+1;
					q.push((Node){tagx,tagy});
				//}
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			printf("%-5d",dist[i][j]);
		}
		printf("\n");
	}
	return 0;
}
