# include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	cin>>n;
	int hight[n+1];
	for (int i=1;i<=n;i++){
		cin>>hight[i];
	}
	int ans=2147483647;
	for (int i=0;i<84;i++){
		int sum=0;
		for (int j=1;j<=n;j++){
			if (hight[j]> i + 17) sum+=(hight[j]-17-i)*(hight[j]-17-i);
			if (hight[j] < i)  sum+=(i-hight[j])*(i-hight[j]);
		}
		ans=min(ans,sum);
	}
	cout<<ans<<endl;
	return 0;
}