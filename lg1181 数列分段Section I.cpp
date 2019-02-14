#include<cstdio>
#include<algorithm>
using namespace std;
int n,m,a[100001],visited[100001]{0},ans=1;

int cmp(int a,int b){
	return a>b;
}

int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	sort(a+1,a+n+1,cmp);
	int k=0;
	for(int i=i;i<=n&&!visited[i];i++)
		for(int j=i+1;j<=n&&!visited[j];j++){
			if(k+a[j]<=m){k+=a[j];visited[j]=1;}
			else {ans++;k=0;continue;}
		}
	printf("%d",ans);
	return 0;
} 
