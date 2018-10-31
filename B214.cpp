#include<bits/stdc++.h>
typedef long long llt;
using namespace std;
llt arr[1000000];
int n;
int print(){
  int check = 0;
  for(int i=n-1;i>=0;i--){
    if(arr[i]!=-1){
      if(check==0 and arr[i]==0){
        cout<<0<<endl;
        return 0;
      }
      else if(check==0 and arr[i]!=0){
        check = 1;
        cout<<arr[i];
      }
      else if(check!=0){
        cout<<arr[i];
      }
    }
  }cout<<endl;
}
void check(int n1){
  llt twocount =  0;
  llt a,b,done1 = 0,done2 = 0;
  for(int i=0;i<n;i++){
    if(arr[i]%3==n1){
      arr[i]=-1;
      done1 = 1;
      break;
    }
  }
  if(done1==1){
    print();
  }

  else{
    int now;
    if(n1==1){
      now=2;
    }
    else{
      now = 1;
    }
    int count = 0;
    for(int i=0;i<n;i++){
      if(arr[i]%3==now){
        arr[i]=-1;
        count++;
      }
      if(count==2){
        break;
      }
    }
    if(count==2){
      print();
    }
    else{
      cout<<-1<<endl;
    }
  }
}
int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin>>n;
  llt sum = 0;
  for(int i=0;i<n;i++){
    cin>>arr[i];
    sum+=arr[i];
  }
  sort(arr,arr+n);
  if(arr[0]!=0){
    cout<<-1<<endl;
  }
  else{
    if(sum%3==0){
      print();
      return 0;
    }
    else if(sum%3==1){
      check(1);
      return 0;
    }
    else{
      check(2);
      return 0;
    }
  }
  return 0;
}
