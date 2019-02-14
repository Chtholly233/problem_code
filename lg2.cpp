#include<cstdio>

int l,q;

int main(){
	scanf("%d %d",&l,&q);
	char a[l+1][l+1];
	for(int i=1;i<=l;i++){
		for(int j=1;j<=l;j++)
		    scanf("%c",&a[i][j]);
	}
	int x,y;
	for(int o=1;o<=q;o++){
		scanf("%d %d",&x,&y);
		int maxx=0;
	for(int i=1;i<=l;i++){
		for(int j=i;j<=l;j++){
			for(int k=i;k<=(j-i/2);k++){
				if(a[x][k]==a[x][l-k+1]&&(j-i)+1>maxx){
					maxx=(j-i)+1;
				}
				if(maxx==l){return maxx;}
			}
		}
	}
	
	
	for(int i=1;i<=l;i++){
		for(int j=i;j<=l;j++){
			for(int k=i;k<=(j-i/2);k++){
				if(a[k][y]==a[l-k+1][y]&&(j-i)+1>maxx){
					maxx=(j-i)+1;
				}
				if(maxx==l){return maxx;}
			}
		}
	}
		printf("%d\n",maxx);
	}
	return 0;
}
