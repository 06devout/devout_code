# include <iostream>
# include <vector>
# include <algorithm>

using namespace std;

struct point{
	int x,y;
}superbig[500005];
vector <point > vec;
int cmp(point a,point b){
	if (a.x!=b.x) return a.x<b.x;
	return a.y<b.y;
}
int main()
{
	int n;
	cin>>n;
	for (int i=1;i<=n;i++)
		cin>>superbig[i].x>>superbig[i].y;
	sort(superbig+1,superbig+n+1,cmp);
	for (int i=1;i<=n;i++){
		while(!vec.empty())
			if(superbig[i].y>=vec.back().y) vec.pop_back();
			else break;
		vec.push_back(superbig[i]);
	}
	cout<<'('<<vec[0].x<<','<<vec[0].y<<')';
	for (int i=1;i<vec.size();i++){
		cout<<",("<<vec[i].x<<','<<vec[i].y<<')';
	}
	return 0;
}                                                                                                                                 