#include<stdio.h>

int n,x=1;

void dfs(int n,char a,char b,char c){
	if(n==1){
		printf("%d.Move %d from %c to %c\n",x++,n,a,c);
	    return;
	}
	else{
		dfs(n-1,a,c,b);
		printf("%d.Move %d from %c to %c\n",x++,n,a,c);
		dfs(n-1,b,a,c);
        return;
	}
		
	     
}

int main(){
	scanf("%d",&n);
    dfs(n,'a','b','c');
	return 0;
}