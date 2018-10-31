#include<cstdio>
#include <math.h>
int k, r;
int n, m;
double ans;
int main()
{
  scanf("%d%d", &k, &r);
  n=(1<<k)-1; m=(1<<k)-r;
  double p=1.0;
  for(int k=1;(1<<k)-1<=m;k++)
  {
    int sm=m-(1<<k)+2, em=m-(1<<(k-1))+1;
    int sn=n-(1<<k)+2;
    for(int mm=sm, nn=sn;mm<=em;mm++, nn++) p*=(double)(mm)/(double)(nn);
    ans+=p;
  }
  int dig = ((int)floor(ans * 1000000)) % 10 ;
  if (dig == 4 || dig == 5) {
     printf("%.15lf %d\n", ans, dig);
  } else {
     printf("%.5lf\n", ans);
  }
  return 0;
}
