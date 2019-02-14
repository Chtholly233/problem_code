#include<cstdio>
using namespace std;

long long n,ans=0;

void sort(long long A[],long long L,long long R,long long T[]) {
    if(R-L>1) {
        long long M=L+(R-L)/2;
        long long p=L,q=M,i=L;
        
        sort(A,L,M,T);
        sort(A,M,R,T);

        while(p<M||q<R) {
            if(q>=R||(p<M&&A[p]<=A[q]))
                T[i++]=A[p++];
            else {
                T[i++]=A[q++];
                ans+=M-p;
            }
        }
        for(i=L; i<R; i++)A[i]=T[i];
    }
}

int main() {
    long long A[500001],T[500001];
    scanf("%lld",&n);
    for(long long i=0; i<n; i++)
        scanf("%lld",&A[i]);
    sort(A,0,n,T);
    printf("%lld",ans);
    return 0;
}
