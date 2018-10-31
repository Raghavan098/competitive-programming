#include<bits/stdc++.h>
using namespace std;
float getdist(int x1,int y1,int x2,int y2){
  // cout<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<" "<<(x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)<<endl;
  return (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
}
int main(){
  int arr[3][2];
  int x1,y1,x2,y2,x3,y3;
  for(int i=0;i<3;i++){
    for(int j=0;j<2;j++){
      cin>>arr[i][j];
    }
  }
  float dist[3];
  dist[0] = getdist(arr[0][0],arr[0][1],arr[1][0],arr[1][1]);
  dist[1] = getdist(arr[0][0],arr[0][1],arr[2][0],arr[2][1]);
  dist[2] = getdist(arr[2][0],arr[2][1],arr[1][0],arr[1][1]);
  sort(dist,dist+3);
  // for(int i=0;i<3;i++){
  //   cout<<dist[i]<<" ";
  // }cout<<endl;
  if(dist[0]+dist[1]==dist[2]){
    cout<<"RIGHT"<<endl;
  }
  else{
    int p=0;
    for(int i = 0;i<3;i++){
      for(int j=-1;j<2;j++){
        for(int k=0;k<2;k++){
          arr[i][k]+=j;
          dist[0] = getdist(arr[0][0],arr[0][1],arr[1][0],arr[1][1]);
          dist[1] = getdist(arr[0][0],arr[0][1],arr[2][0],arr[2][1]);
          dist[2] = getdist(arr[2][0],arr[2][1],arr[1][0],arr[1][1]);
          sort(dist,dist+3);
          if(dist[0]+dist[1]==dist[2] and dist[0]>0 and dist[1]>0 and dist[2]>0){
            cout<<"ALMOST"<<endl;
            p=1;
            break;
          }
          else{
            arr[i][k]-=j;
          }
        }
        if(p==1){
          break;
        }
      }
      if(p==1){
        break;
      }
    }
    if(p==0){
      cout<<"NEITHER"<<endl;
    }
  }
  return 0;
}
