# include <cstdio>
# include <algorithm>
# include <cstring>
# include <cmath>
# include <climits>
# define f(i,a,b) for (int i=a;i<=b;i++)
# define F(i,a,b) for (int i=a;i>=b;i--)

using namespace std;

const int N=50;

const int M=30005;

int v[N],w[N],f[M];

int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	f(i,1,m) scanf("%d",&v[i]),w[i]=v[i];
	f(i,1,m) F(j,n,v[i]) if (j>=v[i]) f[j]=max(f[j],f[j-v[i]]+w[i]);
	printf("%d\n",n-f[n]);
	return 0;
}