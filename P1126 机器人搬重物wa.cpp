//【洛古1126】机器人搬重物
#include<cstdio>
#include<queue>
#include<algorithm>
#include<cstring>
using namespace std;

int n,m,G[51][51],sx,sy,sdir,tx,ty,ans=0,vis[51][51][4]= {0},minn=2147483647,flag=0;

int pathx[10010],pathy[10010];

int walk(int x,int y,int dir,int steps,int &tagx,int &tagy)
{
	//计算走steps步之后的坐标
	if(dir==0) {
		tagx=x;
		tagy=y+steps;
	}
	if(dir==1) {
		tagx=x+steps;
		tagy=y;
	}
	if(dir==2) {
		tagx=x;
		tagy=y-steps;
	}
	if(dir==3) {
		tagx=x-steps;
		tagy=y;
	}
	if(tagx<1||tagy<1)return 0;
	return 1;
}

struct Point {
	int x,y,dir,w;
};

int main()
{
	scanf("%d%d",&n,&m);
	/*
	for(int i=0;i<=n+1;i++)
		for(int j=0;j<=m+1;j++)
			G[i][j]=1;*/
	memset(G,1,sizeof(G));
	for(int i=1; i<=n; i++)
		for(int j=1; j<=m; j++)
			scanf("%d",&G[i][j]);
	scanf("%d%d%d%d",&sx,&sy,&tx,&ty);
	char c;
	scanf("%d",&c);
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
	});//修改最小值
	vis[sx][sy][sdir]=1;
	while(!q.empty()) {
		Point fr=q.front();
		q.pop();

		if(fr.x==tx&&fr.y==ty) {
			//printf("%d\n",fr.w);
			minn=minn>fr.w?fr.w:minn;
			flag=1;
			/*printf("%d %d\n",fr.x,fr.y);//
			for(int i=1;i<=fr.w;i++){//
				printf("%d,%d\n",pathx[i],pathy[i]);//
			}//*/
			return 0;
		}

		for(int kk=1; kk<=5; kk++) { //转2个方向||走1~3步
			if(kk==1) { //trun right
				int tagdir=fr.dir+1;
				if(tagdir>3)tagdir=0;
				if(!vis[fr.x][fr.y][tagdir]) {
					q.push((Point) {
						fr.x,fr.y,tagdir,fr.w+1
					});
					vis[fr.x][fr.y][tagdir]=1;
				}
			}
			if(kk==2) { //trun left
				int tagdir=fr.dir-1;
				if(tagdir<0)tagdir=3;
				if(!vis[fr.x][fr.y][tagdir]) {
					q.push((Point) {
						fr.x,fr.y,tagdir,fr.w+1
					});
					vis[fr.x][fr.y][tagdir]=1;
				}
			}
			if(kk>2) {
				int steps=kk-2;
				int tagx,tagy;
				if(walk(fr.x,fr.y,fr.dir,steps,tagx,tagy)==0)continue;
				int x1=tagx,x2=tagx+1,x3=tagx  ,x4=tagx+1;
				int y1=tagy,y2=tagy  ,y3=tagy+1,y4=tagy+1;
				if(!vis[tagx][tagy][fr.dir]&&!(G[x1][y1]||G[x2][y2]||G[x3][y3]||G[x4][y4])) {
					//printf("\n%d %d\n",tagx,tagy);//
					//pathx[fr.w+1]=tagx;pathy[fr.w+1]=tagy;//
					q.push((Point) {
						tagx,tagy,fr.dir,fr.w+1
					});
					vis[tagx][tagy][fr.dir]=1;
				}
			}
		}
	}
	if(!flag)
		printf("-1");
	else
		printf("%d",minn);
	return 0;
}
