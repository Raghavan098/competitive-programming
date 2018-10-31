#include<bits/stdc++.h>
using namespace std;
bool compare(const pair<int,int> &p1,const pair<int,int> &p2){
  return p1.first<p2.first;
}
int main(){
  int n;
  cin>>n;
  vector<pair<int,int> > l;
  int x,y;
  for(int i=0;i<n;i++){
    cin>>x>>y;
    l.push_back(make_pair(x,y));
  }
  sort(l.begin(),l.end(),compare);
  int max = l[0].second;
  int count =0;
  for(int i=1;i<n;i++){
    if(l[i].second<max){
      count++;
    }
    else{
      max = l[i].second;
    }
  }
  cout<<count<<endl;
  return 0;
}
