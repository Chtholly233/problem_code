#include<cstdio>
#include<string>
using namespace std;
const int MAX=1001;
int a[MAX+1];
void readnum(){
	string s;
	scanf("%s",&s);
	memset(a,0,sizeof(a));
	a[0]=s.length();
	for(int i=1;i<=a[0];i++)
		a[i]=s[a[0]-i]-'0';
}
int main(){
	readnum();
	for(int i=0;i<=a[0];i++)
		printf("%d",a[i]);
	return 0;
}
