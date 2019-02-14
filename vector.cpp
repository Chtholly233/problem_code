#include<stdio.h>
#include<vector>

using namespace std;

struct x{
	int a,b;
};

vector<x> c;

int main(){
	int e,f;
	for(int i=1;i<=3;i++){
		scanf("%d%d",&e,&f);
		c.push_back({e,f});
	}
	c.erase(c.begin()+2);
	for(int i=0;i<c.size();i++){
		printf("%d %d\n",c[i].a,c[i].b);
	}
	return 0;
}
