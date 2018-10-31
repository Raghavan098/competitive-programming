// g++ -std=c++14

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

int lu, ld, lr, lil;
int x, y;
int ans = 0;
int cx, cy;

void go_right();
void go_left();
void go_down();
void go_up();

void go_right(){
    if(cx == x and cy == y){
        cout << ans << endl;
        exit(0);
    }
    if(cx != lr){
        cx ++;
        go_right();
    }
    else{
        lr++;
        ans++;
        go_up();
    }
}

void go_up(){
    if(cx == x and cy == y){
        cout << ans << endl;
        exit(0);
    }
    if(cy != lu){
        cy ++;
        go_up();
    }
    else{
        lu++;
        ans++;
        go_left();
    }
}

void go_left(){
    if(cx == x and cy == y){
        cout << ans << endl;
        exit(0);
    }
    if(cx != lil){
        cx --;
        go_left();
    }
    else{
        lil--;
        ans++;
        go_down();
    }
}

void go_down(){
    if(cx == x and cy == y){
        cout << ans << endl;
        exit(0);
    }
    if(cy != ld){
        cy --;
        go_down();
    }
    else{
        ld--;
        ans++;
        go_right();
    }
}

int32_t main(){ _
    cin >> x >> y;
    lu = 1;
    lr = 1;
    ld = -1;
    lil = -1;
    go_right();
    return 0;
}
