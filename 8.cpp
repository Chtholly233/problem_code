#include<iostream>
#include<cmath>
#include<iomanip>

using namespace std;

int main(){
	printf("计算两个双精度浮点数a和b相除的余数，a和b都是正数。这里余数（r）的定义是：a = k * b + r，其中 k是整数， 0 <= r < b。\n");
    int a,b;
    cin>>a>>b;
    float c=a%b;
    printf("%.2lf",c);
	return 0;
}