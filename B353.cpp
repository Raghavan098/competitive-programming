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

int n;
int arr[500];
vector<pair<int,int> >v;
int done[500];
map<int,int> ct;
map<int,stack<int> > ind;
int temp;

bool cmp(pair<int,int> &v1,pair<int,int> &v2){
  return v1.fi>v2.fi;
}

int main(){
  cin>>n;
  for(int i=0;i<2*n;i++){
    cin>>temp;
    arr[i] = temp;
    ct[temp]++;
    ind[temp].push(i);
  }
  pair<int,int> res;
  set<int> fin_set,fin_set2;
  int curr = 1;
  for(map<int,int> ::iterator it = ct.begin();it!=ct.end();it++){
    res = *it;
    if(res.se>=2){
      fin_set.insert(res.fi);
      fin_set2.insert(res.fi);
    }
    else{
      if(curr==1){
        fin_set.insert(res.fi);
        curr = 2;
      }
      else{
        fin_set2.insert(res.fi);
        curr = 1;
      }
    }
  }
  cout<<fin_set.size()*fin_set2.size()<<endl;
  curr = 1;
  int cta = 0;
  int ctb = 0;
  int cur_intd;
  for(set<int> :: iterator it = fin_set.begin();it!=fin_set.end();it++){
    curr = *it;
    cur_intd = ind[curr].top();
    ind[curr].pop();
    done[cur_intd] =1;
    cta++;
  }
  for(set<int> :: iterator it = fin_set2.begin();it!=fin_set2.end();it++){
    curr = *it;
    cur_intd = ind[curr].top();
    ind[curr].pop();
    done[cur_intd] =2;
    ctb++;
  }
  for(int i=0;i<2*n;i++){
    if(done[i]==1){
      cout<<1<<" ";
    }
    else if(done[i]==2){
      cout<<2<<" ";
    }
    else{
      if(cta<ctb){
        cout<<1<<" ";
        cta++;
      }
      else{
        cout<<2<<" ";
        ctb++;
      }
    }
    // tr(arr[i],cta,ctb);
  }cout<<endl;
  // tr(cta,ctb);
  return 0;
}
