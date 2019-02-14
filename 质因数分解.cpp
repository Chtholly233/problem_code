#include<cstdio>
#include<cmath>
int main(){
int n=76,sz=sqrt(n),i;
for(i=2;i<=sz;i++){
    while(n%i==0) n/=i,printf("%d ",i);
}
    if(n!=1) printf("%d\n",n);
    return 0;
}


