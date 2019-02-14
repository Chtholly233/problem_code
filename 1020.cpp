#include<cstdio>
#include<algorithm>
#include<iostream>
using namespace std;
const int MAXN=100010;

int n=1,a[MAXN],ans1=1,ans2=1;
int stack1[MAXN],stack2[MAXN];

struct cmp{
	bool operator()(int a,int b){
		return a>b;
	}
};

int main(){
	while(cin>>a[n])n++;
	n--;
	stack1[1]=stack2[1]=a[1];
	for(int i=2;i<=n;i++){
		if(a[i]<=stack1[ans1])
			stack1[++ans1]=a[i];
		else
			stack1[upper_bound(stack1+1,stack1+ans1+1,a[i],cmp())-stack1]=a[i];
		if(a[i]>stack2[ans2])
			stack2[++ans2]=a[i];
		else
			stack2[lower_bound(stack2+1,stack2+ans2+1,a[i])-stack2]=a[i];
	}
	printf("%d %d",ans1,ans2);
	return 0;
}
