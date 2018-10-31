#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
typedef long long int lli;
using namespace std;
int main(){
  lli n,m;
  cin>>n>>m;
  lli arr[m];
  lli visited[26];
  lli count;
  string l[n];
  for(int i=0;i<n;i++){
    cin>>l[i];
  }
  for(int i=0;i<m;i++){
    for(int k = 0;k<26;k++){
      visited[k]=0;
    }
    count = 0;
    for(int j=0;j<n;j++){
      // cout<<l[j][i]-'a'+32<<endl;
      if(visited[l[j][i]-'a'+32]==0){
        count++;
        visited[l[j][i]-'a'+32]=1;
      }
    }
    arr[i]=count;
  }
  lli ans = 1;
  for(int i=0;i<m;i++){
    ans = (ans*arr[i])%1000000007;
  }
  cout<<ans<<endl;
  return 0;
}
