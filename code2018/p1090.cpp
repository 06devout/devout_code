# include <bits/stdc++.h>

using namespace std;
int pass[10005];
int weight[10005];
int main()
{
    int n;
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
        scanf("%d",&weight[i]);
    sort(weight+1,weight+n+1);
    int total=0;
    for (int i=1;i<n;i++){
        int x=weight[i]+weight[i+1];
        total+=x;
        for (int j=i+2;j<=n;j++){
            if (weight[j]>x) {
                weight[j-1]=x;
                break;
            }

            weight[j-1]=weight[j];
            if (j==n) weight[j]=x;               
        }                                        
    }
    printf("%d",total);
    return 0;
}