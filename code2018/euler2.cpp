# include <cstdio>

using namespace std;

int main()
{
	int que[1000000];
	que[1]=1;
	que[2]=2;
	int sum=2;
	for (int i=3;i<=100000;i++){
		que[i]=que[i-1]+que[i-2];
		if (que[i]>4000000) break;
		if (que[i]%2==0) sum+=que[i];
	}
	printf("%d",sum);
	return 0;
}