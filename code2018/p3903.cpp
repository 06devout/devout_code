# include <iostream>
# include "algorithm"

using namespace std;

int main()
{
    int n;
    cin>>n;
    int hight[n+1];
    for (int i=1;i<=n;i++)
        cin>>hight[i];
    int ans=1;
    bool k=false;
    for (int i=2;i<=n;i++)
        if (k^(hight[i]<hight[i-1])){
            ans++;
            k=!k;
        }
    cout<<ans<<endl;
    return 0;
}