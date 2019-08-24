# include <cstdio>
# include <queue>
# include <vector>

using namespace std;
priority_queue <long long> que;
int main()
{
	freopen("p2827.in","r",stdin);
	freopen("p2827.out","w",stdout);
	int n,m,q,u,v,t;
	scanf("%d%d%d%d%d%d",&n,&m,&q,&u,&v,&t);
	long long l;
	for (int i=1;i<=n;i++){
		scanf("%lld",&l);
		que.push(l);
	}
	for (int i=1;i<=m;i++){
		long long x=que.top()+(i-1)*q;
		if (i%t==0) printf("%lld ",x);
		que.pop();
		long long y=(x*u)/v;
		que.push(y-i*q);
		que.push(x-y-i*q);
	}
	puts("");
	int top=que.size();
	for (int i=1;i<=top;i++){
		if (i%t==0) printf("%lld ",que.top()+m*q);
		que.pop();
	}
	puts("");
	return 0;
}