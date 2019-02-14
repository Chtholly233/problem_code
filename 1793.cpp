#include<cstdio>
#include<cstring>
#include<cstdlib>

char s[260];

int main(){
	gets(s);
	int i=0;
	int a=0;
	while(s[i]!='@'){
		if(a==0&&s[i]==')'){
			printf("NO");
			exit(0);
		}
		if(s[i]=='(')a++;
		if(s[i]==')')a--;
		i++;
	}
	if(a==0)printf("YES");
	else printf("NO");
	return 0;
} 
