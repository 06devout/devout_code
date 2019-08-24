# include <bits/stdc++.h>

using namespace std;

struct pp{
	int first;
	int second;
};
pp p[10000000];
int cmp(pp a,pp b)
{
	if (a.first!=b.first) return a.first<b.first;
	return a.second<b.second;
}
int main()
{
	int n,m;
	cin>>n>>m;
	for (int i=1;i<=m;i++)
		cin>>p[i].first>>p[i].second;
	sort(p+1,p+1+m,cmp);
	int tmp=0;
	int total=0;
	while(n>0){
		tmp++;
		if (n<p[tmp].second){
			total+=p[tmp].first*n;
			break;
		}
		total+=p[tmp].first*p[tmp].second;
		n-=p[tmp].second;
	}
	cout<<total<<endl;
	return 0;
}