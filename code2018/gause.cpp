# include <cstdio>
# include <cmath>
# include <algorithm>
using namespace std;

const int NR = 105;
const double eps = 1e-2;

int n;
double a[NR][NR],b[NR];

bool gaosi()
{
  for(int i = 1;i <= n;i++)
  {
  	for(int j = i;j <= n;j++)
       if(fabs(a[j][i]) > eps)
       {
       	 for(int k = 1;k <= n;k++)
       	 	swap(a[i][k],a[j][k]);
       	 swap(b[i],b[j]);
       }
    if(fabs(a[i][i]) <= eps) return false;
    for(int j = 1;j <= n;j++)
    {
    	if(i == j) continue;
    	double temp = a[j][i] / a[i][i];
        for(int k = i ;k <= n;k++) a[j][k] -= a[i][k] * temp;
        b[j] -= b[i] * temp; 	
    }
  }
  return true;
}

int main()
{
  scanf("%d",&n);
  for(int i = 1;i <= n;i++)
  {
  	for(int j = 1;j <= n;j++) 
  		scanf("%lf",&a[i][j]);
  	scanf("%lf",&b[i]);
  }
  if(!gaosi())
   puts("No Solution"); 
  else
   for(int i = 1;i <= n;i++) printf("%.2lf\n",b[i] / a[i][i]);
  return 0;
}