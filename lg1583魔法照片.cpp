#include<stdio.h>
#include<algorithm>

#define MAXN 20001

using namespace std;

int n,k,e[11];

struct s{
	int d,w,c;
}mate[MAXN];

int cmp(struct s a,struct s b){
	if(a.w==b.w)return a.d<b.d;
	return a.w>b.w;
}

int main(){
	int i;
	scanf("%d%d",&n,&k);
	for(i=1;i<=10;i++) scanf("%d",&e[i]);
	for(i=1;i<=n;i++) {scanf("%d",&mate[i].w); mate[i].d=i;}
	sort(mate+1,mate+n+1,cmp);
	for(i=1;i<=n;i++){mate[i].w+=e[(i-1)%10+1];}
	sort(mate+1,mate+n+1,cmp);
	for(i=1;i<=k;i++){
	    printf("%d",mate[i].d);
	    if(i!=k){
	    	printf(" ");
	    }
	} 
	return 0;
}
