#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int MAXN = 1000000 + 1000;
const int MOD = 1000000000 + 7;

int f[MAXN];
bool endsAt[MAXN];
string s, t;

void getOccurrences () {
    string joined = "_" + t + "#" + s;
    f[1] = 0;
    for(int i = 2; i < joined.length(); i++) {
        int k = f[i - 1];
        while (k > 0 && joined[k + 1] != joined[i]) {
            k = f[k];
        }
        if (joined[k + 1] == joined[i]) {
            f[i] = k + 1;
        } else {
            f[i] = 0;
        }
    }
    for(int i = (int)t.length() + 2; i < joined.length(); i++) {
        if (f[i] == t.length()) {
            endsAt[i - t.length() - 2] = true;
        }
    }
}

int main(int argc, const char * argv[]) {
    int testCases;
    cin >> testCases;
    while (testCases--) {
        cin >> s;
        cin >> t;
        for(int i = 0; i < s.length(); i++) {
            endsAt[i] = false;
        }
        getOccurrences();
        for(int i = 0; i < s.length(); i++)
            f[i] = 0;
        for(int i=0;i<s.length();i++){
          cout<<endsAt[i]<<" ";
        }
        cout<<endl;
        for(int i = (int)t.length() - 1; i < s.length(); i++) {
            if (endsAt[i]) {
                f[i] = 1;
                if (i > t.length() - 1)
                    f[i] = (f[i] + f[i - t.length()]) % MOD;
            }
            f[i] = (f[i] + f[i - 1]) % MOD;
            cout<<f[i]<<" "<<i<<endl;
        }
        cout<<endl;
        cout << f[s.length() - 1] << endl;
    }
    return 0;
}
