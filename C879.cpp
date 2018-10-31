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

int n,no,arr[20];
char temp;

int get(string s){
  int ans = 0;
  reverse(s.begin(),s.end());
  for(int i = 0;i<s.size();i++){
    ans+=((s[i]-'0')*pow(2,i));
  }
  // tr(ans);
  return ans;
}

void door(int no){
  int curp = 10;
  while(curp){
    if(no%2==1){
      arr[curp] = 1;
      // tr(curp,no);
    }
    no/=2;
    // cout<<"eh"<<endl;
    curp--;
  }
}

void doxor(int no){
  int curp = 10;
  // tr(no);
  while(curp){
    if(no%2==1){
      // tr(no,arr[curp],curp);
      if(arr[curp]==-1)
        arr[curp] = -2;
      else if(arr[curp]==1){
        arr[curp] = 0;
      }
      else if(arr[curp]==-2){
        arr[curp] = -1;
      }
      else{
        arr[curp] = 1;
      }
    }
    no/=2;
    curp--;
  }
}

void doand(int no){
  int curp = 10;
  while(curp){
    if(no%2==0){
      arr[curp] = 0;
    }
    no/=2;
    curp--;
  }
}
int main(){
  cin>>n;
  for(int i=0;i<=10;i++){
    arr[i] = -1;
  }
  for(int i=0;i<n;i++){
    cin>>temp>>no;
    if(temp=='|'){
      door(no);
    }
    else if(temp=='^'){
      doxor(no);
    }
    else{
      doand(no);
    }
  }
  string ands,ors,xors;
  ands = "1111111111";
  ors = "0000000000";
  xors = "0000000000";
  // for(int i=1;i<=10;i++){
  //   cout<<arr[i]<<" ";
  // }cout<<endl;
  int curp= 9;
  for(int i=10;i>=1;i--){
    // tr(arr[i],i,curp);
    if(arr[i]==1){
      ors[curp]='1';
    }
    else if(arr[i]==0){
      ands[curp]='0';
    }
    else if(arr[i]==-2){
      xors[curp]='1';
    }
    curp--;
  }
  // tr(ands,ors,xors);
  cout<<3<<endl;
  cout<<"| ";
  cout<<get(ors)<<endl;
  cout<<"& ";
  cout<<get(ands)<<"\n";
  cout<<"^ ";
  cout<<get(xors)<<endl;
  return 0;
}
