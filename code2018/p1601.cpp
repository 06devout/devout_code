# include <bits/stdc++.h>

# define f(i,a,b) for (int i=a;i<=b;i++)
# define F(i,a,b) for (int i=a;i>=b;i--)
# define N 100005

using namespace std;

char augend[N],addend[N];

int a[N],b[N],c[N];

int main()
{
    scanf("%s%s",augend,addend);
    int topa=strlen(augend);
    int topb=strlen(addend);
    f(i,0,topa-1){
        a[topa-i]=(int)augend[i]-48;
    }
    f(i,0,topb-1){
        b[topb-i]=(int)addend[i]-48;
    }
    a[0]=topa;
    b[0]=topb;
    int k=0;
    int top=max(a[0],b[0])+1;
    f(i,1,top){//           99
        c[i]=a[i]+b[i]+k;//    8
        k=c[i]/10;
        c[i]%=10;
    }
    if (c[top]==0) top--;
    F(i,top,1) printf("%d",c[i]);
    puts("");
    return 0;
}