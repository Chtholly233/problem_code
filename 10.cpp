#include<stdio.h>
#include<iostream>
#include<cmath>
#include<iomanip>

using namespace std;

int main(){
	printf("在社会实践活动中有三项任务分别是：种树、采茶、送水。依据小组人数及男生、女生人数决定小组的接受任务，人数小于10人的小组负责送水（输出water），人数大于等于10人且男生多于女生的小组负责种树（输出tree），人数大于等于10人且男生不多于女生的小组负责采茶（输出tea）。输入小组男生人数、女生人数，输出小组接受的任务。\n");
	int a,b;
	cin >>a>>b;
	if(a+b<10){
		cout<<"water";
	}else if(a>b){
		cout <<"tree";
	}else{
		cout <<"tea";
	}
	return 0;
}