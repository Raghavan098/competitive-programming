// g++ -std=c++14

#include<bits/stdc++.h>

typedef long long ll;
typedef long double lld;
using namespace std;

#define sd(x) scanf("%d",&x)
#define sd2(x,y) scanf("%d%d",&x,&y)
#define sd3(x,y,z) scanf("%d%d%d",&x,&y,&z)

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

int n,m,done;
char arr[100][100],ar2[100][100];
set<int> cs,rs;
vector<set<pair<int,int> > >inp;

int main(){
  cin>>n>>m;
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      cin>>arr[i][j];
      ar2[i][j] =  '.';
    }
  }
  set<pair<int,int> > temp;
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      if(arr[i][j]=='#'){
        done = 0;
        for(int k=0;k<inp.size();k++){
          if(inp[k].find(mp(i,1))!=inp[k].end() || inp[k].find(mp(j,2))!=inp[k].end()){
            done = 1;
            inp[k].insert(mp(i,1));
            inp[k].insert(mp(j,2));
          }
        }
        if(done==0){
          temp.clear();
          temp.insert(mp(i,1));
          temp.insert(mp(j,2));
          inp.pb(temp);
        }
      }
    }
  }
  for(int i=0;i<inp.size();i++){
    for(int j=i+1;j<inp.size();j++){
      for(set<pair<int,int> > :: iterator it = inp[i].begin();it!=inp[i].end();it++ ){
        if(inp[j].find(*it)!=inp[j].end()){
          inp[i].insert(inp[j].begin(),inp[j].end());
        }
      }
    }
  }
  for(int i=0;i<inp.size();i++){
    for(set<pair<int,int> > :: iterator it = inp[i].begin();it!=inp[i].end();it++ ){
      for(set<pair<int,int> > :: iterator it2 = inp[i].begin();it2!=inp[i].end();it2++ ){
        // tr(*it,*it2);
        if((*it).se==1 and (*it2).se==2){
          ar2[(*it).fi][(*it2).fi] = '#';
        }
        else if((*it).se==2 and (*it2).se==1){
          ar2[(*it2).fi][(*it).fi] = '#';
        }
      }
    }
    // cout<<"setover"<<endl;

  }
  // for(int i=0;i<n;i++){
  //   for(int j=0;j<m;j++){
  //     cout<<ar2[i][j];
  //   }cout<<endl;
  // }
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      if(ar2[i][j]!=arr[i][j]){
        cout<<"No"<<endl;
        return 0;
      }
    }
  }

  cout<<"Yes"<<endl;
  return 0;
}
