#include <stdio.h>
int n,sum;
int visited[13]={0}; //防止重复
int ans[13]; //放置答案
int pc[12];//构造所有i C n-1
int dfs(int,int,int); //写函数原型是好习惯！
int main(void){
    int i;
    scanf("%d%d",&n,&sum);
    //下面开始构造杨辉三角(即组合数表)
    pc[0]=pc[n-1]=1; //杨辉三角性质,两边都是1
    if (n>1)
        for (i=1;i*2<n;i++) 
            pc[i]=pc[n-1-i]=(n-i)*pc[i-1]/i; //利用杨辉三角对称性和组合数公式计算
    if (dfs(0,-1,0)) //-1仅起占位符作用
        for (i=1;i<=n;i++)
            printf("%d ",ans[i]); //输出答案
    return 0;
}
int dfs(int i,int num,int v){ //参数说明:i表示正在搜索第i个数(从1开始),num表示第i个数是num,v表示前i个数的“和”为v
//返回值说明:返回0表示不行(不可能)，返回1表示找到了可行解
    int j; //循环变量
    if (v>sum) //已经超了!
        return 0; //不可能
    if (i==n) //枚举到了最后一个,判断一下是否是可行解
        if (v==sum){
            ans[i]=num; //放置解
            return 1;
        }
        else
            return 0;
    visited[num]=1;
    for (j=1;j<=n;j++){
        if (!visited[j] && dfs(i+1,j,v+pc[i]*j)){//v+pc[i]*j表示前(i+1)个数的“和”
            //已经找到了可行的解
            ans[i]=num;
            return 1;
        }
    }
    visited[num]=0;//一定记得复位
    return 0;//执行到这里一定是没有找到解
}
