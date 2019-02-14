#include<cstdio>
#include<cmath>

char a[30],b[30],c[30];
int n,ans[30],ar=0,cr=0;

int rnum(char _c){
	return _c-'A';
}

int dfs(int x,int y,int num){
	if(x==n){
		for(int i=n-1;i>=0;i--){
			ar+=ans[a[i]]*(int)pow(n,i-n+1)+
			    ans[b[i]]*(int)pow(n,i-n+1);
			cr+=ans[c[i]]*(int)pow(n,i-n+1);
		}
		if(ar==cr){
			return 1;
		} 
		return 0;
	}else{
		
	}
}

int main(){
	scanf("%d",&n);
	gets(a);
	gets(b);
	gets(c);
    
	return 0;
} 


