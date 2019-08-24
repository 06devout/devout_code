# include <iostream>
# include <cstdio>
using namespace std;

int main()
{
	int n,t;
	int tot=0;
	double d=0;
	cin>>n;
	for (int i=1;i<=n;i++) cin>>t,tot+=t,d+=t;
	d/=n;
	cout<<tot<<" ";
	printf("%.5lf\n",d);
	return 0;
}