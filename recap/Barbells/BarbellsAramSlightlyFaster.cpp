#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>
#include <algorithm>
using namespace std;

// The complexity is at least 2^P, but I don't know exactly.

int B, P, b[16], p[16], w[1<<16];
unordered_map<int, bool> done;
unordered_map<int, vector<int> > matches;
set<int> sols;

int main() {
    ios::sync_with_stdio(0);
    cin >> B >> P;
    for (int i = 0; i < B; ++i)
        cin >> b[i];
    for (int i = 0; i < P; ++i)
        cin >> p[i];
    w[0] = 0;
    for (int k = 0; k < B; ++k)
        sols.insert(b[k]);
    for (int i = 0; i < P; ++i)
    for (int j = 0; j < 1<<i; ++j)
    {
        int mask = (1<<i) | j;
        w[mask] = p[i] + w[j];
        bool& d = done[w[mask]];
        if (!d)
        {
            auto& vecm = matches[w[mask]];
            for (int m : vecm)
            {
                if (!(m & mask))
                {
                    for (int k = 0; k < B; ++k)
                        sols.insert(b[k] + 2*w[mask]);
                    vecm.clear();
                    d = true;
                    break;
                }
            }
            if (!d) vecm.push_back(mask);
        }
    }
    for (int sol : sols)
        cout << sol << endl;
}
