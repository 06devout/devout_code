# include <cstdio>
# include <algorithm>
# include <cstring>
# include <cmath>

# define f(i,a,b) for (int i=a;i<=b;i++)
# define F(i,a,b) for (int i=a;i<=b;i++)

using namespace std;

const int N=20;

int dp[N][N],a[N][N];

int main()
{
	freopen("euler18.in","r",stdin);
	freopen("euler18.out","w",stdout);
	f(i,1,15) f(j,1,i) scanf("%d",&a[i][j]);
	dp[1][1]=a[1][1];
	f(i,2,15){
		f(j,1,i){
			dp[i][j]=max(dp[i-1][j],dp[i-1][j-1])+a[i][j];
		}
	}
	int ans=0;
	f(i,1,15) ans=max(ans,dp[15][i]);
	printf("%d\n",ans);
	return 0;
}