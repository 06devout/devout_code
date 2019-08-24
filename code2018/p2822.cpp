# include <cstdio>
# include <algorithm>
# include <cstring>
# include <cmath>
# include <climits>
# define f(i,a,b) for (int i=a;i<=b;i++)
# define F(i,a,b) for (int i=a;i>=b;i--)

using namespace std;

const int N=2005;

int c[N][N],k,d[N][N];

void make(){
	c[0][0]=1;
	c[1][0]=1;
	c[1][1]=1;
	f(i,2,2000){
		f(j,1,2000) c[i][j]=(c[i-1][j-1]+c[i-1][j])%k;
	} 
	if (c[1][1]==0) d[1][1]=1;
	f(i,2,2000){
		int tot=0;
		f(j,1,i){
			if (c[i][j]%k==0) tot++;
			if (i==j) d[i][j]=d[i-1][j-1]+tot;
			else d[i][j]=d[i-1][j]+tot;
		}
	}
}
int main()
{
	int t;
	scanf("%d%d",&t,&k);
	make();
	f(i,1,5) f(j,1,i) printf("c[%d][%d]=%d\n",i,j,c[i][j]);
	// f(i,1,5) f(j,1,i) printf("d[%d][%d]=%d\n",i,j,d[i][j]);
	int n,m;
	while(t--){
		scanf("%d%d",&n,&m);
		printf("%d\n",d[n][m]);
	}
	return 0;
}