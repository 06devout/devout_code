# include <cstdio>
# include <algorithm>
# include <cstring>
# include <cmath>
# include <climits>
# define f(i,a,b) for (int i=a;i<=b;i++)
# define F(i,a,b) for (int i=a;i<=b;i++)
# define f_plus(i,a,b,c) for (int i=a;i<=b;i+=c)
const int N=1e7+5;
const int mod=666623333;
int phi[N];
void make(int n){
	f(i,1,n) phi[i]=i;
	f(i,2,n)
		if (phi[i]==i)
			f_plus(j,i,n,i)
				phi[j]=phi[j]/i*(i-1);
}
int main()
{
	
	int l,r;
	scanf("%d%d",&l,&r);
	int ans=0;
	make(r);
	phi[1]=0;
	f(i,l,r) ans+=i-phi[i],ans%=mod;
	printf("%d\n",ans);
	return 0;
}