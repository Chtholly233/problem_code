#include<cstdio>
#include<queue>
using namespace std;

int ans=0,k[201],a,b,n,vis[201]={0},found=0,path[10010];

/*void printo(){
	found=1;
	for(int i=b;i!=-1;i=path[b]){
		ans++;
	}
	printf("%d",ans);
}*/

void bfs(){
	int d[201]={0}; 
	queue<int>q;
	q.push(a);
	//path[a]=-1;
	while(!q.empty()){
		int nn=q.front();q.pop();
		int up=nn+k[nn],down=nn-k[nn];
		if(nn==b){printf("%d",d[b]);found=1;break;}
		if(vis[up]==0&&up>=1&&up<=n){
			vis[up]=1;q.push(up);d[up]=d[nn]+1;
		}
		if(vis[down]==0&&down>=1&&down<=n){
			vis[down]=1;q.push(down);d[down]=d[nn]+1;
		}
	}
}

int main(){
	scanf("%d%d%d",&n,&a,&b);
	for(int i=1;i<=n;i++)
		scanf("%d",&k[i]);
	bfs(); 
	if(!found)printf("-1");
} 
