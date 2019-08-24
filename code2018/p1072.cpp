# include <cstdio>
# include <algorithm>
# include <cstring>
# include <cmath>
# include <climits>
# define f(i,a,b) for (int i=a;i<=b;i++)
# define F(i,a,b) for (int i=a;i>=b;i--)

using namespace std;

int gcd(int a,int b){
	if (b==0) return a;
	return gcd(b,a%b);
}
int main()
{
	int t;
	scanf("%d",&t);
	int a0,a1,b0,b1;
	while(t--){
		int ans=0;
		scanf("%d%d%d%d",&a0,&a1,&b0,&b1);
		for (int i=1;i*i<=b1;i++){
			if (b1%i==0){
				if (i%a1==0&&gcd(i/a1,a0/a1)==1&&gcd(b1/i,b1/b0)==1) ans++;
				int rate=b1/i;
				if (rate==i) continue;
				if (b1%i==0){
					if (rate%a1==0&&gcd(a0/a1,rate/a1)==1&&gcd(b1/b0,b1/rate)==1) ans++;
				}
			}
			
		}
		printf("%d\n",ans);
	}
	return 0;
}