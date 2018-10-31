#include<bits/stdc++.h>
#include<cmath>
#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long llt;
typedef long double lld;
using namespace std;
#define PI 3.14159265358979;
lld get_angle(int x1,int y1){
  return atan(lld(y1)/lld(x1))*180.00f/PI;
}
int main(){ _
  int n;
  cin>>n;
  int arr[n][2];
  for(int i=0;i<n;i++){
    cin>>arr[i][0]>>arr[i][1];
  }
  if(n==1){
    cout<<0<<endl;
    return 0;
  }
  double ans;
  lld temp;
  vector <lld> v;
  for(int i=0;i<n;i++){
    temp = get_angle(abs(arr[i][0]),abs(arr[i][1]));
    if(arr[i][0]>=0 and arr[i][1]>=0){
      v.push_back(temp);
    }
    else if(arr[i][0]<=0 and arr[i][1]>=0){
      v.push_back(180.00- temp);
    }
    else if(arr[i][0]<=0 and arr[i][1]<=0){
      v.push_back(temp+180.00);
    }
    else if(arr[i][0]>=0 and arr[i][1]<=0){
      v.push_back(360.00 - temp);
    }
    // printf("%.10lf\n",double(v[i]));


  }
  sort(v.begin(),v.end());
  int n1 = v.size();
  ans  = double(double(v[n-1]) - double(v[0]));
  // printf("%.10lf\n",ans);
  for(int i=1;i<v.size();i++){
    // printf("%.10lf %.10lf\n",360.00 - double(v[i]) + double(v[i-1]),ans);
    if(360.00 - v[i] + v[i-1]<ans){
      ans =360.00 - double(v[i]) + double(v[i-1]);
    }
  }
  printf("%.10lf\n",double(ans));
  return 0;
}
