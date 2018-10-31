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

int cnt[5];
char arr[4] = {'A','B','C','D'};
int rr = 49;
int cc = 49;
char ans[60][60];
void print(){
  for(int i=0;i<rr;i++){
    for(int j=0;j<cc;j++){
      cout<<ans[i][j];
    }cout<<endl;
  }
}

int main(){
  cin>>cnt[0]>>cnt[1]>>cnt[2]>>cnt[3];
  int s = 0;
  int done = 0;
  int ti = 0;
  int tj = 0;
  int i,j;
  if(cnt[0]!=1 and cnt[1]!=1){
    for(i=0;i<rr;i++){
      for(j=0;j<cc;j++){
        if(s==0){
          ans[i][j] = arr[s];
          s = 1;
          cnt[0]--;
        }
        else{
          ans[i][j] = arr[s];
          s = 0;
          cnt[1]--;
        }
        if(cnt[0]==1 or cnt[1]==1){
          done = 1;
          break;
        }
      }
      if(done==1){
        ti = i;
        tj = j;
        break;
      }
    }
  }
  int st;
  if(cnt[0]==1){
    st = 0;
  }
  else{
    st = 1;
  }
  // print();
  // tr
  s = 2;
  done = 0;
  int kk = tj;
  tj++;
  int temp4 = 0;
  for(i=ti;i<rr;i++){
    for(j = tj;j<cc;j++){
      if(s==2){
        ans[i][j] = arr[s];
        s = 3;
        cnt[2]--;
      }
      else{
        ans[i][j] = arr[s];
        s = 2;
        cnt[3]--;
      }
      if(cnt[2]==1 or cnt[3]==1){
        done = 1;
        break;
      }
    }
    if(done == 1){
      if(i==ti){
        if(j<cc-1){
          for(int j1 = j+1;j1<cc;j1++){
            ans[i][j1] = arr[st];
          }
        }
        cnt[st]--;
        if(st==1){
          st = 0;
        }
        else{
          st = 1;
        }
        for(int j1 = 0;j1<cc;j1++){
          ans[i+1][j1] = arr[st];
          if(ans[i][j1]==arr[st]){
            cnt[st]++;
          }
        }
        cnt[st]--;
      }
      else if(i==ti+1){
        int j1;
        if(s==2){
          s= 3;
        }
        else{
          s = 2;
        }
        for(j1 = j+1;j1<=kk;j1++){
          ans[i][j1] = arr[s];
        }
        for(int j2 = j1;j2<cc;j2++){
          ans[i][j2] = arr[st];
        }
        if(st==1){
          st = 0;
        }
        else{
          st = 1;
        }
        for(int j1 = 0;j1<cc;j1++){
          ans[i+1][j1] = arr[st];
          if(ans[i][j1]==arr[st]){
            cnt[st]++;
          }
        }
        cnt[st]--;
      }
      else{
        tr("haha",j);
        if(j<cc-1){
          for(int j1 = j+1;j1<cc;j1++){
            ans[i][j1] = arr[st];
          }
        }
        for(int j1 = 0;j1<cc;j1++){
          ans[i+1][j1] = arr[st];
          if(ans[i][j1]==arr[st]){
            cnt[st]++;
          }
        }
        cnt[st]--;
      }

      break;
    }
    if(temp4 ==0){
      if(tj%2==1){
        s = 3;
        tj = 0;
      }
      else{
        s = 2;
        tj = 0;
      }
      temp4 = 1;
    }

  }
  // int ones =
  tr(cnt[0],cnt[1],cnt[2],cnt[3]);
  print();
  return 0;
}
