#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int cmp(const void* a,const void* b){
    return strcmp((char**)a,(char**)b);
}
int main(void){
    char s[10][10];
    int i,n;
    scanf("%d",&n);
    for(i=0;i<n;i++) {
        scanf("%s",s[i]);
    }
    qsort(s,n,sizeof(s[0]),cmp);
    for(i=0;i<n;i++) {
        puts(s[i]);
    }
    return 0;
}
