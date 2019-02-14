#include<stdio.h>

int n,k;

int dfs(int blood,int maxblood){
	int i=0;
	while(blood>=maxblood/2){blood-=k;i++;}
	if(blood<=0){return i;}
	else{return 2*(dfs(blood,blood)+i);}
}

int main(){
	scanf("%d%d",&n,&k);
	printf("%d",dfs(n,n));
	return 0;
} 
