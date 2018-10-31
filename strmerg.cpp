#include<bits/stdc++.h>
using namespace std;
int find(string x,string y){
  int m = x.size();
  int n = y.size();
  int l[m+1][n+1];
  for(int i=0;i<m+1;i++){
    for(int j=0;j<n+1;j++){
      l[i][j] = 0;
    }
  }
  for(int i=0;i<m+1;i++){
    for(int j=0;j<n+1;j++){
      if(i==0 or j==0){
        l[i][j] = 0;
      }
      else if(x[i-1]==y[j-1]){
        l[i][j] = l[i-1][j-1]+1;
      }
      else{
        l[i][j] = max(l[i-1][j],l[i][j-1]);
      }
    }
  }
  return l[m][n];
}
int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin>>t;
  while(t--){
    int n,m;
    cin>>n>>m;

    string a,b;
    cin>>a;
    cin>>b;
    string a1;
    a1 = "";
    a1+=a[0];
    char curr = a[0];
    for(int i=1;i<n;i++){
      if (a[i]!=curr){
        curr = a[i];
        a1+=curr;
      }
    }
    string b1;
    b1 = "";
    b1+=b[0];
    curr = b[0];
    for(int i=1;i<m;i++){
      if(b[i]!=curr){
        curr = b[i];
        b1+=curr;
      }
    }
    int k = find(a1,b1);
    int ans = a1.size()+b1.size()-k;
    cout<<ans<<endl;
  }
  return 0;
}
