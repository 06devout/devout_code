# include <cstdio>
# include <iostream>
# include <cstring>

using namespace std;

struct boat{
	int start,end;
	int peonation[22000];
};
boat sail[22000];
int muchyesper()
{
	int ans=0;
	for (int i=1;i<=50000;i++)
		if (sail[a].peonation[i]>0) ans++;
	return ans;
}
int main()
{
	int n;
	cin>>n;
	int t[n+1],p[n+1],nation[n+1][100000];
	for (int i=1;i<=n;i++){
		cin>>t[i]>>p[i];
		for (int j=1;j<=p[i];j++)
			cin>>nation[i][j];
		sail[i].start=t[i]-86400;
		sail[i].end=t[i];
		for (int j=1;j<=i;j++){
			if (sail[j].end<=sail[i].start) continue;
			for (int k=1;k<=p[j];k++){
				sail[i].peonation[nation[j][k]]++;
			}
		}
		cout<<muchyesper()<<endl;
	}
	return 0;
}