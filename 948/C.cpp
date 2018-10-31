#include<bits/stdc++.h>
#include<cmath>
#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define pb push_back
#define MAXN   1000001
typedef long long llt;
typedef long double lld;
using namespace std;

llt n,vol[200000],temp[200000],ans[200000],bini[200000],cumu[200000],ind,lb;

llt bin(llt no,llt l,llt r){
  // cout<<"this "<<no<<endl;
  llt mid,temp2,ans2,to_sub = 0;
  if(l>0){
    to_sub = cumu[l-1];
  }
  if(no>cumu[r]-to_sub){
    return r+1;
  }
  else if(no==cumu[r]-to_sub){
    return r;
  }
  while(l<=r){

    mid = (l+r)/2;
    temp2 = cumu[mid] - to_sub;
    // cout<<mid<<" "<<l<<" "<<r<<" "<<temp2<<endl;
    if(temp2>=no){
      ans2 = mid;
      r = mid-1;
    }
    else{
      l = mid+1;
    }
  }
  return ans2;
}

int main(){
  cin>>n;
  for(llt i=0;i<n;i++){
    cin>>vol[i];
  }
  for(llt i=0;i<n;i++){
    cin>>temp[i];
    bini[i]= 0;
    ans[i] = 0;
  }
  cumu[0] = temp[0];
  for(llt i=1;i<n;i++){
    cumu[i] = cumu[i-1]+temp[i];
  }
  cumu[n] = 0;
  for(llt i=0;i<n;i++){
    ind = bin(vol[i],i,n-1);
    // cout<<i<<" "<<ind<<endl;
    if(ind==n){
      bini[i]+=1;
      bini[i] += bini[i-1];
      ans[i] += bini[i]*temp[i];
      continue;
    }
    bini[i]+=1;
    bini[ind]-=1;
    lb= 0;
    if(i>0){
      lb = cumu[i-1];
    }
    // cout<<vol[i]-(cumu[ind-1] - lb)<<endl;
    ans[ind]+=vol[i]-(cumu[ind-1] - lb);
    bini[i] += bini[i-1];
    // cout<<bini[i]<<"bibi"<<endl;
    ans[i] += bini[i]*temp[i];
  }
  for(llt i=0;i<n;i++){
    cout<<ans[i]<<" ";
  }cout<<endl;
  return 0;
}
