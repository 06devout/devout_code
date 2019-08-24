# include <cstdio>
# include <algorithm>
# include <cstring>
# include <cmath>
# include <vector>
# include <queue>
# include <deque>

# define f(i,a,b) for (int i=a;i<=b;i++)
# define F(i,a,b) for (int i=a;i>=b;i--)

using namespace std;

struct mid_queue{
	static const int N=1000005;
	int a[N];
	int top=0;
	mid_queue(){
		memset(a,0,sizeof(a));
	}
	int size(){
		return top-1;
	}
}