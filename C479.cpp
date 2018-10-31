#include <bits/stdc++.h>
using namespace std;
struct s{
  int a;
  int b;
}arr[10000];
bool comp(s a,s b){
  if(a.a!=b.a)
    return a.a<b.a;
  else{
    return a.b<b.b;
  }
}
int main(){
  int n;
  cin>>n;
  for(int i=0;i<n;i++){
    cin>>arr[i].a>>arr[i].b;
  }
  sort(arr,arr+n,comp);
  int curr=-1;
  for(int i =0;i<n;i++){
    if(arr[i].b>=curr){
      curr = arr[i].b;
    }
    else{
      curr = arr[i].a;
    }
  }
  cout<<curr<<endl;
  return 0;
}
