# include <iostream>
# include <cstdio>
# include <cstring>
# include <string>
# include <algorithm>
 
using namespace std;


# define forp(i,a,b) for(int i=a;i<=b;i++)
# define form(i,a,b) for(int i=a;i>=b;i--)

int main()
{
	freopen("p1203.in","r",stdin);
	freopen("p1203.out","w",stdout);
	int n;
	cin>>n;
	string one;
	cin>>one;
	string three=one;
	three+=one;
	three+=one;
	int ans=0;
	forp(i,n,2*n-1){
		char mention;
		mention=three[i];
		if (mention=='w'){
			int temp=i;
			while(three[++temp]=='w'){

			}
			mention=three[temp];
		}
		int tmp=i;
		int sum=2;
		while(1){
			tmp++;
			if (three[tmp]==mention||three[tmp]=='w'){
				sum++;
			}
			else break;
			if (sum>n){
				cout<<n<<endl;
				return 0;
			}
		}
		tmp=i-1;
		mention=three[tmp];
		if (mention=='w'){
			int temporary=i;
			while(three[++temporary]=='w'){

			}
			mention=three[temporary];
		}
		while(1){
			tmp--;
			if (three[tmp]==mention||three[tmp]=='w'){
				sum++;
			}
			else break;
			if (sum>n){
				cout<<n<<endl;
				return 0;
			}
		}
		ans=max(ans,sum);
	}
	cout<<ans<<endl;	
}