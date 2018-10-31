// Solution to Administrative Difficultis
// Author: Pieter Bootsma

// Time complexity: O(N * (C + |spies|))
// Memory: O(C + |spies|)

// @EXPECTED_RESULTS@: CORRECT

// Solution method: check all events as they happen; use linear arrays to resolve cars and spies

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Car
{
public:
	string name;
	int price;
	int use_cost;
	int km_cost;
};

class Spy
{
public:
	string name;
	int total; // -1 for inconsistent
	bool has_car;
	int car;
	bool operator<(const Spy &s) const
	{
		return name < s.name;
	}
};

void dostep()
{
	int C,N;
	cin >> C >> N;
	
	vector<Car> cars(C);
	for (int i = 0; i < C; i++)
	{
		cin >> cars[i].name >> cars[i].price >> cars[i].use_cost >> cars[i].km_cost;
	}
	
	vector<Spy> spies;
	for (int r = 0; r < N; r++)
	{
		int t;
		string s,e;
		cin >> t >> s >> e;
		int i;
		for (i = 0; (i < spies.size()) && (spies[i].name != s); i++)
		{}
		if (i == spies.size())
		{
			Spy newspy;
			newspy.name = s;
			newspy.total = 0;
			newspy.has_car = false;
			spies.push_back(newspy);
		}
		Spy &spy = spies[i];
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
					for (spy.car = 0; cars[spy.car].name != c; spy.car++)
					{}
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
	
	sort(spies.begin(), spies.end());
	
	for (auto it = spies.begin(); it != spies.end(); it++)
	{
		cout << it->name << " ";
		if ((it->total < 0) || (it->has_car))
			cout << "INCONSISTENT";
		else
			cout << it->total;
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
