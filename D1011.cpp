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

ll m,n,p,ans;
string s;

int main(){
    cin>>m>>n;
    ll curr = 0;
    for(ll i=0;i<n;i++){
        cout<<m<<endl;
        fflush(stdout);
        cin>>ans;
        if(ans==0){
            exit(0);
        }
        else if(ans==1){
            s += '1';
        }
        else{
            s += '0';
        }
        curr++;
    }
    ll l = 1;
    ll r = m;
    ll mid,temp;
    while(l<=r){
        mid = (l+r)/2;
        cout<<mid<<endl;
        fflush(stdout);
        cin>>temp;
        if(s[curr%n]=='0'){
            temp = -1*temp;
        }
        if(temp==0){
            exit(0);
        }
        else if(temp==1){
            r = mid - 1;
        }
        else{
            l = mid + 1;
        }
        curr++;
    }
    return 0;
}
