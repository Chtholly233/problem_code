#include<cstdio>

//#define DEBUG

int n,m,c[10010],p1,s1,p2,s2;
int dragon,tiger;

inline int read(){
	int x=0,w=1;
	char c=getchar();
	while(c>'9'||c<'0'){
		if(c=='-')w=-1;
		c=getchar();
	}
	while(c<='9'&&c>='0'){
		x=(x<<3)+(x<<1)+c-'0';
		c=getchar();
	}
	return w*x;
}

int ginum(int i,int j){
	return i>j?i-j:j-i;
}

int c_point(int l,int r){
	int cnt=0;
	for(int i=l;i<=r;i++){
		cnt+=c[i]*ginum(m,i);
	}
	return cnt;
}

int main(){
	
	freopen("testdata.in","r",stdin);
	freopen("test.out","w",stdout);
	
	n=read();
	for(int i=1;i<=n;i++){
		c[i]=read();
	}
	//scanf("%d%d%d%d",&m,&p1,&s1,&s2);
	m=read();p1=read();s1=read();s2=read();
	c[p1]+=s1;
	
	dragon=c_point(1,m-1);
	tiger=c_point(m+1,n);
	
	#ifdef DEBUG
	printf("\n%d %d\n",dragon,tiger);
	#endif
	
	int min=ginum(tiger,dragon),nn,_min;
	if(dragon>tiger){
		for(int i=m+1;i<=n;i++){
			nn=tiger+s2*(i-m);
			_min=ginum(nn,dragon);
			if(_min<min){
				p2=i;
				min=_min;
			}
		}
	}
	if(dragon<tiger){
		for(int i=1;i<=m-1;i++){
			nn=dragon+s2*(m-i);
			_min=ginum(nn,tiger);
			if(_min<min){
				p2=i;
				min=_min;
			}
		}	
	}
	printf("%d",p2);
	
	return 0;
}
