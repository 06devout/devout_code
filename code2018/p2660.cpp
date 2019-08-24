// # include <bits/stdc++.h>

// using namespace std;

// long long hardworkingzzc(long long a,long long b){
// 	if (a%b==0) return 4*b*(a/b);
// 	if (b%a==0) return 4*a*(b/a);
// 	if (a>b) return b*4+hardworkingzzc(a-b,b);
// 	return a*4+hardworkingzzc(a,b-a);
// }
// int main()
// {
// 	long long a,b;
// 	cin>>a>>b;
// 	cout<<hardworkingzzc(a,b);
// 	return 0;
// }

# include <bits/stdc++.h>

using namespace std;

int main()
{
	long long x,y;
	cin>>x>>y;
	long long ans=0;
	while(1){
		if (x%y==0){
			ans+=4*y*(x/y);
			break;
		}
		if (y%x==0){
			ans+=4*x*(y/x);
			break;
		}
		if (x>y){
			ans+=4*y*(x/y);
			x-=y*(x/y);
		}
		else{
			ans+=4*x*(y/x);
			y-=x*(y/x);
		}
	}
	cout<<ans<<endl;
	return 0;
}