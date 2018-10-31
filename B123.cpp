// g++ -std=c++14

#include <algorithm>
#include <iostream>


typedef long long ll;
typedef long double lld;
using namespace std;

int a,b,x,y,x1,y1,x2,y2;

int main(){
  cin>>a>>b>>x1>>y1>>x2>>y2;
  x = x1;y = y1;
  x1 = x + y;
  y1 = y - x;

  x = x2; y = y2;
  x2 = x + y;
  y2 = y - x;



  a *= 2;
  b *= 2;

  // cout<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<" "<<a<<" "<<b<<endl;

  x1 = x1 / a + (x1 > 0);
  x2 = x2 / a + (x2 > 0);
  y1 = y1 / b + (y1 > 0);
  y2 = y2 / b + (y2 > 0);

  cout<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<" "<<a<<" "<<b<<endl;
  cout << max(abs(y2 - y1), abs(x2 - x1)) << endl;
  return 0;
}
