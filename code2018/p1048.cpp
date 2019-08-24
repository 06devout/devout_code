# include <cstdio>
# include <algorithm>
# include <cstring>
# include <cmath>
# include <climits>
# define f(i,a,b) for (int i=a;i<=b;i++)
# define F(i,a,b) for (int i=a;i>=b;i--)

using namespace std;

const int N=1005;

int v[N],w[N],dp[N];

int main()
{
	int t,m;
	scanf("%d%d",&t,&m);
	f(i,1,m) scanf("%d%d",&v[i],&w[i]);
	f(i,1,m) F(j,t,0) if (j>=v[i]) dp[j]=max(dp[j],dp[j-v[i]]+w[i]);
	printf("%d\n",dp[t]);
	return 0;
}