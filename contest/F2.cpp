// g++ -std=c++14

#include<bits/stdc++.h>

#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

#define sd(x) scanf("%d",&x)
#define sd2(x,y) scanf("%d%d",&x,&y)
#define sd3(x,y,z) scanf("%d%d%d",&x,&y,&z)


typedef long long ll;
typedef long double lld;
using namespace std;


int n,m,pre[300000],req[300000];
vector<int> arr,arr2;

int main(){ _
  sd2(n,m);
  arr.resize(n);
  arr2.resize(m);
  map<int,int> pre;
  for(int i=0;i<n;i++){
    sd(arr[i]);
    pre[arr[i]]++;
  }
  int l,r,mid,k,q,tot = 0;
  l = 0;

  for(int i=0;i<m;i++){
    sd(arr2[i]);
    l+=arr2[i];
    tot+=arr2[i];
    req[i+1] = arr2[i];
  }
  for(int i=1;i<=m;i++){
    k = i;
    q = pre[k];
    pre[k] = -req[k] + pre[k];
    if(pre[k]<0){
      cout<<-1<<endl;
      return 0;
    }
  }
  r = n;
  int ct,temp,ans,done;
  while(l<=r){
    mid = (l+r)/2;
    temp = 0;
    ct = 0;
    done = 0;
    int pre[300000] = {0};
    for(int i=0;i<mid;i++){
      pre[arr[i]]++;
    }
    for(int i = 1;i<=m;i++){
      k = i;
      q = pre[k];
      pre[k] = -req[k] + pre[k];
      if(pre[k]<0){
        ct++;
      }
    }
    if(ct==0){
      ans = mid;
      r = mid-1;
      continue;
    }
    for(int i=mid;i<n;i++){
      k = arr[i];
      q = arr[i-mid];
      pre[q]--;
      if(pre[q]==-1 and req[q]>0){
        ct++;
      }
      pre[k]++;
      if(pre[k]==0  and req[k]>0){
        ct--;
      }
      if(ct==0){
        ans = mid;
        r = mid-1;
        done = 1;
        break;
      }
    }
    if(done==0){
      l = mid+1;
    }
  }
  cout<<ans - tot<<endl;
  return 0;
}
