#include<stdio.h>

int n,sum,ans[20];

int i;

bool dfs(int _n,int resut){
	if(_n=n+1){
		return 1;	
	}
	else{
		for(i=0;i<resut;i++){
			if(i+ans[_n-1]==resut){
				ans[_n]=i;
				dfs(_n+1,i);
				ans[_n]=0;
			}
			else{
				return 0;
			}
		}
	}
}

int main(){
	scanf("%d%d",&n,&sum);
	for(int i=1;i<n;i++){
		if(dfs(i,n)){
			for(int j=1;j<=n;j++){
				printf("%d ",ans[j]);
			}
		}
	}
	return 0;
}
