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


int n;
char t;
int arr[110][100],temp[100][100],arr2[100][100];

void printtemp(){
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      cout<<temp[i][j];
    }cout<<endl;
  }
}


void rotate(){
  // cout<<"dakjsda"<<endl;
  // printtemp();
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      temp[i][j] = arr[n-1-j][i];
    }
  }
  // printtemp();
  // cout<<endl;
  // for(int i=0;i<n;i++){
  //   for(int j=0;j<n;j++){
  //     cout<<temp[i][j];
  //   }cout<<endl;
  // }
}

void fliphor(){
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      temp[i][j] = arr[n-i-1][j];
    }
  }
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      arr[i][j] = temp[i][j];
    }
  }
}

void flipver(){
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      temp[i][j] = arr[i][n-1-j];
    }
  }
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      arr[i][j] = temp[i][j];
    }
  }
}

bool check(){
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      if(temp[i][j]!=arr2[i][j]){
        return false;
      }
    }
  }
  return true;
}


void rotateno(int no){

  for(int i=0;i<no;i++){
    // cout<<endl;
    rotate();
    for(int j=0;j<n;j++){
      for(int k=0;k<n;k++){
        arr[j][k] = temp[j][k];
      }
    }
    // cout<<"hah"<<endl;
    // printtemp();
  }
}

int main(){
  cin>>n;
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      cin>>t;
      arr2[i][j] = (t=='X');
    }
  }
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      cin>>t;
      arr[i][j] = (t=='X');
      temp[i][j] = arr[i][j];
    }
  }
  for(int i=0;i<=3;i++){
    for(int j=0;j<=2;j++){
      rotateno(i);
      if(j==1){
        fliphor();
      }
      else if(j==2){
        flipver();
      }

      if(check()==true){
        cout<<"Yes"<<endl;
        return 0;
      }
      rotateno(4-i);
      // cout<<"after"<<endl;

      // cout<<endl;
      if(j==1){
        fliphor();

      }
      else if(j==2){
        flipver();
      }
      // printtemp();

    }
  }
  cout<<"No"<<endl;
  return 0;
}
