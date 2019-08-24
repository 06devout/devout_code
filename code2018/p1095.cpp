// # include <bits/stdc++.h>

// using namespace std;

// int main()
// {
// 	int m,s,t;
// 	scanf("%d%d%d",&m,&s,&t);
// 	int tc=t;
// 	int sc=s;
// 	while (s>0&&t>0){
// 		if (m>=10){
// 			m-=10;
// 			t--;
// 			s-=60;
// 			continue;
// 		}
// 		if (m==0||m==1){
// 			if (t>=7&&s>=119){
// 				s-=120;
// 				t-=7;
// 			}
// 			// else if (t>=5&&s>=){
// 			// 	s-=60;
// 			// 	t-=4;
// 			// 	m+=2;
// 			// }
// 			else {
// 				int tmp=s/17;
// 				if (s%17!=0) tmp++;
// 				s-=17*tmp;
// 				t-=tmp;
// 			}
// 			continue;
// 		}
// 		if (m==2||m==3){
// 			if (t>=3&&s>=51){
// 				s-=60;
// 				t-=3;
// 			}
// 			else {
// 				s-=17*t;
// 				t=0;
// 			}
// 			continue;
// 		}	
// 		if (m==4||m==5){
// 			if (t>=6&&s>=102){
// 				s-=120;
// 				t-=6;
// 				m-=4;
// 			}
// 			else if (t>=3&&s>=51){
// 				s-=60;
// 				t-=3;
// 				m-=2;
// 			}
// 			else {
// 				s-=17*t;
// 				t=0;
// 			}
// 			continue;
// 		}	
// 		if (m==6||m==7){
// 			if (t>=2&&s>=34){
// 				s-=60;
// 				t-=2;
// 			}
// 			else {
// 				s-=17*t;
// 				t=0;
// 			}
// 			continue;
// 		}
// 		if (m==8||m==9){
// 			if (t>=4&&s>=68){
// 				s-=120;
// 				t-=4;
// 				m-=8;
// 			}
// 			else if (t>=2&&s>=34){
// 				s-=60;
// 				t-=2;
// 				m-=6;
// 			}
// 			else {
// 				s-=17*t;
// 				t=0;
// 			}
// 			continue;
// 		}
// 	}
// 	if (s<0) s=0;
// 	if (t<0) t=0;
// 	if (t<=0&&s>0) printf("No\n%d",sc-s);
// 	else printf("Yes\n%d",tc-t);
// 	return 0;
// }

# include <bits/stdc++.h>

using namespace std;

int choice(int m,int s,int t)//return 0:闪;return 1:等;return 2:走;
{
	if (m>=10) return 0;
	if (m==0||m==1){
		if (t>=7&&s>=120) return 1;
		else return 2;
	}
	if (m==2||m==3||m==4||m==5) {
		if (t>=3&&s>=51) return 1;
		else return 2;
	}
	if (m==6||m==7||m==8||m==9){
		if (t>=2&&s>=34) return 1;
		else return 2;
	}
	return 3;
}
int main()
{
	int m,s,t;
	scanf("%d%d%d",&m,&s,&t);
	int sc=s;
	int tc=t;
	while(t>0&&s>0){
		int x=choice(m,s,t);
		t--;
		if (x==0){
			s-=60;
			m-=10;
			continue;
		}
		if (x==1){
			m+=4;
			continue;
		}
		if (x==2){
			s-=17;
			continue;
		}
		printf("default");
	}
	if (s<0) s=0;
	if (t<0) t=0;
	if (t<=0&&s>0) printf("No\n%d\n",sc-s);
	else printf("Yes\n%d\n",tc-t);
	return 0;
}