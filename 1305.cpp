#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
using namespace std;

int n;

struct node{
	int l,r;
}tree[30];

int id(char ch){
	return ch-'a'+1;
}

void dfs(int cur){
	printf("%c",cur+'a'-1);
	if(tree[cur].l!=-1)dfs(tree[cur].l);
	if(tree[cur].r!=-1)dfs(tree[cur].r);
}

int main(){
	scanf("%d",&n);
	char s[5],start;
	for(int i=1;i<=n;i++){
		scanf("%s",s);
		if(i==1)start=s[0];
		tree[id(s[0])].l=tree[id(s[0])].r=-1;
		if(s[1]!='*')tree[id(s[0])].l=id(s[1]);
		if(s[2]!='*')tree[id(s[0])].r=id(s[2]);
	}
	dfs(start-'a'+1);
	return 0;
} 
