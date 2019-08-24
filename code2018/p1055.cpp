# include <iostream>

using namespace std;

int main()
{
	string s;
	cin>>s;
	int num[15];
	num[1]=s[0]-48;
	num[2]=s[2]-48;
	num[3]=s[3]-48;
	num[4]=s[4]-48;
	num[5]=s[6]-48;
	num[6]=s[7]-48;
	num[7]=s[8]-48;
	num[8]=s[9]-48;
	num[9]=s[10]-48;
	int test=s[12]-48;
	int sum=0;
	for (int i=1;i<=9;i++){
		sum+=num[i]*i;
	}
	sum%=11;
	if (sum==test) {
		cout<<"Right"<<endl;
		return 0;
	}
	for (int i=0;i<=11;i++)
		cout<<s[i];
	cout<<sum<<endl;
	return 0;
}