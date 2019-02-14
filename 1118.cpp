#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

int n,sum,use[12345]= {0},pc[10010],ans[10010];

int dfs(int i,int num,int cnt)
{
	if(cnt>sum)
		return 0;
	if(i==n) {
		if(cnt==sum) {
			ans[i]=num;
			return 1;
		} else return 0;
	}
	use[num]=1;
	for(int j=1; j<=n; j++) {
		if(!use[j]) {
			if(dfs(i+1,j,cnt+pc[i]*j)) {
				ans[i]=num;
				return 1;
			}
		}
	}
	use[num]=0;
	return 0;
}

int main()
{
	scanf("%d%d",&n,&sum);
	pc[0]=pc[n-1]=1;
	for(int i=1; i*2<n; i++)
		pc[i]=pc[n-i-1]=(n-i)*pc[i-1]/i;

	if(dfs(0,0,0))
		for (int j=1; j<=n; j++)
			printf("%d ",ans[j]);

	return 0;
}
