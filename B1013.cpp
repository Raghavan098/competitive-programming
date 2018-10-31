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

const int N = 200000;
int arr[N];
int n,x;
multiset<int> s1,s2;

int main(){ _
    cin>>n>>x;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        if(s1.find(arr[i])!=s1.end()){
            cout<<0<<endl;
            return 0;
        }
        s1.insert(arr[i]);
    }
    bool s = false;
    for(int i=0;i<n;i++){
        s1.erase(s1.find(arr[i]));
        int temp = arr[i]&x;
        if(s1.find(temp)!=s1.end()){
            cout<<1<<endl;
            return 0;
        }
        if(s2.find(temp)!=s2.end()){
            s = true;
        }
        s2.insert(temp);
        s1.insert(arr[i]);
    }
    if(s==true){
        cout<<2<<endl;
        return 0;
    }
    cout<<-1<<endl;
    return 0;
}
