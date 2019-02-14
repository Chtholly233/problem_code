#include<vector>
#include<stdio.h>
#define MAXN 233333
using namespace std;
struct edge{
	int v,w;
};
vector <edge> e[MAXN];
inline void insert(int _u,int _v,int _w){
	e[_u].push_back({_v,_w}); //如果是无向图，则要改为 e[u].push_back({v,w});e[v].push_back({u,w});
}
int n,m;
int main(){
	scanf("%d%d",&n,&m);
	int u,v,w;
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&u,&v,&w);
		insert(u,v,w);
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<e[i].size();j++){
			printf("%d %d %d\n",i,e[i][j].v,e[i][j].w);
		}
	}
	return 0;
} 
