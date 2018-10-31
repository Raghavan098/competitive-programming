// g++ -std=c++14
#include<bits/stdc++.h>
typedef long long int lli;
typedef long double lld;
using namespace std;

#define sd(x) scanf("%d",&x);
#define sd2(x,y) scanf("%d%d",&x,&y);
#define sd3(x,y,z) scanf("%d%d%d",&x,&y,&z);

#define fi first
#define se second
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)

#define LET(x, a)  __typeof(a) x(a)
#define foreach(it, v) for(LET(it, v.begin()); it != v.end(); it++)
#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define __ freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);

int main(){
  _
  int t;
  cin >> t;
  while(t--){
    int n,k;
    cin >> n >> k;
    int a=0,b=0;
    int arr[n];
    for(int i=0;i<n;i++){
      cin >> arr[i];
      int x = arr[i];
      if(i%2==0){
        a+=x;
      }
      else{
        b+=x;
      }
    }
    // if(k==0){
    //   cout << "1\n";
    //   continue;
    // }
    if(b>a){
      int sum = 0;
      for(int i=0;i<n;i++){
        if(i%2==0){
          if(sum>=0){
            sum+=arr[i];
          }
          else{
            sum-=arr[i];
          }
        }
        else{
          if(sum>=0){
            sum-=arr[i];
          }
          else{
            sum+=arr[i];
          }
        }
      }
      if(sum>=k or sum<=-1*k){
        cout << "1\n";
      }
      else{
        cout << "2\n";
      }
    }
    else{
      int sum = 0;
      for(int i=0;i<n;i++){
        if(i%2==0){
          if(sum>=0){
            sum+=arr[i];
          }
          else{
            sum-=arr[i];
          }
        }
        else{
          if(sum>=0){
            sum-=arr[i];
          }
          else{
            sum+=arr[i];
          }
        }
      }
      if(sum<0){
          sum*=-1;
      }
      sum = max(sum,a-b);
      if(sum>=k or sum<=-1*k){
        cout << "1\n";
      }
      else{
        cout << "2\n";
      }
    }
  }
  return 0;
}
