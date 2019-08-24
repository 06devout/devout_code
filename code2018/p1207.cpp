# include <cstdio>
# include <algorithm>

using namespace std;

bool turning(int x,int n)
{
	int num[10000];
	int tmp=0;
	while(x){
		num[++tmp]=x%n;
		x/=n;
	}
	for (int i=1;i<=tmp/2;i++)
		if (num[i]!=num[tmp-i+1]) return false;
	return true;
}

bool double_turner(int x){
	int right=0;
	for (int i=2;i<=10;i++){
		if (turning(x,i)) right++;
		if (right==2) return true;
	}
	return false;
}

int main()
{
	// freopen("p1207.in","r",stdin);
	// freopen("p1207.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	int num=0;
	int i=m+1;
	while(num<n){
		if (double_turner(i)){
		 	num++;
		 	printf("%d\n",i );
		}
		i++;
	}
	return 0;
}