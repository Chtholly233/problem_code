#include<stdio.h>
int main(){
	int n=100,i,a,ans[105]={0};
	for(a=2;a<=100;a++){
		if(ans[a]==0){
			printf("%d ",a);
			for(i=2;i*a<=n;i++)
			    ans[i*a]=1;
		}
	}
	return 0;
}
