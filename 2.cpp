#include<stdio.h>
int main (){
	int a;
	printf("������Ļ����¶�ת��Ϊ�����¶ȡ��ɻ����¶�F�������¶�C��ת����ʽΪ��F��C��9/5��32��\n");
	scanf("%d",&a);
	float b = (a-32)*5/9;
	printf("%.4lf",b);
	return 0;
} 