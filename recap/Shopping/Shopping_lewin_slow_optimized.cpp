#include <cstdio>

using namespace std;

const int MAXN = 200010;

long long arr[MAXN];

int n,q;

int main() {
  scanf("%d%d", &n, &q);
  for (int i = 0; i < n; i++) scanf("%lld", arr+i);
  for (int i = 0, l, r; i < q; i++) {
    long long v;
    scanf("%lld%d%d", &v, &l, &r);
    l--; r--;
    int j;
    for (j = l; j + 8 <= r; j += 8) {
      if (v >= arr[j+0]) {if ((arr[j+0] << 1) >= v) v -= arr[j+0]; else v %= arr[j+0];}
      if (v >= arr[j+1]) {if ((arr[j+1] << 1) >= v) v -= arr[j+1]; else v %= arr[j+1];}
      if (v >= arr[j+2]) {if ((arr[j+2] << 1) >= v) v -= arr[j+2]; else v %= arr[j+2];}
      if (v >= arr[j+3]) {if ((arr[j+3] << 1) >= v) v -= arr[j+3]; else v %= arr[j+3];}
      if (v >= arr[j+4]) {if ((arr[j+4] << 1) >= v) v -= arr[j+4]; else v %= arr[j+4];}
      if (v >= arr[j+5]) {if ((arr[j+5] << 1) >= v) v -= arr[j+5]; else v %= arr[j+5];}
      if (v >= arr[j+6]) {if ((arr[j+6] << 1) >= v) v -= arr[j+6]; else v %= arr[j+6];}
      if (v >= arr[j+7]) {if ((arr[j+7] << 1) >= v) v -= arr[j+7]; else v %= arr[j+7];}
    }
    for (; j <= r; j++) {
      if (v >= arr[j]) {if ((arr[j] << 1) >= v) v -= arr[j]; else v %= arr[j];}
    }
    printf("%lld\n", v);
  }
  return 0;
}