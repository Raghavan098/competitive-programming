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

const int N = 2e5 + 100;

int n;
string s;
int x, y, curx, cury;
int rl, rr, rd, ru, a, b, c, d;

bool check(int req, int gap, int l, int r){
    int pre = (r - l);
    req -= pre;
    req -= gap;
    return (req > 0);
}


int32_t main(){
    cin >> n;
    cin >> s;
    cin >> x >> y;
    for(int i = 0; i < n; i++){
        if(s[i] == 'U'){
            cury++;
        }
        if(s[i] == 'R'){
            curx++;
        }
        if(s[i] == 'L'){
            curx--;
        }
        if(s[i] == 'D'){
            cury--;
        }
    }
    if(curx == x and cury == y){
        cout << 0 << endl;
        return 0;
    }
    if(curx > x){
        a = rl = (curx - x);
    }
    else{
        b = rr = (x - curx);
    }
    if(cury > y){
        c = rd = (cury - x);
    }
    else{
        d = ru = (y - cury);
    }
    int prex = 0, prey = 0;
    int l = 0;
    int r = 0;
    int req = rl + rr + rd + ru;
    tr(a, b, c, d, rl, rr, rd, ru);
    if(req % 2 != 0){
        cout << -1 << endl;
        return 0;
    }
    int gap = 0;
    int ans = 1e9;
    for(int l = 0; l < n; l++){
        tr(req);
        while(check(req, gap, l, r) and r < n){
            if(s[r] == 'U' and rd > 0){
                rd--;
                gap++;
            }
            else if(s[r] == 'D' and ru > 0){
                ru--;
                gap++;
            }
            else if(s[r] == 'L' and rr > 0){
                rr--;
                gap++;
            }
            else if(s[r] == 'R' and rl > 0){
                rl--;
                gap++;
            }
            tr(r, req, gap);
            r++;
        }
        tr(r, l, req, gap, check(req, gap, l, r));
        if(check(req, gap, l, r) == false){
            ans = min(ans, r - l);
        }
        if(s[l] == 'U' and c > 0){
            rd++;
            gap--;
        }
        else if(s[l] == 'D' and d > 0){
            ru++;
            gap--;
        }
        else if(s[l] == 'L' and b > 0){
            rr++;
            gap--;
        }
        else if(s[l] == 'R' and a > 0){
            rl++;
            gap--;
        }
    }
    if(ans == 1e9){
        cout << -1 << endl;
        return 0;
    }
    cout << ans << endl;
}
