#include<cstdio>

int main(){
	int C[105][105]{0},n=10,i,j;
	for(i=0;i<n;i++){
		//注意这里不能从零开始 ！因为要符合组合数！ 
		C[i][0]=1;
		for(j=1;j<=i;j++){
			C[i][j]=C[i-1][j-1]+C[i-1][j];
		}
	}
	for(i=0;i<n;i++,printf("\n")){
		for(j=0;j<=i;j++){
			printf("%d ",C[i][j]);
		}
	}
	return 0;
}
