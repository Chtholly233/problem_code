#include<stdio.h>
//#include<bits/stdc++.h>

int maxdeep,za[500001],zb[500001],deep[500001],n,m,s,u[500001],v[500001],first[500001],next[5000001],a,b,ans[500001];

int dfs(int t,int e,int _deep){
	if(t==e){
		return 1;
	}
	else if(next[t]==-1){
		return 0;
	}
	else{
		for(int k=first[u[t]]; ;k=next[k]){
			if(dfs(v[k],e,_deep+1)) {
				(e==a)?(za[e]=1):(zb[e]=1);
				deep[t]=_deep;
			    return 1;
			}
			else
			    return 0;
		}
	}
}

int main(){
	scanf("%d %d %d",&n,&m,&s);
	int i;
	for(i=1;i<=n;i++){
		first[i]=-1;
	}
	for(i=0;i<=n;i++){
		za[i]=0;
	}
	for(i=0;i<=n;i++){
		zb[i]=0;
	}
	for(i=0;i<=n;i++){
		ans[i]=s;
	}	
	for(i=1;i<=n-1;i++){
		scanf("%d %d",&u[i],&v[i]);
		next[i]=first[u[i]];
		first[u[i]]=i;
	}
	int j;
	for(i=0;i<m;i++){
	    maxdeep=-1;
		scanf("%d %d",&a,&b);
		dfs(s,a,0);
	    dfs(s,b,0);
	    for(j=0;j<n;j++){
		    if(za[j]&&zb[j]&&deep[j]>maxdeep){
		        maxdeep=deep[j];
	            ans[i]=j;
		    }
		}
		maxdeep=-1;
	    for(i=0;i<=n;i++){
		    za[i]=0;
	    }
	    for(i=0;i<=n;i++){
		    zb[i]=0;
	    }
	}
	for(i=0;i<m;i++)
	    printf("%d",ans[i]);
	return 0;
}
