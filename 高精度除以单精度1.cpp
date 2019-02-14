#include<cstdio>
#include<string.h>
#define   N  500
int division(int a[],int b,int c[]){
	int d = 0;//被除数，初始化余数为0 
	for(int i = a[0]; i >= 1 ; i--){
		d = d * 10 + a[i];//被除数=高一位的余数+本位数 
		c[i] = d / b;
		d = d % b;//储存余数 
	}
	c[0]=a[0];
	while(c[c[0]] == 0 && c[0] > 1)  
		c[0]--;  //退位 
	return d;//返回余数 
}
int main(){
	int  a[N+1] = {0}, c[N+1] = {0};
	int  i,b;
	char  s[N+1];
	scanf("%s", s);
	scanf("%d", &b);
	a[0]=strlen(s);
	for(i = 1; i <=a[0]; i++)  a[i] = s[a[0] - i] - '0';
	
	
	int yu_shu=division(a,b,c);

	printf("商=");
	for(i = c[0] ; i >= 1; i--)  
		printf("%d", c[i]);
	
	printf("\n余数=%d",yu_shu);   
	return 0; 
}
