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
      cout<<a[i]<<" "<<b[i]<<endl;
    }
    int cusu[n];
    for(int i=0;i<n;i++){
      cusu[i]=0;
    }
    for(int i=0;i<n;i++){
      cusu[i] = b[i]-mod[i];
    }
    for(int i=n-2;i>=0;i--){
      cusu[i] = cusu[i+1]+cusu[i];
    }
    for(int i=0;i<n;i++){
      cout<<cusu[i]<<" ";
    }cout<<endl;
    int minarr[n];
    minarr[0]=b[0];
    for(int i=1;i<n;i++){
      minarr[i] = min(minarr[i-1],b[i]);
    }
    int curr = mod[n-1];
    int cost = 0;
    int i=n-1;
    int prei;
    for(int i=0;i<n;i++){
      std::cout << mod[i] << ' ';
    }
    while(i>=0){
      prei = i;
      while(mod[i]==curr && i>=0){
        i--;
      }
      cout<<i<<" "<<"i"<<endl;
      if(mod[i+1]<minarr[i]){
        break;
      }
      curr = mod[i];
    }
    cout<<curr<<" "<<"curr"<<endl;
    for(j=0;mod[j]!=curr;j++){
      cost+=curr - mod[j];
    }
    if(prei!=n-1){
      cost+=cusu[prei+1];
    }
    int precost=cost;
    int micost = cost;
    cout<<i<<" "<<"i"<<endl;
    cout<<cost<<"\n";
    while(i>=0){
      prei = i;
      while(mod[i]==curr && i>=0){
        i--;
      }
      if(mod[i+1]<minarr[i] && i>=0){
        continue;
      }
      cost = cusu[prei+1]+(n-i-1)*mod[prei];
      cost+=precost-(mod[prei+1]-mod[prei]);
      if(cost<micost){
        micost=cost;
      }
      curr = mod[prei];
      precost = cost;
      if(i==0){
        break;
      }
    }
    cout<<micost<<endl;
  }
}
