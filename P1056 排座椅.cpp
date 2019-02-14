#include<cstdio>
#include<algorithm>
#define MAXM 1001
using namespace std;
int M,N,K,L,D,x[MAXM]{0},y[MAXM]{0};
int main(){
	scanf("%d%d%d%d%d",&M,&N,&K,&L,&D);
	int xi,yi,pi,qi;
	for(int i=1;i<=D;i++){
		scanf("%d%d%d%d",&xi,&yi,&pi,&qi);
		if(xi!=pi)
			if(xi<pi)
				x[xi]++;
			else x[pi]++;
		if(yi!=qi)
			if(yi<qi)
				y[yi]++;
			else y[qi]++;
	}
	sort(x+1,x+M+1);
	sort(x+1,x+N+1);
	for(int i=1;i<=K;i++)
		printf("%d",x[i]);
	for(int i=1;i<=L;i++)
		printf("%d",y[i]);
	return 0;
} 
