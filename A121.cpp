#include<bits/stdc++.h>
typedef long long llt;
using namespace std;
vector< pair<llt,llt> > v;

llt get_number(llt no){
  if(no==0){
    return 4;
  }
  if(no==1){
    return 7;
  }
  llt curr = 1;
  llt ans = 0;
  llt temp;
  while(no>0){
    temp = no%2;
    if(temp==0){
      ans+=4*curr;
    }
    else{
      ans+=7*curr;
    }
    curr*=10;
    no/=2;
  }
  return ans%(curr/10);
}
llt ans_get(llt b){
  llt ans = 0;
  int done = 0;
  llt i = 0;
  if(b==1){
    return 4;
  }
  while(v[i].first<=b){
    if(v[i].first==b){
      done  = 1;
    }
    ans+=(v[i].first)*(v[i].second);
    // cout<<v[i].first<<" "<<ans<<" "<<v[i].second<<endl;
    i++;
  }
  if(done==0){
    llt left;
    if(i!=0)
      left = b - v[i-1].first;
    else
      left = b;
    ans+=(left)*v[i].first;
  }
  // cout<<"this is ans "<<ans<<endl;
  return ans;
}
int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int a,b;
  cin>>a>>b;
  llt prevcount = 0;
  llt temp,curr;

  for(int i=2;i<=2048;i++){
    temp = get_number(llt(i));
    v.push_back(make_pair(temp,temp-prevcount));
    prevcount = temp;
  }

  cout<<ans_get(b) - ans_get(a-1)<<endl;
  return 0;
}
