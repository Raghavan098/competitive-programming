#include<bits/stdc++.h>
#include<cmath>
#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long llt;
typedef long double lld;
using namespace std;
int n;
char arr[1000][1000];
int main(){ _
  cin>>n;
  for(int i=0;i<n;i++){
    for(int j = 0;j<n;j++){
      cin>>arr[i][j];
    }
  }
  vector<pair<int,int> > ans;
  int not_done = 0;
  int done;
  for(int i=0;i<n;i++){
    done = 0;
    for(int j=0;j<n;j++){
      if(arr[i][j]=='.'){
        ans.push_back(make_pair(i,j));
        done = 1;
        break;
      }
    }
    if(done==0){
      not_done = 1;
      break;
    }
  }
  if(not_done==1){
    vector<pair<int,int> > ans;
    int not_done = 0;
    int done;
    for(int i=0;i<n;i++){
      done = 0;
      for(int j = 0;j<n;j++){
        if(arr[j][i]=='.'){
          ans.push_back(make_pair(j,i));
          done = 1;
          break;
        }
      }
      if(done==0){
        not_done = 1;
        break;
      }
    }
    if(not_done==1){
      cout<<-1<<endl;
    }
    else{
      for(int i=0;i<ans.size();i++){
        cout<<ans[i].first+1<<" "<<ans[i].second+1<<endl;
      }
    }
  }
  else{
    for(int i=0;i<ans.size();i++){
      cout<<ans[i].first+1<<" "<<ans[i].second+1<<endl;
    }
  }
  return 0;
}
