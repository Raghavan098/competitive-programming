// Solution for Disguise
// Author: Thijs
// @EXPECTED_RESULTS@: CORRECT

#include <iostream>
#include <cstdlib>
#include <string>
#include <map>

using namespace std;

void doStep()
{
	map<string, int>  attrs;
	int n;
	cin>>n;
	while(n--) {
		string attr, cat;
		cin>>attr>>cat;
		attrs[cat]++;
	}
	int opts=1;
	for(auto it=attrs.begin(); it!=attrs.end(); it++)
		opts*=(it->second+1);
	cout<<(opts-1)<<endl;
}

int main()
{
	int n;
	cin >> n;
	while (n--) doStep();
	return 0;
}
