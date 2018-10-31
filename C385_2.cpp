#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 1e7 + 5;

int n, a[maxn], p[maxn], v[maxn], c[maxn];

ll b[maxn];

int main() {
    ios::sync_with_stdio(false);
  	cin.tie(NULL);
  	cout.tie(NULL);
    //freopen("test.txt","r",stdin);
    for (int i = 2; i < maxn; i ++) {
        if (!v[i]) p[++ p[0]] = i;
        for (int j = 1; j <= p[0] && 1ll * i * p[j] < maxn; j ++) {
            v[i * p[j]] = 1;
            if (i % p[j] == 0) break;
        }
    }

    cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> a[i], c[a[i]] ++;
    for (int i = 1; i <= p[0]; i ++)
        for (int j = p[i]; j < maxn; j += p[i])
            b[p[i]] += c[j];
    for (int i = 1; i < maxn; i ++)
        b[i] += b[i - 1];
    int m, l, r;
    cin >> m;
    while ( m--) {
        cin >> l >> r;
        if (l >= maxn) cout << 0 << endl;
        else {
            if (r >= maxn) r = maxn - 1;
        cout << b[r] - b[l - 1] << endl;
        }
    }
    return 0;
}
