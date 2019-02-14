#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int n,ans=0;
vector<int>a;
int cmp(int x,int y){
	return x>y;
}
int main(){
	scanf("%d",&n);
	int _a,_b;
	for(int i=1;i<=n;i++){
		scanf("%d",&_a);
		a.push_back(_a);
	}
	sort(a.begin(),a.end(),cmp);
	for(;a.size()>1;){
		_a=a[a.size()-1];
		_b=a[a.size()-2];
		a.pop_back();a.pop_back();
		a.push_back(_a+_b);
		ans+=_a+_b;
		sort(a.begin(),a.end(),cmp);
	}
	printf("%d",ans);
	return 0;
}
