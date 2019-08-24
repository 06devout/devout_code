# include <cstdio>
# include <algorithm>
# include <cstring>
# include <cmath>
# include <vector>
# define f(i,a,b) for (int i=a;i<=b;i++)
# define F(i,a,b) for (int i=a;i>=b;i--)
# define f_plus(i,a,b) for (int i=a;i*i<=b;i++)
using namespace std;

typedef long long ll;
vector<int> prime;
int sz;
int find(int n){
	int cnt=0;
	if (n==1) return 0;
	if (n==2) return prime.push_back(2),++cnt;
	if (n==3) return prime.push_back(2),prime.push_back(3),cnt+=2,cnt;
	int stand=n;
	f_plus(i,2,stand) if (n%i==0) {prime.push_back(i);cnt++;while(n%i==0) n/=i;}
	return cnt;
}
ll exphi(ll n){
	ll ans=n;
	f(i,0,sz){
		if (n%prime[i]==0){
			ans=ans/prime[i]*(prime[i]-1);
			while(n%prime[i]==0) n/=prime[i];
		}
	}
	if (n>1) ans=ans/n*(n-1);
	return ans;
}
int main()
{
	ll n;
	scanf("%lld",&n);
	ll ans=0;

	sz=find(n)-1;
	// printf("%lld\n",exphi(n));
	// f(i,0,sz) printf("%d ",prime[i]);
	f_plus(i,1,n)
		if (n%i==0) {
			ll tmp=n/i;
			ans+=i*exphi(tmp);
			if (i!=tmp){ 
				ans+=tmp*exphi(i);
			}
		}
	printf("%lld\n",ans);
	return 0;
}