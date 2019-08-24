// # include <bits/stdc++.h>

// using namespace std;
// short int onum[40000000];
// int main()
// {
//     int n;
//     cin>>n;    
//     int total=3;
//     onum[1]=2;
//     int i=1,time=1;
//     while(total*2+i+3<n){ 
//         onum[++time]=i+2;
//         int tmp=time;
//         for (int j=1;j<tmp;j++){
//             ++time;
//             onum[time]=onum[time%tmp];
//         }
//         i++;
//         total*=2;
//         total+=i+3;
//         // for (int j=1;j<=time;j++)
//         //     cout<<onum[j]<<" ";
//         // cout<<time<<" "<<n<<" "<<total<<endl;
//     }
//     i++;
//     int k=0;
//     int sum=0;
//     time++;
//     while(sum<n){
//         sum+=1+onum[(++k)%time];
//     }
//     // cout<<sum<<" "<<onum[k]<<" "<<n<<endl;
//     if (sum-onum[k%time]==n) cout<<'m'<<endl;
//     else cout<<'o'<<endl;
//     return 0;
// }
# include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin>>n;
    int total[50];
    total[0]=3;
    int i=0;
    while(total[i]<=n){ 
        i++;
        total[i]=2*total[i-1]+i+3;  
        // cout<<total[i]<<endl;
    }
    while(i){
        // cout <<n<<" "<<total[i]<<" "<<i<<endl; 
        int x=n;
        if (n-total[i-1]>0) {
            x=n-total[i-1];   
            if (x<=i+3){
                if (x==1) cout<<"m"<<endl;
                else cout<<"o"<<endl;
                return 0;
            }
            else{ 
                if (n-total[i-1]-i-3>0) n-=total[i-1]+i+3;
                else if (n-total[i-1]>0) n-=total[i-1];
                i--;
            } 
        }
        else  i--;
    }
    if (n==1) cout<<"m"<<endl;
    else cout<<"o"<<endl; 

    return 0;
}