# include <cstdio>
using namespace std;

const int N = 1e5+10;

int n,phi[N],p[N / 2];
bool flag[N];

void euler_onlogn()
{
    for(int i = 1;i <= n;i++) phi[i] = i;
    for(int i = 2;i <= n;i++){
        if(phi[i] == i) for(int j = i;j <= n;j += i) phi[j] = phi[j] / i * (i - 1);
        printf("i = %d: ",i);
        for(int i = 1;i<=n;i++) printf("%d ",phi[i]);
        printf("\n");
}   
}

void euler_on()
{
    int t = 0;
    for(int i = 2;i <= n;i++)
    {
        if(!flag[i]) p[++t] = i,phi[i] = i - 1;
        for(int j = 1;j <= t && p[j] * i <= n;j++)
        {
  		    flag[i * p[j]] = true;
  		    if(i % p[j] == 0) {phi[i * p[j]] = phi[i] * p[j]; break;}
  		    phi[i * p[j]] = phi[i] * (p[j] - 1);
        }
    }
}

int main()
{
    scanf("%d",&n);
    euler_onlogn();
    printf("%d",phi[n])
    // for(int i = 1;i <= n;i++) printf("%d\n",phi[i]);
    return 0;
}