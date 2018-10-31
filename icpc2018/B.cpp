// g++ -std=c++14
#include<bits/stdc++.h>
typedef long long int lli;
typedef long double lld;
using namespace std;

#define sd(x) scanf("%d",&x);
#define sd2(x,y) scanf("%d%d",&x,&y);
#define sd3(x,y,z) scanf("%d%d%d",&x,&y,&z);

#define fi first
#define se second
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define all(c) c.begin(),c.end()

#define LET(x, a)  __typeof(a) x(a)
#define foreach(it, v) for(LET(it, v.begin()); it != v.end(); it++)
#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define __ freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
vector<pair<int,int> >vec;
int main(){
  _
  int t;
  cin >> t;
  while(t--){
    string s;
    cin >> s;
    vec.clear();
    int sz = s.size();
    int n = sz;
    for(int i=0;i<sz;i++){
      if(s[i]!='.'){
        int num = s[i]-'0';
        int l = max(0,i-num);
        int r = min(n-1,i+num);
        vec.pb(mp(l,r));
      }
    }
    sort(vec.begin(),vec.end());
    int flg = 0;
    for(int i=1;i<vec.size();i++){
      if(vec[i].fi<=vec[i-1].se){
        flg = 1;
        break;
      }
    }
    if(flg==0){
      cout << "safe\n";
    }
    else{
      cout << "unsafe\n";
    }
  }
  return 0;
}
