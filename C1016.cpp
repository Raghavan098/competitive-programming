// g++ -std=c++14

/*

Today might be the chance to grasp the chance to let your talent bloom.
May be tomorrow, the day after, or next year...
May be even when you are 30. I'm not sure if physique has anything to do with it
but if you think that it will never come, it probably never will.

- Tooru Oikawa.

*/


#include<bits/stdc++.h>

typedef long long ll;
typedef long double lld;
using namespace std;

#define sd(x) scanf("%d",&x)
#define sd2(x,y) scanf("%d%d",&x,&y)
#define sd3(x,y,z) scanf("%d%d%d",&x,&y,&z)
#define endl "\n"
#define fi first
#define se second
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define LET(x, a)  __typeof(a) x(a)
#define foreach(it, v) for(LET(it, v.begin()); it != v.end(); it++)
#define MEMS(a,b) memset(a,b,sizeof(a))
#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define __ freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#define all(c) c.begin(),c.end()
#define inf 1000000000000000001

#define tr(...) cout<<__FUNCTION__<<' '<<__LINE__<<" = ";trace(#__VA_ARGS__, __VA_ARGS__)

template<typename S, typename T>
ostream& operator<<(ostream& out,pair<S,T> const& p){out<<'('<<p.fi<<", "<<p.se<<')';return out;}

template<typename T>
ostream& operator<<(ostream& out,vector<T> const& v){
ll l=v.size();for(ll i=0;i<l-1;i++)out<<v[i]<<' ';if(l>0)out<<v[l-1];return out;}

template<typename T>
void trace(const char* name, T&& arg1){cout<<name<<" : "<<arg1<<endl;}

template<typename T, typename... Args>
void trace(const char* names, T&& arg1, Args&&... args){
const char* comma = strchr(names + 1, ',');cout.write(names, comma-names)<<" : "<<arg1<<" | ";trace(comma+1,args...);}

#define int ll

const int N = 3e5 + 100;

int a[N], b[N], n;
int c1[N], c2[N], c3[N], c4[N], c5[N], c6[N];

int32_t main(){ _
    cin >> n;
    int tota = 0;
    int totb = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        c1[i] += i*a[i];
        if(i != 0){
            c1[i] += c1[i-1];
        }
        c5[i] += a[i];
        if(i != 0){
            c5[i] += c5[i-1];
        }
    }
    for(int i = 0; i < n; i++){
        cin >> b[i];
        c2[i] += i*b[i];
        if(i != 0){
            c2[i] += c2[i - 1];
        }
        c6[i] += b[i];
        if(i != 0){
            c6[i] += c6[i-1];
        }
    }
    int curr = n;
    for(int i = n - 1; i >= 0; i--){
        c4[i] = curr*b[i] + c4[i + 1];
        curr++;
    }
    curr = n;
    for(int i = n - 1; i >= 0; i--){
        c3[i] = curr*a[i] + c3[i + 1];
        curr++;
    }
    int state = 0;
    int ans = -1;
    int ap = 0;
    int bp = 0;
    curr = 0;
    int tim = 0;
    for(int i = 0; i < 2*n; i++){
        if(state == 0){
            int temp = c1[n - 1];
            if(ap != 0){
                temp -= c1[ap - 1];
            }
            int t2 = c5[n - 1];
            if(ap != 0){
                t2 -= c5[ap - 1];
            }
            temp += (tim - ap)*(t2);
            temp += c4[ap];
            temp += (tim - ap)*(c6[ap]);
            if(ap != 0){
                temp -= (tim - ap)*(c6[ap - 1]);
            }
            ans = max(ans, temp + curr);
            curr += tim*a[ap];
            ap++;
        }
        else if(state == 1){
            int temp = c2[n - 1];
            if(bp != 0){
                temp -= c2[bp - 1];
            }
            int t2 = c6[n - 1];
            if(bp != 0){
                t2 -= c6[bp - 1];
            }
            temp += (tim - bp)*(t2);
            temp += c3[bp + 1];
            temp += (tim - bp)*(c5[n -1] - c5[bp]);
            ans = max(ans, temp + curr);
            curr += tim*b[bp];
            bp++;

        }
        else if(state == 2){
            int temp = c2[n - 1];
            if(bp != 0){
                temp -= c2[bp - 1];
            }
            int t2 = c6[n - 1];
            if(bp != 0){
                t2 -= c6[bp - 1];
            }
            temp += (tim - bp)*(t2);
            temp += c3[bp];
            temp += (tim - bp)*(c5[n -1] - c5[bp - 1]);
            ans = max(ans, temp + curr);
            curr += tim*b[bp];
            bp++;
        }
        else{
            int temp = c1[n - 1];
            if(ap != 0){
                temp -= c1[ap - 1];
            }
            int t2 = c5[n - 1];
            if(ap != 0){
                t2 -= c5[ap - 1];
            }
            temp += (tim - ap)*(t2);
            temp += c4[ap + 1];
            temp += (tim - ap)*(c6[n - 1]);
            temp -= (tim - ap)*(c6[ap]);
            ans = max(ans, temp + curr);
            curr += tim*a[ap];
            ap++;
        }
        tim++;
        state += 1;
        state %= 4;

    }
    cout << ans << endl;
    return 0;
}
