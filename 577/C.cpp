#include<bits/stdc++.h>
#include<cmath>
#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define pb push_back
#define MAXN 10000
typedef long long llt;
typedef long double lld;
using namespace std;


int n;
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

set<int> ans;
vector<int> factors;
int curr;

int main(){
  cin>>n;
  sieve();
  if(n==1){
    cout<<0<<endl;
    return 0;
  }
  int temp;
  for(int i=2;i<=n;i++){
    factors = getFactorization(i);
    temp =i;
    for(int j=0;j<factors.size();j++){
      curr = 1;

      while(temp%factors[j]==0){
        curr*=factors[j];
        temp/=factors[j];
      }
      if(curr!=1)
        ans.insert(curr);
    }
  }
  cout<<ans.size()<<endl;
  set<int> :: iterator itr;
  for(itr = ans.begin();itr!=ans.end();itr++){
    cout<<*itr<<" ";
  }cout<<endl;
  return 0;
}
