#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long int lli;

int main() {
	for(int test = 0; test <= 39; test++){
        string in = "input" + to_string(test) + ".txt";
        string out = "output" + to_string(test) + ".txt";
        freopen(in.c_str(),"r",stdin);
        freopen(out.c_str(),"w",stdout);
	    lli n,k;
	    cin >> n >> k;
	    lli a[n];
	    for(int i = 0; i<n; i++)
	    {
	        cin >> a[i];
	    }
	    lli max = -1,maxi,maxj;
	    for(int i = 0; i<n; i++)
	    {
	        for(int j = i+1; j<n; j++)
	        {
	            if(j-i-1 <= k)
	            {
	                if(a[i] + a[j] > max)
	                {
	                    maxi = i;
	                    maxj = j;
	                    max = a[i] + a[j];
	                }
	                if(a[i] + a[j] == max)
	                {
	                    if(j-i-1 < maxj-maxi-1)
	                    {
	                        maxi = i;
	                        maxj = j;
	                        max = a[i] + a[j];
	                    }
	                }
	            }
	        }
	    }
	    cout << maxi << " " << maxj << endl;
	}
    return 0;
}
