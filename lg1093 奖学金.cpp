#include<cstdio>
#include<algorithm>

using namespace std;

int n;

struct point{
	int num,ch,sum;
}stds[301];

int cmp(struct point a,struct point b){
	if(a.sum!=b.sum)return a.sum>b.sum;
	else if(a.ch!=b.ch)return a.ch>b.ch;
	else return a.num<b.num;
}

int main(){
	scanf("%d",&n);
	int c,m,e;
	for(int i=1;i<=n;i++){
		scanf("%d%d%d",&c,&m,&e);
		stds[i].ch=c;stds[i].sum=c+m+e;stds[i].num=i;
	}
	sort(stds+1,stds+n+1,cmp);
	for(int i=1;i<=5;i++){
		printf("%d %d\n",stds[i].num,stds[i].sum);
	}
	return 0;
} 
