# include <cstdio>
# include <algorithm>
# include <cstring>
# include <cmath>

# define f(i,a,b) for (int i=a;i<=b;i++)
# define F(i,a,b) for (int i=a;i>=b;i--)

using namespace std;

struct int500{
	static const int N=505;
	static char s[N];
	int num[N];
	int500(){
		memset(num,0,sizeof(num));
		num[0]=1;
	}
	void read(){
		scanf("%s",s);
		num[0]=strlen(s);
		f(i,1,num[0]) num[i]=(int)s[num[0]-i]-48;
	}
	void write(){
		F(i,num[0],1) printf("%d",num[i]);
		puts("");
	}
	int500 operator * (const int500 &x) const {
		int500 b;
		b.num[0]=num[0]+x.num[0]-1;
		f(i,1,num[0]){
			f(j,1,x.num[0]){
				b.num[i+j-1]+=num[i]*x.num[j];
				b.num[i+j]+=b.num[i+j-1]/10;
				b.num[i+j-1]%=10;
			}
		}
		if(b.num[b.num[0]+1])b.num[0]++;
		return b;
	}
};
char int500::s[N];
int main()
{
	int500 a,b,c;
	a.read();
	b.read();
	if ((a.num[0]==1&&a.num[1]==0)||(b.num[0]==1&&a.num[1]==0)) return printf("0\n"),0;
	c=a*b;
	c.write();
	return 0;
}