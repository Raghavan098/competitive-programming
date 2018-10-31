// Solution to Incognito
// Author: Thomas Beuman

// Time complexity: O(n*log(n))
// Memory: O(n)

// @EXPECTED_RESULTS@: CORRECT

// Solution method: map


#include <cstdio>
#include <string>
#include <map>
using namespace std;


map<string,int> M;


int main()
{ int cases, casenr, n, i, d;
  char S[21];
  string Type;
  map<string,int>::iterator it;
  
  scanf("%d\n", &cases);
  for (casenr = 1; casenr <= cases; casenr++)
  { 
    scanf("%d\n", &n);
    M.clear();
    for (i = 0; i < n; i++)
    { scanf("%*s %s\n", S); // (Ignore attribute name)
      Type = S; // Convert from C-string to string
      if (M.count(Type))
        M[Type]++; // Already seen one of this type
      else
        M[Type] = 1; // New type
    }

    // Multiply!
    d = 1;
    for (it = M.begin(); it != M.end(); it++)
      d *= it->second + 1;
    printf("%d\n", d-1);
  }
  return 0;
}

