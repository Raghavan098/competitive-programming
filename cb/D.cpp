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

vector<long long> a,b;
const long long M = 1e9 + 7;

long long get(long long x){
    long long ans = 1;
    for(long long i=1;i*i<=x;i++){
        if(x%i==0){
            ans = (ans*i)%M;
            if((x/i)!=i){
                ans = (ans*(x/i))%M;
            }
        }
    }
    return ans;
}

vector<long long> solve(vector<long long> a,vector<long long> b){
    multiset<pair<long long,long long> > s;
    long long n = a.size();
    for(long long i =0;i<n;i++){
        s.insert(make_pair(a[i],i));
    }
    multiset<long long> :: iterator l,u;
    map<long long,long long> q;
    set<long long> ind;
    ind.insert(-1);
    ind.insert(n);
    pair<long long,long long> temp;
    for(long long i=0;i<n;i++){
        temp = *s.rbegin();
        l = ind.lower_bound(temp.second);
        u = ind.upper_bound(temp.second);
        l--;
        long long l1 = *(l);
        long long u1 = *(u);
        l1++;
        u1--;
        long long x = temp.second;
        q[temp.first] += (x - l1 + 1)*(u1 - x +1);
        // tr(temp.first,q[temp.first]);
        ind.insert(temp.second);
        s.erase(s.find(temp));
    }
    unordered_map<long long,long long> :: iterator tt = q.begin();
    map<long long,long long> m2;
    long long xx;
    for(tt = q.begin();tt!=q.end();tt++){
        temp = *tt;
        xx = get(temp.first);
        m2[xx] = temp.second;
    }
    vector<long long> cum;
    vector<long long> num;
    for(tt = m2.begin();tt!=m2.end();tt++){
        cum.push_back((*tt).second);
        num.push_back((*tt).first);
    }
    reverse(cum.begin(),cum.end());
    reverse(num.begin(),num.end());
    for(long long i=1;i<cum.size();i++){
        cum[i] += cum[i-1];
    }
    long long m = b.size();
    vector<long long> :: iterator it;
    vector<long long> ans;
    for(long long i=0;i<m;i++){
        long long x = b[i];
        it = lower_bound(cum.begin(),cum.end(),x);
        ans.push_back(num[it - cum.begin()]);
    }
    return ans;
}

int main(){
    cin>>n>>m;
    for(long long i=0;i<n;i++){
        long long temp;
        cin>>temp;
        a.push_back(temp);
    }
    for(long long i=0;i<m;i++){
        long long temp;
        cin>>temp;
        b.push_back(temp);
    }
    cout<<solve(a,b)<<endl;
}
