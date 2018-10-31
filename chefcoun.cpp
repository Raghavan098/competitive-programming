#include <bits/stdc++.h>
using namespace std;
int wrongSolver(std::vector <unsigned int> a) {
	int n = a.size();
	std::vector<unsigned int> prefSum(n), sufSum(n);
	prefSum[0] = a[0];
	for (int i = 1; i < n; i++) {
		prefSum[i] = prefSum[i - 1] + a[i];
	}
	sufSum[n - 1] = a[n - 1];
	for (int i = n - 2; i >= 0; i--) {
		sufSum[i] = sufSum[i + 1] + a[i];
	}
	unsigned int mn = prefSum[0] + sufSum[0];
	// cout<<mn<<endl;
	int where = 1;
	for (int i = 1; i < n; i++) {
		unsigned int val = prefSum[i] + sufSum[i];
		// cout<<val<<endl;
		if (val < mn) {
			mn = val;
			where = i + 1;
		}
	}
	// for(int i=0;i<n;i++){
	// 	cout<<prefSum[i]<<" "<<sufSum[i]<<endl;
	// }
	return where;
}
int correctSolver(std::vector <unsigned int> a){
  int where =0;
  int min = a[0];
  for(int i=1;i<a.size();i++){
    if(a[i]<min){
      min = a[i];
      where = i;
    }
  }
  return where;
}
int main(){
  vector<unsigned int> a;
	a.resize(4);
	// a[0] = 4294967295;
	// a[1] = 1;
	// a[2] = 1;
	// a[3] = 0;
	// cout<<a[0]<<endl;
  // a.push_back(4294967295);
  // a.push_back(1);
  // a.push_back(1);
  // a.push_back(0);
  cout<<wrongSolver(a)<<" "<<correctSolver(a);
  return 0;
}
