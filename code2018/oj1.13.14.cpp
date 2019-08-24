# include <bits/stdc++.h>

using namespace std;

bool square(int a){
	for (int i=10;i*i<=a;i++)
		if (i==a/i&&a%i==0) return true;
	return false;
}
bool two_same(int a){
	int num[5],cnt=0;
	while(a){
		num[++cnt]=a%10;
		a/=10;
	}
	if (num[1]==num[2]||num[1]==num[3]||num[2]==num[3]) return true;
	else return false;
}
int main()
{
	int n;
	scanf("%d",&n);
	int f[100];
	int cnt=0;
	for (int i=100;i<=1000;i++) if (square(i)) if (two_same(i)) f[++cnt]=i;
	printf("%d\n",f[n]);
    return 0;
}