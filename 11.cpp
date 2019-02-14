#include<stdio.h>

int c[30],f[30],f1[30],f2[30];
int ans=0;
void dfs(int k){
	int i,j;
for(i=1;i<=k;i++)
 for(j=1;j<=k;j++){
  if(c[i]==1)c[i]=0;
  if(c[i]==0)c[i]=1;
  if(f[j]==1)f[j]=0;
  if(f[j]==0)f[j]=1;
  if(f1[i+j]==1)f1[i+j]=0;
  if(f1[i+j]==0)f1[i+j]=1;
  if(f2[i-j+15]==1)f2[i-j+15]=0;
  if(f2[i-j+15]==0)f2[i-j+15]=1;
 }
}

int main(){
int n,i1,j1;
scanf("%d",&n);
dfs(n);
for(i1=1;i1<=n;i1++)
 for(j1=1;j1<=n;j1++){
 	if(c[i1]&&f[j1]&&f1[i1+j1]&&f2[i1-j1+15]&&c[i1]+f[j1]+f1[i1+j1]+f2[i1-j1+15]==n){
	 	ans++;
	 }
 }
 printf("%d",ans);
return 0;
}