# include <cstdio>
# include <algorithm>
# include <cstring>
# include <cmath>

# define f(i,a,b) for (int i=a;i<=b;i++)
# define F(i,a,b) for (int i=a;i>=b;i--)

using namespace std;

struct int5000{
	static const int N=5001;
	static char s[N];
	int num[N];
	int5000(){
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
	bool operator < (const int5000 &cmp) const {
		if (num[0]!=cmp.num[0]) return num[0]<cmp.num[0];
		F(i,num[0],1) if (num[i]!=cmp.num[i]) return num[i]<cmp.num[i];
		return false;
	}
	int5000 operator * (const int &x) const {
		int5000 b;
		b.num[0]=num[0];
		f(i,1,b.num[0]) b.num[i]+=x*num[i];
		f(i,1,b.num[0]){
			b.num[i+1]+=b.num[i]/10;
			b.num[i]%=10;
			if (b.num[i+1]) b.num[0]=max(b.num[0],i+1);
		}
		return b;
	}
	int5000 operator / (const int &d) const {
		int5000 b=*this;
		F(i,b.num[0],1) b.num[i]+=b.num[i+1]%d*10;
		f(i,1,b.num[0]) b.num[i]/=d;
		while(!b.num[b.num[0]]&&b.num[0]>1) b.num[0]--;
		return b;
	}
	int5000 operator * (const int5000 &x) const {
		int5000 b;
		b.num[0]=num[0]+x.num[0]-1;
		f(i,1,num[0]) {
			f(j,1,x.num[0]){
				b.num[i+j-1]+=num[i]*x.num[j];
				b.num[i+j]+=b.num[i+j-1]/10;
				b.num[i+j-1]%=10;
			}
		}
		if (b.num[b.num[0]+1]) b.num[0]++;
		return b;
	}
};
char int5000::s[N];
int main()
{
	int5000 a,b,c;
	a.read();
	b.read();
	c=a*b;
	c.write();
	// a.read();
	// b.read();
	// c=a*b;
	// c.write();
	return 0;
}