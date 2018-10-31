// Solution to Encoded Coordinates
// Author: Thomas Beuman

// Time complexity: O(P*log(N))
// Memory: O(log(N))

// @EXPECTED_RESULTS@: CORRECT

// Solution method: represent the recursive relation by a matrix,
//   compute the appropriate power logarithmically

/*
[ 0 1 1 0 ] [ F(n) ]     [F(n+1)]
[ K 0 0 1 ] [ G(n) ]  =  [G(n+1)]
[ 1 K 0 0 ] [ H(n) ]     [H(n+1)]
[ 0 0 1 0 ] [H(n-1)]     [ H(n) ]
*/


#include <cstdio>
using namespace std;


// Multiplies matrix A by B (modulo P)
void matrix_multiply (int A[4][4], int B[4][4], int P)
{ int Z[4][4];
  int i, j, k;
  for (i = 0; i < 4; i++)
    for (j = 0; j < 4; j++)
    { Z[i][j] = 0;
      for (k = 0; k < 4; k++)
        Z[i][j] += A[i][k] * B[k][j];
      Z[i][j] %= P;
    }
  for (i = 0; i < 4; i++)
    for (j = 0; j < 4; j++)
      A[i][j] = Z[i][j];
}

// Raises matrix A to the n-th power (modulo P), puts result in Z
void matrix_pow (int A[4][4], int n, int Z[4][4], int P)
{ if (n == 0) // Base case: A^0 = identity matrix
  { int i, j;
    for (i = 0; i < 4; i++)
      for (j = 0; j < 4; j++)
        Z[i][j] = (i==j);
    return;
  }
  matrix_pow(A, n/2, Z, P); // Compute the square root recursively
  matrix_multiply(Z, Z, P);
  if (n%2 == 1)
    matrix_multiply(Z, A, P);
}

// Calculates the coordinate based on the parameters
int coordinate (int P, int A, int B, int C, int K, int N, int H0)
{ int M[4][4] = {{0,1,1,0},{K,0,0,1},{1,K,0,0},{0,0,1,0}};
  int Z[4][4];
  matrix_pow(M, N-1, Z, P);
  return (Z[0][0]*A + Z[0][1]*B + Z[0][2]*C + Z[0][3]*H0) % P;
}


int main()
{ int cases, casenr, P, Ax, Bx, Cx, Kx, Nx, Ay, By, Cy, Ky, Ny, x, y, c, H0;
  bool ambiguous;
  
  scanf("%d\n", &cases);
  for (casenr = 1; casenr <= cases; casenr++)
  { 
    // Read input
    scanf("%d\n%d %d %d %d %d\n%d %d %d %d %d\n%d\n",
          &P, &Ax, &Bx, &Cx, &Kx, &Nx, &Ay, &By, &Cy, &Ky, &Ny, &x);
    
    y = -1;
    ambiguous = false;
    for (H0 = 0; H0 < P && !ambiguous; H0++)
      if (coordinate(P, Ax, Bx, Cx, Kx, Nx, H0) == x) // Check if this value of H0 works
      { c = coordinate(P, Ay, By, Cy, Ky, Ny, H0); // Corresponding y-coordinate
        if (y == -1) // No solution found yet
          y = c;
        else if (y != c) // Different solution for y
          ambiguous = true;
      }

    // Print result
    if (ambiguous || y == -1)
      printf("UNKNOWN\n");
    else
      printf("%d\n", y);
  }
  return 0;
}

