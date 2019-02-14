#include<cstdio>
#include<string.h>

int ans=0,n,maxp[21][21]={0},visit[21]={0};
char word[21][100],start;
int mm(int x, int y){
    bool pp=true; 
    int ky=0;
    for(int k=strlen(word[x])-1;k>=0;k--){
        for(int kx=k;kx<strlen(word[x]);kx++)
            if(word[x][kx]!=word[y][ky++]){
                pp=false;
                break;
            }
        if(pp==true)
            return strlen(word[x])-k;
        ky=0;
        pp=true;
    }
    return 0;
}

int max(int a,int b){
	return a>b?a:b;
}
int m_ans=0;
void dfs(int xx){
	int found=0;
	for(int i=0;i<=n;i++){
		if(visit[i]>=2)continue;
		if(maxp[xx][i]==0)continue;
		if(maxp[xx][i]==strlen(word[xx])||maxp[xx][i]==strlen(word[i]))continue;
		found=1;
		visit[i]++;
		m_ans+=strlen(word[i])-maxp[xx][i];
		dfs(i);
		visit[i]--;
		m_ans-=strlen(word[i])-maxp[xx][i];
	}
	if(!found)ans=max(ans,m_ans);
}

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%s",&word[i]);
	}
	scanf(" %c",&start);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			maxp[i][j]=mm(i,j);
	for(int i=1;i<=n;i++)
		if(word[i][0]==start){
			visit[i]++;
			m_ans+=strlen(word[i]);
			dfs(i);
			m_ans-=strlen(word[i]);
			visit[i]=0;
		}
	printf("%d",ans);
	return 0;
} 
