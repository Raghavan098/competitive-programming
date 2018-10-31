#include<iostream>
#include<algorithm>
#include<vector>
#include<string.h>
#include<math.h>
#include<iomanip>
#include<string.h>
#include<limits>
#include<queue>
typedef long long int llt;
using namespace std;
llt board[2005][2005];
llt d1[5000];
llt d2[5000];
llt n;
llt getd1(llt i,llt j){
  return n-i+j;
}
llt getd2(llt i,llt j){
  return 2*n-i-j+1;
}
int main(){
  ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
  cin>>n;
  for(llt i=1;i<=n;i++){
    for(llt j=1;j<=n;j++){
      cin>>board[i][j];
      d1[getd1(i,j)]+=board[i][j];
      d2[getd2(i,j)]+=board[i][j];
    }
  }
  llt i;
  llt j;
  llt max1=0;
  llt max2=0;
  llt a1=-1,a2=-1,b1=-1,b2=-1;
  llt n1 = 1;
  for(i=1;i<=n;i++){
    for(j=n1;j<=n;j+=2){
      if((d1[getd1(i,j)]+d2[getd2(i,j)]-board[i][j])>max1){
          max1 = d1[getd1(i,j)]+d2[getd2(i,j)]-board[i][j];
          a1 = i;
          a2 = j;
      }
    }
    if(n1==1){
      n1=2;
    }
    else{
      n1 = 1;
    }
  }
  n1 = 2;
  for(i=1;i<=n;i++){
    for(j=n1;j<=n;j+=2){
      if((d1[getd1(i,j)]+d2[getd2(i,j)]-board[i][j])>max2){
          max2 = d1[getd1(i,j)]+d2[getd2(i,j)]-board[i][j];
          b1 = i;
          b2 = j;
      }
    }
    if(n1==1){
      n1=2;
    }
    else{
      n1 = 1;
    }
  }
  if(a1==-1 && a2==-1){
    a1 = 1;
    a2 = 1;

  }
  if(b1==-1 && b2 ==-1){
    b1=1;
    b2=2;
  }
  cout<<max1+max2<<endl;
  cout<<a1<<" "<<a2<<" "<<b1<<" "<<b2<<endl;
  return 0;
}
