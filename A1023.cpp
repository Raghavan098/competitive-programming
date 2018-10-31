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

int n, m;
string s, t;

int main(){ _
    cin >> n >> m;
    cin >> s >> t;
    int done = 0;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == '*'){
            done = 1;
            break;
        }
    }
    if(done == 0){
        if(s != t){
            cout << "NO\n";
            return 0;
        }
        else{
            cout << "YES\n";
            return 0;
        }
    }
    if((n - 1) > m){
        cout << "NO\n";
        return 0;
    }
    if(s[0] == '*'){
        int i, j;
        for(i = s.size()-1, j = t.size() - 1; i >= 1 && j >= 0; i--, j--){
            if(s[i] != t[j]){
                cout << "NO\n";
                return 0;
            }
        }
        cout << "YES\n";
        return 0;
    }
    if(s[s.size() - 1] == '*'){
        int i, j;
        for(i = 0, j = 0; i < s.size()-1 && j < t.size(); i++, j++){
            if(s[i] != t[j]){
                cout << "NO\n";
                return 0;
            }
        }
        cout << "YES\n";
        return 0;
    }
    int st = 0;
    int ed = s.size() - 1;
    int i, j;
    for(i = 0, j = 0; i < s.size() && j < t.size(); i++, j++){
        if(s[i] == '*'){
            st = j - 1;
            break;
        }
        if(s[i] != t[j]){
            cout << "NO\n";
            return 0;
        }
    }
    for(i = s.size()-1, j = t.size() - 1; i >= 0 && j >= 0; i--, j--){
        if(s[i] == '*'){
            ed = j + 1;
            break;
        }
        if(s[i] != t[j]){
            cout << "NO\n";
            return 0;
        }
    }
    if(st < ed){
        cout << "YES\n";
        return 0;
    }
    cout << "NO\n";
    return 0;
}
