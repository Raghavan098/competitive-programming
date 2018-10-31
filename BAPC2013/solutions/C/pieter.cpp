// Solution to Cracking the Code
// Author: Pieter Bootsma

// Time complexity: O(n*|D| + |X|)
// Memory: O(n*|D| + |X|)

// @EXPECTED_RESULTS@: CORRECT

// Solution method: match unless inconsistencies found; handle case of only one unknown

#include <iostream>

using namespace std;

bool match(string enc, string dec, char trans[128]) // trans enc->dec
{
	if (enc.length() != dec.length())
		return false;
	
	char rev[128]; // dec -> enc
	for (char i = 'a'; i <= 'z'; i++)
	{
		trans[i] = '?';
		rev[i] = '?';
	}
	
	int nfound = 0;
	for (size_t i = 0; i < enc.length(); i++)
	{
		if ((trans[enc[i]] != '?') && (trans[enc[i]] != dec[i]))
			return false;
		if ((rev[dec[i]] != '?') && (rev[dec[i]] != enc[i]))
			return false;
		if (trans[enc[i]] == '?')
		{
			trans[enc[i]] = dec[i];
			rev[dec[i]] = enc[i];
			nfound++;
		}
	}
	if (nfound == 25)
	{
		char from = 0, to = 0;
		for (char i = 'a'; i <= 'z'; i++)
		{
			if (trans[i] == '?')
				from = i;
			if (rev[i] == '?')
				to = i;
		}
		trans[from] = to;
	}
	
	return true;
}

void dostep()
{
	int n;
	cin >> n;
	
	string messages[105];
	for (int i = 0; i < n; i++)
	{
		cin >> messages[i];
	}
	
	string D;
	cin >> D;
	
	string X;
	cin >> X;
	
	bool found = false;
	char trans[128];
	char cur[128];
	
	for (int i = 0; i < n; i++)
	{
		if (match(messages[i], D, cur))
		{
			if (found)
			{
				for (char j = 'a'; j <= 'z'; j++)
				{
					if (cur[j] != trans[j])
					{
						trans[j] = '?';
					}
				}
			}
			else
			{
				found = true;
				for (int j = 'a'; j <= 'z'; j++)
				{
					trans[j] = cur[j];
				}
			}
		}
	}
	
	if (!found)
	{
		cout << "IMPOSSIBLE" << endl;
		return;
	}
	
	for (size_t i = 0; i < X.length(); i++)
	{
		cout << trans[X[i]];
	}
	cout << endl;
}

int main()
{
	int n;
	cin >> n;
	while (n--)
		dostep();
	return 0;
}
