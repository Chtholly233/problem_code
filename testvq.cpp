#include<cstdio>
#include<algorithm>
#include<queue>
#include<vector>

using namespace std;
queue<int>a;
vector<int>b;

int main(){
	a.push(1),a.push(2);
	b.push_back(1),b.push_back(2);
	for(int i=0;i<a.size();i++){
		printf("%d ",a.front());
	}
	printf("\n");
	for(int i=0;i<b.size();i++){
		printf("%d ",b[i]);
	}
	printf("\n\n");
	a.pop();
	b.pop_back();
	for(int i=0;i<a.size();i++){
		printf("%d ",a.front());
	}
	printf("\n");
	for(int i=0;i<b.size();i++){
		printf("%d ",b[i]);
	}
	printf("\n\n");
	return 0;
}
