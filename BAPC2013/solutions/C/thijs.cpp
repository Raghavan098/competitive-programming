// Solution for Decryption
// Author: Thijs
// @EXPECTED_RESULTS@: CORRECT

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>

using namespace std;

void doStep()
{
	int n;
	cin>>n;
	vector<string> msg(n);
	string D, X;
	for(int i=0;i<n;i++)
		cin>>msg[i];
	cin>>D>>X;
	string Y(X.size(),'_');
	bool any=false;
	char sol[26]={0};
	for(int i=0;i<n;i++)
	{
		char repl[26]={0};
		char rrepl[26]={0};
		bool ok=msg[i].size()==D.size();
		for(int j=0; ok&&j<(int)msg[i].size(); j++)
		{
			if (repl[msg[i][j]-'a']!=0&&repl[msg[i][j]-'a']!=D[j])
				ok=false;
			repl[msg[i][j]-'a']=D[j];
			if (rrepl[D[j]-'a']!=0&&rrepl[D[j]-'a']!=msg[i][j])
				ok=false;
			rrepl[D[j]-'a']=msg[i][j];
		}
		if (ok)
		{
			any=true;
			for (int j=0;j<26;j++)
			{
				if (sol[j]!=0&&sol[j]!=repl[j])
					sol[j]='?';
				else
					sol[j]=repl[j]==0?'?':repl[j];
			}
		}
	}
	int nsol=0;
	for(int i=0;i<26;i++)
		if (sol[i]!=0&&sol[i]!='?')nsol++;
	if(!any)
		cout<<"IMPOSSIBLE"<<endl;
	else {
		if (nsol==25)
		{
			bool found[26]={false};
			for(int i=0;i<26;i++)
				if (sol[i]!=0&&sol[i]!='?') found[sol[i]-'a']=true;
			char over='-';
			for(int i=0;i<26;i++)
				if (!found[i])over='a'+i;
			for(int i=0;i<26;i++)
				if (sol[i]==0||sol[i]=='?') sol[i]=over;
			// find last letter
		}
		for (int i=0;i<26; i++)
			if(sol[i]==0)sol[i]='?';
		for (int i=0;i<(int)Y.size(); i++)
			Y[i] = sol[X[i]-'a'];
		cout<<Y<<endl;
	}
}

int main()
{
	int n;
	cin >> n;
	while (n--) doStep();
	return 0;
}
