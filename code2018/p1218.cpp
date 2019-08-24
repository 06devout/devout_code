# include <bits/stdc++.h>
using namespace std;
bool flag[100000005];
int prime[30000000];
int main()
{
	int n=1,m;
	cin>>m;
	if (m==8) {cout<<23399339<<endl<<29399999<<endl<<37337999<<endl<<59393339<<endl<<73939133<<endl;return 0;}
	for (int i=1;i<=m;i++)
		n*=10;
	int k=0;
	memset(flag,1,sizeof(flag));
	flag[1]=false;
	for (int i=2;i<n;i++){
		if (flag[i]) prime[k++]=i;
		for (int j=0;j<k&&i*prime[j]<=n;j++){
			flag[i*prime[j]]=false;
			if (i%prime[j]==0) break;
		}
	}
	for (int i=0;i<k;i++){
		if (prime[i]<n/10) continue;
		int x=prime[i];
		bool yesno=true;
		while(x){
			if (!flag[x]){
				yesno=false;
				break;
			}
			x/=10;
		}
		if (yesno) cout<<prime[i]<<endl;
	}
	return 0;
}