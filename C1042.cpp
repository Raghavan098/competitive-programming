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

// #define int ll

const int N = 2e5 + 100;
vector<pair<int, int> > inp, pos, neg, zer;
int arr[N], n;

int32_t main(){ _
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        inp.pb(mp(arr[i], i + 1));
    }
    sort(all(inp));
    pair<int, int> last;
    int hh = -1;
    int y = -1;
    int qq = -1;
    for(int i = 0; i < n; i++){
        if(inp[i].fi < 0){
            neg.pb(inp[i]);
            last = inp[i];
            qq = inp[i].se;
        }
        else if(inp[i].fi > 0){
            pos.pb(inp[i]);
            hh = inp[i].se;
        }
        else{
            zer.pb(inp[i]);
            y = inp[i].se;
        }
    }
    for(int i = 0; i < (int)zer.size() - 1; i++){
        cout << 1 << " " << zer[i].se << " " << zer[i+1].se << endl;
        y = zer[i+1].se;
    }
    for(int i = 0; i < (int)pos.size() - 1; i++){
        cout << 1 << " " << pos[i].se << " " << pos[i+1].se << endl;
        hh = pos[i+1].se;
    }
    if(qq != -1 and (int)neg.size() % 2 == 0){
        for(int i = 0; i < (int)neg.size() - 1; i++){
            cout << 1 << " " << neg[i].se << " " << neg[i+1].se << endl;
            qq = neg[i+1].se;
        }
        if(hh != -1)
            cout << 1 << " " << qq << " " << hh << endl;
        else{
            hh = qq;
        }
        qq = -1;

    }
    else if(qq != -1){
        int done = 1;
        for(int i = 0; i < (int)neg.size() - 2; i++){
            cout << 1 << " " << neg[i].se << " " << neg[i+1].se << endl;
            qq = neg[i+1].se;
            done = 0;
        }
        if(hh != -1 and done == 0)
            cout << 1 << " " << qq << " " << hh << endl;
        else if(done == 0){
            hh = qq;
        }
    }
    // tr(hh, qq, y);
    if(qq == -1){
        if(hh != -1 and y!=-1){
            cout << 2 << " " << y << endl;
        }
    }
    else if(hh == -1){
        if(y == -1){
            cout << 2 << " " << last.se << endl;
        }
        else{
            cout << 1 << " " << y << " " << last.se << endl;
        }
    }
    else{
        if(y == -1){
            cout << 2 << " " << last.se << endl;
        }
        else{
            cout << 1 << " " << y << " " << last.se << endl;
            cout << 2 << " " << last.se << endl;
        }
    }
    return 0;
}
