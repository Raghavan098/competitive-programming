#include<bits/stdc++.h>
#include<cmath>
#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define pb push_back
typedef long long llt;
typedef long double lld;
using namespace std;

int n,k,a,b,temp,swap1,cont[200000],p,rem;

int main(){
  cin>>n>>k>>a>>b;
  if(b>a){
    temp = a;
    a = b;
    b = temp;
    swap1 = 1;
  }
  // cout<<a<<" "<<b;
  if(b==0){
    // cout<<"te";
    if(a>k){
      cout<<"NO\n";
      return 0;
    }
    char p1 = 'G';
    char s1 = 'B';
    char t1;
    if(swap1==1){
      t1= p1;
      p1 = s1;
      s1 = t1;
    }

      for(int i=0;i<a;i++){
        cout<<p1;
      }cout<<endl;
      return 0;

  }
  else if(b==1){
    if(ceil(a*1.0/2)<=k){
      char p1 = 'G';
      char s1 = 'B';
      char t1;
      if(swap1==1){
        t1= p1;
        p1 = s1;
        s1 = t1;
      }

        for(int i=0;i<a/2;i++){
          cout<<p1;
        }cout<<s1;
        rem = a-a/2;
        for(int i=0;i<rem;i++){
          cout<<p1;
        }cout<<endl;
        return 0;
      }

  }
  p = a/b;
  if(p>k){
    cout<<"NO\n";
    return 0;
  }
  else{
    rem = a%b;
    if(rem<=k){
      cont[b] = rem;
      rem = 0;
    }
    else{
      cont[b] = k;
      rem-=k;
    }
    if(rem>0){
      for(int i=0;i<b;i++){

        cont[i] = min(rem,k-p);
        rem-=min(rem,k-p);
        if(rem==0){
          break;
        }
      }
    }
  }
  if(rem>0){
    cout<<"NO\n";
    return 0;
  }
  char p1 = 'G';
  char s1 = 'B';
  char t1;
  if(swap1==1){
    t1= p1;
    p1 = s1;
    s1 = t1;
  }
  for(int i=0;i<b;i++){
    for(int j=0;j<p;j++){
      cout<<p1;
    }
    for(int j=0;j<cont[i];j++){
      cout<<p1;
    }
    cout<<s1;
  }
  for(int i=0;i<cont[b];i++){
    cout<<p1;
  }cout<<endl;
  return 0;
}
