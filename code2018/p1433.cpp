# include <cstdio>
# include <algorithm>
# include <cstring>
# include <cmath>
# include <climits>
# define Rep(i,a,b) for (int i=a;i<=b;i++)
# define _Rep(i,a,b) for (int i=a;i<=b;i++)

using namespace std;

const int N=20;
bool flag[N];
int n;
double x[N],y[N];
double ans=100000;
void dfs(int t,double sum,double last_x,double last_y)
{
	if (sum>ans) return;
	if (t==n){
		ans=min(ans,sum);
		return;
	}
	Rep(i,1,n){
		if (flag[i]) continue;
		flag[i]=true;
		dfs(t+1,sum+sqrt((x[i]-last_x)*(x[i]-last_x)+(y[i]-last_y)*(y[i]-last_y)),x[i],y[i]);
		flag[i]=false;
	}
}
int main()
{
	scanf("%d",&n);
	Rep(i,1,n) scanf("%lf%lf",&x[i],&y[i]);
	dfs(0,0,0,0);
	printf("%.2lf\n",ans);
	return 0;
}