#include<bits/stdc++.h>
using namespace std;
#define lld long long int
lld maxSubArraySum(lld a[], lld size)
{
    lld max_so_far = INT_MIN, max_ending_here = 0;

    for (lld i = 0; i < size; i++)
    {
        max_ending_here = max_ending_here + a[i];
        if (max_so_far < max_ending_here)
            max_so_far = max_ending_here;

        if (max_ending_here < 0)
            max_ending_here = 0;
    }
    return max_so_far;
}
int main(){
  lld t;
  cin>>t;
  for(lld j=0;j<t;j++){
    lld n,k;
    cin>>n>>k;
    lld a[2*n];
    lld b[2*n];
    lld sum = 0;
    for(lld i=0; i<n; i++){
      cin>>a[i];
      sum+=a[i];
    }
    for(lld i=0;i<2*n;i++){
      b[i]=a[i%n];
    }
    lld y = maxSubArraySum(a,n);
    if(k==1){
      cout<<y<<endl;
    }
    else if(k==2){
      lld x = maxSubArraySum(b,2*n);
      cout<<x<<endl;
    }
    else{
      if(sum>=0){
        a[n] = sum*(k-2);
        for(int i=0;i<n;i++){
          a[i+n+1] = a[i];
        }
        lld x = maxSubArraySum(a,2*n+1);
        cout<<x<<endl;
      }
      else{
        lld x = maxSubArraySum(b,2*n);
        cout<<x<<endl;
      }
    }
  }
  return 0;
}
