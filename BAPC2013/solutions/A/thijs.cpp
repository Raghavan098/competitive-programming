// Solution for Car administration
// Author: Thijs
// @EXPECTED_RESULTS@: CORRECT

#include <iostream>
#include <cstdlib>
#include <string>
#include <map>

using namespace std;

struct car
{
	int p,q,k;
};
struct spy
{
	spy(){incar=false;ok=true;cost=0;}
	string car;
	bool incar;
	bool ok;
	int cost;
};
void doStep()
{
	int C,N;
	cin>>C>>N;
	map<string,car> cars;
	for(int i=0;i<C;i++)
	{
		string name;
		cin>>name;
		cin>>cars[name].p>>cars[name].q>>cars[name].k;
	}
	map<string,spy> spies;
	for (int i=0;i<N;i++)
	{
		int t;
		string s,c;
		cin>>t>>s>>c;
		if (c=="p")
		{
			string car;
			cin>>car;
			if (spies[s].incar)
				spies[s].ok=false;
			else {
				spies[s].incar=true;
				spies[s].car=car;
				spies[s].cost+=cars[car].q;
			}
		} else if (c=="r") {
			int km;
			cin>>km;
			if (!spies[s].incar)
				spies[s].ok=false;
			else {
				spies[s].cost+=cars[spies[s].car].k*km;
				spies[s].incar=false;
			}
		} else if (c=="a") {
			int p;
			cin>>p;
			if (!spies[s].incar)
				spies[s].ok=false;
			else if (p>0){
				spies[s].cost+=(cars[spies[s].car].p*p+99)/100;
			}
		}
	}
	for (auto it=spies.begin();it!=spies.end();it++)
	{
		if(it->second.ok && !it->second.incar)
			cout<<it->first<<" "<<it->second.cost<<endl;
		else
			cout<<it->first<<" INCONSISTENT"<<endl;
	}
}

int main()
{
	int n;
	cin >> n;
	while (n--) doStep();
	return 0;
}
