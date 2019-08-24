# include <cstdio>
# include <algorithm>
# include <cstring>
# include <cmath>
# include <climits>
# define f(i,a,b) for (int i=a;i<=b;i++)
# define F(i,a,b) for (int i=a;i>=b;i--)

using namespace std;

const int N=40005;

int phi[N];

void euler_onlogn(int n)
{
	f(i,1,n) phi[i]=i;
	f(i,2,n)
		if (phi[i]==i)
			for (int j=i;j<=n;j+=i)
				phi[j]=phi[j]/i*(i-1);
}
int main()
{
	int n;
	scanf("%d",&n);
	if (n==1) return printf("1\n"),0;
	euler_onlogn(n+1);
	printf("%d\n",n-phi[n]);
	return 0;
}