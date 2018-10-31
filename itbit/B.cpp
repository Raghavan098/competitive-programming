// g++ -std=c++14

/*

Today might be the chance to grasp the chance to let your talent bloom.
May be tomorrow, the day after, or next year...
May be even when you are 30. I'm not sure if physique has anything to do with it
but if you think that it will never come, it probably never will.

- Tooru Oikawa.

*/


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
#define all(c) c.begin(),c.end()
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

// #define int ll

int32_t main(){ _
    int n;
    cin>>n;
    int A[n],B[n];
    for(int i=0;i<n;i++)
        cin>>A[i];
    for(int i=0;i<n;i++)
        cin>>B[i];
    int k,p;
    cin>>k>>p;
    set<pair<int,int>> s1,s2;
    // int n=A.size();
    vector<int> dp1(n,0);
    vector<int> dp2(n,0);
    for(int i=0;i<n;i++){
        if(i==0){
            dp1[0]=A[0];
            dp2[0]=B[0];
            s1.insert(make_pair(A[0],0));
            s2.insert(make_pair(B[0],0));
        }
        else{
            if((*s1.begin()).first<(*s2.begin()).first+p){
                dp1[i]=dp1[(*(s1.begin())).second]+A[i];
            }
            else
                dp1[i]=dp2[(*(s2.begin())).second]+p+A[i];
            if((*(s1.begin())).first+p<(*(s2.begin())).first){
                dp2[i]=dp1[(*(s1.begin())).second]+p+B[i];
            }
            else
                dp2[i]=dp2[(*(s2.begin())).second]+B[i];
            s1.insert(make_pair(dp1[i],i));
            s2.insert(make_pair(dp2[i],i));
            if(i>=k){
                s1.erase(make_pair(dp1[i-k],i-k));
                s2.erase(make_pair(dp2[i-k],i-k));
            }
        }
    }
    for(int i=0;i<n;i++){
        tr(dp1[i],dp2[i]);
    }
    cout<<min(dp1[n-1],dp2[n-1]);
}
