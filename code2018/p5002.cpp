# include <cstdio>
# include <algorithm>
# include <cstring>
# include <cmath>
# include <vector>
# define f(i,a,b) for (int i=a;i<=b;i++)
# define F(i,a,b) for (int i=a;i>=b;i--)

using namespace std;

const int N=10005;

const int mod=1e9+7;
vector <int> e[N];
int a,b,n,r,m,num[N],ans[N];
void dfs(int root,int par){
	num[root]=1;
	for (int i=0;i<e[root].size();i++){
		if (e[root][i]==par) continue;
		dfs(e[root][i],root);
		num[root]+=num[e[root][i]];
		ans[root]-=1ll*num[e[root][i]]%mod*num[e[root][i]]%mod;
	}
	ans[root]+=1ll*num[root]%mod*num[root]%mod;
}
int main()
{
	scanf("%d%d%d",&n,&r,&m);
	f(i,1,n-1) scanf("%d%d",&a,&b),e[a].push_back(b),e[b].push_back(a);
	dfs(r,0);
	int x;
	while(m--){
		scanf("%d",&x);
		printf("%d\n",ans[x]);
	}
	return 0;
}