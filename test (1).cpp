#include<cstdio>
#include<iostream>
using namespace std;

int T;

int main(){
	cin>>T;
	int cnt;
	while(T){
		T--;cnt=0;
		int a;
		for(int i=1;i<=7;i++){
			cin>>a;
			cnt+=a;
		}
		cout<<"Grade:"<<(float)cnt/7<<endl;
	}
	return 0;
} 
