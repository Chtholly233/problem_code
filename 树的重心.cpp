/*
���ĵ����ʣ�

���� 1 ���������е㵽ĳ����ľ�����У������ĵľ��������С�ģ�������������ģ������ǵľ����һ����

���� 2 ����������ͨ��ĳһ�������õ�һ���µ������µ��������ı�Ȼ������ԭ�����������ĵ�·���ϡ�

���� 3 ��һ������ӻ���ɾ��һ���ڵ㣬�����������ֻ�ƶ�һ���ߵ�λ�á�
*/

//�������� 

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


