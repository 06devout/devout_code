# include <bits/stdc++.h>

using namespace std;

int one_in_double_jinzhi_num(int a)
{
	int ans=0;
	while(a){
		if (a%2==1) ans++;
		a/=2;
	}
	return ans;
}
int main()
{
	int n;
	cin>>n;
	while(n){
		int x=one_in_double_jinzhi_num(n);
		int i=n;
		while(one_in_double_jinzhi_num(++i)!=x){}
		cout<<i<<endl;
		cin>>n;
	}
	return 0;
}