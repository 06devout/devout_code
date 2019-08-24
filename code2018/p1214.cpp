# include <cstdio>
# include <iostream>
# include <cstring>
# include <algorithm>

using namespace std;
struct queueue{
    int first;
    int bet;
};
queueue que[40000];
int cmp(queueue a,queueue b)
{
    if (a.bet!=b.bet) return a.bet<b.bet;
    return a.first<b.first;
}
int main()
{
    int n,m;
    cin>>n>>m;
    bool flag[1000000];
    memset(flag,0,sizeof(flag));
    int rightnum[40000],temp=0;
    for (int i=0;i<=m;i++)
        for (int j=0;j<=m;j++){
            flag[i*i+j*j]=true;
        }
    int top=2*m*m;
    for (int i=0;i<=top;i++){
        if (flag[i]){ rightnum[++temp]=i;
            // cout<<rightnum[temp]<<endl;
        }
    }
    
    // for (int i=0;i<=m*m;i++)
    // 	cout<<flag[i]<<endl;
    // cout<<temp<<endl;
    int time=0;
    for (int i=1;i<temp;i++){
        for (int j=i+1;j<temp;j++){
            int d=rightnum[j]-rightnum[i];
            bool tmp=true;
            for (int k=n-1;k>=2;k--){
                if (rightnum[i]+k*d>top){
                    tmp=false;
                    break;
                 }
                if (!flag[rightnum[i]+k*d]){
                    tmp=false;
                    break;
                }
            }
            if (tmp){
                time++;
                que[time].first=rightnum[i];
                que[time].bet=d;
            }
        }
        if (time>10000) break;
    }
    if (time==0){ 
        cout<<"NONE"<<endl;
        return 0;
    }
    sort(que+1,que+time+1,cmp);
    for (int i=1;i<=time;i++)
        cout<<que[i].first<<" "<<que[i].bet<<endl;
    return 0;
}