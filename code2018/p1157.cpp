# include <cstdio>
# include <algorithm>
# include <cstring>
# include <cmath>
# include <climits>
# define Rep(i,a,b) for (int i=a;i<=b;i++)
# define _Rep(i,a,b) for (int i=a;i>=b;i--)

using namespace std;

const int N=25;
bool flag[N];
int a[N],n,r;
void dfs(int t,int last){
	if (t==r) {
		Rep(i,1,r) printf("%3d",a[i]);
		puts("");
		return;
	}
	Rep(i,last,n){
		if (flag[i]) continue;
		a[t+1]=i;
		flag[i]=true;
		dfs(t+1,i);
		flag[i]=false;
	}
}
int main()
{
	scanf("%d%d",&n,&r);
	dfs(0,1);
	return 0;
}