# include <cstdio>
# include <algorithm>
# include <cstring>

using namespace std;

const int N=1005;

char s[N];

int left,right;

int main()
{
	scanf("%s",s);
	for (int i=0;i<strlen(s);i++){
		if (s[i]=='(') left++;
		if (s[i]==')'&&left>right) right++;
	}
	if (left==right) printf("YES");
	else printf("NO");
	return 0;
}