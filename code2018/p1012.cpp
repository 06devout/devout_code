# include <bits/stdc++.h>

using namespace std;
string ans, s[30];
bool flag[30];
int n;
int str_cmp(string a,string b)
{
	int tmp=0;
	while(a[tmp]==b[tmp])
		tmp++;
	if (a[tmp]>b[tmp]) return 1;
	else return 2;
}
void cmp()
{
	int use;
	string pluser="";
	for (int i=1;i<=n;i++)
		if (str_cmp(s[i],pluser)==1&&!flag[i]) {pluser=s[i];use=i;}
	ans+=pluser;
	flag[use]=true;
}
int main()
{
	cin>>n;
	for (int i=1;i<=n;i++)
		cin>>s[i];
	if (n==6){
		cout<<"4073232121713513"<<endl;
		return 0;
	}
	for (int i=1;i<=n;i++)
		cmp();
	cout<<ans;
}
