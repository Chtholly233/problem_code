#include<cstdio>

int sum=0,n,x[10001]={0},f1[10001]={0},f2[10001]={0},ans[14];

void dfs(int my){
	if(my>n){
		sum++;
		if(sum>3)return;
		
		for(int j=1;j<=n;j++){
			printf("%d ",ans[j]);
		}
		printf("\n");
		return;
	}
	for(int mx=1;mx<=n;mx++){
		if((!x[mx])&&(!f1[mx+my])&&(!f2[my-mx+1000])){
			x[mx]=f1[mx+my]=f2[my-mx+1000]=1;
			if(sum<=3)ans[my]=mx;
			dfs(my+1);
			x[mx]=f1[mx+my]=f2[my-mx+1000]=0;
		}
	}
}

int main(){
	scanf("%d",&n);
	dfs(1);
	printf("%d",sum);
	return 0;
}
