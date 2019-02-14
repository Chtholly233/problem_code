#include<cstdio>
#include<queue>
#define MAXM 100
#define MAXN 1000
using namespace std;

int m,n,ans=0,inm[MAXN+1]{0},full=0;
queue<int> q;

int main(){
	scanf("%d%d",&m,&n);
	int w;
	for(int i=1;i<=n;i++){
		scanf("%d",&w);
		if(!inm[w]){
			if(full){
				inm[q.front()]=0;
				q.pop();
			}
			q.push(w);
			inm[w]=1;
			ans++;
			if(q.size()>=m)full=1;
		}
	}
	printf("%d",ans);
	return 0;
} 
