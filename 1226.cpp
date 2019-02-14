#include<cstdio>

long long b,p,k;

long long quickpow(long long d,long long zs){
	if(zs==0)return 1;
	long long r=quickpow(d,zs/2)%k;
	r=r*r%k;
	if(zs%2==1)r=r*d%k;
	return r;
}

int main(){
	scanf("%lld%lld%lld",&b,&p,&k);
	printf("%lld^%lld mod %lld=%lld",b,p,k,quickpow(b,p)%k);
	return 0;
}
