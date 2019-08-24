# include <cstdio>
# include <cstring>
using namespace std;
char name[15][15];
int n;
int whogotmon(char s[14]){
	for (int i=1;i<=n;i++){
	int x=strcmp(s,name[i]);
	if (x==0) return i;
	}
	return 0;
}
int main()
{
	freopen("p1201.in","r",stdin);
	freopen("p1201.out","w",stdout);
	scanf("%d",&n);	
	for (int i=1;i<=n;i++){
	scanf("%s",name[i]);
	}
	int mon[n+1];
	memset(mon,0,sizeof(mon));
	for (int i=1;i<=n;i++){
		char giver[14];
		scanf("%s",giver);
		int givemon,begiverpernum;
		scanf("%d%d",&givemon,&begiverpernum);
		char begiverpername[14][14];
		for (int j=1;j<=begiverpernum;j++){
			scanf("%s",begiverpername[j]);
			int x=whogotmon(begiverpername[j]);
			if (begiverpernum!=0)
				mon[x]+=givemon/begiverpernum;

		}
		int y=whogotmon(giver);
		if (begiverpernum!=0){
		// mon[y]=mon[y]+givemon-givemon/begiverpernum;
		// mon[y]-=givemon;
			mon[y]-=(givemon/begiverpernum)*begiverpernum;
		}
	}
	for (int i=1;i<=n;i++)
	printf("%s %d\n",name[i],mon[i] );
	return 0;

}