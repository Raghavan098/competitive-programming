#include<iostream>
typedef long long int lli;
using namespace std;
int main(){
  lli n;
  cin>>n;
  lli x,y;
  int p=0;
  lli bx=100000,by=100000;
  for(x=0;x<100000000;x++){
    y = (n-x*7)/4;
    // if(x==99998){
    //   cout<<y<<" "<<7*x+4*y<<endl;
    // }
    if((7*x+4*y)==n && y>=0){
      if((bx+by)>(x+y)){
        bx = x;
        by = y;
      }
    }
  }
  // cout<<bx<<" "<<by<<endl;
  if(bx==100000 && by==100000){
    cout<<-1<<endl;
  }
  else{
    for(int i=0;i<by;i++){
      cout<<4;
    }
    for(int i=0;i<bx;i++){
      cout<<7;
    }
    cout<<endl;
  }
  return 0;
}
