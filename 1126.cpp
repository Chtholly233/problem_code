#include<cstdio>
#include<queue>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;

int n,m,G[60][60]= {0},sx,sy,tx,ty,sdir,vis[60][60][10]= {0},ans=25000,visp[60][60]= {0};

struct Point {
	int x,y,dir,dis;
};

void walk(int x,int y,int steps,int dir,int &tagx,int &tagy)
{
	switch(dir) {
		case 0: {
			tagx=x;
			tagy=y+steps;
			break;
		}
		case 1: {
			tagx=x+steps;
			tagy=y;
			break;
		}
		case 2: {
			tagx=x;
			tagy=y-steps;
			break;
		}
		case 4: {
			tagx=x-steps;
			tagy=y;
			break;
		}
	}
}

int main()
{
	scanf("%d%d",&n,&m);
	int tt;
	for(int i=1; i<=n; i++)
		for(int j=1; j<=m; j++) {
			scanf("%d",&tt);
			if(tt==1) {
				G[i][j]=G[i+1][j]=G[i][j+1]=G[i+1][j+1]=1;
			}
		}
	scanf("%d%d%d%d",&sx,&sy,&tx,&ty);
	++sx;
	++sy;
	++tx;
	++ty;
	char c;
	cin>>c;
	switch(c) {
		case 'E': {
			sdir=0;
			break;
		}
		case 'S': {
			sdir=1;
			break;
		}
		case 'W': {
			sdir=2;
			break;
		}
		case 'N': {
			sdir=3;
			break;
		}
	}

	queue<Point> q;
	q.push((Point) {
		sx,sy,sdir,0
	});
	vis[sx][sy][sdir]=1;
	visp[sx][sy]=1;
	int found=0;
	while(!q.empty()) {
		Point fr=q.front();
		q.pop();
		int tagx,tagy,tagdir;
		/*if(fr.x==tx&&fr.y==ty){
			ans=min(ans,fr.dis);
			found=1;
		}*/
		for(int kk=1; kk<=5; kk++) {
			if(kk==1) {
				tagx=fr.x;
				tagy=fr.y;
				tagdir=fr.dir-1;
				if(tagdir<0)tagdir=3;
				if(!vis[tagx][tagy][tagdir]) {
					q.push((Point) {
						tagx,tagy,tagdir,fr.dis+1
					});
					visp[tagx][tagy]=vis[tagx][tagy][tagdir]=1;
				}
			}
			if(kk==2) {
				tagx=fr.x;
				tagy=fr.y;
				tagdir=fr.dir+1;
				if(tagdir>3)tagdir=0;
				if(!vis[tagx][tagy][tagdir]) {
					q.push((Point) {
						tagx,tagy,tagdir,fr.dis+1
					});
					visp[tagx][tagy]=vis[tagx][tagy][tagdir]=1;
				}
			}
			if(kk>2) {
				int steps=kk-2;
				tagdir=fr.dir;
				walk(fr.x,fr.y,steps,tagdir,tagx,tagy);
				if(tagx==tx&&tagy==ty) {
					ans=min(ans,fr.dis);
					found=1;
				}
				if(!vis[tagx][tagy][tagdir]&&!G[tagx][tagy]&&tagx>1&&tagx<=n&&tagy>1&&tagy<=m) {
					//printf("%d,%d\n",tagx,tagy);//
					vis[tagx][tagy][tagdir]=visp[tagx][tagy]=1;
					q.push((Point) {
						tagx,tagy,tagdir,fr.dis+1
					});
				}
			}
		}
	}
	if(!found)printf("-1");
	else printf("%d\n",ans);
	return 0;
}
