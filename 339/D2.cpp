#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <set>
#include <cstdio>
#include <cstdlib>
#include <stack>
#include <cstring>
#include <iomanip>


using namespace std;
const int N = 400040;

long long ST[N];

int q;
long long val;

void update(int x,int y,int n,int p) {
    if(q > y || q < x) return;
    else if(q == x && q == y) {
        ST[n] = val;
        return;
    }
    update(x,(x + y)/2, 2 * n, !p);
    update( (x + y)/2 + 1,y, 2 * n + 1, !p);
    if(p == 1) ST[n] = ST[2 * n] | ST[2 * n + 1];
    else ST[n] = ST[2 * n] ^ ST[2 * n + 1];
}

int main() {
    for(int i = 0;i < N;i++) ST[i] = 0;
    int n,m; cin>>n>>m;
    for(int i = 1;i <= (1<<n);i++) {
        scanf("%lli",&val );
        q = i;
        update(1,(1<<n),1, (n % 2) );
    }
    while(m--) {
        scanf("%d %lli",&q,&val );
        update(1, (1<<n), 1, (n % 2) );
        printf("%lli\n",ST[1]);
    }
}
