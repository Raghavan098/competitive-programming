#include<bits/stdc++.h>
#include<cmath>
#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long llt;
typedef long double lld;
using namespace std;

int n,q;
bool prime[100000+5];
int MAXN = 100000+5;
int spf[100000+5];
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
  cin>>n>>q;
  sieve();
  vector<int> primes;
  int prime_factors[n];
  int already_on[n+1];
  for(int i=0;i<=n;i++){
    already_on[i] = 0;
    prime_factors[i] = 0;
  }
  char temp;
  int current,done;
  for(int i=0;i<q;i++){
    cin>>temp>>current;
    if(temp=='+'){
      if(already_on[current]==0){
        done = 0;
        vector<int> primes = getFactorization(current);
        vector<int> prime_factors_this;
        for(int j=0;j<primes.size();j++){
          if(current%primes[j]==0){
            if(prime_factors[primes[j]]!=0){
              cout<<"Conflict with "<<prime_factors[primes[j]]<<endl;
              done = 1;
              break;
            }
            prime_factors_this.push_back(primes[j]);
          }
        }
        if(done==0){
          cout<<"Success"<<endl;
          for(int j = 0;j<prime_factors_this.size();j++){
            prime_factors[prime_factors_this[j]] = current;
          }
          already_on[current] = 1;
        }
      }
      else{
        cout<<"Already on"<<endl;
      }
    }
    else{
      if(already_on[current]==1){
        primes = getFactorization(current);
        for(int j = 0;j<primes.size();j++){
          if(current%primes[j]==0){
            prime_factors[primes[j]] = 0;
          }
        }
        already_on[current] = 0;
        cout<<"Success"<<endl;
      }
      else{
        cout<<"Already off"<<endl;
      }
    }
  }
  return 0;
}
