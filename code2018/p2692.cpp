# include <cstdio>
# include <algorithm>
# include <cstring>
# include <cmath>

# define f(i,a,b) for (int i=a;i<=b;i++)
# define F(i,a,b) for (int i=a;i>=b;i--)

using namespace std;

const int N=40,M=600;
int n,m;
bool a[N][N],b[N];

void gause()
{
	f(i,1,n){
		if (!a[i][i])
			f(j,i+1,n){
				if (a[j][i]){
					f(k,1,n) swap(a[j][k],a[i][k]);
					swap(b[i],b[j]);
					break;
				}
			}
		f(j,1,n){
			if (i==j) continue;
			if (a[j][i]){
				f(k,1,n) a[j][k]^=a[i][k];
				b[j]^=b[i];
			}
		}
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	f(i,1,m){
		int x,y;
		scanf("%d%d",&x,&y);
		a[x][y]=true;
		a[y][x]=true;
	}
	f(i,1,n) a[i][i]=true;
	memset(b,1,sizeof(b));
	gause();
	int ans=0;
	f(i,1,n)if (b[i]&&a[i][i]) ans++;
	printf("%d\n",ans);
	return 0;
}