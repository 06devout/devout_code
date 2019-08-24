# include <cstdio>
# include <algorithm>
# include <cstring>
# include <cmath>
# include <climits>
# define f(i,a,b) for (int i=a;i<=b;i++)
# define F(i,a,b) for (int i=a;i>=b;i--)

using namespace std;

const int N=30;

const int M=30005;

int c[N],v[N];

int f[M];

int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	f(i,1,m) scanf("%d%d",&c[i],&v[i]),v[i]*=c[i];
	f(i,1,m) F(j,n,c[i]) if (j>=c[i]) f[j]=max(f[j],f[j-c[i]]+v[i]);
	printf("%d\n",f[n]);
	return 0;
}