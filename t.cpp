#include<bits/stdc++.h>
using namespace std;
int x;
void digui(int n) { //���еݹ�ĺ���ģ��
	int y;
	if(n==0) return;//�ݹ���ֹ����
	for(int i=0; i<=15; i++) { //����������ҵ���nС��2�η�������
		y=i;//���д���
		if((1<<y)>n) { //��2�η���һ�δ���nʱ
			y--;//��ΪС��n
			break;//����ѭ��
		}
	}
	if(y==0) cout<<"2(0)";//���2��0�η�
	if(y==1) cout<<"2";//ͬ�����2��1�η�
	if(y>1) { //���η�����һʱ
		cout<<"2(";//���2
		digui(y);
		cout<<")";//��β����Ĳ�����
	}
	if(n!=(1<<y)) { //��n������2��y�η�ʱ
		cout<<"+";//��Ӻ�
		digui(n-(1<<y)); //�ݹ�ʣ���
	}
}
int main() {
	cin>>x;
	digui(x);
	return 0;
}
