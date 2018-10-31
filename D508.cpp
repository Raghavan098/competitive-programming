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

int n;
map<int,vector<int> > grp,grp2;
int in[300300],out[300300];
vector<int> v;
set<int> ts;

void dfs(int start){
  while(!grp[start].empty()){
    int nxt = grp[start].back();
    grp[start].pop_back();
    dfs(nxt);
  }
  v.pb(start);
}

int visited[300300];


void dfs2(int no){
  visited[no] = 1;
  for(auto it: grp2[no]){
    if(visited[it]==0){
      dfs2(it);
    }
  }
}


bool connected(){
  dfs2(*(ts.begin()));
  for(auto it:ts){
    if(visited[it]==0){
      return false;
    }
  }
  return true;
}

int main(){
  cin>>n;
  for(int i=0;i<n;i++){
    string temp;
    cin>>temp;
    int v1 = temp[0]*1000 + temp[1];
    int v2 = temp[1]*1000 + temp[2];
    grp[v1].pb(v2);
    grp2[v1].pb(v2);
    grp2[v2].pb(v1);
    in[v2]++;
    out[v1]++;
    ts.insert(v1);
    ts.insert(v2);
  }
  if(connected()){

    int start = -1;
    for(auto it:ts){
      int temp = it;
      if(in[temp]+1==out[temp]){
        if(start!=-1){
          cout<<"NO\n";
          return 0;
        }
        start = temp;
      }
      else if(in[temp]==out[temp]){
        continue;
      }
      else if(in[temp]==out[temp]+1){
        continue;
      }
      else{
        cout<<"NO\n";
        return 0;
        break;
      }
    }
    if(start==-1){
    start = *(ts.begin());
  }
    // tr(start,char(start/1000),char(start%1000));
    // tr(start);
    if(start==-1){
      cout<<"NO\n";
      return 0;
    }
    dfs(start);
    reverse(v.begin(),v.end());
    string final_ans = "";
    // tr(v);
    final_ans += (char)(v[0]/1000);
    // tr(final_ans);
    for(auto i:v){
      // tr(i);
      final_ans += (char)(i%1000);
    }
    cout<<"YES\n";
    cout<<final_ans<<endl;
    return 0;
  }
  else{
    cout<<"NO\n";
    return 0;
  }
}
