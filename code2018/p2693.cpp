# include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin>>n;
    int john[4];
    for (int i=1;i<=3;i++)
        cin>>john[i];
    int lock[4];
    for (int i=1;i<=3;i++)
        cin>>lock[i];
    bool flag[120][120][120];
    memset(flag,0,sizeof(flag));
    for (int i=-2;i<=2;i++)
        for (int j=-2;j<=2;j++)
            for (int k=-2;k<=2;k++){
                flag[(john[1]+i+n)%n][(john[2]+j+n)%n][(john[3]+k+n)%n]=true;
                flag[(lock[1]+i+n)%n][(lock[2]+j+n)%n][(lock[3]+k+n)%n]=true;
            }
    int ans=0;
    for (int i=0;i<n;i++)
        for (int j=0;j<n;j++)
            for (int k=0;k<n;k++){
                if (flag[i][j][k]) ans++;
            }
    cout<<ans<<endl;
    return 0;
}