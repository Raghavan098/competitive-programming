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
string s;
int n;
set<string> ans;
map<pair<int, string>, int > done;

void f(int ind, string prev){
    if(done[mp(ind, prev)] == 1){
        return;
    }
    done[mp(ind, prev)] = 1;
    string temp = "";
    int len = 0;
    for(int i = ind; i >= 0; i--){
        temp = s[i] + temp;
        len ++;
        if(len > 3 or i < 5){
            return;
        }
        if(temp != prev and len>1){
            ans.insert(temp);
            f(i -1, temp);
        }
    }
}



int32_t main(){ _
    cin >> s;
    n = s.size();
    if(s.size() < 7){
        cout << 0 << endl;
        return 0;
    }
    string temp = "";
    int len = 0;
    for(int i = n-1; i >= 0; i--){
        temp = s[i] + temp;
        len ++;
        if(len > 3 or i < 5){
            break;
        }
        if(len > 1){
            ans.insert(temp);
            f(i - 1, temp);
        }
    }
    cout << ans.size() << endl;
    for(auto i: ans){
        cout << i << endl;
    }
    return 0;
}
