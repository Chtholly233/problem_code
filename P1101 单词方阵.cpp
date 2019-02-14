#include<cstdio>

int n;
char a[101][101],ans[101][101],word[]={'0','y','i','z','h','o','n','g'};
int walkx[]={0,-1,-1,0,1,1,1,0,-1},walky[]={0,0,1,1,1,0,-1,-1,-1};

int xx[10010],yy[10010];
void dfs(int x,int y,int nn,int dir){
	if(nn==7){
		for(int i=1;i<=nn;i++)
			ans[xx[i]][yy[i]]=word[i];
		return;
	}
	int tagx=x+walkx[dir],tagy=y+walky[dir];
	if(a[tagx][tagy]==word[nn+1]&&tagx<=n&&tagx>=1&&tagy>=1&&tagy<=n
	&&tagx+walkx[dir]*(6-nn)>=1&&tagx+walkx[dir]*(6-nn)<=n&&tagy+walky[dir]*(6-nn)>=1&&tagy+walky[dir]*(6-nn)<=n){
		xx[nn+1]=tagx;yy[nn+1]=tagy;
		dfs(tagx,tagy,nn+1,dir);
	}
}

int main(){
	int _x[1001],_y[1001],cnt=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%s",&a[i]);
		for(int j=n;j>=1;j--){
			a[i][j]=a[i][j-1];
		}
		for(int j=1;j<=n;j++){
			if(a[i][j]=='y'){
				_x[++cnt]=i;_y[cnt]=j;
			}
			ans[i][j]='*';
		}
	}
	for(int i=1;i<=cnt;i++)
		for(int k=1;k<=8;k++)
			if(a[_x[i]+walkx[k]][_y[i]+walky[k]]=='i'){
				xx[1]=_x[i];xx[2]=_x[i]+walkx[k];yy[1]=_y[i];yy[2]=_y[i]+walky[k];
				dfs(_x[i]+walkx[k],_y[i]+walky[k],2,k);
			}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)
			printf("%c",ans[i][j]);
		printf("\n");
	}
	return 0;
} 
