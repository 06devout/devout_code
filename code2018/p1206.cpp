# include <cstdio>
# include <cstring>
# include <algorithm>
# include <cmath>
# define FOR(i, a, b) for (int i = a; i <= b; ++i)
# define _FOR(i, a, b) for (int i = a; i >= b; --i)
using namespace std;
const int NR = 20;
int n;
char num[NR];
void base(int x, int n)
{
    int t = 0;
    while(x){
        ++t;
        int remainder = x % n;
        if (remainder <= 9)
            num[t] = remainder ^ 48;
        else {
            remainder -= 9;
            num[t] = remainder ^ 64;
        }
        x /= n;
    }
    num[0] = t;
}
bool check(const char x[NR])
{
    FOR(i, 1, x[0])
        if (x[i] != x[x[0] - i + 1]) return false;
    return true;
}
void PT(const char x[NR])
{
    _FOR(i, x[0], 1) printf("%c", x[i]);
}
int main()
{    
    scanf("%d", &n);
    FOR(i, 1, 300){
        base(i*i, n);
        if (check(num)){
            base(i, n);
            PT(num);
            printf(" ");
            base(i * i, n);
            PT(num);
            puts("");
        }
    }
    return 0;
}