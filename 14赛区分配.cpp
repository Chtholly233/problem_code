#include<stdlib.h>
#include<stdio.h>

//ѧ���ṹ
struct point{
    int w,P,idx;//�����idx���ڴ��ԭ��������˳��id
}a[16006];

//������K  ÿ��������������N[i]  �Ѷ�Q[i]  ʵ��P[i]  ��ע��W[i]

int ans[16006],Q[101],N[101];


//����qsort�����Ƚϵĺ����������Ƚ���������Ԫ�أ���һ���������ڣ����ڣ�С�ڵڶ�������ʱ���ֱ���ʾ��ֵ���㣬��ֵ��
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
    qsort(����)�����������£�

    void qsort(void * base,size_t nmemb,size_t size ,int(*compar)(const void *,const void *));

     ����˵����

    base,Ҫ���������

    nmemb,������Ԫ�ص���Ŀ

    size,ÿ������Ԫ��ռ�õ��ڴ�ռ䣬��ʹ��sizeof�������

    compar,ָ������ָ��Ҳ������ָ�롣������������Ƚ���������Ԫ�أ���һ���������ڣ����ڣ�С�ڵڶ�������ʱ���ֱ���ʾ��ֵ���㣬��ֵ��
	*/
	qsort(a,n,sizeof(struct point),cmp);



	for(i=n-1;i>=0;i--){
		//m���������
		for(m=0,j=1;j<=k;j++)
			if(N[j]/*��j�����������Ϊ0*/ && a[i].P>Q[j]/*��i��ѡ��ʵ�����ڵ�j�������Ѷ�*/ && Q[j]>Q[m]/*���Գ������Ѷ�����*/) m=j;
	    
			
		
		if(m==0)
			for(j=1;j<=k;j++)
				if(N[j]&&Q[j]>Q[m]) m=j;

        N[m]--;//��ȥһ������

		 //����ѡ������˳��id���뷿��
		ans[a[i].idx]=m;
	}

	for(i=0;i<n;i++){
		printf("%d ",ans[i]);
	}
	printf("\n");

    getchar();

	return 0;
}
