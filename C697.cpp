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

#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define __ freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);

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

ll temp;
ll q,a,b,cur_ans,w;
map<pair<ll,ll>, ll > s;
vector<ll> v1,v2;
int main(){
  cin>>q;
  while(q--){
    cin>>temp;
    if(temp==1){
      cin>>a>>b>>w;
      v1.clear();
      v2.clear();
      while(a!=0){
        v1.pb(a);
        a/=2;
      }
      while(b!=0){
        v2.pb(b);
        b/=2;
      }
      cur_ans = 1;
      reverse(v1.begin(),v1.end());
      reverse(v2.begin(),v2.end());
      for(ll i=0;i<v1.size() && i<v2.size();i++){
        if(v1[i]!=v2[i]){
          break;
        }
        else{
          cur_ans = v1[i];
        }
      }
      for(ll i=v1.size()-1;i>0 && v1[i]!=cur_ans;i--){
        if(v1[i]==cur_ans){
          break;
        }
        else{
          if(s.find(mp(v1[i],v1[i-1]))==s.end()){
            s[mp(v1[i],v1[i-1])] = w;
            s[mp(v1[i-1],v1[i])] = w;
          }
          else{
            s[mp(v1[i],v1[i-1])] += w;
            s[mp(v1[i-1],v1[i])] += w;
          }
        }
      }
      for(ll i=v2.size()-1;i>0 && v2[i]!=cur_ans;i--){
        if(v2[i]==cur_ans){
          break;
        }
        else{
          if(s.find(mp(v2[i],v2[i-1]))==s.end()){
            s[mp(v2[i],v2[i-1])] = w;
            s[mp(v2[i-1],v2[i])] = w;
          }
          else{
            s[mp(v2[i],v2[i-1])] += w;
            s[mp(v2[i-1],v2[i])] += w;
          }
        }
      }
    }
    else{
      ll ans  =0;
      cin>>a>>b;
      v1.clear();
      v2.clear();
      while(a!=0){
        v1.pb(a);
        a/=2;
      }
      while(b!=0){
        v2.pb(b);
        b/=2;
      }
      cur_ans = 1;
      reverse(v1.begin(),v1.end());
      reverse(v2.begin(),v2.end());
      for(ll i=0;i<v1.size() && i<v2.size();i++){
        if(v1[i]!=v2[i]){
          break;
        }
        else{
          cur_ans = v1[i];
        }
      }
      for(ll i=v1.size()-1;i>0 && v1[i]!=cur_ans;i--){
        if(v1[i]==cur_ans){
          break;
        }
        else{
          if(s.find(mp(v1[i],v1[i-1]))!=s.end()){
            ans+=s[mp(v1[i],v1[i-1])];
          }
        }
      }
      for(ll i=v2.size()-1;i>0 && v2[i]!=cur_ans;i--){
        if(v2[i]==cur_ans){
          break;
        }
        else{
          if(s.find(mp(v2[i],v2[i-1]))!=s.end()){
            ans+=s[mp(v2[i],v2[i-1])];
          }
        }
      }
      cout<<ans<<endl;
    }
  }
  return 0;
}
