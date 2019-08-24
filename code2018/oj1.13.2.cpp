# include <cstdio>
# include <algorithm>
# include <cstring>

using namespace std;

const int mod=7;

int main()
{
	int day;
	scanf("%d",&day);
	day--;
	day+=12;
	day=day%mod;
	if (day==4) printf("1\n");
	day+=3;
	day=day%mod;
	if (day==4) printf("2\n");
	day=day%mod;
	if (day==4) printf("3\n");
	day+=3;
	day=day%mod;
	if (day==4) printf("4\n");
	day+=2;
	day=day%mod;
	if (day==4) printf("5\n");
	day+=3;
	day=day%mod;
	if (day==4) printf("6\n");
	day+=2;
	day=day%mod;
	if (day==4) printf("7\n");
	day+=3;
	day=day%mod;
	if (day==4) printf("8\n");
	day+=3;
	day=day%mod;
	if (day==4) printf("9\n");
	day+=2;
	day=day%mod;
	if (day==4) printf("10\n");
	day+=3;
	day=day%mod;
	if (day==4) printf("11\n");
	day+=2;
	day=day%mod;
	if (day==4) printf("12\n");
	return 0;
}