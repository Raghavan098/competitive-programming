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

int32_t main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> j(n);
        vector<int> l(n);
        vector<int> pre;
        for(int i=0;i<n;i++){
            cin>>j[i];
        }
        for(int i=0;i<n;i++){
            cin>>l[i];
        }
        for(int i=0;i<n;i++){
            if(j[i]==1){
                pre.pb(l[i]);
            }
        }
        if(pre.size()==1 or pre.size()==0){
            cout<<"#laughing_arjun\n";
        }
        else{
            vector<bool> cummfront(pre.size()),cummback(pre.size());
            cummfront[0]=true;
            for(int i=1;i<pre.size();i++){
                if(cummfront[i-1]==false)
                    cummfront[i]=false;
                else if(pre[i]<=pre[i-1])
                    cummfront[i]=false;
                else
                    cummfront[i]=true;
            }
            cummback[pre.size()-1]=true;
            for(int i=pre.size()-2;i>=0;i--){
                if(cummback[i+1]==false)
                    cummback[i]=false;
                else if(pre[i]>=pre[i+1])
                    cummback[i]=false;
                else
                    cummback[i]=true;
            }   
            int k=0;
            int done = 0;
            for(int i=1;i<pre.size()-1;i++){
                if(cummfront[i-1]==true and cummback[i+1]==true and pre[i-1]<pre[i+1]){
                    done = 1;
                    cout<<"#laughing_arjun\n";
                    break;
                }
            }
            if(done==0){
                if(cummback[1]==true){
                    done = 1;
                    cout<<"#laughing_arjun\n";
                }
                else if(cummfront[pre.size()-2]==true){
                    done = 1;
                    cout<<"#laughing_arjun\n";
                }
            }
            if(done==0){
                cout<<"#itsnot_arjun\n";
            }
        }
    }
    return 0;
}
