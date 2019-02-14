#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

int n,m,jc[10010],a[10010],cnt=0,innum,tagnum=-1;

void c_jc(){
	jc[0]=1;
	for(int i=1;i<=n;i++)
		jc[i]=i*jc[i-1];
}

void printans(int A[]){
	for(int i=1;i<=n;i++)printf("%d ",A[i]);
}

int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	int A[10010];
	memcpy(&A,&a,sizeof(a));
	
	c_jc();
	
	do{
		cnt++;
		
		int ok=1;
		for(int i=1;i<=n;i++)if(A[i]!=a[i]){ok=0;break;}
		if(ok){
			innum=cnt;
			tagnum=cnt+m;
		}
		
		if(cnt==tagnum){
			printans(A);
			return 0;
		}
	}
	while(next_permutation(A+1,A+n+1));
	
	return 0;
}
