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

int ncr(int n, int r){
    if(r == 0)return 1;
    if(r < 0)return 0;
    int ans = 1;
    for(int i = n; i > n-r; i--)ans *=i;
    for(int i = 1; i <= r; i++)ans /= i;
    return ans;
}
int solve(int no){
    string arr = to_string(no);
    int len = arr.size();
    int temp = no;
    if(len <= 3)return no;
    int ans = 0;
    int cnt = 3;
    for(int i = 0; i < len; i++){
        if(arr[i] != '0'){
            for(int j = 0; j <= cnt; j++){
                ans += ncr(len - i - 1, j)*pow(9, j);
            }
            for(int j = 0; j <= cnt-1; j++){
                ans += (arr[i] - '0' - 1)*ncr(len - i - 1, j)*pow(9, j);
            }
            cnt--;
        }
        if(cnt == 0)break;
    }
    return ans;
}

int32_t main(){
    int t;
    cin >> t;
    for(int i_i = 0; i_i < t; i_i++){
        int l, r;
        cin >> l >> r;
        cout << solve(r) - solve(l-1) << endl;
    }
}
