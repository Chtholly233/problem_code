#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
using namespace std;

int n,db[]= {3,7,15,31,63,127,255,511,1023,2047};

char s[1024];

struct node {
	int w,left,right;
} tree[3000];

int tot=1,wow=0;
void creaft(int cur,int d) {
	if(d<n) {
		tree[cur].left=++tot;
		tree[cur].right=++tot;
		tree[cur].w=-1;
		if(d==n-1) {
			tree[tree[cur].left].w=s[++wow]-'0';
			tree[tree[cur].right].w=s[++wow]-'0';
		}
		creaft(tree[cur].left,d+1);
		creaft(tree[cur].right,d+1);
	}
}

char fbi[3]= {'B','I','F'};
int dfs(int root) {
	if(tree[root].w!=-1) {
		printf("%c",fbi[tree[root].w]);
		return tree[root].w;
	}
	int l=dfs(tree[root].left);
	int r=dfs(tree[root].right);
	int ti;
	if(l==r&&l==1)ti=1;
	else if(l==r&&l==0)ti=0;
	else if(l==r&l==2)ti=2;
	else ti=2;
	printf("%c",fbi[ti]);
	return ti;
}

int main() {
	scanf("%d",&n);
	scanf("%s",s+1);
	creaft(1,0);
	dfs(1);
}
