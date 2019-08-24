# include <cstdio>
# include <algorithm>
# include <cstring>
# include <iostream>

# define f(i,a,b) for (int i=a;i<=b;i++)
# define F(i,a,b) for (int i=a;i>=b;i--)

using namespace std;

const int N=15;

const double M=1e-2;

double a[N][N],b[N],r[N][N];

int n;

void gause()
{
	f(i,1,n){
		f(j,i,n){
			if (fabs(a[j][i])>M){
				f(k,1,n) swap(a[j][k],a[i][k]);
				swap(b[i],b[j]);
			}
		}
		f(j,1,n){
			if (i==j) continue;
			double rate=a[j][i]/a[i][i];
			f(k,1,n) a[i][k]-=a[j][k]*rate;
			b[i]-=b[j]*rate;
		}
	}
}
int main()
{
	scanf("%d",&n);
	printf("%d\n",n);
	for (int i=1;i<=n+1;i++){
		for (int j=1;j<=n;j++){
		 	// scanf("%lf",&r[i][j]);
		 	cin>>r[i][j];
		 	cout<<r[i][j]<<" ";
		}
		puts("");
	}
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++) {
			a[i][j]=2*(r[i+1][j]-r[i][j]);
			b[i]+=(r[i+1][j]-r[i][j])*(r[i+1][j]+r[i][j]);
		}
	}
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++) printf("%.3lf ",a[i][j]);
		printf("%.3lf\n",b[i]); 
	}
	gause();
	for (int i=1;i<=n;i++) printf("%.3lf ",b[i]/a[i][i]);
	return 0;
}