#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
typedef long long int lli;
using namespace std;
bool cmp(pair<int,int> p1,pair<int,int> p2){
	return p1.first%p1.second < p2.first%p2.second;
}
int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		vector<pair<int,int> > v(n);
    int a[n];
    int b[n];
		for(int i=0;i<n;i++){
			cin >> v[i].first;
		}
		for(int i=0;i<n;i++){
			cin >> v[i].second;
		}
    int j;
  	sort(v.begin(),v.end(),cmp);
    int mod[n];
    for(int i=0;i<n;i++){
      mod[i] = v[i].first%v[i].second;
      a[i] = v[i].first;
      b[i] = v[i].second;
    }
    int cs[n];
    int minarr[n];
    minarr[0]=b[0];
    cs[0] = mod[0];
    for(int i=1;i<n;i++){
      cs[i] = mod[i]+cs[i-1];
      minarr[i] = (minarr[i-1],b[i])
    }
    
  }
}
