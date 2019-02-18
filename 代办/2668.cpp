#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;

inline int read(){
	int x=0,w=1;char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')w=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<3)+(x<<1)+c-'0';
		c=getchar();
	}
	return x*w;
}

int n,t;
int a[15]={0},ans;

void dfs(int x){
	if(x>=ans)return;
	/*--------------顺子--------------*/
	//单顺
	int len=0;
	for(int i=3;i<=14;i++){
		if(a[i]<1)len=0;
		else{
			len++;
			if(len>=5){
				for(int j=i-len+1;j<=i;j++)a[j]--;
				dfs(x+1);
				for(int j=i-len+1;j<=i;j++)a[j]++;
			}
		}
	}
	//双顺
	len=0;
	for(int i=3;i<=14;i++){
		if(a[i]<2)len=0;
		else{
			len++;
			if(len>=3){
				for(int j=i-len+1;j<=i;j++)a[j]-=2;
				dfs(x+1);
				for(int j=i-len+1;j<=i;j++)a[j]+=2;
			}
		}
	}
	//三顺
	len=0;
	for(int i=3;i<=14;i++){
		if(a[i]<3)len=0;
		else{
			len++;
			if(len>=2){
				for(int j=i-len+1;j<=i;j++)a[j]-=3;
				dfs(x+1);
				for(int j=i-len+1;j<=i;j++)a[j]+=3;
			}
		}
	}
	/*--------------带--------------*/
	for(int i=2;i<=15;i++){
		//有三张：三带一，三带一对 
		if(a[i]==3){
			a[i]-=3;
			for(int j=2;j<=15;j++){
				if(a[j]>=1){
					a[j]--;
					dfs(x+1);
					a[j]++;
				}
			}
			for(int j=2;j<=14;j++){
				if(a[j]>=2){
					a[j]-=2;
					dfs(x+1);
					a[j]+=2;
				}
			}
			a[i]+=3;
		}
		//有四张：三带一，三带一对 ，四带二，四带二对 
		if(a[i]>=4){
			//三带一（对） 
			a[i]-=3;
			for(int j=2;j<=15;j++){
				if(a[j]>=1){
					a[j]--;
					dfs(x+1);
					a[j]++;
				}
			}
			for(int j=2;j<=14;j++){
				if(a[j]>=2){
					a[j]-=2;
					dfs(x+1);
					a[j]+=2;
				}
			}
			a[i]+=3;
			//四带二（对） 
			a[i]-=4;
			for(int j=2;j<=15;j++){
				for(int k=2;k<=15;k++){
					if(j!=k&&a[j]>=1&&a[k]>=1){
						a[j]--;a[k]--;
						dfs(x+1);
						a[j]++;a[k]++;
					}
				}
			}
			for(int j=2;j<=14;j++){
				for(int k=2;k<=14;k++){
					if(j!=k&&a[j]>=2&&a[k]>=2){
						a[j]-=2;a[k]-=2;
						dfs(x+1);
						a[j]+=2;a[k]+=2;
					}
				}
			}
			a[i]+=4;
		}
	}
	/*--------------剩下的--------------*/
	for(int i=2;i<=15;i++)
		if(a[i])x++;
	ans=min(ans,x);
} 

int main(){
	t=read();n=read();
	while(t--){
		memset(a,0,sizeof(a));
		for(int i=1;i<=n;i++){
			int x=read();read();
			if(x==1)a[14]++;
			else if(x==0)a[15]++;
			else a[x]++;
		}
		ans=n;
		dfs(0);
		printf("%d\n",ans);
	}
	return 0;
}
