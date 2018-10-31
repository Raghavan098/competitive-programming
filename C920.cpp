#include<bits/stdc++.h>
#include<cmath>
#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long llt;
typedef long double lld;
using namespace std;

void updateBIT(int BITree[], int n, int index, int val)
{
    index = index + 1;

    while (index <= n)
    {
        BITree[index] += val;

        index += index & (-index);
    }
}
int *constructBITree(int arr[], int n)
{
    int *BITree = new int[n+1];
    for (int i=1; i<=n; i++)
        BITree[i] = 0;
    for (int i=0; i<n; i++)
        updateBIT(BITree, n, i, arr[i]);

    return BITree;
}
int getSum(int BITree[], int index)
{
    int sum = 0;

    index = index + 1;

    while (index>0)
    {
        sum += BITree[index];

        index -= index & (-index);
    }
    return sum;
}

void update(int BITree[], int l, int r, int n, int val)
{
    updateBIT(BITree, n, l, val);
    updateBIT(BITree, n, r+1, -val);
}
int n;
int arr[300000];
map<int ,int > m;
string s;
int temp[300000];
int count1[300000];
int den[300000];
int x,y;
int main(){
  cin>>n;
  for(int i=0;i<n;i++){
    cin>>arr[i];
    temp[i]= arr[i];
    m[arr[i]] = i;
    den[i]= 0;
  }
  int *BIT = constructBITree(den,n);
  cin>>s;
  if(s[0]=='0'){
    count1[0]= 0;
  }
  else{
    count1[0] = 1;
  }
  for(int i =1;i<n-1;i++){
    if(s[i]=='1'){
      count1[i] = count1[i-1]+1;
    }
    else{
      count1[i] = count1[i-1];
    }
  }
  sort(temp,temp+n);
  for(int i=n-1;i>=0;i--){
    x = m[temp[i]] - getSum(BIT,m[temp[i]]);
    y = i;
    cout<<x<<" "<<y<<" "<<temp[i]<<" "<<count1[y-1]<<" "<<count1[]
    if(count1[y-1] - count1[x] == y-x-1){
      update(BIT,x+1,y,n,1);
    }
    else{
      cout<<"NO"<<endl;
      return 0;
    }
  }
  cout<<"YES"<<endl;
  return 0;
}
