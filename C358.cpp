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



int main(){
  int n;
  cin>>n;
  int a,b,c,temp;
  vector<int> v;
  int tt = 0;
  while(n--){
    if(tt==0)
      cin>>temp;
    else{
      temp = 0;
    }
    if(temp==0){
      // cout<<v<<endl;
      if(v.size()==0){
        cout<<0<<endl;
      }
      else if(v.size()==1){
        cout<<"pushStack"<<endl;
        if(tt==0){
            cout<<"1 popStack\n";
        }
      }
      else if(v.size()==2){
        cout<<"pushStack"<<endl<<"pushQueue"<<endl;
        if(tt==0){
            cout<<"2 popStack popQueue\n";
        }
      }
      else{
        // cout<<v<<endl;
        vector<pair<int,int> > nos;
        for(int i=0;i<v.size();i++){
          nos.pb(mp(v[i],i));
        }
        sort(nos.begin(),nos.end());
        reverse(nos.begin(),nos.end());
        a = nos[0].fi;
        b = nos[1].fi;
        c = nos[2].fi;
        multiset<int> s;
        s.insert(a);
        s.insert(b);
        s.insert(c);
        // tr(a,b,c);
        int done=0;
        for(int i=0;i<v.size();i++){
          // tr(v[i]);
          if(done==0){
            if(s.find(v[i])==s.end()){
              cout<<"pushStack"<<endl;
            }
            else{
              cout<<"pushStack"<<endl;
              auto itr = s.find(v[i]);
              s.erase(itr);
              done=1;
            }
          }
          else if(done==1){
            if(s.find(v[i])==s.end()){
              cout<<"pushFront"<<endl;
            }
            else{
              cout<<"pushFront"<<endl;
              auto itr = s.find(v[i]);
              s.erase(itr);
              done=2;
            }
          }
          else if(done==2){
            if(s.find(v[i])==s.end()){
              cout<<"pushBack"<<endl;
            }
            else{
              cout<<"pushQueue"<<endl;
              auto itr = s.find(v[i]);
              s.erase(itr);
              done=3;
            }
          }
          else{
            cout<<"pushBack"<<endl;
          }
        }
        if(tt==0)
          cout<<3<<" "<<"popStack popFront popQueue"<<endl;
      }
      v.clear();
    }
    else{
      v.pb(temp);
      // tr(n);
      if(n==0){
        // v.pb(0);
        n++;
        tt = 1;
      }
    }
  }
}
