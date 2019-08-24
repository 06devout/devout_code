# include <cstdio>
# include <cstring>
using namespace std;
int num[10];
int n;
int eachnum[5]; 
int int_length(int a)
{
	int ans=0;
	while(a){
		a/=10;
		ans++;
	}
	return ans;
}
bool same(int x)
{
	memset(eachnum,0,sizeof(eachnum));
	int i=0;
	while(x){
		eachnum[++i]=x%10;
		bool flag=false;
		for (int j=1;j<=n;j++)
			if (eachnum[i]==num[j]) flag=true;
		if (!flag) return false;
		x/=10;
	}
	return true;
}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%d",&num[i]);
	int ans=0;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			for (int k=1;k<=n;k++)
				for (int l=1;l<=n;l++)
					for (int m=1;m<=n;m++){
						int a=num[m]*(100*num[i]+10*num[j]+num[k]);
						int b=num[l]*(100*num[i]+10*num[j]+num[k]);
						int c=a+b*10;
						if (same(a) and same(b) and same(c) and int_length(a)==3 and int_length(b)==3 and int_length(c)==4) ans++;
					}
	printf("%d\n",ans );
	return 0;
}