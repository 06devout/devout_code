# include <iostream>
# include <algorithm>

using namespace std;

int main()
{
	int r,n;
	while(1){
		int sum=0;
		cin>>r>>n;
		if (r==-1&&n==-1) break;
		int x[n+1];
		for (int i=0;i<n;i++)
			cin>>x[i];
		sort(x,x+n);
		int l=0;
		while(l<n){
			int tmp=x[l];
			while(x[l]-tmp<=r) l++;
			tmp=x[l-1];
			while(x[l]-tmp<=r) l++;
			sum++;
		}
		cout<<sum<<endl;
	}
	return 0;
}