#include <iostream>
#include <cstdio>

using namespace std;

int main(int argc, char** argv) {
	printf("����һ����λ��n���ж��Ƿ�Ϊˮ�ɻ�����������������YES���������������NO����ˮ�ɻ�������ָһ��3λ��������ÿ��λ�ϵ����ֵ�3����֮�͵��������������磺1^3 + 5^3+ 3^3 = 153��\n");
	int a , b , c, x;
	cin>>x;
	a=x%10;
	b=x/10%10;
	c=x/100;
	if (x==a*a*a+b*b*b+c*c*c)
	{
		cout<<"YES"<<endl;
	}
	else
	cout<<"NO"<<endl;
	return 0;
}