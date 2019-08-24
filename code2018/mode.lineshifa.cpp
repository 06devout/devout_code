# include <bits/stdc++.h>

using namespace std;
bool flag[100000001];
int prime[30000000],k=0;

int main()
{
	int n;
	cin>>n;
	
	memset(flag,1,sizeof(flag));
	flag[0]=flag[1]=false;
		for (int i=2;i<=n;i++){
		if (flag[i]) prime[k++]=i;
		for (int j=0;j<k&&1ll*i*prime[j]<=n;j++){
			flag[i*prime[j]]=false;
			if (i%prime[j]==0) break;
		}
	}
	int m;
	cin>>m;
	int ask_prime;
	for (int i=1;i<=m;i++){
		cin>>ask_prime;
		if (flag[ask_prime]) cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
	return 0;

}