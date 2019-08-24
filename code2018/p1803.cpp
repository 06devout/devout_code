# include <bits/stdc++.h>

using namespace std;
struct test{
	int a,b;
}cry[1000005];
int cmp(test x,test y){
	if (x.b!=y.b) return x.b<y.b;
	return x.a<y.b;
}
int main()
{
	int n;
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%d%d",&cry[i].a,&cry[i].b);
	sort(cry+1,cry+n+1,cmp);
	int end=cry[1].b;
	int total=1;
	for (int i=2;i<=n;i++){
		if (cry[i].a>=end){
			total++;
			end=cry[i].b;
		}
	}
	printf("%d\n",total);
	return 0;
}