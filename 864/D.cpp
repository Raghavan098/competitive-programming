#include<bits/stdc++.h>
#include<cmath>
#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define pb push_back
typedef long long llt;
typedef long double lld;
using namespace std;

int n,arr[200010],temp[200010],ans;
set<int> to;
set<int> fin[200010];

int main(){
  cin>>n;
  for(int i=0;i<=n;i++){
    temp[i] = -1;
  }
  for(int i=0;i<n;i++){
    cin>>arr[i];
    temp[arr[i]] = i;
    fin[arr[i]].insert(i);
  }
  for(int i=1;i<=n;i++){
    if(temp[i]==-1){
      to.insert(i);
    }
  }
  for(int i=1;i<=n;i++){
    temp[i] =-1;
  }
  int temp1,a,c,b,done=0;
  set<int> :: iterator it,it2,it3;
  for(int i=0;i<n;i++){
    if(fin[arr[i]].size()>1){
      temp1 = arr[i];
      done = 0;
      it = to.begin();
      c = *it;
      it2 = fin[arr[i]].begin();
      a = *it2;

      fin[arr[i]].erase(*it2);
      it3 = fin[arr[i]].begin();
      b = *it3;
      fin[arr[i]].erase(*it3);
      if(*it>arr[i]){
        if(i==b){
          arr[b] = c;
          fin[temp1].insert(b);
          to.erase(c);
          done = 1;
          ans++;
        }

      }
      else{
        arr[a] = c;
        fin[temp1].insert(b);
        to.erase(c);
        done = 1;
        ans++;
      }
      if(done==0){
        fin[temp1].insert(a);
        fin[temp1].insert(b);
      }
    }
  }
  cout<<ans<<endl;
  for(int i=0;i<n;i++){
    cout<<arr[i]<<" ";
  }cout<<endl;
  return 0;
}
