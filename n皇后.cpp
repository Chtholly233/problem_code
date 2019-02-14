#include<stdio.h>
int n,f1[30],f2[30],c[30],f[30],ans;
void dfs(int k){
	if(k==n+1){
	ans++;
	return;
	}

	int i;
	for(i=1;i<=n;i++)
	    if(c[i]&&f1[i+k]&&f2[i-k+15])
		{
		     c[i]=f1[i+k]=f2[i-k+15]=0;
             dfs(k+1);
			 c[i]=f1[i+k]=f2[i-k+15]=1;
          
		}
}
int main(){
	int i;
	scanf("%d",&n);
	for(i=1;i<30;i++){
        c[i]=f1[i]=f2[i]=1;
	}

	for(i=1;i<=(n+1)/2;i++){
		
		ans=0;
		
		c[i]=f1[i+1]=f2[i+14]=0;

		dfs(2);

		c[i]=f1[i+1]=f2[i+14]=1;

		f[i]=ans;
	
	}

	ans=0;
	for(i=0;i<=n;i++){
		if(i<=(n+1)/2){
			ans+=f[i];
		}
		else{
			ans+=f[n+1-i];
		}

	}

	printf("%d",ans);
	return 0;
}

