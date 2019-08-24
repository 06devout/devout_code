# include <bits/stdc++.h>

using namespace std;
bool flag[100005];
struct Str{
	int dnum;
	int dis;
	int tir;
	int tot;
}ordered[100005],unordered[100005];
bool cmp(Str a,Str b)
{
	return a.tir<b.tir;
}
bool comp(Str a,Str b){
	if (a.dis==b.dis) return a.tir>b.tir;
	return a.dis<b.dis;
}
int finder(int a)
{
	while(flag[--a]){}
	return a;
}
int main()
{
	int n;
	scanf("%d",&n);
	int x=0;
	for (int i=1;i<=n;i++){
		scanf("%d",&ordered[i].dis);
		unordered[i].dis=ordered[i].dis;
	}
	for (int i=1;i<=n;i++){
		scanf("%d",&ordered[i].tir);
		unordered[i].tir=ordered[i].tir;
		ordered[i].dnum=i;
		unordered[i].dnum=i;
		x+=ordered[i].tir;
		ordered[i].tot=2*ordered[i].dis+ordered[i].tir;
		unordered[i].tot=2*unordered[i].dis+unordered[i].tir;
	}
	x+=2*ordered[n].dis;
	int max_tir[n+1];
	max_tir[n]=x;
	int hand=n,next=n-1;
	sort(ordered+1,ordered+n,cmp);
	sort(unordered+1,unordered+n+1,comp);
	for (int i=1;i<n;i++){
		if (ordered[i].tir>unordered[hand].tir+2*(unordered[hand].dis-unordered[next].dis)){
			x=x-unordered[hand].tir-2*(unordered[hand].dis-unordered[next].dis);
			flag[hand]=true;
			hand=next;
			next=finder(next);
		}
		else {
			flag[ordered[i].dnum]=true;
			if (ordered[i].dnum==next) next=finder(next);
			x-=ordered[i].tir;
		}
		max_tir[n-i]=x;
	}
	for (int i=1;i<=n;i++)
		printf("%d\n",max_tir[i]);
	return 0;
}