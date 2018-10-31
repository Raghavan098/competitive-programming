#include<bits/stdc++.h>
typedef long long llt;
using namespace std;
llt mod = 1000000007;
vector<llt> v;
void primeFactors(llt n)
{

    while (n%2 == 0)
    {

        v.push_back(2);
        n = n/2;
    }
    for (llt i = 3; i <= sqrt(n); i = i+2)
    {
        while (n%i == 0)
        {
            v.push_back(i);
            n = n/i;
        }
    }
    if (n > 2)
        v.push_back(n);
}
