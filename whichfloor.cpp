#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
  int n,m;
  cin>>n>>m;
  int arr[m][2];
  int done=-1;
  for(int i=0;i<m;i++){
    cin>>arr[i][0]>>arr[i][1];
    if(arr[i][0]==n){
      done = arr[i][1];
    }
  }
  if(done!=-1){
    cout<<done<<endl;
    return 0;
  }
  int temp1,temp2;
  for(int i=0;i<m-1;i++){
    for(int j=i+1;j<m;j++){
      if(arr[i][0]>arr[j][0]){
        temp1 = arr[i][0];
        temp2 = arr[i][1];
        arr[i][0]=arr[j][0];
        arr[i][1]=arr[j][1];
        arr[j][0]=temp1;
        arr[j][1]=temp2;
      }
    }
  }
  int floors=-1;
  int curr = 1;
  int curno = -1;
  for(int i=0;i<m;i++){
    if(arr[i][1]==curr && arr[i][0]>n && curno<n){
      cout<<arr[i][1]<<endl;
      return 0;
    }
    else{
      curr = arr[i][1];
      curno = arr[i][0];
    }
  }
  for(int i=0;i<m-1;i++){

    if(arr[i][1]==arr[i+1][i]-1 && arr[i][0]+1 == arr[i+1][0]){
      floors = arr[i][0]/arr[i][1];
    }

  }
  if(floors==-1){
    cout<<-1<<endl;
  }
  else{
    // cout<<"hello";
    cout<<ceil(n*1.0/floors)<<endl;
  }
  return 0;
}
