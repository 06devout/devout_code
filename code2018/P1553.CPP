# include <bits/stdc++.h>

using namespace std;
string input;
string threw="";
void change_way()
{
	int n=threw.size();
	for (int i=0;i<n/2;i++){
		swap(threw[i],threw[n-i-1]);
	}
}
void change()
{
	cin>>input;
	int x;
	x=input.find('/');
	if (x!=string::npos){
		for (int i=0;i<x;i++)
			threw+=input[i];
		change_way();
		int tmp=0;
		while(threw[tmp]=='0'&&tmp<threw.size()-1){
			threw.erase(tmp,1);
		}
		if (threw.empty()){
			cout<<0<<endl;
			exit(0);
		}
		cout<<threw;
		cout<<'/';
		threw="";
		int top=input.size();
		for (int i=x+1;i<top;i++){
			threw+=input[i];
		}
		change_way();
		tmp=0;
		while(threw[tmp]=='0'){
			threw.erase(tmp,1);
		}
		cout<<threw<<endl;
		exit(0);
	}
	else{
		x=input.find('.');
		if (x!=string::npos){
			for (int i=0;i<x;i++)
				threw+=input[i];
			change_way();
			int tmp=0;
			while(threw[tmp]=='0'){
				threw.erase(tmp,1);
			}
			if (threw.empty()) cout<<0;
			else cout<<threw;
			cout<<'.';
			threw="";
			int top=input.size();
			for (int i=x+1;i<top;i++){
				threw+=input[i];
			}
			change_way();
			tmp=threw.size();
			while(threw[--tmp]=='0'){
				threw.erase(tmp,1);
			}
			if (threw.empty()) cout<<0<<endl;	
			else cout<<threw<<endl;
			exit(0);
		}
		else{
			int len=input.size()-1;
			if (input[len]=='%'){
				for (int i=0;i<len;i++)
					threw+=input[i];
				change_way();
				int tmp=0;
				while(threw[tmp]=='0'){
					threw.erase(tmp,1);
				}
				if (threw.empty()) cout<<"0%"<<endl;
				else cout<<threw<<"%"<<endl;
				exit(0);
			}
			else {
				threw=input;
				change_way();
				int tmp=0;
				while(threw[tmp]=='0'){
					threw.erase(tmp,1);
				}
				if (threw.empty()) cout<<0<<endl;
				else cout<<threw<<endl;
				exit(0);
			}
		}
	}
}
int main()
{
	change();
	return 0;
}