# include <bits/stdc++.h>

using namespace std;

struct _{
	int total,line;
};
_ linechat[1000000];
_ culchat[1000000];
int cmp(_ a,_ b)
{
	return a.total>b.total;
}
int main()
{
	int m,n,k,l,d;
	cin>>m>>n>>k>>l>>d;
	for (int i=1;i<=d;i++){
		int x,y,p,q;
		cin>>x>>y>>p>>q;
		if (x==p){
			int sign=min(y,q);
			culchat[sign].total++;
			culchat[sign].line=sign;
		}
		if (y==q) {
			int sign=min(x,p);
			linechat[sign].total++;
			linechat[sign].line=sign;
		}
	}
	sort(linechat+1,linechat+m,cmp);
	sort(culchat+1,culchat+n,cmp);
	int cutline[m+1],cutcul[n+1];
	for (int i=1;i<m;i++){
		cutline[i]=linechat[i].line;
	}
	for (int i=1;i<n;i++)
		cutcul[i]=culchat[i].line;
	sort(cutline+1,cutline+k+1);
	sort(cutcul+1,cutcul+l+1);
	cout<<cutline[1];
	for (int i=2;i<=k;i++)
		cout<<" "<<cutline[i];
	puts("");
	cout<<cutcul[1];
	for (int i=2;i<=l;i++)
		cout<<" "<<cutcul[i];
	puts("");
	return 0;
}