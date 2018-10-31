#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

// 4^P solution. In practice, about as fast as my 3^P solution,
// provided it's sufficiently optimized.

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
    for (int m1 = 0; m1 < 1<<P; ++m1)
    for (int m2 = 0; m2 <= m1; ++m2)
    {
        if (!(m1 & m2) && w[m1] == w[m2])
        for (int i = 0; i < B; ++i)
            sols.insert(b[i] + w[m1] + w[m2]);
    }
    
    for (int sol : sols)
        cout << sol << endl;
}
