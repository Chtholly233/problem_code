#include <stdio.h>
int n,sum;
int visited[13]={0}; //��ֹ�ظ�
int ans[13]; //���ô�
int pc[12];//��������i C n-1
int dfs(int,int,int); //д����ԭ���Ǻ�ϰ�ߣ�
int main(void){
    int i;
    scanf("%d%d",&n,&sum);
    //���濪ʼ�����������(���������)
    pc[0]=pc[n-1]=1; //�����������,���߶���1
    if (n>1)
        for (i=1;i*2<n;i++) 
            pc[i]=pc[n-1-i]=(n-i)*pc[i-1]/i; //����������ǶԳ��Ժ��������ʽ����
    if (dfs(0,-1,0)) //-1����ռλ������
        for (i=1;i<=n;i++)
            printf("%d ",ans[i]); //�����
    return 0;
}
int dfs(int i,int num,int v){ //����˵��:i��ʾ����������i����(��1��ʼ),num��ʾ��i������num,v��ʾǰi�����ġ��͡�Ϊv
//����ֵ˵��:����0��ʾ����(������)������1��ʾ�ҵ��˿��н�
    int j; //ѭ������
    if (v>sum) //�Ѿ�����!
        return 0; //������
    if (i==n) //ö�ٵ������һ��,�ж�һ���Ƿ��ǿ��н�
        if (v==sum){
            ans[i]=num; //���ý�
            return 1;
        }
        else
            return 0;
    visited[num]=1;
    for (j=1;j<=n;j++){
        if (!visited[j] && dfs(i+1,j,v+pc[i]*j)){//v+pc[i]*j��ʾǰ(i+1)�����ġ��͡�
            //�Ѿ��ҵ��˿��еĽ�
            ans[i]=num;
            return 1;
        }
    }
    visited[num]=0;//һ���ǵø�λ
    return 0;//ִ�е�����һ����û���ҵ���
}
