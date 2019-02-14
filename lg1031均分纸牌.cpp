#include<stdio.h>
#define MAXN 100

int ans,n,a[MAXN],p;

int main(){
	int i;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
		p+=a[i];
	}
	p=p/n;
	for(i=0;i<n;i++){
		if(a[i]<p){
		    a[i+1]-=p-a[i];
		    ans++;
		} 
		else 
		    if(a[i]>p){
			    a[i+1]+=a[i]-p;
			    ans++;
		    } 
	}
	printf("%d",ans);
	return 0;
} 
