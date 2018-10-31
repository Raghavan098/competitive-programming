// Solution to Cracking the Code
// Author: Thomas Beuman

// Time complexity: O(n * messagelength)
// Memory: O(n * messagelength)

// @EXPECTED_RESULTS@: CORRECT

// Solution method: bookkeeping

// Tip: use the -Wno-char-subscripts flag for compiling, or get ready for lots of warnings :)


#include <cstdio>
#include <cstring>
using namespace std;


char M[100][1001], D[1001], X[1001];
char Decr[256], Encr[256], OverallEncr[256], OverallDecr[256];


int main()
{ int cases, casenr, n, m, i, j, k;
  char c, d;
  bool matchfound;

  scanf("%d\n", &cases);
  for (casenr = 1; casenr <= cases; casenr++)
  { 
    // Read input
    scanf("%d\n", &n);
    for (i = 0; i < n; i++)
      scanf("%s\n", M[i]);
    scanf("%s\n%s\n", D, X);

    m = strlen(D);
    memset(OverallEncr, 0, 256);
    matchfound = false;

    for (i = 0; i < n; i++)
    { 
      if ((int)strlen(M[i]) != m) // Message of wrong size: ignore
        continue;

      memset(Decr, 0, 256); // Map to corresponding decrypted letter
      memset(Encr, 0, 256); // Map to corresponding encrypted letter
      for (j = 0; j < m; j++)
      { if (Decr[M[i][j]] == 0) // No match yet
          Decr[M[i][j]] = D[j];
        else if (Decr[M[i][j]] != D[j]) // Inconsistency
          break;
        if (Encr[D[j]] == 0) // No match yet
          Encr[D[j]] = M[i][j];
        else if (Encr[D[j]] != M[i][j]) // Inconsistency
          break;
      }

      if (j < m) // Inconsistency found
        continue;
      matchfound = true;

      // Take the "intersection" of the encryption map with the overall map
      for (c = 'a'; c <= 'z'; c++)
      { if (OverallEncr[c] == 0)
          OverallEncr[c] = Encr[c];
        else if (OverallEncr[c] != Encr[c]) // A different possible encryption
          OverallEncr[c] = '?';
      }
    }

    // No potential match found
    if (!matchfound)
    { printf("IMPOSSIBLE\n");
      continue;
    }

    // Invert encryption map
    memset(OverallDecr, '?', 256);
    for (c = 'a'; c <= 'z'; c++)
      if (OverallEncr[c] >= 'a') // Note: '?' < 'a'
        OverallDecr[OverallEncr[c]] = c;

    // Check if there is only one unknown (this can then be deduced)
    k = 0;
    for (c = 'a'; c <= 'z'; c++)
      if (OverallDecr[c] == '?')
        k++;
    if (k == 1)
    { for (c = 'a'; OverallDecr[c] != '?'; c++); // Find unmatched letters
      for (d = 'a'; OverallEncr[d] >= 'a'; d++);
      OverallDecr[c] = d;
    }

    // Decrypt X and print
    m = strlen(X);
    for (i = 0; i < m; i++)
      printf("%c", OverallDecr[X[i]]);
    printf("\n");
  }
  return 0;
}

