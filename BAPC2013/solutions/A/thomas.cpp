// Solution to Administrative Difficulties
// Author: Thomas Beuman

// Time complexity: O(m * namelength * (n + #spies))
// Memory: O(n + #spies)

// @EXPECTED_RESULTS@: CORRECT

// Solution method: bookkeeping


#include <cstdio>
#include <cstring>
using namespace std;


const int N = 500, S = 500, M = 10000;

char Car[N][41];
int P[N], Q[N], K[N];

char Spy[S][41];
int Bill[S], CarTaken[S];
bool Consistent[S], Listed[S];


int main()
{ int cases, casenr, n, m, i, z, s, j, p, d;
  char Name[41], event;
  
  scanf("%d\n", &cases);
  for (casenr = 1; casenr <= cases; casenr++)
  { 
    // Read car info
    scanf("%d %d\n", &n, &m);
    for (i = 0; i < n; i++)
      scanf("%s %d %d %d\n", Car[i], &P[i], &Q[i], &K[i]);
    
    z = 0; // Number of spies
    for (i = 0; i < m; i++)
    { 
      scanf("%*d %s %c\n", Name, &event); // (Ignore time stamp)
      for (s = 0; s < z && strcmp(Name, Spy[s]) != 0; s++); // Look for spy
      if (s == z) // New spy
      { strcpy(Spy[z++], Name);
        Bill[s] = 0;
        CarTaken[s] = -1; // -1 = no car picked up
        Consistent[s] = true;
      }
      
      switch (event)
      { case 'p':
          if (CarTaken[s] >= 0) // Already picked up a car
            Consistent[s] = false;
          scanf("%s\n", Name);
          for (j = 0; j < n && strcmp(Name, Car[j]) != 0; j++); // Find car id
          if (j == n)
          { printf("Unknown car!\n");
            return 0;
          }
          CarTaken[s] = j;
          Bill[s] += Q[j];
          break;
        case 'a':
          if (CarTaken[s] < 0) // No car picked up
            Consistent[s] = false;
          scanf("%d\n", &p);
          Bill[s] += (p * P[CarTaken[s]] + 99) / 100; // The "+ 99" is for rounding up
          break;
        case 'r':
          if (CarTaken[s] < 0) // No car picked up
            Consistent[s] = false;
          scanf("%d\n", &d);
          Bill[s] += d * K[CarTaken[s]];
          CarTaken[s] = -1;
          break;
      }
    }
    
    // Print bills
    for (i = 0; i < z; i++)
      Listed[i] = false;
    for (i = 0; i < z; i++)
    { // Look for lexicographically first spy not listed yet
      s = -1;
      for (j = 0; j < z; j++)
        if (!Listed[j] && (s == -1 || strcmp(Spy[j], Spy[s]) < 0))
          s = j;

      printf("%s ", Spy[s]);
      if (Consistent[s] && CarTaken[s] < 0)
        printf("%d\n", Bill[s]);
      else
        printf("INCONSISTENT\n");
      Listed[s] = true;
    }
  }
  return 0;
}

