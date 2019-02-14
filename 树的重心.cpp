/*
重心的性质：

性质 1 ：树中所有点到某个点的距离和中，到重心的距离和是最小的，如果有两个重心，到他们的距离和一样。

性质 2 ：把两棵树通过某一点相连得到一颗新的树，新的树的重心必然在连接原来两棵树重心的路径上。

性质 3 ：一棵树添加或者删除一个节点，树的重心最多只移动一条边的位置。
*/

//树的重心 

#include<bits/stdc++.h>
const int N=1000010;
const int inf=0x7f7f7f7f;
using namespace std;
int f[N],size[N],n,head[N],tot;
int rt,sum;
vector<int> G[N];
void addedge(int u,int v){
	G[u].push_back(v);
	G[v].push_back(u);
}
inline void getrt(int u,int fa){
	size[u]=1;f[u]=0;
	for(int i=0;i<G[u].size();i++){
		int v=G[u][i];if(v==fa)continue;
		getrt(v,u);
		size[u]+=size[v];
		f[u]=max(f[u],size[v]);
	}
	f[u]=max(f[u],sum-size[u]);
	if(f[u]<f[rt])rt=u;
}
inline int read(){
	int f=1,x=0;char ch;
	do{ch=getchar();if(ch=='-')f=-1;}while(ch<'0'||ch>'9');
	do{x=x*10+ch-'0';ch=getchar();}while(ch>='0'&&ch<='9');
	return f*x;
}
int main(){
	n=read();
	for(int i=1;i<n;i++){
		int u=read(),v=read();
		addedge(u,v);
	}
	rt=0;sum=n;f[0]=inf;getrt(1,0);
	printf("%d\n",rt);
	return 0;
}


