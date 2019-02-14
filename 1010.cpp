#include<cstdio>
using namespace std;

int n;

void dfs(int nn) {
	if(nn==0)return;
	int i;
	for(int j=0;; j++) {
		i=j;
		if((1<<i)>nn) {
			i--;
			break;
		}
	}
	if(i==0)printf("2(0)");
	if(i==1)printf("2");
	if(i>1) {
		printf("2(");
		dfs(i);
		printf(")");
	}
	if((1<<i)<nn) {
		printf("+");
		dfs(nn-(1<<i));
	}
}

int main() {
	scanf("%d",&n);
	dfs(n);
	return 0;
}
