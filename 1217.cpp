#include<cstdio>

int a,b;

int isp(int x){
	for(int i=2;i*i<x;i++)
		if(x%i==0)return 0;
	return 1;
}

int ish(int x){
	int c=x,d=0;
	while(c){
		d=d*10+c%10;
		c/=10; 
	}
	if(d==x)return 1;
	return 0;
}

int main(){
	scanf("%d%d",&a,&b);
	for(int i=a;i<=b;i++){
		if(isp(i)&ish(i))printf("%d\n",i);
	}
	return 0;
}
