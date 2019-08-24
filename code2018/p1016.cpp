# include <cstdio>

using namespace std;

int main()
{
	freopen("p1016.in","r",stdin);
	freopen("p1016.out","w",stdout);
	double dis,full,d,cost[10],bet[10];
	bet[0]=0;
	scanf("%lf%lf%lf%lf",&dis,&full,&d,&cost[0]);
	int n;
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%lf%lf",&bet[i],&cost[i]);
	bet[n+1]=dis-bet[n];
	cost[n+1]=0;
	double fulloil=full*d;
	double total=0;
	double have=0;
	int forward=0;
	for (int i=0;i<=n;i++){
		if (forward!=i) continue;
		if (bet[i]+fulloil<bet[i+1]) {
			printf("No Solution\n");
			return 0;
		}
		int arrive=i;
		for (int j=i+1;j<=n&&bet[i]+fulloil>=bet[j];j++)
			if (cost[j]<cost[arrive]) arrive=j;
		if (arrive==i){
			int tmp=i+1;
			for (int j=i+1;j<=n&&bet[i]+fulloil>=bet[j];j++)
				if (cost[j]<cost[tmp]) tmp=j;
			forward=tmp;
			if ((dis-bet[i])/d<full){
				total+=((dis-bet[i])/d-have)*cost[i];
				break;
			}
			total+=(full-have)*cost[i];
			have=full;
			have-=(bet[forward]-bet[i])/d;
		}
		else{
			double x=(bet[arrive]-bet[i])/d-have;
			if (x<0) x=0;
			total+=x*cost[i];
			have+=x;
			forward=arrive;
			have-=(bet[forward]-bet[i])/d;
		}
	}
	printf("%.2f\n",total);
	return 0;
}