#include<bits/stdc++.h>
using namespace std;
#pragma comment(linker, "/STACK:102400000,102400000")
#define rep(i,a,b) for (int i=a; i<=b; ++i)
#define per(i,b,a) for (int i=b; i>=a; --i)
#define mes(a,b)  memset(a,b,sizeof(a))
#define INF 0x3f3f3f3f
#define MP make_pair
#define PB push_back
#define fi  first
#define se  second
typedef long long ll;
const int N = 500005;

int n, tree[N<<2], cnt;
void update(int ro, int L, int R, int x, int y)
{
    if(L==R && L==x) {
        tree[ro] = y;
        return ;
    }
    int mid = L+R>>1;
    if(x <= mid)
        update(ro<<1, L, mid, x, y);
    else
        update(ro<<1|1, mid+1, R, x, y);
    tree[ro] = __gcd(tree[ro<<1], tree[ro<<1|1]);
}
bool query(int ro, int L, int R, int l, int r, int x)
{
    if(cnt>1) return false;
    if(l<=L && R<=r)
    {
        if(tree[ro]%x==0) return true;
        if(L==R && tree[ro]%x!=0) { ++cnt; return false; }
    }
    int mid = L+R>>1;
    if(l<=mid) {
        query(ro<<1, L, mid, l, r, x);
    }
    if(mid<r) {
        query(ro<<1|1, mid+1, R, l, r, x);
    }
    if(cnt>1) return false;
    return true;
}
int main()
{
    scanf("%d", &n);
    int ai, ti, l, r, x, y, q;
    rep(i,1,n)
    {
        scanf("%d", &ai);
        update(1, 1, n, i, ai);
    }
    scanf("%d", &q);
    while(q--)
    {
        scanf("%d", &ti);
        if(ti==1) {
            scanf("%d%d%d", &l, &r, &x);
            cnt = 0;
            if(query(1, 1, n, l, r, x)) puts("YES");
            else puts("NO");
        }
        else {
            scanf("%d%d", &x, &y);
            update(1, 1, n, x, y);
        }
    }

    return 0;
}
