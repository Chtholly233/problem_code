#include<iostream>
#include<cmath>
#include<iomanip>

using namespace std;

int main(){
	printf("按年利率R%存入本钱X，存入P年后的本利合计为Y=X*((100+R)/100)^P，求Y的值。\n");
	double r,y,x,p;
	cin>>r>>x>>p;
	y=x*pow(((100+r)/100),p);
	cout<<fixed<<setprecision(2)<<y<<endl;
	return 0;
}