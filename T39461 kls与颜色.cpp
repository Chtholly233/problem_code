#define MAXN 1001
#include<stdio.h>

int n,c[MAXN],ans=0,now=-1;

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){scanf("%d",&c[i]);}
	for(int i=1;i<=n;i++){
		if(c[i]==now){continue;}
		else{now=c[i];ans++;}
		if(i==n&&c[1]==c[i]&&ans!=1) ans--;
	}
	printf("%d",ans);
	return 0;
} 
