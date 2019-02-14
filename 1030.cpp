#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
using namespace std;

int lenth;
char m[8],l[8],f[8];

int getcur(char c){
	for(int i=0;i<lenth;i++)
		if(m[i]==c)return i;
}

void dfs(int L1,int R1,int L2,int R2){
	int mid=getcur(l[R2]);
	printf("%c",m[mid]);
	if(mid>L1)dfs(L1,mid-1,L2,R2-R1+mid-1);
	if(mid<R1)dfs(mid+1,R2,L2-L1+mid,R2-1);
}

int main(){
	gets(m);gets(l);
	lenth=strlen(l);
	dfs(0,lenth-1,0,lenth-1);
	return 0;
}
 
