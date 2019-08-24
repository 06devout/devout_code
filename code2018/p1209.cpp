# include <bits/stdc++.h>

using namespace std;

int cmp(int a,int b)
{
	return a>b;
}
int main()
{
	int m,s,c;
	cin>>m>>s>>c;
	int cow[c+1];
	for (int i=1;i<=c;i++)
		cin>>cow[i];
	if (m>=c){
		cout<<c<<endl;
		return 0;
	}
	sort(cow+1,cow+c+1);
	int bet[c+1];
	for (int i=1;i<c;i++) bet[i]=cow[i+1]-cow[i];
	sort(bet+1,bet+c,cmp);
	int ans=cow[c]-cow[1]+1;
	for (int i=1;i<m;i++){
		ans-=bet[i]-1;
	}
	cout<<ans<<endl;
	return 0;
}