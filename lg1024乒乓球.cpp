#include<stdio.h>
#include<iostream>

using namespace std;

int w=0,l=0;
char a[62501];

//WWWWWWWWWWWWWWWWWWWW
//WWLWE

int main(){
	int i;
	for(i=0;a[i-1]!='E';i++){
		scanf("%c",&a[i]);
	}
	//a.remove("\n");
	for(i=0;a[i-1]!='E';i++){
		if(a[i]=='W'){
			w++;
		}
		else if(a[i=='L']){
			l++;
		}
		if((w>=11&&w-l>=2)||(l==11&&l-w<=2)){
			printf("%d:%d\n",w,l);
			w=l=0;
		}
	}
	printf("\n\n");
	
	for(i=0;a[i-1]!='E';i++){
		if(a[i]=='W'){
			w++;
		}
		if(a[i]=='L'){
			l++;
		}
		if((w>=21&&w-l>=2)||(l==21&&l-w<=2)){
			printf("%d:%d\n",w,l);
			w=l=0;
		}
	}
	return 0;
} 
