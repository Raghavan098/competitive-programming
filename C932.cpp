#include<bits/stdc++.h>
#include<cmath>
#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long llt;
typedef long double lld;

#define tr(x) cout<<x<<endl;
#define tr2(x,y) cout<<x<<" "<<y<<endl;
#define tr3(x,y,z) cout<<x<<" "<<y<<" "<<z<<endl;

using namespace std;

llt n,a,b,a1,b1;
float temp;

void get_solution(int i,int j){
  // tr2(i,j);
  int curr = 1;
  for(int k = 0;k<i;k++){
    cout<<curr+a-1<<" ";
    for(int l = curr;l<curr+a-1;l++){
      cout<<l<<" ";
    }
    curr = curr+a;
  }
  // cout<<endl;
  // cout<<curr<<endl;
  for(int k = 0;k<j;k++){
    cout<<curr+b-1<<" ";
    for(int l = curr;l<curr+b-1;l++){
      cout<<l<<" ";
    }
    curr = curr+b;
  }
  cout<<endl;
}

int main(){
  cin>>n>>a>>b;
  for(int i = 0;i<=n;i++){
    // tr2(i,temp);
    temp = ((n - a*i)*1.0)/b;
    if(llt(temp)==temp and temp>=0){
      get_solution(i,temp);
      return 0;
    }
  }
  cout<<-1<<endl;
  return 0;
}
