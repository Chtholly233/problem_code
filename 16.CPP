#include<stdio.h>

int main(){

    for(int i=0;i<4;i++){
		for(int f=0;f<i;f++){
		    printf(" ");
		}
		for(int k=0;k<4;k++){
		    printf("*");
		}
		printf("\n");
	}
    return 0;
}