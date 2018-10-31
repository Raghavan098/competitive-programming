#include<iostream>
#include<algorithm>
#include<vector>
#include<string.h>
#include<math.h>
#include<iomanip>
#include<string.h>
#include<limits>
#include<queue>
typedef long long int llt;
using namespace std;

int visited[8][8];
int mini;
void search(int x1,int y1,int x2,int y2){
  int x,y;
  queue<vector<int> > q;
  vector<int> v;
  v.push_back(x1);
  v.push_back(y1);
  v.push_back(0);
  q.push(v);
  int count = 0;
  while(!q.empty()){
    vector<int> v = q.front();
    q.pop();
    x1 = v[0];
    y1 = v[1];
    count = v[2];
    // cout<<x1<<" "<<y1<<" "<<count<<" "<<x2<<" "<<y2<<endl;
    // cout<<q.size()<<endl;
    visited[x1][y1]=1;
    if(x1==x2 && y1==y2){
      mini = count;
      break;
    }
    if(y1+1<8 && x1+2<8 && visited[x1+2][y1+1]==0){
      vector<int> v;
      v.push_back(x1+2);
      v.push_back(y1+1);
      v.push_back(count+1);
      q.push(v);
    }
    if(x1+1<8 && y1+2<8 && visited[x1+1][y1+2]==0){
      // vector<int> v{x1+1,y1+2,count+1};
      vector<int> v;
      v.push_back(x1+1);
      v.push_back(y1+2);
      v.push_back(count+1);
      q.push(v);
    }
    if(x1-1>=0 && y1-2>=0 && visited[x1-1][y1-2]==0){
      // vector<int> v{x1-1,y1-2,count+1};
      vector<int> v;
      v.push_back(x1-1);
      v.push_back(y1-2);
      v.push_back(count+1);
      q.push(v);
    }
    if(x1-1>=0 && y1+2<8 && visited[x1-1][y1+2]==0){
      // vector<int> v{x1-1,y1+2,count+1};
      vector<int> v;
      v.push_back(x1-1);
      v.push_back(y1+2);
      v.push_back(count+1);
      q.push(v);
    }
    if(x1+1<8 && y1-2>=0 && visited[x1+1][y1-2]==0){
      // vector<int> v{x1+1,y1-2,count+1};
      vector<int> v;
      v.push_back(x1+1);
      v.push_back(y1-2);
      v.push_back(count+1);
      q.push(v);
    }
    if(y1-1>=0 && x1-2>=0 && visited[x1-2][y1-1]==0){
      // vector<int> v{x1-2,y1-1,count+1};
      vector<int> v;
      v.push_back(x1-2);
      v.push_back(y1-1);
      v.push_back(count+1);
      q.push(v);
    }
    if(y1-1>=0 && x1+2<8 && visited[x1+2][y1-1]==0){
      // vector<int> v{x1+2,y1-1,count+1};
      vector<int> v;
      v.push_back(x1+2);
      v.push_back(y1-1);
      v.push_back(count+1);
      q.push(v);
    }
    if(y1+1<8 && x1-2>=0 && visited[x1-2][y1+1]==0){
      // vector<int> v{x1-2,y1+1,count+1};
      vector<int> v;
      v.push_back(x1-2);
      v.push_back(y1+1);
      v.push_back(count+1);
      q.push(v);
    }
  }

}
int main()
{
  ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
  int t;
  cin>>t;
  while(t--){
    char a1,a2,temp;
    int y1,y2;
    cin>>a1>>y1>>a2>>y2;
    int x1,x2;
    x1 = a1-96;
    x2 = a2-96;
    x1--;
    x2--;
    y1--;
    y2--;
    for(int i=0;i<8;i++){
      for(int j=0;j<8;j++){
        visited[i][j] = 0;
      }
    }
    search(x1,y1,x2,y2);
    cout<<mini<<endl;
  }
  return 0;
}
