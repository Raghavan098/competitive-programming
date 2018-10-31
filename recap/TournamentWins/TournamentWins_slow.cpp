#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int n, m;
int k, r;
int cnt, tot;
int a[1024];
int main()
{
  scanf("%d%d", &k, &r);
  n=(1<<k)-1; m=(1<<k)-r;
  int i;
  for(i=0;i<=n;i++) a[i]=i;
  do
  {
    //for(i=0;i<=n;i++) printf("%d ", a[i]);
    //printf("\n");
    if(a[0]==m)
    {
      int wins=0;
      for(int k=1;(1<<k)-1<=n;k++)
      {
        bool flag=false;
        for(int j=1;j<(1<<k);j++)
        {
          if(a[0]<a[j]){flag=true; break;}
        }
        if(flag) break;
        wins++;
      }
      cnt+=wins; tot++;
    }
  } while(next_permutation(&a[0], &a[n+1]));
  printf("%.5lf\n", (double)(cnt)/(double)(tot));
  return 0;
}
