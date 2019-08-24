# include <cstdio>
# include <cstring>
# include <algorithm>

using namespace std;

bool prime(int a)
{
	for (int i=2;i*i<=a;i++)
		if (a%i==0) return false;
	return true;
}
bool panlindrome(int a)
{
	int num[5];
	memset(num,0,sizeof(num));
	int cnt=0;
	while(a){
		num[++cnt]=a%10;
		a/=10;
	}
	for (int i=1;i<=cnt;i++)
		if (num[i]!=num[cnt-i+1]) return false;
	return true;
}
int main()
{
	int n;
	scanf("%d",&n);
	int ans=0;
	for (int i=11;i<=n;i++) if (panlindrome(i)) if (prime(i)) ans++;
	printf("%d\n",ans);
    return 0;
}