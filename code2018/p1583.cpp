# include <cstdio>
# include <algorithm>
# include <iostream>

using namespace std;

struct people{
	int num;
	int w;
	int c;
	int d;
};
int cmp1(people a,people b)
{
	if (a.w!=b.w) return a.w>b.w;
	else return a.num<b.num;
}
int cmp2(people a,people b)
{
	if (a.w!=b.w) return a.w>b.w;
	else return a.num<b.num;
}
people ren[100000];
int main()
{
	int n,k;
	cin>>n>>k;
	int e[11];
	for (int i=1;i<=10;i++)
		cin>>e[i];
	for (int i=1;i<=n;i++)
		cin>>ren[i].w;
	for (int i=1;i<=n;i++)
		ren[i].num=i;
	sort(ren+1,ren+1+n,cmp1);
	for (int i=1;i<=n;i++)
		ren[i].d=i;
	for (int i=1;i<=n;i++)
		ren[i].c=(ren[i].d-1)%10+1;
	for (int i=1;i<=n;i++)
		ren[i].w+=e[ren[i].c];
	sort(ren+1,ren+n+1,cmp2);
	for (int i=1;i<=k;i++)
		cout<<ren[i].num<<" ";
	cout<<endl;
	return 0;
}