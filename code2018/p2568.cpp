# include <cstdio>
# include <algorithm>
# include <cstring>
# include <cmath>
# include <climits>

using namespace std;

const int N=1e7+5;

int phi[N],p[N/2],t;
bool flag[N];
void euler(int n){
	memset(flag,1,sizeof(flag));
	for (int i=2;i<=n;i++){
		if (flag[i]) p[++t]=i,phi[i]=i-1;
		for (int j=1;j<=t&&p[j]*i<=n;j++){
			flag[p[j]*i]=false;
			if (i%p[j]==0) {phi[p[j]*i]=phi[i]*p[j];break;}
			phi[p[j]*i]=phi[i]*(p[j]-1);
		}
	}
}
int main()
{
	int n;
	scanf("%d",&n);
	euler(n);
	long long ans=0;
	for (int i=1;i<=t;i++){
		long long plus_cnt=0;
		for (int j=1;j<=n/p[i];j++) plus_cnt+=phi[j];
		ans+=plus_cnt*2+1;
	}
	// for (int i=1;i<=t;i++){
	// 	if (p[i]<=n/2){
	// 		num++;
	// 	}
	// 	else break;
	// }
	// int k=1;
	// while(num){
	// 	k++;
	// 	ans+=phi[k]*num;
	// 	if (flag[k]) num--;
	// }
	// ans*=2;
	// ans+=t;
	printf("%lld\n",ans);
	return 0;
}