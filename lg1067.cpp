#include<stdio.h>

int n;

int main(){
	scanf("%d",&n);
	int x[n],i;
	for(i=0;i<=n;i++){
		scanf("%d",&x[i]);
	}
	for(i=0;i<=n;i++){
		if(x[i]==0) continue ;
		else{
			if(x[i]==-1&&i!=n) printf("-");
			if(i!=0&&x[i]>0) printf("+");
			if((x[i]!=1&&x[i]!=-1)||i==n) printf("%d",x[i]);
			if(i!=n&&i!=n-1) printf("x^%d",n-i);
			if(i==n-1) printf("x");
		}
	}
	return 0;
}
