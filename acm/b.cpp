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
map<set<pair<int,int> >,int >rank;
vector<int>ans(10,0);
vector<pair<int,int> >used;
set<vector<pair<int,int> > >s;
int A,B,a1,a2,b1,b2;
void check(vector<int>& v){
    
}
int main(){ _
    int a1,b1,a2,b2;
    cin >> A >> B;
    cin >> a1 >> b1 >> a2 >> b2;
    for(int i=0;i<A;i++){
        for(int j=0;j<B;j++){
                if((i!=a1 and j!=b1) or (i!=a2 and j!=b2))
                    used.push_back(mp(i,j));
        }
    }
    int n = used.size();
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            for(int k=j+1;k<n;k++){
                vector<pair<int,int> >v;
                v.pb(mp(a1,b1));
                v.pb(mp(a2,b2));
                v.pb(used[i]);
                v.pb(used[j]);
                v.pb(used[k]);
                sort(v.begin(),v.end());
                // s.insert(v);
                check(v);
            }
        }
    }
}
