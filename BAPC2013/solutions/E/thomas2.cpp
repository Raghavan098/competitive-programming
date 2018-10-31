// Solution to Encoded Coordinates
// Author: Thomas Beuman

// Time complexity: O(log(N)+log(P))
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
#include <utility>
using namespace std;


// Determines: x (0 < x < m) such that x*a = ggd(a, m) (mod m)
int modinv (int a, int m)
{ int b = m, x = 0, y = 1, t; // x*a + y*m = b throughout
  while (a > 0)
  { t = x - (b/a) * y;  x = y;  y = t;
    t = b % a;  b = a;  a = t;
  }
  return x < 0 ? x + m : x; // b = ggd(a, m)
}

// Greatest common divisor
int gcd (int a, int b)
{ return b ? gcd(b, a%b) : a;
}

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
// Return value is (a,b), coordinate = (a+b*H(0)) % P
pair<int,int> coordinate (int P, int A, int B, int C, int K, int N)
{ int M[4][4] = {{0,1,1,0},{K,0,0,1},{1,K,0,0},{0,0,1,0}};
  int Z[4][4];
  matrix_pow(M, N-1, Z, P);
  return make_pair((Z[0][0]*A + Z[0][1]*B + Z[0][2]*C) % P, Z[0][3] % P);
}


int main()
{ int cases, casenr, P, Ax, Bx, Cx, Kx, Nx, Ay, By, Cy, Ky, Ny, x, d, H0;
  pair<int,int> Jx, Jy;
  
  scanf("%d\n", &cases);
  for (casenr = 1; casenr <= cases; casenr++)
  { 
    // Read input
    scanf("%d\n%d %d %d %d %d\n%d %d %d %d %d\n%d\n",
          &P, &Ax, &Bx, &Cx, &Kx, &Nx, &Ay, &By, &Cy, &Ky, &Ny, &x);
    
    Jx = coordinate(P, Ax, Bx, Cx, Kx, Nx);
    Jy = coordinate(P, Ay, By, Cy, Ky, Ny);
    d = gcd(P, Jx.second);
    if (gcd(P, Jy.second) % d || (x - Jx.first) % d) // Multiple solutions or no solution
      printf("UNKNOWN\n");
    else
    { H0 = ((x - Jx.first + P) / d * modinv(Jx.second / d, P / d)) % P; // A solution for H(0)
      printf("%d\n", (Jy.first + H0 * Jy.second) % P);
    }
  }
  return 0;
}

