#include<stdlib.h>
#include<stdio.h>

//学生结构
struct point{
    int w,P,idx;//这里的idx用于存放原本的输入顺序id
}a[16006];

//赛区数K  每个赛区人数限制N[i]  难度Q[i]  实力P[i]  关注度W[i]

int ans[16006],Q[101],N[101];


//用于qsort函数比较的函数，用来比较两个数组元素，第一个参数大于，等于，小于第二个参数时，分别显示正值，零，负值。
int cmp(const void *a,const void *b){
    return ((struct point * )a)->w-((struct point * )b)->w;
}


int main(){
	int n=0;
    int i,j,k,m;
	scanf("%d ",&k);
	for(i=1;i<=k;i++) scanf("%d",&N[i]);
    for(i=1;i<=k;i++) scanf("%d",&Q[i]);
	for(i=1;i<=k;i++) n+=N[i];
	for(i=0;i<n;i++) scanf("%d",&a[i].P);
	for(i=0;i<n;i++) scanf("%d",&a[i].w);
	for(i=0;i<n;i++) a[i].idx=i;
    
    printf("\n");


    /*
    qsort(排序)函数声明如下：

    void qsort(void * base,size_t nmemb,size_t size ,int(*compar)(const void *,const void *));

     参数说明：

    base,要排序的数组

    nmemb,数组中元素的数目

    size,每个数组元素占用的内存空间，可使用sizeof函数获得

    compar,指向函数的指针也即函数指针。这个函数用来比较两个数组元素，第一个参数大于，等于，小于第二个参数时，分别显示正值，零，负值。
	*/
	qsort(a,n,sizeof(struct point),cmp);



	for(i=n-1;i>=0;i--){
		//m存放赛区号
		for(m=0,j=1;j<=k;j++)
			if(N[j]/*第j个赛区名额还不为0*/ && a[i].P>Q[j]/*第i个选手实力大于第j个赛区难度*/ && Q[j]>Q[m]/*可以出线中难度最大的*/) m=j;
	    
			
		
		if(m==0)
			for(j=1;j<=k;j++)
				if(N[j]&&Q[j]>Q[m]) m=j;

        N[m]--;//减去一个名额

		 //按照选手输入顺序id存入房间
		ans[a[i].idx]=m;
	}

	for(i=0;i<n;i++){
		printf("%d ",ans[i]);
	}
	printf("\n");

    getchar();

	return 0;
}
