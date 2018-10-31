#include<iostream>
#include<bits/stdc++.h>
#define ll long long
using namespace std;
map<int,int> prime;
int **arr;

int temp;
int l,u;
int m;
int x;
int n;
ll i;

int main(){
  ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
  arr = new int*[10000000];
  for(i=0;i<10000000;i++){
    arr[i]=new int[2];
  }
  for(i=0;i<10000000;i++){
    arr[i][0]=0;
    arr[i][1]=0;
  }
  int max;
  cin>>n;
  max=-1;
  for(i=0;i<n;i++){
    cin>>x;
    if(x>max){
      max = x;
    }
    arr[x][0]+=1;
  }
  vector<int> list;
  for(i=2;i<1000;i++){
    x = 2;
    if (arr[i][1]==0){
      prime[i]=0;
      list.push_back(i);
      prime[i]+=arr[i][0];
      temp=0;
      while(i*x<10000000 && i*x<=max){
        arr[i*x][1]=1;
        temp+=arr[i*x][0];
        x++;
      }
      prime[i]+=temp;
    }
  }
  // for(i=0;i<10;i++){
  //   cout<<list[i]<<" "<<prime[list[i]]<<endl;
  // }
  for(i=0;i<10000000;i++){
    delete[] arr[i];
  }
  cin>>m;

  while(m--){
    cin>>l>>u;
    temp=0;
    while(list[temp++]<l);
    temp--;
    x=0;
    while(list[temp]<=u){
      x+=prime[list[temp]];
      temp++;
      // cout<<i<<endl;
    }
    cout<<x<<endl;
  }
  return 0;
}
