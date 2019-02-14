#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int a[502],b[502];
int c[502]={0};

void insert(int _tag[],char s[]){
	int d=strlen(s);
	for(int i=1;i<=d;i++)_tag[i]=s[d-i+1];
	_tag[0]=d;
}

void plus(int p1[],int p2[],int tag[]){
	tag[0]=max(p1[0],p2[0]);
	for(int i=1;i<=tag[0];i++){
		tag[i+1]+=(p1[i]+p2[i])/10;
		tag[i]+=(p1[i]+p2[i])%10;
	}
	if(tag[tag[0]+1])tag[0]++;
}

int main(){
	char s[502];
	scanf("%d",&s);
	insert(a,s);
	scanf("%d",&s);
	insert(b,s);
	plus(a,b,c);
	for(int i=c[0];i>0;i--)
		printf("%d",a[0]);
	return 0;
} 
