// g++ -std=c++14

#include<bits/stdc++.h>

typedef long long ll;
typedef long double lld;
using namespace std;
lld v1,r1,v2,r2;
int n;

int main(){
    cin>>v1>>r1>>v2>>r2>>n;
    lld a1 = (v1*n);
    while(a1>360.00){
        a1-=360.00;
    }
    lld a2 = (v2*n);
    while(a2>360){
        a2 -= 360.00;
    }
    lld ang = abs(a1 - a2)*3.14159/180;
    lld side = r1*r1 + r2*r2 - 2*r1*r2*cos(ang);
    side = sqrt(side);
    printf("%0.5Lf\n",side);
    return 0;
}
