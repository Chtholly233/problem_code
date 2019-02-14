#include<cstdio>
int a[10001],b[10001],c[10001],d[10001],n,tagx,tagy;

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d%d%d%d",&a[i],&b[i],&c[i],&d[i]);
		c[i]=a[i]+c[i];
		d[i]=b[i]+d[i];
	}
	scanf("%d%d",&tagx,&tagy);
	for(int i=n;i>=1;i--){
		if(tagx>=a[i]&&tagx<=c[i]&&tagy>=b[i]&&tagy<=d[i]){
			printf("%d",i);
			break;
		}
	}
	return 0;
}
