#include<string>
#include<cstdio>
#include<algorithm>

using namespace std;

struct point{
	char name[21];
	int lp,cp,isgb,isxb,lw,num;
	int money;
}stds[101];

int n,am;

void getname(int f){
	char o;
	scanf("%c",&o);
	for(int i=1;o!=' ';i++){
		stds[f].name[i]=o;
	}
	//stds[f].name[i+1]='\0';
}

int cmp(struct point a,struct point b){
	if(a.money==b.money){return a.num<b.num;}
	return a.money>b.money;
}

int main(){
	scanf("%d",&n);
	char GB,XB;
	for(int i=1;i<=n;i++){
		//scanf("%s",&stds[i].name);
		getname(i);
		scanf("%d%d%c%c%d",&stds[i].lp,&stds[i].cp,&GB,&XB,&stds[i].lw);
		stds[i].num=i,stds[i].money=0;
		stds[i].isgb=(GB=='Y'?1:0);
		stds[i].isxb=(XB=='Y'?1:0);
		if(stds[i].lp>80&&stds[i].lw>=1)stds[i].money+=8000,am+=8000;
		if(stds[i].lp>85&stds[i].cp>80)stds[i].money+=4000,am+=4000;
		if(stds[i].lp>90)stds[i].money+=2000,am+=2000;
		if(stds[i].lp>85&&stds[i].isxb)stds[i].money+=1000,am+=1000;
		if(stds[i].cp>80&&stds[i].isgb)stds[i].money+=850,am+=850;
	}
	sort(stds+1,stds+n+1,cmp);
	//printf("%s\n",stds[1].name.c_str());
	for(int i=1;i<=20&&stds[1].name[i]!='\0';i++){
		printf("%c\n",stds[1].name[i]);
	}
	printf("%d\n",stds[1].money);
	printf("%d\n",am);
	return 0;
}
