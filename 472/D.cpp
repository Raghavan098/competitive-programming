
// g++ -std=c++14
#include<bits/stdc++.h>
typedef long long int lli;
typedef long double lld;
using namespace std;

#define sd(x) scanf("%d",&x);
#define sd2(x,y) scanf("%d%d",&x,&y);
#define sd3(x,y,z) scanf("%d%d%d",&x,&y,&z);

#define fi first
#define se second
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define all(c) c.begin(),c.end()

#define LET(x, a)  __typeof(a) x(a)
#define foreach(it, v) for(LET(it, v.begin()); it != v.end(); it++)
#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define __ freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
vector<vector<lli> >mat;
bool poss;
vector<pair<int,int> >edg;
vector<bool>taken;
struct cmp{
 bool operator()(const pair<int,int>& lhs, const pair<int,int>& rhs){
   return mat[lhs.fi][lhs.se] > mat[rhs.fi][rhs.se];
 }
};
int main(){
 _
 int n;
 cin >> n;
 poss = true;
 lli Min = 1000000009;
 mat.resize(n,vector<lli>(n));
 taken.resize(n,false);
 int u = -1, v = -1;
 for(int i=0;i<n;i++){
   for(int j=0;j<n;j++){
     cin >> mat[i][j];
     if(i!=j and Min>mat[i][j]){
       Min = mat[i][j];
       u = i;
       v = j;
     }
   }
 }
 edg.pb(make_pair(u,v));
 for(int i=0;i<n;i++){
   for(int j=0;j<n;j++){
     if(i==j and mat[i][j]!=0){
       poss = false;
       break;
     }
     if(mat[i][j]!=mat[j][i]){
       poss = false;
       break;
     }
   }
 }
 if(!poss){
   cout << "NO\n";
   return 0;
 }
 while(edg.size()<n-1){
   int u = edg[edg.size()-1].fi;
   int v = edg[edg.size()-1].se;
   priority_queue<pair<int,int>,vector<pair<int,int> >, cmp >pq;
   for(int i=0;i<n;i++){
     if(i!=u and !taken[u]){
       pq.push(mp(u,i));
     }
     if(i!=v and !taken[v]){
       pq.push(mp(v,i));
     }
   }
   taken[u] = true;
   taken[v] = true;
   pair<int,int> pii = pq.top();
   edg.pb(make_pair(pii.fi,pii.se));
   int newNode;
   int oldNode;
   if(!taken[pii.fi]){
     newNode = pii.fi;
     oldNode = pii.se;
   }
   else{
     newNode = pii.se;
     oldNode = pii.fi;
   }
   for(int i=0;i<n;i++){
     if(i!=newNode and taken[i]){
       if(mat[i][newNode]!=mat[i][oldNode]+mat[oldNode][newNode]){
         cout << newNode << " " << oldNode << " " << i << "\n";
         poss = false;
         break;
       }
     }
   }
 }
 cout << "comehere\n";
 if(poss){
   cout << "YES\n";
 }
 else{
   cout << "NO\n";
 }
 return 0;
}
