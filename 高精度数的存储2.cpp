#include<cstdio>
#include<cstring>
using namespace std;
const int N=100;//���100λ
int main()
{
int a[N+1],i,s,key;
scanf("%d",&key);//��key
memset(a,0,sizeof(a)); //������0
i=0;//��0λ
while(key)  //��key����0
{
  a[++i]=key%10;//ȡ��iλ����
  key=key/10;
}
a[0]=i; //��iλ��
for(int x=1;x<=i;x++){
	printf("%d",a[x]);
}
return 0;
}
