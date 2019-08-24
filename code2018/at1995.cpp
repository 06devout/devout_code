# include <bits/stdc++.h>

using namespace std;

int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	if (a>b) swap(a,b);
	if (a<0&&b>0){
		cout<<"Zero"<<endl;
		return 0;
	}
	if (a<0&&b<0){
		int x=abs(b-a);
		if (x%2==0) cout<<"Positive"<<endl;
		else cout<<"Negative"<<endl;
		return 0;
	}
	if (a>0&&b>0){
		cout<<"Positive"<<endl;
		return 0;
	}
	if (a==0||b==0){
		cout<<"Zero"<<endl;
		return 0;
	}
	return 0;
}