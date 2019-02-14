#include<stdio.h> 
#include<algorithm>
using namespace std;

int n,m,q;

struct p{
	int num,point;
}a[5001];

int cmp(struct p _a,struct p _b){
	if(_a.point==_b.point)return _a.num<_b.num;
    return _a.point>_b.point;
}

int main(){
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++){
		scanf("%d %d",&a[i].num,&a[i].point);
	}
	sort(a+0,a+n,cmp);
	int j=m*1.5;
	printf("%d %d\n",a[j].point,j+1);
	for(int i=0;i<j+1;i++)
	    printf("%d %d\n",a[i].num,a[i].point);
	return 0;
}
