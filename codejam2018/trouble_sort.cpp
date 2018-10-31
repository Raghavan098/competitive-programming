#include<bits/stdc++.h>
#include<cmath>
#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define pb push_back
#define mp make_pair
typedef long long llt;
typedef long double lld;
using namespace std;

int t,arr[200000],n,flag;
vector<pair<int,int> > vo,ve,vi;

int main(){
  cin>>t;
  for(int ti=1;ti<=t;ti++){
    flag = 0;
    vi.clear();
    vo.clear();
    ve.clear();
    cin>>n;
    for(int i=0;i<n;i++){
      cin>>arr[i];
      if(i%2==0)
        ve.pb(mp(arr[i],i));
      else{
        vo.pb(mp(arr[i],i));
      }
    }
    sort(arr,arr+n);
    sort(vo.begin(),vo.end());
    sort(ve.begin(),ve.end());
    int i=0,j=0;
    for(;i<ve.size() && j<vo.size();i++,j++){
      vi.pb(ve[i]);
      vi.pb(vo[j]);
    }
    for(int i1=i;i1<ve.size();i1++){
      vi.pb(ve[i1]);
    }
    for(int i1=j;i1<vo.size();i1++){
      vi.pb(vo[i1]);
    }
    // for(int i=0;i<n;i++){
    //   cout<<vi[i].first<<" "<<vi[i].second<<endl;
    // }
    for(int i=0;i<n;i++){
      if(arr[i]!=vi[i].first){
        cout<<"Case #"<<ti<<": "<<i<<endl;
        flag=1;
        break;
      }
    }
    if(flag==0){
      cout<<"Case #"<<ti<<": "<<"OK"<<endl;
    }

  }
  return 0;
}
