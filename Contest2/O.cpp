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

int n;
int arr[100][100];
char temp;

int main(){
  cin>>n;
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      cin>>temp;
      arr[i][j] = temp-'0';
    }
  }
  // for(int i=0;i<n;i++){
  //   for(int j=0;j<n;j++){
  //     cout<<arr[i][j]<<" ";
  //   }cout<<endl;
  // }
  for(int no=0;no<10;no++){
    // tr(no);
    for(int i=0;i<n;i++){
      int ct = 0;

      for(int j=0;j<n;j++){
        if(arr[i][j]==no){
          ct++;
        }
      }
      if(ct>1){
        cout<<"No\n";
        return 0;
      }
    }
    for(int i=0;i<n;i++){
      int ct = 0;
      for(int j=0;j<n;j++){
        if(arr[j][i]==no){
          ct++;
        }
      }
      if(ct>1){
        cout<<"No\n";
        return 0;
      }
    }
  }
  // tr((int)('A')-52);
  for(int no = 'A'-56;no<'A'-56+26;no++){
    // tr(no);
    for(int i=0;i<n;i++){
      int ct = 0;
      for(int j=0;j<n;j++){
        if(arr[i][j]==no){
          ct++;
        }
      }
      if(ct>1){
        cout<<"No\n";
        return 0;
      }
    }
    for(int i=0;i<n;i++){
      int ct = 0;
      for(int j=0;j<n;j++){
        if(arr[j][i]==no){
          ct++;
        }
      }
      if(ct>1){
        cout<<"No\n";
        return 0;
      }
    }
  }
  for(int i=1;i<n;i++){
    // tr(arr[1][i],arr[1][i-1],arr[i][1],arr[i-1][1]);
    if(arr[0][i]<arr[0][i-1]){
      cout<<"Not Reduced\n";
      return 0;
    }

    if(arr[i][0]<arr[i-1][0]){
      cout<<"Not Reduced\n";
      return 0;
    }
  }
  cout<<"Reduced\n";
  return 0;
}
