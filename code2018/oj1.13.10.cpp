# include <cstdio>
# include <algorithm>
# include <cstring>

using namespace std;

bool prime(int a)
{
	if (a==0||a==1) return false;
	if (a==2||a==3) return true;
	for (int i=2;i*i<=a;i++)
		if (a%i==0) return false;
	return true;
}
int main()
{
	int x,y;
	scanf("%i%i",&x,&y);
	if (x>y) swap(x,y); 
	int cnt=0;
	for (int i=x;i<=y;i++)
		if (prime(i)) cnt++;
	printf("%i\n",cnt);
	return 0;
}