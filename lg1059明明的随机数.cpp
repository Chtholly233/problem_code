#include<stdio.h>

int m,in[101],last,i,j,t,ans=0,a[101];

int main(){
	scanf("%d",&m);
	for(i=0;i<m;i++){
		scanf("%d",&in[i]);
	}
	for(i=0;i<m-1;i++)
		for(j=m-1;j>=0;j--)
			if(in[j]<=in[j-1]){
				t=in[j-1];
				in[j-1]=in[j];
				in[j]=t;
			}
	last=-1;
	for(i=0;i<m;i++){
		if(last==in[i]) continue;
		else{
			last=in[i];
			a[ans]=in[i];
			ans++;
		}
	}
	printf("%d\n",ans);
	for(i=0;i<ans;i++){
	    printf("%d",a[i]);
	    if(i!=ans-1)
	        printf(" ");
	}
	return 0;
} 
