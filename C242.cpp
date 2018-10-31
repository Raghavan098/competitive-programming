#include<bits/stdc++.h>
// #include<cmath>
// #define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long llt;
typedef long double lld;
using namespace std;
int x,y,x2,y2;
int m;
map<int, vector<pair<int ,int> > > gr;
bool cmp(pair<int,int>p1,pair<int,int>p2){
  if(p1.first==p2.first){
    return p1.second<p2.second;
  }
  return p1.first<p2.first;
}
bool check(int i,int j){
  int l,r;
  l = 0;
  r = gr[i].size()-1;
  int mid;
  while(l<=r){
    mid = (r+l)/2;
    if(gr[i][mid].first<=j and gr[i][mid].second>=j){
      return true;
    }
    else if(gr[i][mid].second<j){
      l = mid+1;
    }
    else{
      r = mid-1;
    }
  }
  return false;
}
int main(){ _
  cin>>x>>y>>x2>>y2;
  cin>>m;
  int temp1,l,r;
  for(int i=0;i<m;i++){
    cin>>temp1>>l>>r;
    gr[temp1].push_back(make_pair(l,r));
  }

  map<int,vector<pair<int,int> > >::iterator itr;
  for(itr=gr.begin();itr!=gr.end();itr++){
    sort((itr->second).begin(),(itr->second).end(),cmp);
  }
  set<pair<int,int> >vis;
  // cout<<check(x,y)<<" "<<check(x2,y2)<<endl;
  if(check(x,y)==true && check(x2,y2)==true){
    queue<vector<int > > q;
    q.push({x,y,0});
    int count = 0;
    vector<int> temp;
    int weight;
    vis.insert(make_pair(x,y));
    while(!q.empty()){
      temp = q.front();
      q.pop();

      int i1,j1;
      i1 = temp[0];
      j1 = temp[1];
      weight = temp[2];
      // cout<<i1<<" "<<j1<<endl;
      if(temp[0]==x2 and temp[1]==y2){
        cout<<temp[2]<<endl;
        return 0;
      }
      if(i1+1<=1000000000 and check(i1,j1)==true and vis.find(make_pair(i1+1,j1))==vis.end()){
        q.push({i1+1,j1,weight+1});
        vis.insert(make_pair(i1+1,j1));
      }
      if(i1+1<=1000000000 and j1+1<=1000000000 and check(i1,j1)==true and vis.find(make_pair(i1+1,j1+1))==vis.end()){
        q.push({i1+1,j1+1,weight+1});
        vis.insert(make_pair(i1+1,j1+1));
      }
      if(i1+1<=1000000000 and j1-1>=0 and check(i1,j1)==true and vis.find(make_pair(i1+1,j1-1))==vis.end()){
        q.push({i1+1,j1-1,weight+1});
        vis.insert(make_pair(i1+1,j1-1));
      }
      if(j1+1<=1000000000 and check(i1,j1)==true and vis.find(make_pair(i1,j1+1))==vis.end()){
        q.push({i1,j1+1,weight+1});
        vis.insert(make_pair(i1,j1+1));
      }
      if( j1-1>=0 and check(i1,j1)==true and vis.find(make_pair(i1,j1-1))==vis.end()){
        q.push({i1,j1-1,weight+1});
        vis.insert(make_pair(i1,j1-1));
      }
      if(i1-1>=0 and check(i1,j1)==true and vis.find(make_pair(i1-1,j1))==vis.end()){
        q.push({i1-1,j1,weight+1});
        vis.insert(make_pair(i1-1,j1));
      }
      if(i1-1>=0 and j1-1>=0 and check(i1,j1)==true and vis.find(make_pair(i1-1,j1-1))==vis.end()){
        q.push({i1-1,j1-1,weight+1});
        vis.insert(make_pair(i1-1,j1-1));
      }
      if(i1-1>=0 and j1+1<=1000000000 and check(i1,j1)==true and vis.find(make_pair(i1-1,j1+1))==vis.end()){
        q.push({i1-1,j1+1,weight+1});
        vis.insert(make_pair(i1-1,j1+1));
      }
      count++;
    }
  }
  cout<<-1<<endl;
  return 0;
}
