// @EXPECTED_RESULTS@: CORRECT

#include <iostream>
#include <map>
#include <string>

using namespace std;

int main()
{
	int N;
	cin >> N;
	while (N--)
	{
		map<string,int> attributes;
		int n;
		cin >> n;
		while (n--)
		{
			string name, category;
			cin >> name >> category;
			attributes[category]++;
		}
		long long sum = 1;
		for (auto it = attributes.begin(); it != attributes.end(); it++)
		{
			sum *= it->second + 1;
		}
		cout << sum - 1 << endl;
	}
	return 0;
}
