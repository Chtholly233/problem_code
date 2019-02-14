inline long long read(){
	char c=getchar();long long x=0,w=1;
	while(x<'0'||x>'9'){
		if(c=='-')w=-1;
		c=getchar();
	}
	while(x>='0'&&x<='9'){
		x=(x<<3)+(x<<1)+c-'0';
		c=getchar();
	}
	return x*w;
}
