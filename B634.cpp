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

string s1,s2;
ll a,b;

bool check(ll i){
    if(s1[i]=='1' and s2[i]=='0'){
        return true;
    }
    if(s1[i]=='0' and s2[i]=='0'){
        return true;
    }
    if(s1[i]=='0' and s2[i]=='1'){
        return true;
    }
    return false;
}



int main(){ _
    for(ll i=0;i<31;i++){
        s1 += '0';
        s2 += '0';
    }
    cin>>a>>b;
    int temp = 0;
    if(a==b){
        temp = 2;
    }
    for(ll i=0;i<31;i++){
        if(a%2 == 1){
            s1[i] = '1';
        }
        else{
            s1[i] = '0';
        }
        if(b%2 == 1){
            s2[i] = '1';
        }
        else{
            s2[i] = '0';
        }
        a/=2;
        b/=2;
    }
    reverse(s1.begin(),s1.end());
    reverse(s2.begin(),s2.end());
    ll ans = 1;
    tr(s1,s2);
    // s1 += '*';
    // s2 += '*';
    for(ll i=0;i<31;i++){
        tr(i,s1[i],s2[i],s1[i+1],s2[i+1]);
        if(s1[i]=='1' and s2[i]=='1'){
            ans*=2;
        }
        else if(s1[i]=='1' and s2[i]=='0'){
            if(!check(i+1)){
                cout<<0<<endl;
                return 0;
            }
        }
        else if(s1[i]=='0' and s2[i]=='1'){
            if(!check(i+1)){
                cout<<0<<endl;
                return 0;
            }
            ans*=2;
        }
        tr(i,ans,s1[i],s2[i]);
    }
    tr(ans,ans*2);
    cout<<ans - temp<<endl;
    return 0;
}
