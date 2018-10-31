#include<bits/stdc++.h>
#include<cmath>
#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define pb push_back
typedef long long llt;
typedef long double lld;
using namespace std;

vector<vector<int> > inp;
vector<int> final_ans;
int n,a,b,ans,done;

int main(){
  cin>>n;
  for(int i=0;i<n;i++){
    cin>>a>>b;
    inp.pb({a,b,i});
  }
  sort(inp.begin(),inp.end());
  // for(int i=0;i<n;i++){
  //   cout<<inp[i][0]<<" "<<inp[i][1]<<" "<<inp[i][2]<<endl;
  // }
  for(int i=0;i<n;i++){
    done=0;
    for(int j=1;j<n;j++){
      if(i+1!=j and i!=j){
        if(inp[j-1][1]>inp[j][0]){
          done =  1;
          break;
        }
      }
      else if(i+1==j and j-2>=0){
        if(inp[j-2][1]>inp[j][0]){
          done=1;
          break;
        }
      }
    }
    // cout<<i<<" "<<done<<endl;
    if(done==0){
      final_ans.pb(inp[i][2]);
    }
  }
  cout<<final_ans.size()<<endl;
  sort(final_ans.begin(),final_ans.end());
  for(int i=0;i<final_ans.size();i++){
    cout<<final_ans[i]+1<<" ";
  }cout<<endl;
  return 0;
}
