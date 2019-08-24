# include <iostream>
# include <queue>

using namespace std;
int num[110005];
queue <pair<int,int> > q;
int main()
{
	int n;
	cin>>n;
	int ans=0;
	for (int i=1;i<=n;i++){
		
		int t,k,nation;
		cin>>t>>k;
		for (int j=1;j<=k;j++){
			cin>>nation;
			if (num[nation]++ == 0) ans++;
			q.push(make_pair(nation,t));
		}
		while(!q.empty()&&q.front().second+86400<=t){
			if (--num[q.front().first]==0) ans--;
			q.pop();
		}
		cout<<ans<<endl;
	}
	return 0;
}
