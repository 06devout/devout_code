# include <cstdio>
# include <algorithm>
# include <cstring>
# include <cmath>

# define f(i,a,b) for (int i=a;i<=b;i++)
# define F(i,a,b) for (int i=a;i>=b;i--)

using namespace std;

const int N=10005;

int n;

int a[N],b[N],c[N];

void high_plus()
{
    c[0]=max(a[0],b[0]);
    int k=0;
    f(i,1,c[0]){
        c[i]=a[i]+b[i]+k;
        k=c[i]/10;
        c[i]%=10;
    }
    c[c[0]+1]+=k;
    if (c[c[0]+1]) c[0]++;
}
int main()
{
    scanf("%d",&n);
    if (n<=3){
        printf("%d\n",n);
        return 0;
    }
    a[0]=1;
    b[0]=1;
    a[1]=1;
    b[1]=2;
    f(i,3,n){
        high_plus();
        memcpy(a,b,sizeof(b));
        memcpy(b,c,sizeof(c));
    }
    F(i,b[0],1) printf("%d",b[i]);
    puts("");
    return 0;
}