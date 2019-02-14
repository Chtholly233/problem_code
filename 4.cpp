#include<stdio.h>
int main(){
	printf("有一个“就是它”的猜数游戏，步骤如下：请你对任意输入的一个三位数x，在这三位数后重复一遍，得到一个六位数，467-->467467.把这个数连续除以7、11、13，输出最后的商。\n");
	int a;
	scanf("%d",&a);
	float b=(a*1000+a)/7/11/13;
	printf("%.4lf",b);
	return 0;
}