# include <cstdio>
# include <algorithm>
# include <cstring>

using namespace std;

int main()
{
	char s[500];
	char ans[500];
	int sz=0;
	scanf("%s",s);
	int cnt=0;
	while(s[strlen(s)-1]!='.'){
		if (strlen(s)-1>sz){
			sz=strlen(s)-1;
			strcpy(ans,s);
		}
		scanf("%s",s);
		cnt++;
	}
	if (!cnt){
		for (int i=0;i<strlen(s)-1;i++) printf("%c",s[i]);
		puts("");
		return 0;
	}
	if (strlen(s)-2>sz){
		for (int i=0;i<strlen(s)-1;i++)
			printf("%c",s[i]);
		puts("");
	}
	else printf("%s\n",ans);
	return 0;
}