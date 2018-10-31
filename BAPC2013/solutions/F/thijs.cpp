// Solution for Safe flight
// Author: Thijs
// @EXPECTED_RESULTS@: CORRECT

#include <iostream>
#include <cstdlib>
#include <string>
#include <map>

using namespace std;

void doStep()
{
	int n,m,d;
	cin>>n>>m;
	for(int i=0;i<m;i++)
		cin>>d>>d;
	cout<<(n-1)<<endl;
}

int main()
{
	int n;
	cin >> n;
	while (n--) doStep();
	return 0;
}
