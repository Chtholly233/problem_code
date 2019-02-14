#include <string>
#include <algorithm>
#include<stdio.h>
using namespace std;
string Trans10to2(int x)
{
    string s;
    if (x == 0)
        s = "0";
    else
        while (x)
        {
            s += char(x % 2 + '0');
            x /= 2;
        }
    reverse(s.begin(), s.end());
    return s;
}
int main(){
	int a,b;
	scanf("%d\n%d",&a,&b);
	int c=a+b;
	a=atoi(Trans10to2(a).c_str());b=atoi(Trans10to2(b).c_str());c=atoi(Trans10to2(c).c_str());
	printf("%d+%d=%d",a,b,c);
}
