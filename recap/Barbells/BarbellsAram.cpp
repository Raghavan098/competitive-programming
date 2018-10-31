#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

// Some careful optimization reduces the complexity to N*logN + 3^P.
// where the output size is N < B*(2^P).

int B, P, b[16], p[16], w[1<<16];

int main() {
    ios::sync_with_stdio(0);
    cin >> B >> P;
    for (int i = 0; i < B; ++i)
        cin >> b[i];
    for (int i = 0; i < P; ++i)
        cin >> p[i];
    w[0] = 0;
    for (int i = 0; i < P; ++i)
    for (int j = 0; j < 1<<i; ++j)
        w[(1<<i)|j] = p[i] + w[j];
    
    set<int> sols;
    for (int mask = 0; mask < 1<<P; ++mask)
    {
        int m1 = mask+1;
        do
        {
            m1 = (m1-1)&mask;
            if (w[mask] == 2*w[m1])
            for (int i = 0; i < B; ++i)
                sols.insert(b[i] + w[mask]);
        }
        while (2*m1 > mask);
    }
    
    for (int sol : sols)
        cout << sol << endl;
}
