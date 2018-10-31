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

int n,m;
vector<int> ja;
vector<int> jd;
vector<int> ca;

int main(){
  cin>>n>>m;
  int tot_atk_j = 0;
  for(int i=0;i<n;i++){
    string temp;
    int s;
    cin>>temp>>s;
    if(temp=="ATK"){
      ja.pb(s);
      tot_atk_j+=s;
    }
    else{
      jd.pb(s);
    }
  }
  int total_attack = 0;
  for(int i=0;i<m;i++){
    int s;
    cin>>s;
    ca.pb(s);
    total_attack+=s;
  }
  int done[200];
  fill(done,done+m,0);
  int cant = 0;
  int tot = 0;
  for(int i=0;i<jd.size();i++){
    int temp = -1;
    int ind;
    for(int j=0;j<m;j++){
      if(ca[j]>jd[i] and done[j]==0){
        if(temp==-1){
          temp = ca[j];
          ind = j;
        }
        else if(ca[j]<temp and done[j]==0){
          temp = ca[j];
          ind = j;
        }
      }
    }
    if(temp==-1){
      cant = 1;
      break;
    }
    done[ind] = 1;
    tot+=temp;
    // tr(temp,ind);
  }
  // tr(tot);
  int m1 =0;
  if(cant==0){
    for(int i=0;i<ja.size();i++){
      int temp = -1;
      int ind;
      for(int j=0;j<m;j++){
        if(ca[j]>=ja[i] and done[j]==0){
          if(temp==-1){
            temp = ca[j];
            ind = j;
          }
          else if(ca[j]<temp and done[j]==0){
            temp = ca[j];
            ind = j;
          }
        }
      }
      if(temp==-1){
        cant = 1;
        break;
      }
      done[ind] = 1;
      m1 += (ca[ind] - ja[i]);
      // tr(m1);
    }
    if(cant==0){
      // tr(m1);
      for(int i=0;i<m;i++){
        if(done[i]==0){
          m1+=ca[i];
          // tr(i);
        }
      }
      // tr(m1);
      // m1 -= tot;
    }
    else{
      m1 =0;
    }
  }
  int m2 = 0;
  sort(ja.begin(),ja.end());
  sort(ca.begin(),ca.end());
  reverse(ca.begin(),ca.end());
  for(int i=0;i<m;i++){
    if(i<ja.size() and ca[i]>ja[i]){
      m2+=(ca[i] - ja[i]);
    }
    else{
      break;
    }
  }
  // tr(m1,m2);
  cout<<max(m1,m2)<<endl;
  return 0;
}
