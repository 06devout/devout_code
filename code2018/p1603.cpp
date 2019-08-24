# include <bits/stdc++.h>

using namespace std;

int cmp(string a,string b){
	return a<b;
}
int main()
{
	string word[10];
	char point;
	for (int i=1;i<=6;i++)
		cin>>word[i];
	cin>>point;
	string num[10];
	int k=0;
	for (int i=1;i<=6;i++){
			if (word[i]=="one")num[++k]="01";
			else if (word[i]=="two")num[++k]="04";
			else if (word[i]=="three")num[++k]="09";
			else if (word[i]=="four")num[++k]="16";
			else if (word[i]=="five")num[++k]="25";
			else if (word[i]=="six")num[++k]="36";
			else if (word[i]=="seven")num[++k]="49";
			else if (word[i]=="eight")num[++k]="64";
			else if (word[i]=="nine")num[++k]="81";
			else if (word[i]=="ten")num[++k]="00";
			else if (word[i]=="eleven")num[++k]="21";
			else if (word[i]=="twelve")num[++k]="44";
			else if (word[i]=="thirteen")num[++k]="69";
			else if (word[i]=="fourteen")num[++k]="96";
			else if (word[i]=="fifteen")num[++k]="25";
			else if (word[i]=="sixteen")num[++k]="56";
			else if (word[i]=="seventeen")num[++k]="89";
			else if (word[i]=="eighteen")num[++k]="24";
			else if (word[i]=="nineteen")num[++k]="61";
			else if (word[i]=="twenty")num[++k]="00";
			else if (word[i]=="a")num[++k]="01";
			else if (word[i]=="both")num[++k]="04";
			else if (word[i]=="another")num[++k]="01";
			else if (word[i]=="first")num[++k]="01";
			else if (word[i]=="second")num[++k]="04";
			else if (word[i]=="third")num[++k]="09";
			else continue;
		}
	sort(num+1,num+1+k,cmp);
	if (k==0) {
		cout<<0;
		return 0;
	}
	if (num[1][0]=='0') cout<<num[1][1];
	else cout<<num[1];
	for (int i=2;i<=k;i++)
		cout<<num[i];
	puts("");
	return 0;
}
// # include <bits/stdc++.h>

// using namespace std;

// int cmp(int a,int b){
// 	if ((int)log10(a)==0){
// 		if (a>=b/10) return 1;
// 		else return 0;
// 	}
// 	else if ((int)log10(b)==0){
// 		if (a/10>=b) return 1;
// 		else return 0;
// 	}
// 	else return a>b;
// }
// int main()
// {
// 	string word[10];
// 	char point;
// 	for (int i=1;i<=6;i++)
// 		cin>>word[i];
// 	cin>>point;
// 	int num[10];
// 	int k=0;
// 	for (int i=1;i<=6;i++){
// 			if (word[i]=="one")num[++k]=1;
// 			else if (word[i]=="two")num[++k]=4;
// 			else if (word[i]=="three")num[++k]=9;
// 			else if (word[i]=="four")num[++k]=16;
// 			else if (word[i]=="five")num[++k]=25;
// 			else if (word[i]=="six")num[++k]=36;
// 			else if (word[i]=="seven")num[++k]=49;
// 			else if (word[i]=="eight")num[++k]=64;
// 			else if (word[i]=="nine")num[++k]=81;
// 			else if (word[i]=="ten")num[++k]=0;
// 			else if (word[i]=="eleven")num[++k]=21;
// 			else if (word[i]=="twelve")num[++k]=44;
// 			else if (word[i]=="thirteen")num[++k]=69;
// 			else if (word[i]=="fourteen")num[++k]=96;
// 			else if (word[i]=="fifteen")num[++k]=25;
// 			else if (word[i]=="sixteen")num[++k]=56;
// 			else if (word[i]=="seventeen")num[++k]=89;
// 			else if (word[i]=="eighteen")num[++k]=24;
// 			else if (word[i]=="nineteen")num[++k]=61;
// 			else if (word[i]=="twenty")num[++k]=0;
// 			else continue;
// 		}
// 	sort(num+1,num+1+k,cmp);
// 	if (k==0){
// 		cout<<0<<endl;
// 		return 0;
// 	}
// 	cout<<num[1];
// 	for (int i=2;i<=k;i++){
// 		if (log10(num[i])==0) cout<<0;
// 		cout<<num[i];
// 	}
// 	puts("");
// 	return 0;
// }