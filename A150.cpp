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
llt no;
int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin>>no;
  if(no==1){
    cout<<1<<endl<<0<<endl;
    return 0;
  }
  primeFactors(no);
  sort(v.begin(),v.end());
  // cout<<v.size()<<endl;
  // for(llt i=0;i<v.size();i++){
  //   cout<<v[i]<<" ";
  // }cout<<endl;
  llt curr = v[0];
  llt curr2 = -1;
  for(llt i =1;i<v.size();i++){
    if(v[i]!=v[i-1]){
      curr2 = v[i];
      break;
    }
  }
  if(curr2!=-1){
    if(curr*curr2!=no){
      cout<<1<<endl;
      cout<<curr*curr2<<endl;
    }
    else{
      cout<<2<<endl;
    }
  }
  else{
    if(v.size()>2){
      cout<<1<<endl<<v[0]*v[1]<<endl;
    }
    else if(v.size()==1){
      cout<<1<<endl<<0<<endl;
    }
    else{
      cout<<2<<endl;
    }
  }
  return 0;
}
