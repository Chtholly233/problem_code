#include<stdio.h>
int dfs(int i){
	if(i==0){
		return 1;
	}

	else{
		return dfs(i-1)*i; //
	}
}
int main(){
	int a;
	scanf("%d",&a);
	printf("%d\n",dfs(a));
	return 0;
}
