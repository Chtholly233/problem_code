#include<iostream>
#include<cmath>
#include<iomanip>

using namespace std;

int main(){
	printf("��������˫���ȸ�����a��b�����������a��b��������������������r���Ķ����ǣ�a = k * b + r������ k�������� 0 <= r < b��\n");
    int a,b;
    cin>>a>>b;
    float c=a%b;
    printf("%.2lf",c);
	return 0;
}