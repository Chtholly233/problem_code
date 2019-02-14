#include<cstdio>

int n,ans=0,f[1001]={0};

int dfs(int x){
	if(f[x])return f[x];
	f[x]++;
	for(int i=1;i<=x/2;i++){
		f[x]+=dfs(i);
	}
	return f[x];
}

int main(){
	scanf("%d",&n);
	dfs(n);
	printf("%d",ans);
	return 0;
}
