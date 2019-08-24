# include <cstdio>
# include <iostream>
# include <cmath>
# include <algorithm>
# include <cstring>
# include <string>
# include <ctime>

using namespace std;

char yester[10000][10000],tomorr[10000][10000],aftern[10000][10000];
int n;

void one()
{
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			aftern[j][n-i+1]=yester[i][j];
}

void two()
{
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			aftern[n-i+1][n-j+1]=yester[i][j];
}

void three()
{
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			aftern[n-j+1][i]=yester[i][j];
}

void four()
{
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			aftern[i][n-j+1]=yester[i][j];
}

void five_one()
{
	four();
	char tmp[10000][10000];
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			tmp[i][j]=aftern[i][j];
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			aftern[j][n-i+1]=tmp[i][j];
}

void five_two()
{
	four();
	char tmp[10000][10000];
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			tmp[i][j]=aftern[i][j];
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			aftern[n-i+1][n-j+1]=tmp[i][j];
}

void five_three()
{
	four();
	char tmp[10000][10000];
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			tmp[i][j]=aftern[i][j];
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			aftern[n-j+1][i]=tmp[i][j];
}
void six(){
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			aftern[i][j]=yester[i][j];
}

bool check()
{
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			if (tomorr[i][j]!=aftern[i][j]) return false;
	return true;
}

void set0()
{
	memset(aftern,0,sizeof(aftern));
}

int main()
{
	freopen("p1205.in","r",stdin);
	freopen("p1205.out","w",stdout);
	cin>>n;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			cin>>yester[i][j];
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			cin>>tomorr[i][j];
	one();
	bool flag=check();
	if (flag){
		cout<<1<<endl;
		return 0;
	}
	set0();
	two();
	flag=check();
	if (flag){
		cout<<2<<endl;
		return 0;
	}
	set0();
	three();
	flag=check();
	if (flag){
		cout<<3<<endl;
		return 0;
	}
	set0();
	four();
	flag=check();
	if (flag){
		cout<<4<<endl;
		return 0;
	}
	set0();
	five_one();
	flag=check();
	if (flag){
		cout<<5<<endl;
		return 0;
	}
	set0();
	five_two();
	flag=check();
	if (flag){
		cout<<5<<endl;
		return 0;
	}
	set0();
	five_three();
	flag=check();
	if (flag){
		cout<<5<<endl;
		return 0;
	}
	set0();
	six();
	flag=check();
	if (flag){
		cout<<6<<endl;
		return 0;
	}
	cout<<7<<endl;
	return 0;
}