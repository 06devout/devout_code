#include <bits/stdc++.h>
using namespace std;

const int N=1e7+5;

void Euler(int x){
	int ans=x;
	for(int i=2;i*i<=x;++i)
		if(x%i==0){
			ans=ans/i*(i-1);
			while(x%i==0) x/=i;
		}
	return ans;
}

void euler(){
	for(int i=1;i<=n;++i) phi[i]=i;
	for(int i=2;i<=n;++i)
		if(phi[i]==i)
			for(int j=i;j<=n;j+=i) phi[j]=phi[j]/i*(i-1);
}

void euler(){
	memset(vis,0,sizeof(vis));
	cnt=0;
	for(int i=2;i<=n;++i){
		if(!vis[i]){
			mn[i]=i,pri[++cnt]=i;
			phi[i]=i-1;
		}
		for(int j=1;j<=cnt;++j){
			if(pri[j]>mn[i]||pri[j]>n/i) break;
			mn[i*pri[j]]=pri[j],vis[i*pri[j]]=true;
			if(i%pri[j]==0) phi[i*pri[j]]=phi[i]*pri[j];
			else phi[i*pri[j]]=phi[i]*(pri[j]-1);
		}
	}
}

int main()
{
	
 	return 0;
}

