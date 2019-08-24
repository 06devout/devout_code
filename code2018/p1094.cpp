# include <bits/stdc++.h>

using namespace std;

int main()
{
	int max_prize,n;
	cin>>max_prize>>n;
	int value[n+1];
	for (int i=1;i<=n;i++)
		cin>>value[i];
	sort(value+1,value+n+1);
	int ans=0;
	bool flag[n+1];
	memset(flag,0,sizeof(flag));
	int cap=1;
	for (int i=n;i>=1;i--){
		if (value[i]+value[cap]<=max_prize&&!flag[i]&&!flag[cap]){
			ans++;
			flag[cap]=true;
			cap++;
			flag[i]=true;
		}
		else if (value[i]+value[cap]>max_prize&&!flag[i]&&!flag[cap])
			ans++;
		if (cap>i) break;
	}
	cout<<ans<<endl;
	return 0;
}