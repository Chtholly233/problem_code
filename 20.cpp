#include<math.h>
#include<iostream>

using namespace std;

int xa,ya,xb,yb;

int main(){
    cin>>xa>>ya>>xb>>yb;
    cout<<(abs(xa-xb)+abs(ya-yb))<<"\n";
    return 0;
}