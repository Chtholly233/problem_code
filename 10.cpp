#include<stdio.h>
#include<iostream>
#include<cmath>
#include<iomanip>

using namespace std;

int main(){
	printf("�����ʵ���������������ֱ��ǣ��������ɲ衢��ˮ������С��������������Ů����������С��Ľ�����������С��10�˵�С�鸺����ˮ�����water�����������ڵ���10������������Ů����С�鸺�����������tree�����������ڵ���10��������������Ů����С�鸺��ɲ裨���tea��������С������������Ů�����������С����ܵ�����\n");
	int a,b;
	cin >>a>>b;
	if(a+b<10){
		cout<<"water";
	}else if(a>b){
		cout <<"tree";
	}else{
		cout <<"tea";
	}
	return 0;
}