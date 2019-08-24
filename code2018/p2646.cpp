# include <cstdio>
# include <algorithm>
# include <cstring>
# include <cmath>
# include <climits>
# define Rep(i,a,b) for (int i=a;i<=b;i++)
# define _Rep(i,a,b) for (int i=a;i>=b;i--)

using namespace std;

const int N=100005;

char c;
long long z,ans;
int main()
{
	while(scanf("%c",&c)!=EOF){
		if (c=='z') z++;
		if (c=='y') ans+=z*(z-1)/2;
	}
	printf("%lld\n",ans);
	return 0;
}