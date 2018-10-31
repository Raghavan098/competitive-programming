
#include <cstdio>

int N, Q, a, b;
int values[100010];
int dp_asc[100010], dp_dec[100010];

int main() {
  scanf("%d %d", &N, &Q);
  for (int i=0 ; i<N ; i++)
      scanf("%d", &values[i]);

  dp_asc[N-1] = dp_dec[N-1] = 0;
  for (int i=N-2 ; i>=0 ; i--) {
      if (values[i] <= values[i+1]) {
          dp_asc[i] = 1 + dp_asc[i+1];
      }
      else {
          dp_asc[i] = 0;
      }

      if (values[i] >= values[i+1]) {
          dp_dec[i] = 1 + dp_dec[i+1];
      }
      else {
          dp_dec[i] = 0;
      }
  }

  while (Q--) {
      scanf("%d %d", &a, &b);
      a--, b--;
      bool ladder = false;
      if (b <= a+dp_asc[a] || b <= a+dp_dec[a] || b <= (a+dp_asc[a]) + dp_dec[a+dp_asc[a]])
          ladder = true;

      printf(ladder ? "Yes\n" : "No\n");
  }
}
