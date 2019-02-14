#include<stdio.h>
int main(){
	printf("神龙数码公司设计了一个加密算法：用a代替z,用b代替y，用c代替x,......，用z代替a。现要求输入一个小写字母，对其进行加密输出。\n");
	char n;
	while(scanf("%c",&n)!=EOF){
		char a;
		a='a'+'z'-n;
		printf("%c\n",a);
		return 0;
	}
}