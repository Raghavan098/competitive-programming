#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
typedef long long int lli;
using namespace std;
int arr[3][3];
int check(int i,int j,int k){
  int count=0;
  int p1=0;
  int q1=0;
  for(int q=0;q<3;q++){
    if(arr[i][q]>arr[j][q]){
      p1++;
    }
    if(arr[i][q]==arr[j][q]){
      q1++;
    }
  }
  if(p1>0 && 3-p1==q1){
    count++;
  }
  p1=0;
  q1=0;
  for(int q=0;q<3;q++){
    if(arr[i][q]>arr[k][q]){
      p1++;
    }
    if(arr[i][q]==arr[k][q]){
      q1++;
    }
  }
  if(p1>0 && 3-p1==q1){
    count++;
  }
  return count;
}
int main(){
  lli t;
  cin>>t;
  while(t--){
    for(int i=0;i<3;i++){
      for(int j=0;j<3;j++){
        cin>>arr[i][j];
      }
    }
    int count[3];
    count[0] = check(0,1,2);
    count[1] = check(1,0,2);
    count[2] = check(2,1,0);
    sort(count,count+3);
    // for(int i=0;i<3;i++){
    //   cout<<count[i]<<" ";
    // }
    if(count[0]==0 && count[1]==1 && count[2]==2){
      cout<<"yes\n";
    }
    else{
      cout<<"no\n";
    }
  }
}
