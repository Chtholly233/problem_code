#include<cstdio>
#include<algorithm>
using namespace std;

int f[1001][1001],n,ans=0;

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=i;j++)
			scanf("%d",&f[i][j]);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=i;j++)
			f[i][j]=max(f[i-1][j-1]+f[i][j],f[i-1][j]+f[i][j]);
	for(int i=1;i<=n;i++)
		ans=max(ans,f[n][i]);
	printf("%d",ans);
	return 0;
}
