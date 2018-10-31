// Solution to Administrative Difficultis
// Author: Pieter Bootsma

// Time complexity: O(N * (log(C) + log(|spies|)))
// Memory: O(C + |spies|)

// @EXPECTED_RESULTS@: CORRECT

// Solution method: check all events as they happen; use maps to resolve cars and spies

#include <iostream>
#include <map>
#include <string>

using namespace std;

class Car
{
public:
	int price;
	int use_cost;
	int km_cost;
};

class Spy
{
public:
	int total; // -1 for inconsistent
	bool has_car;
	string car;
};

void dostep()
{
	int C,N;
	cin >> C >> N;
	
	map<string,Car> cars;
	for (int i = 0; i < C; i++)
	{
		string name;
		cin >> name;
		Car &car = cars[name];
		cin >> car.price >> car.use_cost >> car.km_cost;
	}
	
	map<string,Spy> spies;
	for (int i = 0; i < N; i++)
	{
		int t;
		string s,e;
		cin >> t >> s >> e;
		Spy &spy = spies[s];
		switch (e[0])
		{
			case 'p':
			{
				string c;
				cin >> c;
				if (spy.total == -1);
				else if (spy.has_car)
				{
					spy.total = -1;
				}
				else
				{
					spy.has_car = true;
					spy.car = c;
				}
				break;
			}
			
			case 'r':
			{
				int k;
				cin >> k;
				if (spy.total == -1);
				else if (!spy.has_car)
				{
					spy.total = -1;
				}
				else
				{
					Car &car = cars[spy.car];
					spy.total += car.use_cost + k * car.km_cost;
					spy.has_car = false;
				}
				break;
			}
			
			case 'a':
			{
				int p;
				cin >> p;
				if (spy.total == -1);
				else if (!spy.has_car)
				{
					spy.total = -1;
				}
				else
				{
					Car &car = cars[spy.car];
					int cents = p * car.price;
					spy.total += cents/100;
					if (cents % 100)
						spy.total++;
				}
				break;
			}
		}
	}
	
	for (auto it = spies.begin(); it != spies.end(); it++)
	{
		cout << it->first << " ";
		if ((it->second.total < 0) || (it->second.has_car))
			cout << "INCONSISTENT";
		else
			cout << it->second.total;
		cout << endl;
	}
}

int main()
{
	int n;
	cin >> n;
	while (n--)
		dostep();
	return 0;
}
