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

int n,x,y;
int visited[5000];
map<int,vector<int> > grp;
set<int> s;
int done;

int dfs(int no,int parent){
//   tr(no,parent);
 visited[no] = 1;
 int temp,x2;
 if(done==0){

   for(int i=0;i<grp[no].size();i++){
     temp = grp[no][i];
     // tr(temp);
     if(visited[temp]==0 and temp!=0){
       x2 = dfs(temp,no);
       //   tr(x,temp);
       if(x2!=-1 and x2!=no and x2!=0 and done==0){
         s.insert(no);
         return x2;
       }
       else if(x2!=-1 and x2==no and done==0){
         s.insert(no);
         done = 1;
         return -1;
       }
     }
     else if(temp!=parent and visited[temp]==1 and done==0){
       s.insert(no);
       return temp;
     }
   }
   return -1;
 }
 else{
   return -1;
 }
}

int ans[4000];

int get_bfs(int no){

 queue<pair<int,int> > q;
 q.push(mp(no,0));
 int x2;
 pair<int,int> temp;
 visited[no] = 1;
 while(!q.empty()){
   temp = q.front();
   q.pop();
   // tr(temp);
   ans[temp.fi] = temp.se;
   for(int i=0;i<grp[temp.fi].size();i++){
     x2 = grp[temp.fi][i];
     if(visited[x2]==0 and s.find(x2)==s.end()){
       visited[x2] = 1;
       q.push(mp(x2,temp.se+1));
     }
   }
 }
 return 0;
}

int main(){
 cin>>n;
 for(int i=0;i<n;i++){
   cin>>x>>y;
   grp[x].pb(y);
   grp[y].pb(x);
 }
 for(int i=1;i<=n;i++){
   if(visited[i]==0){
     x = dfs(i,-1);
   }
   else{
     break;
   }
 }
 // for(set<int> :: iterator it = s.begin();it!=s.end();it++){
 //   cout<<*it<<endl;
 // }
 for(int i=1;i<=n;i++){
   visited[i] = 0;
 }
 for(int i=1;i<=n;i++){
   if(s.find(i)!=s.end()){
     x = get_bfs(i);
     ans[i] = 0;
   }
 }
 for(int i=1;i<=n;i++){
   cout<<ans[i]<<" ";
 }cout<<endl;
 return 0;
}
