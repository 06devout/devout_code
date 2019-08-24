# include <cstdio>
# include <cstring>
# include <algorithm>
# include <cmath>

# define f(i,a,b) for (int i=a;i<=b;i++)
# define F(i,a,b) for (int i=a;i>=b;i--)

using namespace std;

struct int100{
	static const int N=105;
	static char s[N];
	int num[N];
	int100(){
		memset(num,0,sizeof(num));
		num[0]=1;
	}
	void read(){
		scanf("%s",s);
		num[0]=strlen(s)+1;
		f(i,1,num[0]) num[i]=(int)s[num[0]-i]-48;
	}
	void ten_write(){
		F(i,num[0],num[0]-9) printf("%d",num[i]);
		puts("");
	}
	bool operator < (const int100 &cmp) const {
		if (num[0]!=cmp.num[0]) return num[0]<cmp.num[0];
		F(i,num[0],1) if (num[i]!=cmp.num[i]) return num[i]<cmp.num[i];
		return false;
	}
	int100 operator + (const int100 &a) const {
		int100 b;
		b.num[0]=max(num[0],a.num[0]);
		f(i,1,b.num[0]){
			b.num[i]+=num[i]+a.num[i];
			if (b.num[i]>=10){
				b.num[i]-=10;
				b.num[i+1]++;
			}
		}
		if (b.num[b.num[0]+1]) b.num[0]++;
		return b;
	}
};
char int100::s[N];

int main()
{
	freopen("euler13.in","r",stdin);
	freopen("euler13.out","w",stdout);
	int100 a[105];
	f(i,1,100) a[i].read();
	int100 sum;
	f(i,1,100) sum=sum+a[i];
	sum.ten_write();
	return 0;
}