# include <cstdio>
# include <algorithm>

using namespace std;

int main()
{
	int ans=1,top=0;
	for (int i=1;i<1000000;i++){
		unsigned long long k=i;
		int t=0;
		while(k!=1){
			t++;
			if (k%2) k=3*k+1;
			else k/=2;
		}
		if (top<t){
			top=t;
			ans=i;
		}
	}
	printf("%d\n",ans);
	return 0;
}