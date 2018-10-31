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

struct rect{
    int a, b, c, d;
};
const int N = 2e5 + 10;
const int eps = 1e9 + 7;

rect arr[N], cf[N], cb[N];
int n;

void pre(rect s){
    tr(s.a, s.b, s.c, s.d);
}

pair<int, int> mer2(int a, int b, int c, int d){
    if(a == -1){
        return mp(-1, -1);
    }
    if(a > c){
        swap(a, c);
        swap(b, d);
    }
    if(b < c){
        return mp(-1, -1);
    }
    else{
        if(a <= c and b >= c){
            if(b >= d){
                return mp(c, d);
            }
            else{
                return mp(c, b);
            }
        }
    }
}

rect mer(rect f, rect s){
    rect ans;
    auto temp = mer2(f.a, f.c, s.a, s.c);
    ans.a = temp.fi;
    ans.c = temp.se;
    temp = mer2(f.b, f.d, s.b, s.d);
    ans.b = temp.fi;
    ans.d = temp.se;
    if(ans.a == -1 or ans.b == -1 or ans.c == -1 or ans.d == -1){
        ans.a = -1;
        ans.b = -1;
        ans.c = -1;
        ans.d = -1;
    }
    return ans;
}

int32_t main(){ _
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> arr[i].a >> arr[i].b >> arr[i].c >> arr[i].d;
        arr[i].a += eps;
        arr[i].b += eps;
        arr[i].c += eps;
        arr[i].d += eps;
    }
    cf[0] = arr[0];
    for(int i = 1; i < n; i++){
        cf[i] = mer(cf[i-1], arr[i]);
    }
    cb[n-1] = arr[n-1];
    for(int i = n-2; i >= 0; i--){
        cb[i] = mer(cb[i+1], arr[i]);
    }
    for(int i = 1; i < n-1; i++){
        rect temp = mer(cf[i-1], cb[i+1]);
        if(temp.a != -1){
            cout << temp.a - eps << " " << temp.b - eps << endl;
            return 0;
        }
    }
    if(cf[n-2].a != -1){
        cout << cf[n-2].a - eps << " " << cf[n-2].b - eps << endl;
        return 0;
    }
    if(cb[1].a != -1){
        cout << cb[1].a - eps << " " << cb[1].b - eps << endl;
        return 0;
    }
    return 0;
}
