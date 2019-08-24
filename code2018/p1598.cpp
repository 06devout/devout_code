# include <cstdio>
# include <algorithm>
# include <cstring>
# include <iostream>
using namespace std;
int avoid(char a)
{
	if (a==' '||a=='.') return 64;
	else return a;
}
int main()
{
	char a[100],b[100],c[100],d[100];
	cin.getline(a,100);
	cin.getline(b,100);
	cin.getline(c,100);
	cin.getline(d,100);
	int time[27];
	memset(time,0,sizeof(time));
	for (int i=0;i<strlen(a);i++){
		a[i]=avoid(a[i]);
		time[a[i]-64]++;
	}
	for (int i=0;i<strlen(b);i++){
		b[i]=avoid(b[i]);
		time[b[i]-64]++;
	}
	for (int i=0;i<strlen(c);i++){
		c[i]=avoid(c[i]);
		time[c[i]-64]++;
	}
	for (int i=0;i<strlen(d);i++){
		d[i]=avoid(d[i]);
		time[d[i]-64]++;
	}
	int max_top=0;
	for (int i=1;i<=26;i++)
		max_top=max(time[i],max_top);
	for (int i=1;i<=max_top;i++){
		for (int j=1;j<=25;j++){
			if (time[j]>=max_top+1-i) printf("* ");
			else printf("  ");
		}
		if (time[26]>=max_top+1-i) printf("*");
		else printf(" ");
		puts("");
	}
	for (char i=65;i<=90;i++)
		printf("%c ",i );
	return 0;
}