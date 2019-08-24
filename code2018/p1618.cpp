# include <cstdio>
# include <algorithm>
using namespace std;
bool cut(int x,int y,int z){
    int place[10];
    place[1]=x/100;
    place[2]=(x/10)%10;
    place[3]=x%10;
    place[4]=y/100;
    place[5]=(y/10)%10;
    place[6]=y%10;
    place[7]=z/100;
    place[8]=(z/10)%10;
    place[9]=z%10;
    sort(place+1,place+10);
    for (int i=1;i<=9;i++)
        if (place[i]!=i) return false;
    return true;
}
struct Con{
    int a,b,c;
}con[100];
bool cmp(Con a,Con b){
    return a.a<b.a;
}
int main()
{
    int a,b,c;
    bool flag=false;
    scanf("%d%d%d",&a,&b,&c);
    int end=1000/c;
    int k=0;
    for (int i=100/a;i<=end;i++){
        if (cut(i*a,i*b,i*c)) {
            k++;
            con[k].a=i*a;
            con[k].b=i*b;
            con[k].c=i*c;
            flag=true;
        }
    }
    sort(con+1,con+k+1,cmp);
    if (!flag) printf("No!!!");
    else {
        for (int i=1;i<=k;i++)
            printf("%d %d %d\n",con[i].a,con[i].b,con[i].c);
    }
    return 0;
}