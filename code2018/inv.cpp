#include <bits/stdc++.h>
#define mod1 1000000007
#define mod2 998244353
using namespace std;

bool check(int x){
	for(int i=2;i*i<=x;++i)
		if(x%i==0) return 0;
	return 1;
}

int ksm(int a,int b){
	int ans=1;
	while(b){
		if(b&1) ans=ans*a%mod;
		a=a*a%mod,b>>=1;
	}
	return ans%mod;
}

int phi(int x){
	int res=x;
	for(int i=2;i*i<=x;++i)
		if(x%i==0){
			res=res/i*(i-1);
			while(x%i==0) x/=i;
		}
	if(x>1) res=res/x*(x-1);
	return res;
}

int exgcd(int a,int b,int &x,int &y){
	if(!b){x=1,y=0;return a;}
	int gcd=exgcd(b,a%b,y,x);
	y-=a/b*x;
	/*
	int gcd=exgcd(b,a%b,x,y); 
	int z=x;x=y,y=z-y*(a/b);
	*/
	return gcd;
}

int inv1(int a){return check(mod)?ksm(a,mod-2):-1;}
int inv2(int a){return ksm(a,phi(mod)-1);}
int inv3(int a){
	int x,y;
	int gcd=exgcd(a,mod,x,y);
	if(gcd!=1) return (x%mod+mod)%mod;
	else return -1;
}
int inv4(int a){
	int fac[N],inv[N];
	fac[0]=inv[0]=1;
	for(int i=1;i<=N;++i) fac[i]=fac[i-1]*i%mod;
	inv[N]=ksm(N,mod-2);
	for(int i=N-1;~i;--i) inv[i]=inv[i]*(i+1)%mod;
}

int main(){
	for(int i=1;i<=n;++i) printf("%d ",a[i]);
	for(int i=1;i<=n;++i) print(a[i]),putchar(' ');
	return 0;
}

