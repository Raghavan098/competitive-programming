#include<iostream>
using namespace std;
int main(){
  long long int n,q;
  cin>>n>>q;
  int arr[n];
  for(int i=0;i<n;i++){
    cin>>arr[n];
  }
  for(int i=0;i<q;i++){
    int temp;
    cin>>temp;
    if(temp==1){
      int j,k;
      cin>>j>>k;
      int max=arr[j-1];
      int r=j-1;
      for(int o=j;o<n;o++){
        if(o-r<=100 && arr[o]>max && k>0){
          k--;
          max=arr[o];
          r=o;
        }
      }
      cout<<r+1<<"\n";
    }
    else{
      int b,a,val;
      cin>>a>>b>>val;
      for(int o=a-1;o<b;o++){
        arr[o]+=val;
      }
    }
  }
  return 0;
}
