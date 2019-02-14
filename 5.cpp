#include <iostream>

using namespace std;

int main ()
{
	printf("已知矩形的大小为n×m，现用a×a的正方形填充该矩形。输入三个正整数n,m,a（n,m,a≤10^9），计算至多能填入多少正方形？（正方形可以正好碰到矩形边界，但不能超出矩形外）\n");
	long n,m,a,w,h;
	cin >> n >> m >> a;
	w = n/a;
	h = m/a;
	cout << w*h;
	return 0;
}