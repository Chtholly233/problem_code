#include<cstdio>
#include<cstring>
using namespace std;
const int N=100;//最多100位
int main()
{
int a[N+1],i,s,key;
scanf("%d",&key);//数key
memset(a,0,sizeof(a)); //数组清0
i=0;//第0位
while(key)  //当key大于0
{
  a[++i]=key%10;//取第i位的数
  key=key/10;
}
a[0]=i; //共i位数
for(int x=1;x<=i;x++){
	printf("%d",a[x]);
}
return 0;
}
