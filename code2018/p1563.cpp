# include <cstdio>
# include <iostream>

using namespace std;

int main()
{
	freopen("p1563.in","r",stdin);
	freopen("p1563.out","w",stdout);
	int popu,num;//population of the toys and code's number
	cin>>popu>>num;
	string name[popu];
	int way[popu];// the way of a toy looking at
	for (int i=0;i<popu;i++)
		cin>>way[i]>>name[i];
	int counter_clockwised_ask[num];
	int journeylength[num];
	for (int i=0;i<num;i++){
		cin>>counter_clockwised_ask[i]>>journeylength[i];
		journeylength[i]%=popu;
		// cout<<counter_clockwised_ask[i]<<journeylength[i];
	}
	int people=0;
	//for (int i=0;i<popu;i++) 
		//cout<<name[i]<<endl;
	for (int i=0;i<num;i++){
		if (way[people]==1){
			if (counter_clockwised_ask[i]==1) people-=journeylength[i];
			else people+=journeylength[i];
			// cout<<people<<endl;
			people+=popu;
			//cout<<people<<endl;
			people%=popu;
		}
		else {
			if (counter_clockwised_ask[i]==1) people+=journeylength[i];
			else people-=journeylength[i];
			//cout<<people<<endl;
			people+=popu;
			//cout<<people<<endl;
			people%=popu;
		}
		//cout<<people<<endl;
	}
	cout<<name[people]<<endl;
	return 0;
}