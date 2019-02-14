#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
int n,ans,lie[30],f1[30],f2[30],sum[30];
vector<int> a[30];
int x[30];
void dfs(int hang){
	if(hang==n+1){
	    ans++;
	    for(int i=1;i<=n;i++){
	    	a[i].push_back(x[i]);
			a[i].push_back(n-x[i]+1);
	    }
		return;
	}
    for(int i=1;i<=n;i++)
			if(lie[i]&&f1[i+hang]&&f2[i-hang+15]){
				x[hang]=i;
				lie[i]=f1[i+hang]=f2[i-hang+15]=0;
				dfs(hang+1);
				lie[i]=f1[i+hang]=f2[i-hang+15]=1;
			}
}

int main(){
	scanf("%d",&n);
	memset(lie,1,sizeof(lie));
	memset(f1,1,sizeof(f1));
	memset(f2,1,sizeof(f2));
	for(int i=1;i<=(n+1)/2;i++){
		x[1]=i;
		ans=0;
		lie[i]=f1[i+1]=f2[i-1+15]=0;
		dfs(2);
		lie[i]=f1[i+1]=f2[i-1+15]=1;
		sum[i]=ans;
	}
	ans=0;
	for(int i=1;i<=n;i++){
	    if(i<=(n+1)/2)ans+=sum[i];
	    else ans+=sum[n-i+1];
	}
	for(int i=0;i<100;i++){  ////
		for(int j=1;j<=n;j++)
		    printf("%d ",a[j][i]);
		printf("\n");
	}
	printf("%d",ans);
	return 0;
} 
