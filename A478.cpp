
#include <bits/stdc++.h>


using namespace std;

typedef long long llt;
typedef long double ld;
typedef pair<int,int> pii;

int arr[9];
int hy,ay,dy,hm,am,dm,ch,ca,cd;
int main(){
  cin>>hy>>ay>>dy>>hm>>am>>dm>>ch>>ca>>cd;
  int min1 = 1000000008;
  llt cost;
  llt temp1,temp2;
  for(int i = 0;i<=1001;i++){
    for(int j = 0;j<=251;j++){
      for(int k = 0;k<=251;k++){
        if(ay+j>dm){
          cost = i*ch+j*ca+k*cd;
          if(am-dy-k<=0){
            min1 = min(cost,llt(min1));

          }
          else{
            temp1 = llt(ld(hy+i)/ld(am - (dy+k)));
            temp2 = ceil(ld(hm)/ld(-dm + (ay+j)));
            if(llt(hy+i)%llt(am - (dy+k))==0){
              temp1--;
            }
            if(temp1>=temp2){
              min1 = min(cost,llt(min1));
            }
          }
        }

      }
    }
  }
  cout<<min1<<endl;
  return 0;
}
