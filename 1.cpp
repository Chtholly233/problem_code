#include<stdio.h>
int main(){
	printf("�������빫˾�����һ�������㷨����a����z,��b����y����c����x,......����z����a����Ҫ������һ��Сд��ĸ��������м��������\n");
	char n;
	while(scanf("%c",&n)!=EOF){
		char a;
		a='a'+'z'-n;
		printf("%c\n",a);
		return 0;
	}
}