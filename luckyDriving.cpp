#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<assert.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

#define ll long long
#define M 1000000007

int main(){
  int T;
  char in[20000];
  int n, i, j;
  int cnt[10], a, b, c, d, sum, use[10];
  ll res, tmp;

  assert( scanf("%d",&T)==1 );
  assert( 1<=T && T<=200 );
  while(T--){
    assert( scanf("%s",in)==1 );
    n = strlen(in);
    assert( 1<=n && n<=10000 );
    rep(i,n) assert( '0'<=in[i] && in[i]<='9' );

    rep(i,n) in[i] -= '0';

    rep(i,10) cnt[i] = 0;
    rep(i,n) cnt[in[i]]++; /* cnt[i] = the number of digits i in the input string */

    res = 0;
    rep(a,11) REP(b,a,11) REP(c,b,11) REP(d,c,11){ /* use digits a, b, c and d. (if x=10, then x is unused) */
      sum = 0;
      rep(i,10) use[i] = 0;
      if(a < 10) sum += a, use[a]++;
      if(b < 10) sum += b, use[b]++;
      if(c < 10) sum += c, use[c]++;
      if(d < 10) sum += d, use[d]++;
      if(sum==0 || sum%9) continue;
      tmp = 1;
      rep(i,10) rep(j,use[i]) tmp = tmp * (cnt[i]-j) / (j+1); /* the combination will fit in long long:) */
      res += tmp;
    }

    printf("%d\n",(int)(res%M));
  }

  return 0;
}
