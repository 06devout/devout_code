# include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	cin>>n;
	int ave=0;
	int num[n+1];
	for (int i=1;i<=n;i++){
		cin>>num[i];
		ave+=num[i];
	}
	ave/=n;
	int time=0;
	for (int i=1;i<n;i++){
		if (ave==num[i]) continue;
		if (ave>num[i]) num[i+1]-=(ave-num[i]);
		if (ave<num[i]) num[i+1]+=(num[i]-ave);
		time++;
	}
	cout<<time<<endl;
	return 0;
}