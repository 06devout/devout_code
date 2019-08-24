# include <cstring>
# include <iostream>
# include <algorithm>

using namespace std;

int main()
{
	int n;
	cin>>n;
	int num[n+1];
	for (int i=1;i<=n;i++)
		cin>>num[i];
	// int tmp[1000000000];
	// memset(tmp,0,sizeof(tmp));
	// for (int i=1;i<=n;i++)
	// 	tmp[num[i]]++;
	// for (int i=1;i<=1000000000;i++)
	// 	for (int j=1;j<=tmp[i];j++)
	// 		cout<<num[i]<<" ";
	sort(num+1,num+n+1);
	for (int i=1;i<=n;i++)
		cout<<num[i]<<" ";
	return 0;
}