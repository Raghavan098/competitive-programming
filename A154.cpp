#include<bits/stdc++.h>
typedef long long llt;
using namespace std;
char arr[40][40],curtop,topush;
string inp;
int m,n,ptr,ans,ac,bc,j,running;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin>>inp;
  cin>>m;
  for(int i=0;i<m;i++){
    cin>>arr[i][0]>>arr[i][1];
  }
  char temp;
  inp+="*";
  n = inp.size();
  ptr = 0;
  while(ptr<n){
    running  = -1;
    temp = inp[ptr];
    ac =0;
    bc = 0;
    for(int i=0;i<m;i++){
      if(arr[i][0]==temp || arr[i][1]==temp){
        running  = i;
        break;
      }
    }
    // cout<<running<<endl;
    if(running!=-1){
      ac++;
      j = ptr+1;
      while(j<n){
        if(inp[j]==arr[running][0] || inp[j]==arr[running][1]){
          if(inp[j]==temp){
            ac++;
          }
          else{
            bc++;
          }
        }
        else{
          ptr = j-1;
          ans+=min(ac,bc);
          break;
        }
        j++;
      }
    }
    ptr++;
  }
  cout<<ans<<endl;
  return 0;
}
