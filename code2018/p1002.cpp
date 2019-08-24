# include <cstdio>
# include <algorithm>
# include <cstring>
# include <cmath>
# include <climits>
# define f(i,a,b) for (int i=a;i<=b;i++)
# define F(i,a,b) for (int i=a;i>=b;i--)

using namespace std;

struct Gaojing{
	static const int N=2000;
	static char s[N];
	int num[N];
	Gaojing(){
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
	Gaojing operator + (const Gaojing &a) const {
		Gaojing b;
		b.num[0]=max(num[0],a.num[0]);
		f(i,1,b.num[0]) b.num[i]+=num[i]+a.num[i],b.num[i+1]+=b.num[i]/10,b.num[i]%=10;
		if (b.num[b.num[0]+1]) b.num[0]++;
		return b;
	}
};
char Gaojing::s[N];
const int N=30;
Gaojing dp[N][N];
bool control[N][N];
int main(){
	int m,n,x,y;
	scanf("%d%d%d%d",&m,&n,&x,&y);
	control[x][y]=true;
	if (x>=2&&y>=1) control[x-2][y-1]=true;
	if (x>=1&&y>=2) control[x-1][y-2]=true;
	if (x>=2) control[x-2][y+1]=true;
	if (x>=1) control[x-1][y+2]=true;
	if (y>=2) control[x+1][y-2]=true;
	if (y>=1) control[x+2][y-1]=true; 
	control[x+1][y+2]=true;
	control[x+2][y+1]=true;
	f(i,0,n) if (control[0][i]) break;
		else dp[0][i].num[1]=1;
	f(i,0,m) if (control[i][0]) break;
		else dp[i][0].num[1]=1;
	f(i,1,m){
		f(j,1,n){
			// if ((i==x&&j==y)||(i==y&&j==x)||(i==x+2&&j==y+1)||(i==x+2&&j==y-1)||(i==x-2&&j==y+1)||(i==x-2&&j==y-1)||(i==y+1&&j==x+2)||(i==y+1&&j==x-2)||(i==y-1&&j==x+2)||(i==y-1&&j==x-2)) continue;
			if (control[i][j]) continue;
			dp[i][j]=dp[i][j-1]+dp[i-1][j];
		}
	}
	dp[m][n].write();
	return 0;
}