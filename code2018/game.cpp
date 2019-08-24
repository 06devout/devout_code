# include <bits/stdc++.h>

using namespace std;

string word[100]={"perfect","hurry","sleep","village","stamp","street","done","football","tennis","compare","seven","light",
"leave","apple","counter","double","bool","string","long","float","lock","capital","delete","insert","print","queue","vector","find","absolute","free",
"random","maximum","minimum","steck","root","sqrue","circle","round","horse","cloud","jack","queen","king","russia","china","england","france","spain","italy",
"america","canada","brazil","grape","banana","pear","mars","earth","venus","pluto","jupiter","mercury","seturn","titan","moon","scorpio","cancer","taoism",
"consin","father","brother","uncle","naphew","grandpa","mother","sister","aunt","niece","grandma","fridge","sofa","table","desk","oxygen","carbon","nitrogen","hydrogen",
"liquid","stable","solid","water","rabbit","girrafe","hippo","rhino","monkey","donkey","human","puppy","kitten","tiger"};
int main()
{
	srand(time(0));
	char play;
	printf("are you going to play the <hanged man>? answer 'y' as <yes>,answer 'n' as <no>\n" );
	scanf("%c%*c",&play);
	if (play=='n') {
		printf("byebye");
		return 0;
	}
	while(play=='y'){
		int player=rand()%100;
		int length=word[player].size();
		int fortime=length*2;
		printf("now let's begin,you have %d time for guessing letters  ",fortime);
		
		bool flag[10];
		memset(flag,0,sizeof(flag));
		
		int tmp=0;
		char unappear[10];
		memset(unappear,0,sizeof(unappear));
		for (int i=1;i<=fortime;i++){
			printf("your word:");
			for (int j=0;j<length;j++){
				if (flag[j]) printf("%c",word[player][j] );
				else printf("-");
			}
			if (tmp>0) {
				puts("");
				printf("default letters:");
				for (int i=1;i<=tmp;i++)
					printf("%c ",unappear[i] );
				
			}
			puts("");
			char guess;
			printf("guess time:%d\n",i);
			scanf("%c%*c",&guess);
			int a=word[player].find(guess,0);
			if (a==string::npos){
				printf("you guess a wrong letter!!!\n");
				unappear[++tmp]=guess;
			}
			else {
				flag[a]=true;
				int b=a;
				while(a!=string::npos){
					flag[a]=true;
					b=word[player].find(guess,a+1);
					a=b;
				}
				printf("you guess a right letter!!!\n" );
			}
			bool breaker=true;
			for (int j=0;j<length;j++)
				if (!flag[j]) breaker=false;
			if (breaker) {
				printf("the final answer is:");
				for (int j=0;j<length;j++){
					if (flag[j]) printf("%c",word[player][j] );
					else printf("-");
				}
				printf("\nyou are right!you saved the hanged man!congratulation!\n");
				break;
			}
			if (i==fortime) {
				printf("you failed ,you could't save the hanged man .be more luck next time!\n");
				printf("the answer is:");
				for (int j=0;j<length;j++)
					printf("%c",word[player][j] );
			}
		}
		printf("\nyou finished the game,now do you want to try again?\nanswer <y> as yes answer <n> as no\n");
		scanf("%c%*c",&play);
		if (play=='n') break;
	}
	printf("byebye\n");
	return 0;
}