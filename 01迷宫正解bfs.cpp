//LG1141 01รินฌ BFS
#include<cstdio>
#include<queue>
#include<cstring>
#include<iostream>
using namespace std;

int n,m,G[10010][10010],vis[10010][10010]= {0},connt[1001][1001]= {0},ans[1000001];
int nx[]= {-1,1,0,0},ny[]= {0,0,-1,1};

struct Node {
	int x,y;
};

int main()
{
	scanf("%d%d",&n,&m);
	for(int i=0; i<=n+1; i++)
		for(int j=0; j<=n+1; j++)
			G[i][j]=-1;
	char c;
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=n; j++) {
			cin>>c;
			G[i][j]=c-'0';
		}
	}

	queue<Node> q;
	int x,y,sum,flag=0;
	for(int x=1; x<=n; x++)
		for(int y=1; y<=n; y++) {
			if(connt[x][y]==0) {
				connt[x][y]=++flag;
				/*
				for(int i=1; i<=n; i++)
					for(int j=1; j<=n; j++)
						vis[i][j]=0;
						*/
				vis[x][y]=1;
				sum=1;
				q.push((Node) {
					x,y
				});
				while(!q.empty()) {
					Node fr=q.front();
					q.pop();
					for(int dir=0; dir<4; dir++) {
						int tagx=fr.x+nx[dir],tagy=fr.y+ny[dir];
						if(!connt[tagx][tagy]&&G[fr.x][fr.y]!=G[tagx][tagy]&&G[tagx][tagy]!=-1) {
							vis[tagx][tagy]=1;
							q.push((Node) {
								tagx,tagy
							});
							sum++;
							connt[tagx][tagy]=flag;
						}
					}
				}
				ans[flag]=sum;
			}
		}
	int xx,yy;
	for(int i=1; i<=m; i++) {
		scanf("%d%d",&xx,&yy);
		printf("%d\n",ans[connt[xx][yy]]);
	}
	return 0;
}

