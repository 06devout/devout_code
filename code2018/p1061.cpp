# include <iostream>
# include <cstdio>

using namespace std;

string s;
int n,x,y;

int jamnum(int k)
{
    if(k==0) return ' ';
    char c=s[k];
    if(c+1>(char)96+(y-(n-1-k))) 
    {
        char c=jamnum(k-1);
        if(c==' ') return ' ';
        s[k]=c+1;
        return s[k];
    }
    else
    {
        s[k]=c+1; 
        return s[k];
    }
}
int main()
{
    scanf("%d%d%d\n",&x,&y,&n); 
    cin>>s;
    for(int i=1; i<=5; i++)
    {
        char x=jamnum(n-1); 
        if(x==' ') break;
        cout<<s<<endl;
    }
    return 0;
}