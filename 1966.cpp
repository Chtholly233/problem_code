#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
using namespace std;
const int mod = 99999997,MAXN = 1000010;

int n,c[MAXN];

struct node{
	int n,p,tag;
}a[MAXN],b[MAXN];

int cmp1(node lxl,node chen_zhe){
	return lxl.n<chen_zhe.n;
}

int cmp2(node lxl,node chen_zhe){
	return lxl.p<chen_zhe.p;
}

int temp[MAXN];
long long ans=0;
void merge_sort(int l,int r){
	if(r-l>1){
		int m=(l+r)/2;
		merge_sort(l,m);
		merge_sort(m,r);
		int p1=l,p2=m,i=l;
		while(p1<m||p2<r){
			if(p2>=r||(p1<m&&c[p1]<=c[p2]))temp[i++]=c[p1++];
			else {
				temp[i++]=c[p2++];
				ans+=(m-p1)%mod;
			}
		}
		for(i=l;i<r;i++)c[i]=temp[i];
	}
}

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i].n);
		a[i].p=i;
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&b[i].n);
		b[i].p=i;
	}
	sort(a+1,a+n+1,cmp1);
	sort(b+1,b+n+1,cmp1);
	for(int i=1;i<=n;i++)
		a[i].tag=b[i].p;
	sort(a+1,a+n+1,cmp2);
	for(int i=1;i<=n;i++)
		c[i]=a[i].tag;
	merge_sort(1,n+1);
	printf("%lld",ans%mod);
	return 0;
}
