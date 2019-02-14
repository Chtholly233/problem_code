#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
 
bool cmp(vector<int> a, vector<int> b)
{
	if(a[0] != b[0]) return a[0] > b[0];
	if(a[1] != b[1]) return a[1] > b[1];
	if(a[2] != b[2]) return a[2] > b[2];
}
 
int main()
{
	vector< vector<int> > vec = { {1,4,3}, {1,4,7} , {1,3,5} , {2,9,4} , {2,5,8} , {3,9,6} };
	
	sort(vec.begin(), vec.end(), cmp);
 
	for(auto p : vec)
		cout<<p[0]<<' '<<p[1]<<' '<<p[2]<<endl;
 
	return 0;
}

