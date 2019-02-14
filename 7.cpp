#include<iostream>
#include<cmath>
#include<iomanip>

using namespace std;

int main(){
	printf("憨厚的老农夫昨天捡到了3块小石头，他想再去捡一个小石头,让这4个石头正好一共重20斤，请问他应该去捡一个多少斤的石头?\n");
	int a,b,c,d;
	cin >>a>>b>>c;
	d=20-a-b-c;
	printf("%d",d);
	return 0;
}