#include <iostream>
#include <cstdio>

using namespace std;

int main(int argc, char** argv) {
	printf("输入一个三位数n，判断是否为水仙花数，如果是则输出“YES”，不是则输出“NO”。水仙花数：是指一个3位数，它的每个位上的数字的3次幂之和等于它本身。（例如：1^3 + 5^3+ 3^3 = 153）\n");
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