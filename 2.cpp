#include<stdio.h>
int main (){
	int a;
	printf("将输入的华氏温度转换为摄氏温度。由华氏温度F与摄氏温度C的转换公式为：F＝C×9/5＋32。\n");
	scanf("%d",&a);
	float b = (a-32)*5/9;
	printf("%.4lf",b);
	return 0;
} 