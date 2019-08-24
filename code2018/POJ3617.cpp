# include <iostream>
# include <string>
# include <cstdio>

using namespace std;

string s,ans;
bool cmp(int a,int b){
	if (s[a]>s[b]) return 0;
	if (s[a]<s[b]) return 1;
	if (a==b) return 0;
	return cmp(a+1,b-1);
}
int main()
{
	int n;
	cin>>n;
	for (int i=0;i<n;i++){
		char tmp;
		scanf("%*c");
		cin>>tmp;
		s+=tmp;
	}
	int front=0,last=n-1;
	for (int i=1;i<=n;i++){
		if (s[front]<s[last]) {
			ans+=s[front];
			front++;
		}
		else {
			if (s[front]>s[last]){
			ans+=s[last];
			last--;
			}
			else{
				bool x=cmp(front+1,last-1);
				if (!x){
					ans+=s[last];
					last--;
				}
				else{
					ans+=s[front];
					front++;
				}
			}
		}
	}
	for (int i=0;i<n;i++){
		cout<<ans[i];
		if ((i+1)%80==0) cout<<endl;
	}
	return 0;
}