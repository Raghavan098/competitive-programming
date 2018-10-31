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

int solve(){
    int n, e;
    cin >> n >> e;
    vector<int> v(n);
    int mi = INT_MAX;
    int ind_mi;
    int mx = -1;
    int ind_mx;
    for(int i = 0; i < n; i++){
        int temp;
        cin >> temp;
        if(temp > mx){
            mx = temp;
            ind_mx = i;
        }
        if(temp < mi){
            mi = temp;
            ind_mi = i;
        }
    }
    if(e < mi or e > mx){
        cout << -1 << endl;
        return 0;
    }
    if(mx == mi){
        if(e==mx){
            cout << 1 << " ";
            for(int i = 1; i < n; i++){
                cout << 0 << " ";
            }
            cout << endl;
        }
        else{
            cout << -1 << endl;
        }
        return 0;
    }
    lld a = (lld(e - mi)/lld(mx - mi));
    for(int i = 0; i < n; i++){
        if(i==ind_mx){
            printf("%0.12Lf ",a);
        }
        else if(i==ind_mi){
            printf("%0.12Lf ",1 - a);
        }
        else{
            printf("0 ");
        }
    }printf("\n");
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}
