# include <cstdio>
# include <algorithm>
# include <cstring>
# include <cmath>

# define f(i,a,b) for (int i=a;i<=b;i++)
# define F(i,a,b) for (int i=a;i>=b;i--)

using namespace std;

const int N=10005;

int sum[N],tmp[N],ans[N];

struct employee{
    int l,r;
}survey[N];

bool cmp(employee a,employee b){
    return a.l*a.r<b.l*b.r;
}
void multi(int s[],int a)
{
    f(i,1,s[0]) s[i]*=a;
    f(i,1,s[0]){
        s[i+1]+=s[i]/10;
        s[i]%=10;
        if (s[i+1]) s[0]=max(i+1,s[0]);
    }
}
void div(int s[],int a)
{
    F(i,s[0],1) s[i]+=s[i+1]%a*10;
    f(i,1,s[0]) s[i]/=a;
    while(!s[s[0]]&&s[0]) s[0]--;
}
bool Memcmp(int a[],int b[])
{
    if (a[0]!=b[0]) return a[0]<b[0];
    F(i,a[0],1) if (a[i]!=b[i]) return a[i]<b[i];
    return false;
}
int main()
{
    int n,a,b;
    scanf("%d%d%d",&n,&a,&b);
    f(i,1,n) scanf("%d%d",&survey[i].l,&survey[i].r);
    sort(survey+1,survey+n+1,cmp);
    sum[0]=1;
    sum[1]=a;
    f(i,1,n){
        memcpy(tmp,sum,sizeof(sum));
        div(tmp,survey[i].r);
        if (Memcmp(ans,tmp)) memcpy(ans,tmp,sizeof(tmp));
        multi(sum,survey[i].l);
    }
    F(i,ans[0],1) printf("%d",ans[i]);
    puts("");
    return 0;
}