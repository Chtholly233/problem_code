#include<cstdio>
#include<cstring>
using namespace std;

int lenth;
char m[10],l[10];

int getcur(char c){
	for(int i=0;i<lenth;i++)
		if(m[i]==c)return i;
}

void dfs(int L1,int R1,int L2,int R2){
	int mid=getcur(l[R2]);
	printf("%c",m[mid]);
	if(mid>L1)dfs(L1,mid-1,L2,R2-R1+mid-1);
	if(mid<R1)dfs(mid+1,R1,L2-L1+mid,R2-1);
}

int main(){
	scanf("%s",m);
	scanf("%s",l);
	lenth=strlen(l);
	dfs(0,lenth-1,0,lenth-1);
	return 0;
}
