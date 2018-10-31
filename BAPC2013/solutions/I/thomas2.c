// Solution to Disguise
// Author: Thomas Beuman

// Time complexity: O(n^2)
// Memory: O(n)

// @EXPECTED_RESULTS@: CORRECT

// Solution method: basic


#include <stdio.h>
#include <string.h>


char TypeName[30][21];
int Number[30];


int main()
{ int cases, casenr, n, t, i, j, d;
  char S[21];
  
  scanf("%d\n", &cases);
  for (casenr = 1; casenr <= cases; casenr++)
  { 
    scanf("%d\n", &n);
    t = 0;
    for (i = 0; i < n; i++)
    { scanf("%*s %s\n", S); // (Ignore attribute name)
      for (j = 0; j < t && strcmp(TypeName[j], S) != 0; j++); // Look for type name
      if (j == t) // New type
      { strcpy(TypeName[t++], S);
        Number[j] = 1;
      }
      else
        Number[j]++;
    }

    // Multiply!
    d = 1;
    for (j = 0; j < t; j++)
      d *= Number[j] + 1;
    printf("%d\n", d-1);
  }
  return 0;
}

