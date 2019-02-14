#include<cstdio>
#include<queue>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

int n,m,t,g[32][32]= {0},ex,ey,sx,sy,tx,ty;

int dx[]= {-1,1,0,0},dy[]= {0,0,-1,1};

struct Node {
	int ex,ey,sx,sy,dist;
};

int vis[32][32][32][32]= {0};
void bfs() {
	queue<Node> q;
	Node start;
	start.ex=ex;
	start.ey=ey;
	start.sx=sx;
	start.sy=sy;
	start.dist=0;
	q.push(start);
	vis[ex][ey][sx][sy]=1;

	while(!q.empty()) {
		Node fr=q.front();
		q.pop();
		if(fr.sx==tx&&fr.sy==ty) {
			printf("%d\n",fr.dist);
			return;
		}
		for(int i=0; i<4; i++) {
			Node tag=fr;
			tag.ex=fr.ex+dx[i],tag.ey=fr.ey+dy[i];
			if(g[tag.ex][tag.ey]) {
				tag.dist++;
				if(tag.ex==fr.sx&&tag.ey==fr.sy) {
					tag.sx=fr.ex;
					tag.sy=fr.ey;
				}
				if(!vis[tag.ex][tag.ey][tag.sx][tag.sy]) {
					vis[tag.ex][tag.ey][tag.sx][tag.sy]=1;
					q.push(tag);
				}
			}
		}
	}
	printf("-1\n");
}

int main() {
	scanf("%d%d%d",&n,&m,&t);
	for(int i=1; i<=n; i++)
		for(int j=1; j<=m; j++)
			scanf("%d",&g[i][j]);
	while(t--) {
		scanf("%d%d%d%d%d%d",&ex,&ey,&sx,&sy,&tx,&ty);
		memset(vis,0,sizeof(vis));
		if(sx==tx&&sy==ty) {
			printf("0\n");
			continue;
		}
		bfs();
	}
	return 0;
}
