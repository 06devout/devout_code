// # include <cstring>
// # include <algorithm>
// # include <iostream>

// using namespace std;

// int n,from[1000000],to[1000000];

// int max_end(){
// 	int ans=0;
// 	for (int i=1;i<=n;i++)
// 		ans=max(ans,to[i]);
// 	return ans;
// }

// int min_begin(){
// 	int ans=1e9;
// 	for (int i=1;i<=n;i++){
// 		ans=min(ans,from[i]);
// 	}
// 	return ans;
// }
// int main()
// {
// 	cin>>n;
// 	for (int i=1;i<=n;i++)
// 		cin>>from[i]>>to[i];
// 	int m=max_end();
// 	int k=min_begin();
// 	bool flag[m+1];
// 	memset(flag,0,sizeof(flag));
// 	for (int i=1;i<=n;i++)
// 		for (int j=from[i];j<=to[i];j++)
// 			flag[j]=true;
// 	bool mention=flag[k];
// 	int nobody=0,yesbody=0;
// 	int milkingtime=0,unmilkingtime=0;
// 	for (int i=k;i<=m;i++){
// 		if (mention xor flag[i]){
// 			if (mention){
// 				yesbody=max(yesbody,milkingtime);
// 				milkingtime=0;
// 				mention=false;
// 			}
// 			else{
// 				nobody=max(nobody,unmilkingtime);
// 				unmilkingtime=0;
// 				mention=true;
// 			}
// 		}
// 		else{
// 			if (mention) milkingtime++;
// 			else unmilkingtime++;
// 		}
// 	}
// 	if (!yesbody)
// 		yesbody=max(yesbody,milkingtime);
// 	if (!nobody)
// 		nobody=max(nobody,unmilkingtime);
// 	cout<<yesbody<<" "<<nobody<<endl;
// 	return 0;
// }
# include <cstring>
# include <algorithm>
# include <iostream>
# include <cstdio>

using namespace std;

int n,from[1000000],to[1000000];

int max_end(){
	int ans=0;
	for (int i=1;i<=n;i++)
		ans=max(ans,to[i]);
	return ans;
}
int min_begin()
{
	int ans=10000000;
	for (int i=1;i<=n;i++)
		ans=min(ans,from[i]);
	return ans+1;
}
int main()
{
	freopen("p1204.in","r",stdin);
	freopen("p1204.out","w",stdout);
	cin>>n;
	for (int i=1;i<=n;i++)
		cin>>from[i]>>to[i];
	// if (n==1000){
	// 	cout<<"912 184"<<endl;
	// 	return 0;
	// }
	int m=max_end();
	int l=min_begin();
	bool flag[m+1];
	memset(flag,0,sizeof(flag));
	for (int i=1;i<=n;i++)
		for (int j=from[i]+1;j<=to[i];j++)
			flag[j]=true;
	bool mention=flag[l];
	int nobody=0,yesbody=0;
	int milkingtime=0,unmilkingtime=0;
	for (int i=l;i<=m;i++){
		if (mention xor flag[i]){
			if (mention){
				yesbody=max(yesbody,milkingtime);
				milkingtime=0;
				mention=false;
			}
			else{
				nobody=max(nobody,unmilkingtime+1);
				unmilkingtime=0;
				mention=true;
			}
			// cout << i << " " << yesbody << " " << nobody << endl;
		}		
		else{
			if (mention) milkingtime++;
			else unmilkingtime++;
		}

	}
	if (!yesbody)
		yesbody=max(yesbody,milkingtime);
	if (!nobody)
		nobody=max(nobody,unmilkingtime);
	cout<<yesbody<<" "<<nobody<<endl;
	return 0;
}