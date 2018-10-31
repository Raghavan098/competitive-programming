#include<bits/stdc++.h>
#include<cmath>
#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define pb push_back
#define MAXN   1000001
typedef long long llt;
typedef long double lld;
using namespace std;
vector<int> l,l2;
int n,curr,rem,curr2,rem2;

int spf[MAXN];

void sieve()
{
    spf[1] = 1;
    for (int i=2; i<MAXN; i++)
        spf[i] = i;

    for (int i=4; i<MAXN; i+=2)
        spf[i] = 2;

    for (int i=3; i*i<MAXN; i++)
    {
        if (spf[i] == i)
        {
            for (int j=i*i; j<MAXN; j+=i)

                if (spf[j]==j)
                    spf[j] = i;
        }
    }
}
vector<int> getFactorization(int x)
{
    vector<int> ret;
    while (x != 1)
    {
        ret.push_back(spf[x]);
        x = x / spf[x];
    }
    return ret;
}
int main(){ _
  cin>>n;
  int ans,min_ans;
  sieve();
  l = getFactorization(n);
  sort(l.begin(),l.end());
  min_ans = INT_MAX;
  curr = l[l.size()-1];
  rem = n/curr;
  for(int i=curr*(rem-1)+1;i<=curr*(rem)-1;i++){
    l2.clear();
    l2 = getFactorization(i);
    if(l2.size()!=1){
      curr2 = l2[l2.size()-1];
      rem2 = i/curr2;
      ans = curr2*(rem2-1)+1;
      if(ans<min_ans){
        min_ans = ans;
      }
    }
    else{
      ans = i;
      if(ans<min_ans){
        min_ans = ans;
      }
    }
  }
  cout<<min_ans<<endl;
  return 0;

}
