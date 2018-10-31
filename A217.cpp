#include<iostream>
#include<algorithm>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
bool compare(const pair<int,int> &p1,const pair<int,int> &p2){

  return p1.first<p2.first;
}
int main(){
  int n;
  cin>>n;
  vector< pair <int,int> > v;
  int x,y;
  for(int i=0;i<n;i++){

    cin>>x>>y;
    v.push_back(make_pair(x,y));
  }
  sort(v.begin(),v.end(),compare);
  map<int, int> map;
  map[v[0].second]=1;
  int count=0;
  std::map<int,int>::iterator it;

  for(int i=1;i<n;i++){
    it = map.find(v[i].second);
    if(it==map.end()){
      map[v[i].second]=1;
      count++;
    }
  }
  cout<<count<<endl;
  return 0;
}
