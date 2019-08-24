# include <bits/stdc++.h>
# define N 100005
using namespace std;

int phi[N];
int n;
void euler()
{
	for (int i=1;i<=n;i++)
		phi[i]=i;
	for (int i=2;i<=n;i++)
		if (phi[i]==i)
			for (int j=i;j<=n;j+=i)
				phi[j]=phi[j]/i*(i-1);
}
int main()
{
	scanf("%d",&n);
	if (n==1){
		printf("0\n");
		return 0;
	}
	euler();
	int ans=0;
	for (int i=2;i<n;i++)
		ans+=phi[i];
	printf("%d\n",ans*2+3);
	return 0;
}