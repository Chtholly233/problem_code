#include<iostream>
#include<algorithm>
using namespace std;
struct f
{
    int rank,sum;//����ṹ�壬���к���0�ĸ�����Ӧ 
}cou[10];

int point[9][9]{
     6,6,6,6,6,6,6,6,6,
     6,7,7,7,7,7,7,7,6,
     6,7,8,8,8,8,8,7,6,       
     6,7,8,9,9,9,8,7,6,
     6,7,8,9,10,9,8,7,6,
     6,7,8,9,9,9,8,7,6,
     6,7,8,8,8,8,8,7,6, 
     6,7,7,7,7,7,7,7,6,
     6,6,6,6,6,6,6,6,6,
} ;

int a[10][10],hang[10][10],lie[10][10],gong[10][10],s[100][4],u,ok,most=-1,have;
int which(int,int);//�����������ͱ����������꣬���ش���������ڹ�                                     
void dfs(int,int); 
bool cmp(f a,f b) 
{
    return a.sum<b.sum; 
}
int main()
{
    for(int i=1;i<=9;i++)  cou[i].rank=i;//rank�����ʼ�кţ������Ͳ��ᶪʧ 
    for(int i=1;i<=9;i++)
    for(int j=1;j<=9;j++)
    {
        cin>>a[i][j];
        if(a[i][j]>0)
        hang[i][a[i][j]]=lie[j][a[i][j]]=gong[which(i,j)][a[i][j]]=1,have+=a[i][j]*point[i-1][j-1];//����Ͳ��洢����������s�У�����������ֵ���������С��С����б�� ������ӷ� 
        else  cou[i].sum++;//��0�ͼ��� 
    }
    sort(cou+1,cou+10,cmp);//����0�ٵ���ǰ 
    for(int i=1;i<=9;i++)//����s���飬׼������ 
    {
        for(int j=1;j<=9;j++)//����0�ٵ��� 
        if(a[cou[i].rank][j]==0)
        s[u][0]=cou[i].rank,s[u][1]=j,s[u][2]=point[(cou[i].rank)-1][j-1],s[u++][3]=which(cou[i].rank,j);//���治���� 
    }
    dfs(0,have);//���� 
    cout<<most<<endl;//most����𰸣���ʼֵΪ-1 
    return 0;
} 

void dfs(int p,int score)// ��ʾ������s[p],scoreΪĿǰ���� 
{
    if(p==u)//�Ϸ����������е��� 
    {
        if(score>most)  most=score;//����͸��� 
        return;//return��ȥѰ�Ҹ���ķ��� 
    }
    for(int i=1;i<=9;i++) 
    {
        if(!hang[s[p][0]][i]&&!lie[s[p][1]][i]&&!gong[s[p][3]][i])//�жϿɲ����Խ�i���� 
        {
            hang[s[p][0]][i]=lie[s[p][1]][i]=gong[s[p][3]][i]=1;//���˺�ͽ�������ֵ���������С��С����б��
            dfs(p+1,score+(s[p][2]*i));//��һ��ݹ� 
            hang[s[p][0]][i]=lie[s[p][1]][i]=gong[s[p][3]][i]=0;//���� 
        }
    }
    return;
}

int which(int i,int j)
{
    if(i<=3)
    {
        if(j<=3)        return 1;
        else if(j<=6)   return 2;
        else            return 3;          
    }
    else if(i<=6)
    {
        if(j<=3)        return 4;
        else if(j<=6)    return 5;
        else            return 6;
    }
    else
    {
        if(j<=3)        return 7;
        else if(j<=6)   return 8;
        else            return 9;
    }
}

