# include <bits/stdc++.h>
# define f(i,a,b) for (int i=a;i<=b;i++)
# define F(i,a,b) for (int i=a;i>=b;i--)
# define w(a,b) while(a>=b)
# define W(a,b) while(a<=b)

using namespace std;

typedef unsigned long long ull;

const int N=10005;

const int M=1000005;

int n,cut[N],ans[M];

void multi(int x){
    for (int i=1;i<=ans[0];i++) ans[i]*=x;
    for (int i=1;i<=ans[0];i++){
        ans[i+1]+=ans[i]/10;
        ans[i]%=10;
        if (ans[i+1]) ans[0]=max(ans[0],i+1);
    }
}
int main()
{
    ans[0]=1;
    ans[1]=1;
    scanf("%d",&n);
    if (n<=4){
        printf("%d\n",n);
        printf("%d\n",n);
        return 0;
    }
    int k=2;
    int nt=n;
    w(nt,k){
        nt-=k;
        cut[k-1]=k;
        k++;
    }
    k-=2;
    int moded=k;
    f(i,1,nt){
        if (k<0) k+=moded;
        cut[k]++;
        k--;
    } 
    f(i,1,moded) {   
        printf("%d ",cut[i]);
        multi(cut[i]);
    }
    puts("");
    F(i,ans[0],1)
        printf("%d",ans[i]);
    puts("");
    return 0;
}